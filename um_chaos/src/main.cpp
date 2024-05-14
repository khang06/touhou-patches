#include <Windows.h>
#include <commctrl.h>
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
            } else {
                g_game_stage_transition = true;
            }
            g_game_loaded = false;
        }
        if (self->switch_target_mode == 4 && g_twitch_status == TWITCH_DISABLED && Settings::TwitchEnabled && Settings::TwitchUsername[0] != '\0') {
            memcpy(g_twitch_last_user, Settings::TwitchUsername, sizeof(Settings::TwitchUsername));
            g_twitch_status = TWITCH_INIT_PENDING;
            g_twitch_init_timer = 16;
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

int __fastcall post_frame_draw(void*) {
    if (!AsciiManager::Instance)
        return 1;

    if (Settings::TwitchEnabled) {
        D3DVECTOR pos = { 4.0f, 460.0f, 0.0f };
        AsciiManager::Instance->style = 6;
        AsciiManager::Instance->color = D3DCOLOR_ARGB(0xFF, 0x91, 0x46, 0xFF);
        AsciiManager::Instance->shadow_color = D3DCOLOR_ARGB(0xFF, 0x00, 0x00, 0x00);
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
