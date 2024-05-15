#include <Windows.h>
#include <commctrl.h>
#include <numeric>
#include <stdio.h>
#include "assets.hpp"
#include "commonhooks.hpp"
#include "effect.hpp"
#include "th18.hpp"
#include "twitch_irc.hpp"
#include "settings.hpp"
#include "util.hpp"

bool g_game_loaded = false;
bool g_game_stage_transition = false;
int g_effect_req = -1;
int g_next_effect_timer = 0;
bool g_vote_active = false;
int g_cur_vote_timer = 0;
int g_next_vote_timer = 0;
size_t g_vote_choices[4] = {};

TwitchStatus g_twitch_status = TWITCH_DISABLED;
int g_twitch_init_timer = 0; // Makes sure the current frame is showing the initializing message before freezing the main thread
char g_twitch_last_user[sizeof(Settings::TwitchUsername)] = {};

extern int orig_threadproc();
extern "C" int game_threadproc_hook() {
    orig_threadproc();

    Util::Log("Game started\n");

    if (!g_game_stage_transition) {
        LARGE_INTEGER qpc;
        QueryPerformanceCounter(&qpc);
        Rand::Seed(qpc.LowPart);
        g_next_effect_timer = Rand::RangeFrames(Settings::MinRandomTime, Settings::MaxRandomTime);
        g_vote_active = false;
        twitch_voting(false);
        //g_next_vote_timer = Rand::RangeFrames(Settings::MinVoteTime, Settings::MaxVoteTime);
        g_next_vote_timer = 120; // debug
    }
    g_game_loaded = true;
    return 0;
}

extern "C" int __thiscall switch_mode_hook(Main* self) {
    if (self->cur_mode != self->switch_target_mode) {
        Util::Log("Switching modes from %d to %d\n", self->cur_mode, self->switch_target_mode);
        if (self->cur_mode == 7) {
            Util::Log("Game ended\n");
            if (self->switch_target_mode != 12) {
                while (Effect::EnabledCount != 0)
                    Effect::Disable(0);
                g_game_stage_transition = false;
                for (int i = 0; i < _countof(g_vote_choices); i++)
                    Effect::Infos[g_vote_choices[i]].vote_choice = false;
                g_vote_active = false;
                twitch_voting(false);
            } else {
                g_game_stage_transition = true;
            }
            g_game_loaded = false;
        }
        if (self->switch_target_mode == 4 && g_twitch_status == TWITCH_DISABLED && Settings::TwitchEnabled && Settings::TwitchUsername[0] != '\0') {
            memcpy(g_twitch_last_user, Settings::TwitchUsername, sizeof(Settings::TwitchUsername));
            g_twitch_status = TWITCH_INIT_PENDING;
            g_twitch_init_timer = 4;
        }
    }
    return self->SwitchMode();
}

int __fastcall post_frame_calc(void*) {
    if (CommonHooks::TitleScreenShake)
        CommonHooks::TitleScreenShake--;

    if (g_twitch_status == TWITCH_INIT_PENDING && --g_twitch_init_timer <= 0)
        g_twitch_status = start_twitch_thread(g_twitch_last_user) ? TWITCH_INITIALIZED : TWITCH_FAILED;

    if (!g_game_loaded || AbilityShop::Instance)
        return 1;

    if (Settings::RandomEnabled && --g_next_effect_timer <= 0) {
        Effect::EnableRandom();
        g_next_effect_timer = Rand::RangeFrames(Settings::MinRandomTime, Settings::MaxRandomTime);
    }

    if (Settings::VotingEnabled) {
        if (!g_vote_active && --g_next_vote_timer <= 0) {
            if (Effect::VoteChoices(g_vote_choices, _countof(g_vote_choices))) {
                g_cur_vote_timer = Settings::VoteDuration * 60;
                g_vote_active = true;

                twitch_voting(true);
                Util::Log("Starting vote\n");
                for (int i = 0; i < _countof(g_vote_choices); i++)
                    Util::Log("%d: %s\n", i + (voting_is_high_numbers() ? 5 : 1), Effect::Infos[g_vote_choices[i]].name);
            } else {
                Util::Log("Failed to pick vote choices\n");
            }
        } else if (g_vote_active && --g_cur_vote_timer <= 0) {
            Util::Log("Voting finished\n");
            auto accum = get_final_votes();
            for (int i = 0; i < _countof(g_vote_choices); i++) {
                Util::Log("%s: %d\n", Effect::Infos[g_vote_choices[i]].name, accum[i]);
                Effect::Infos[g_vote_choices[i]].vote_choice = false;
            }
            for (int i = 1; i < accum.size(); i++)
                accum[i] += accum[i - 1];
            if (accum.back() == 0) // Failsafe for no votes
                accum.back() = 1;

            int num = Rand::Range(0, accum.back());
            for (int i = 0; i < accum.size(); i++) {
                if (accum[i] > num) {
                    printf("Picked %s!\n", Effect::Infos[g_vote_choices[i]].name);
                    Effect::Enable(g_vote_choices[i]);
                    break;
                }
            }

            twitch_voting(false);
            g_vote_active = false;
            g_next_vote_timer = Rand::RangeFrames(Settings::MinVoteTime, Settings::MaxVoteTime);
        }
    }

    if (g_effect_req != -1) {
        if (Effect::Infos[g_effect_req].enabled) {
            for (int i = 0; i < Effect::EnabledCount; i++) {
                if (Effect::Enabled[i].id == g_effect_req) {
                    Effect::Disable(i);
                    break;
                }
            }
        } else {
            Effect::Enable(g_effect_req);
        }
        g_effect_req = -1;
    }
    Effect::UpdateAll();

    return 1;
}

void draw_voting_overlay() {
    constexpr D3DCOLOR COLORS[] = {
        D3DCOLOR_ARGB(0xFF, 0xFF, 0x60, 0x60),
        D3DCOLOR_ARGB(0xFF, 0x60, 0xFF, 0x60),
        D3DCOLOR_ARGB(0xFF, 0x60, 0x60, 0xFF),
        D3DCOLOR_ARGB(0xFF, 0xFF, 0xFF, 0x60),
    };
    constexpr uint16_t indices[] = {
        0, 1, 2,
        1, 2, 3,

        4, 5, 6,
        5, 6, 7,

        8, 9, 10,
        9, 10, 11,

        12, 13, 14,
        13, 14, 15,

        16, 17, 18,
        17, 18, 19,
    };
    static ZunVertex vertices[] = {
        {0,    0,   0, 1, 0xCD000000, 0,     0},
        {1280, 0,   0, 1, 0xCD000000, 0.001, 0},
        {0,    56,  0, 1, 0xCD000000, 0,     0.001},
        {1280, 56,  0, 1, 0xCD000000, 0.001, 0.001},

        {0, 32, 0, 1, COLORS[0], 0,     0},
        {0, 32, 0, 1, COLORS[0], 0.001, 0},
        {0, 48, 0, 1, COLORS[0], 0,     0.001},
        {0, 48, 0, 1, COLORS[0], 0.001, 0.001},
        {0, 32, 0, 1, COLORS[1], 0,     0},
        {0, 32, 0, 1, COLORS[1], 0.001, 0},
        {0, 48, 0, 1, COLORS[1], 0,     0.001},
        {0, 48, 0, 1, COLORS[1], 0.001, 0.001},
        {0, 32, 0, 1, COLORS[2], 0,     0},
        {0, 32, 0, 1, COLORS[2], 0.001, 0},
        {0, 48, 0, 1, COLORS[2], 0,     0.001},
        {0, 48, 0, 1, COLORS[2], 0.001, 0.001},
        {0, 32, 0, 1, COLORS[3], 0,     0},
        {0, 32, 0, 1, COLORS[3], 0.001, 0},
        {0, 48, 0, 1, COLORS[3], 0,     0.001},
        {0, 48, 0, 1, COLORS[3], 0.001, 0.001},
    };

    AsciiManager::Instance->style = 1;
    AsciiManager::Instance->color = D3DCOLOR_ARGB(0xFF, 0xFF, 0xFF, 0xFF);
    AsciiManager::Instance->shadow_color = D3DCOLOR_ARGB(0xFF, 0x00, 0x00, 0x00);
    AsciiManager::Instance->ver_align = 1;
    AsciiManager::Instance->hor_align = 1;
    auto votes = get_votes();
    float total_votes = std::accumulate(votes.begin(), votes.end(), 0);
    float vote_offset = 0.0f;
    for (int i = 0; i < votes.size(); i++) {
        const D3DVECTOR pos = { (i & 1) ? 192.0f : 4.0f, (i >> 1) ? 16.0f : 4.0f, 0.0f };
        AsciiManager::Instance->color = COLORS[i];
        AsciiManager::Instance->DrawShadowText(&pos, "%d: %s (%d)\n",
            i + (voting_is_high_numbers() ? 5 : 1), Effect::Infos[g_vote_choices[i]].name, votes[i]);

        float x1 = 1280 - 384 - 6 + (vote_offset / total_votes) * 384.0f;
        vote_offset += votes[i];
        float x2 = 1280 - 384 - 6 + (vote_offset / total_votes) * 384.0f;
        vertices[4 + i * 4].x = x1;
        vertices[4 + i * 4 + 1].x = x2;
        vertices[4 + i * 4 + 2].x = x1;
        vertices[4 + i * 4 + 3].x = x2;
    }

    const D3DVECTOR pos = { 640.0f - 4.0f, 4.0f, 0.0f };
    AsciiManager::Instance->color = D3DCOLOR_ARGB(0xFF, 0xFF, 0xFF, 0xFF);
    AsciiManager::Instance->hor_align = 2;
    AsciiManager::Instance->DrawShadowText(&pos, "Voting ends in %.2fs", g_cur_vote_timer / 60.0f);

auto d3d9_dev = Main::Instance.d3d9_device;
    DWORD z_enable;
    IDirect3DBaseTexture9* prev_tex = nullptr;
    AnmManager::Instance->FlushSprites();
    d3d9_dev->GetRenderState(D3DRS_ZENABLE, &z_enable);
    d3d9_dev->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
    d3d9_dev->GetTexture(0, &prev_tex);
    d3d9_dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
    d3d9_dev->SetTexture(0, NULL);
    d3d9_dev->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, _countof(indices), _countof(indices) / 3, indices, D3DFMT_INDEX16, vertices, sizeof(ZunVertex));
    d3d9_dev->SetTexture(0, prev_tex);
    d3d9_dev->SetRenderState(D3DRS_ZENABLE, z_enable);
}

int __fastcall post_frame_draw(void*) {
    if (!AsciiManager::Instance)
        return 1;

    if (Main::Instance.cur_mode == 4) {
        D3DVECTOR pos = { 4.0f, 460.0f, 0.0f };
        AsciiManager::Instance->style = 6;
        AsciiManager::Instance->color = g_twitch_status == TWITCH_FAILED ? D3DCOLOR_ARGB(0xFF, 0xFF, 0x00, 0x00) : D3DCOLOR_ARGB(0xFF, 0x91, 0x46, 0xFF);
        AsciiManager::Instance->shadow_color = D3DCOLOR_ARGB(0xFF, 0x00, 0x00, 0x00);
        AsciiManager::Instance->ver_align = 1;
        AsciiManager::Instance->hor_align = 1;

        switch (g_twitch_status) {
            case TWITCH_INIT_PENDING:
                AsciiManager::Instance->DrawShadowText(&pos, "Connecting to %s...", g_twitch_last_user);
                break;
            case TWITCH_INITIALIZED:
                AsciiManager::Instance->DrawShadowText(&pos, "Connected to %s", g_twitch_last_user);
                break;
            case TWITCH_FAILED:
                AsciiManager::Instance->DrawShadowText(&pos, "Failed to connect to %s!", g_twitch_last_user);
                break;
            case TWITCH_DISABLED:
            default:
                break;
        }
    }

    if (Main::Instance.cur_mode == 4 && Window::IsFullscreen()) {
        D3DVECTOR pos1 = { 4.0f, 4.0f, 0.0f };
        D3DVECTOR pos2 = { 4.0f, 20.0f, 0.0f };
        AsciiManager::Instance->style = 6;
        AsciiManager::Instance->color = D3DCOLOR_ARGB(0xFF, 0xFF, 0xFF, 0x00);
        AsciiManager::Instance->shadow_color = D3DCOLOR_ARGB(0xFF, 0x00, 0x00, 0x00);
        AsciiManager::Instance->ver_align = 1;
        AsciiManager::Instance->hor_align = 1;
        AsciiManager::Instance->DrawShadowText(&pos1, "Some effects only work in windowed mode!");
        AsciiManager::Instance->DrawShadowText(&pos2, "You can switch modes by pressing Alt+Enter.");
    }

    AsciiManager::Instance->style = 1;
    for (int i = 0; i < Effect::EnabledCount; i++) {
        D3DVECTOR pos = { 4.0f, 470.0f - i * 10.0f, 0.0f };
        //auto fade = min(0xFF, Effect::Enabled[i].frames_active * 8);
        auto fade = Effect::Enabled[i].frames_active > 60 ? 0xFF : (Effect::Enabled[i].frames_active % 8 < 4 ? 0x00 : 0xFF);
        AsciiManager::Instance->color = D3DCOLOR_ARGB(0xFF, 0xFF, fade, fade);
        AsciiManager::Instance->DrawShadowText(&pos, "%s", Effect::Enabled[i].name);
    }
    AsciiManager::Instance->color = 0xFFFFFFFF;

    if (g_vote_active)
        draw_voting_overlay();

    Effect::DrawAll();

    return 1;
}

DWORD __stdcall console_input_proc(void*) {
    char str[128];
    while (true) {
        if (!fgets(str, sizeof(str), stdin))
            continue;
        g_effect_req = strtol(str, nullptr, 10);
    }

    return 0;
}

extern "C" void custom_anm_handler() {
    LARGE_INTEGER qpc;
    QueryPerformanceCounter(&qpc);
    Rand::Seed(qpc.LowPart);
    SoundManager::Instance.PlaySE(51, 0.0f);
    CommonHooks::TitleScreenShake = 60;
}

extern "C" EnemyManager* __fastcall enemy_manager_create_hook(const char* filename) {
    if (!EnemyManager::Create(filename))
        return nullptr;

    auto file_manager = EnemyManager::Instance->file_manager;
    if (file_manager->LoadECLFile("chaos.ecl")) {
        MessageBox(NULL, "Failed to load chaos.ecl :(", NULL, MB_ICONERROR);
        DebugBreak();
    }

    auto anm = AnmManager::Instance->Preload(18, "chaos.anm");
    if (!anm) {
        MessageBox(NULL, "Failed to load chaos.anm :(", NULL, MB_ICONERROR);
        DebugBreak();
    }
    EnemyManager::Instance->enemy_ecls[5] = anm;

    Assets::StageAttacks.clear();
    Assets::BossAttacks.clear();
    for (uint32_t i = 0; i < file_manager->sub_count; i++) {
        if (!strncmp(file_manager->subroutines[i].name, "STAGE_", 6))
            Assets::StageAttacks.push_back(file_manager->subroutines[i].name);
        else if (!strncmp(file_manager->subroutines[i].name, "BOSS_", 5))
            Assets::BossAttacks.push_back(file_manager->subroutines[i].name);
    }
    Util::Log("Loaded %zu stage attacks and %zu boss attacks\n", Assets::StageAttacks.size(), Assets::BossAttacks.size());

    return EnemyManager::Instance;
}

extern "C" int __thiscall enemy_get_global_hook(Enemy* self, int idx) {
    if (idx == -1337)
        return self->random_attack_cur_et;
    return self->GetGlobal(idx);
}

// Automatically run the unlock code on boot
// This is here because the scorefile path gets overridden (scoreth18chaos.dat)
extern "C" void scorefile_init_hook() {
    ScoreFile::Init();
    ScoreFile::UnlockCode();
}

// Runs after the game is mostly initialized (e.g. D3D9 device ready)
extern "C" int entry_hook() {
    // Load config
    Settings::Load();

    // Spawn a console window for debugging
    if (Settings::DebugConsole) {
        AllocConsole();
        freopen("CONIN$", "r", stdin);
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }
    Util::Log("UM:CE " __DATE__ "\n");
    Util::Log("Loaded %zu effects\n", Effect::AllCount);
    for (size_t i = 0; i < Effect::AllCount; i++)
        Util::Log("%zu %s\n", i, Effect::Infos[i].name);
    Util::Log("\n");
    SetForegroundWindow(Main::Window);

    // Spawn debug console input thread
    if (Settings::DebugConsole)
        CreateThread(NULL, 0, console_input_proc, NULL, 0, NULL);

    // Load assets
    Assets::Load();

    // Register post-frame calc function
    auto calc = CalcChain::Create(post_frame_calc);
    calc->flags |= 2;
    CalcChain::RegisterCalc(calc, 1000);

    // Register post-frame draw function
    auto draw = CalcChain::Create(post_frame_draw);
    draw->flags |= 2;
    CalcChain::RegisterDraw(draw, 87);

    return 0;
}

// Runs as early as possible
// This code tries to activate comctl32 6.0
extern "C" void coff2binhack_init() {
    // https://stackoverflow.com/questions/4308503/how-to-enable-visual-styles-without-a-manifest
    WCHAR dir[MAX_PATH];
    ULONG_PTR ulpActivationCookie = FALSE;
    ACTCTXW actCtx =
    {
        sizeof(actCtx),
        ACTCTX_FLAG_RESOURCE_NAME_VALID
            | ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID,
        L"shell32.dll", 0, 0, dir, (LPCWSTR)124
    };
    UINT cch = GetSystemDirectoryW(dir, sizeof(dir) / sizeof(*dir));
    if (cch >= sizeof(dir) / sizeof(*dir)) { return; }
    dir[cch] = TEXT('\0');
    StupidWindowsStuff::ActivationContext = CreateActCtxW(&actCtx);

    ActivateActCtx(StupidWindowsStuff::ActivationContext, &ulpActivationCookie);

    // This class only exists in comctl32 6.0 and above, so querying its window class should load its DLL
    WNDCLASSEX wnd_class = {};
    wnd_class.cbSize = sizeof(wnd_class);
    GetClassInfoEx(NULL, "ListBox", &wnd_class);

    DeactivateActCtx(0, ulpActivationCookie);
}
