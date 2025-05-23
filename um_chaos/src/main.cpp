#define _CRT_RAND_S
#include <atomic>
#include <Windows.h>
#include <cmath>
#include <commctrl.h>
#include <numeric>
#include <stdio.h>
#include <algorithm>
#include "assets.hpp"
#include "commonhooks.hpp"
#include "effect.hpp"
#include "th18.hpp"
#include "twitch_irc.hpp"
#include "settings.hpp"
#include "util.hpp"

enum VoteState {
    VOTE_INACTIVE,
    VOTE_ACTIVE,
    VOTE_RESULTS_SPIN,
    VOTE_RESULTS_END,
};

extern "C" D3DVECTOR g_fps_pos = {588.0f, 470.0f, 0.0f};

bool g_game_loaded = false;
bool g_game_stage_transition = false;
int g_effect_req = -1;
int g_next_effect_timer = 0;

VoteState g_vote_state = VOTE_INACTIVE;
int g_vote_state_timer = 0;
size_t g_vote_choices[4] = {};
size_t g_vote_chosen_idx = 0;
size_t g_pie_tri_count = 0;
float g_vote_rand = 0.0f;
float g_pie_angle = 0.0f;
size_t g_last_votes[4] = {};
int g_vote_transition = 0;
float g_spin_tick = 0;

TwitchStatus g_twitch_status = TWITCH_DISABLED;
int g_twitch_init_timer = 0; // Makes sure the current frame is showing the initializing message before freezing the main thread
char g_twitch_last_user[sizeof(Settings::TwitchUsername)] = {};

static constexpr D3DCOLOR VOTE_COLORS[] = {
    D3DCOLOR_XRGB(0xFF, 0x00, 0x00),
    D3DCOLOR_XRGB(0x00, 0xEB, 0x00),
    D3DCOLOR_XRGB(0x00, 0x9B, 0xFF),
    D3DCOLOR_XRGB(0xCC, 0xCA, 0x00),
};

extern int orig_threadproc();
extern "C" int game_threadproc_hook() {
    orig_threadproc();

    Util::Log("Game started\n");

    if (!g_game_stage_transition) { 
        Util::Log("Running new run init code\n");

        uint32_t seed;
        rand_s(&seed);
        if (!seed)
            seed = 1;
        Rand::Seed(seed);
        g_next_effect_timer = Rand::RangeFrames(Settings::MinRandomTime, Settings::MaxRandomTime);
        g_vote_state = VOTE_INACTIVE;
        twitch_voting(false);
        g_vote_state_timer = Rand::RangeFrames(Settings::MinVoteTime, Settings::MaxVoteTime);
        //g_vote_state_timer = 120; // debug
        g_pie_angle = 0.0f;

        // For CharacterSwap
        // Loads in ANM slots normally resolved for ending
        static constexpr const char* anm_files[] = {"pl00.anm", "pl01.anm", "pl02.anm", "pl03.anm"};
        for (int i = 0; i < 4; i++) {
            if (i != Globals::Character)
                AnmManager::Instance->Preload(20 + i, anm_files[i]);
        }
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
                if (g_vote_state != VOTE_INACTIVE) {
                    reset_cur_votes();
                    g_vote_state = VOTE_INACTIVE;
                }
                twitch_voting(false);
                g_fps_pos.x = 588.0f;
                for (int i = 0; i < 4; i++) {
                    if (i != Globals::Character)
                        AnmManager::Instance->Unpreload(20 + i);
                }
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

    if (Settings::TwitchEnabled && Settings::VotingEnabled) {
        switch (g_vote_state) {
            case VOTE_INACTIVE: {
                if (--g_vote_state_timer <= 0) {
                    if (Effect::VoteChoices(g_vote_choices, _countof(g_vote_choices))) {
                        Util::Log("Starting vote\n");
                        g_vote_state = VOTE_ACTIVE;
                        g_vote_state_timer = Settings::VoteDuration * 60;

                        twitch_voting(true);
                        for (int i = 0; i < _countof(g_vote_choices); i++)
                            Util::Log("%d: %s\n", i + (voting_is_high_numbers() ? 5 : 1), Effect::Infos[g_vote_choices[i]].name);
                        memset(g_last_votes, 0xFF, sizeof(g_last_votes));
                        g_vote_transition = 0;

                        SoundManager::Instance.PlaySE(67, 0.0f);
                    } else {
                        Util::Log("Failed to pick vote choices\n");
                    }
                }
                break;
            }
            case VOTE_ACTIVE: {
                if (g_vote_transition < 24)
                    g_vote_transition++;
                if (--g_vote_state_timer <= 0) {
                    Util::Log("Voting finished, showing results\n");
                    g_vote_state = VOTE_RESULTS_SPIN;
                    g_vote_state_timer = 4 * 60;
                    twitch_voting(false);

                    g_vote_rand = Rand::NextFloat();
                    g_pie_angle = 0.0f;
                    g_spin_tick = 0.0f;

                    SoundManager::Instance.PlaySE(31, 0.0f);
                }
                break;
            }
            case VOTE_RESULTS_SPIN: {
                if (--g_vote_state_timer <= 0) {
                    g_vote_state = VOTE_RESULTS_END;
                    g_vote_state_timer = 2 * 60;

                    auto accum = get_votes();
                    for (int i = 0; i < _countof(g_vote_choices); i++) {
                        Util::Log("%s: %d\n", Effect::Infos[g_vote_choices[i]].name, accum[i]);
                        Effect::Infos[g_vote_choices[i]].vote_choice = false;
                    }
                    for (int i = 1; i < accum.size(); i++)
                        accum[i] += accum[i - 1];
                    if (accum.back() == 0) {
                        // Failsafe for no votes
                        for (int i = 0; i < accum.size(); i++)
                            accum[i] = i + 1;
                    }

                    int num = accum.back() * g_vote_rand;
                    for (int i = 0; i < accum.size(); i++) {
                        if (accum[i] > num) {
                            printf("Picked %s!\n", Effect::Infos[g_vote_choices[i]].name);
                            Effect::Enable(g_vote_choices[i]);
                            g_vote_chosen_idx = i;
                            break;
                        }
                    }

                    SoundManager::Instance.PlaySE(59, 0.0f);
                } else {
                    float t = (float)g_vote_state_timer / (4 * 60);
                    g_pie_angle = (1.0f - powf(t, 4.0f)) * (16.0f + g_vote_rand) * TWO_PI;
                    if (--g_spin_tick <= 0) {
                        g_spin_tick = 1.0f / (4.0f * powf(t, 3.0f));
                        SoundManager::Instance.PlaySE(78, 0.0f);
                    }
                }
                break;
            }
            case VOTE_RESULTS_END: {
                g_vote_transition = std::max(0, std::min(g_vote_state_timer - 1, 24));
                if (--g_vote_state_timer <= 0) {
                    Util::Log("Vote results finished\n");
                    g_vote_state = VOTE_INACTIVE;
                    g_vote_state_timer = Rand::RangeFrames(Settings::MinVoteTime, Settings::MaxVoteTime);

                    reset_cur_votes();
                }
                break;
            }
        }
    }

    if (g_effect_req != -1) {
        if (g_effect_req < Effect::AllCount) {
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
        } else {
            printf("Invalid effect ID %d\n", g_effect_req);
        }
        g_effect_req = -1;
    }
    Effect::UpdateAll();

    return 1;
}

// TODO: This is TERRIBLE
void update_vote_pie(const std::array<size_t, 4>& votes) {
    float total_votes = std::accumulate(votes.begin(), votes.end(), 0);
    bool has_votes = total_votes != 0.0f;
    float offset = 0.0f;

    VoteVertex* vertices;
    uint16_t* indices;
    Assets::VoteVB->Lock(0, 0, (void**)&vertices, 0);
    Assets::VoteIB->Lock(0, 0, (void**)&indices, 0);

    static constexpr float fringe_size = 0.5f;
    size_t cur_vertex = 4;
    size_t cur_index = 6;
    for (int i = 0; i < votes.size(); i++) {
        if (has_votes && votes[i] == 0)
            continue;
        float proportion = has_votes ? (votes[i] / total_votes) : 0.25f;
        int res = std::max(1.0f, proportion * 50);

        // Draw vote arc
        size_t center_vertex = cur_vertex;
        vertices[cur_vertex++] = {578.0f, 451.0f, 0.0f, 1.0f, 1.0f, VOTE_COLORS[i]};
        for (int j = 0; j <= res; j++) {
            float t = (float)j / res * proportion + offset;
            float sin = sinf(t * TWO_PI);
            float cos = cosf(t * TWO_PI);
            auto& last_vtx = vertices[cur_vertex++] = {578.0f + cos * 22.0f, 451.0f - sin * 22.0f, 0.0f, (float)j / res, 0.0f, VOTE_COLORS[i]};
            vertices[cur_vertex++] = {578.0f + cos * (22.0f + fringe_size), 451.0f - sin * (22.0f + fringe_size), 0.0f, (float)j / res, 0.0f, VOTE_COLORS[i] & 0xFFFFFF};
            if (j == res) {
                // Arc end fringes
                vertices[cur_vertex++] = {last_vtx.x - sin * fringe_size, last_vtx.y - cos * fringe_size, 0.0f, (float)j / res, 0.0f, VOTE_COLORS[i] & 0xFFFFFF};
                vertices[cur_vertex++] = {578.0f - sin * fringe_size, 451.0f - cos * fringe_size, 0.0f, (float)j / res, 0.0f, VOTE_COLORS[i] & 0xFFFFFF};
                
                indices[cur_index++] = center_vertex;
                indices[cur_index++] = cur_vertex - 4;
                indices[cur_index++] = cur_vertex - 2;

                indices[cur_index++] = center_vertex;
                indices[cur_index++] = cur_vertex - 2;
                indices[cur_index++] = cur_vertex - 1;
            } else {
                if (j == 0) {
                    // Arc start fringes
                    vertices[cur_vertex++] = {last_vtx.x + sin * fringe_size, last_vtx.y + cos * fringe_size, 0.0f, (float)j / res, 0.0f, VOTE_COLORS[i] & 0xFFFFFF};
                    vertices[cur_vertex++] = {578.0f + sin * fringe_size, 451.0f + cos * fringe_size, 0.0f, (float)j / res, 0.0f, VOTE_COLORS[i] & 0xFFFFFF};

                    indices[cur_index++] = center_vertex;
                    indices[cur_index++] = cur_vertex - 4;
                    indices[cur_index++] = cur_vertex - 2;

                    indices[cur_index++] = center_vertex;
                    indices[cur_index++] = cur_vertex - 2;
                    indices[cur_index++] = cur_vertex - 1;
                }

                // Main arc parts
                indices[cur_index++] = center_vertex;
                indices[cur_index++] = center_vertex + j * 2 + 1;
                indices[cur_index++] = center_vertex + 2 + j * 2 + 3;

                // Outer circle fringes
                indices[cur_index++] = center_vertex + j * 2 + 1;
                indices[cur_index++] = center_vertex + j * 2 + 2;
                indices[cur_index++] = center_vertex + 2 + j * 2 + 4;

                indices[cur_index++] = center_vertex + j * 2 + 1;
                indices[cur_index++] = center_vertex + 2 + j * 2 + 4;
                indices[cur_index++] = center_vertex + 2 + j * 2 + 3;
            }
        }
        offset += proportion;
    }

    // Random choice arrow
    static constexpr float arrow_radius = 4.0f;
    static constexpr float arrow_axis_fringe = 0.7071067f * fringe_size;
    static constexpr VoteVertex arrow_vertices[] = {
        {578.0f + 18.0f, 451.0f, 1.0f, 0.0f, 0.5f, 0xFFFFFFFF},
        {578.0f + 18.0f + arrow_radius * 2.0f, 451.0f - arrow_radius, 1.0f, 1.0f, 1.0f, 0xFFFFFFFF},
        {578.0f + 18.0f + arrow_radius * 2.0f, 451.0f + arrow_radius, 1.0f, 0.0f, 1.0f, 0xFFFFFFFF},

        {578.0f + 18.0f - arrow_axis_fringe, 451.0f - arrow_axis_fringe, 1.0f, 0.0f, 0.5f, 0x00FFFFFF},
        {578.0f + 18.0f + arrow_radius * 2.0f - arrow_axis_fringe, 451.0f - 4.0f - arrow_axis_fringe, 1.0f, 1.0f, 1.0f, 0x00FFFFFF},

        {578.0f + 18.0f - arrow_axis_fringe, 451.0f + arrow_axis_fringe, 1.0f, 0.0f, 0.5f, 0x00FFFFFF},
        {578.0f + 18.0f + arrow_radius * 2.0f - arrow_axis_fringe, 451.0f + 4.0f + arrow_axis_fringe, 1.0f, 0.0f, 1.0f, 0x00FFFFFF},
    };
    static constexpr int16_t arrow_indices[] = {
        0, 1, 2,

        0, 1, 4,
        0, 4, 3,

        0, 2, 6,
        0, 6, 5,
    };
    memcpy(&vertices[cur_vertex], arrow_vertices, sizeof(arrow_vertices));
    for (size_t i = 0; i < _countof(arrow_indices); i++)
        indices[cur_index++] = cur_vertex + arrow_indices[i];

    g_pie_tri_count = cur_index / 3;

    Assets::VoteVB->Unlock();
    Assets::VoteIB->Unlock();
}

void draw_voting_overlay() {
    auto ascii = AsciiManager::Instance;

    auto votes = get_votes();
    if (Assets::VotePieResetPending || memcmp(votes.data(), g_last_votes, sizeof(votes))) {
        update_vote_pie(votes);
        memcpy(g_last_votes, votes.data(), sizeof(g_last_votes));
        Assets::VotePieResetPending = false;
    }

    float interp = g_vote_state == VOTE_ACTIVE ?
        powf(1.0f - g_vote_transition / 24.0f, 3.0f) :
        (1.0f - powf(g_vote_transition / 24.0f, 3.0f));
    float y_offset = interp * 56.0f;
    g_fps_pos.x = 588.0f + (1.0f - interp) * 6.0f;
    ascii->style = 1;
    ascii->color = D3DCOLOR_XRGB(0xFF, 0xFF, 0xFF);
    ascii->shadow_color = D3DCOLOR_XRGB(0x00, 0x00, 0x00);
    ascii->ver_align = 1;
    ascii->hor_align = 1;
    for (int i = 0; i < votes.size(); i++) {
        const D3DVECTOR pos = { 421.0f, 431.0f + i * 12.0f + y_offset, 0.0f };
        int alpha = (g_vote_state == VOTE_RESULTS_END && g_vote_chosen_idx != i) ? 0x80000000 : 0xFF000000;
        ascii->color = (VOTE_COLORS[i] & 0xFFFFFF) | alpha;
        ascii->DrawShadowText(&pos, "%d %s (%d)\n",
            i + (voting_is_high_numbers() ? 5 : 1), Effect::Infos[g_vote_choices[i]].name, votes[i]);
    }

    const D3DVECTOR pos = { 640.0f - 4.0f, 427.0f + y_offset, 0.0f };
    ascii->color = D3DCOLOR_XRGB(0xFF, 0xFF, 0xFF);
    ascii->hor_align = 2;
    ascii->DrawShadowText(&pos, "%.2fs", g_vote_state == VOTE_ACTIVE ? (g_vote_state_timer / 60.0f) : 0.0f);

    auto d3d9_dev = Main::Instance.d3d9_device;
    DWORD z_enable;
    IDirect3DBaseTexture9* prev_tex = nullptr;
    AnmManager::Instance->FlushSprites();
    d3d9_dev->GetRenderState(D3DRS_ZENABLE, &z_enable);
    d3d9_dev->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
    d3d9_dev->GetTexture(0, &prev_tex);
    d3d9_dev->SetTexture(0, CommonHooks::LeSanae ? Assets::LeSanae : NULL);

    // https://github.com/ocornut/imgui/blob/5e2368045418a7cf6e21f555f0f018e778e2eae2/backends/imgui_impl_dx9.cpp#L136
    // ...but transposed, because D3D9 wants that for some reason?
    static constexpr float L = 0.0f;
    static constexpr float R = 640.0f;
    static constexpr float T = 0.0f;
    static constexpr float B = 480.0f;
    float consts[] = {
        2.0f/(R-L), 0.0f,       0.0f, (L+R)/(L-R),
        0.0f,       2.0f/(T-B), 0.0f, (T+B)/(B-T),
        0.0f,       0.0f,       0.5f, 0.5f,
        0.0f,       0.0f,       0.0f, 1.0f,

        sinf(g_pie_angle), cosf(g_pie_angle), y_offset, 0.0f,
    };
    d3d9_dev->SetVertexShaderConstantF(0, consts, _countof(consts) / 4);
    d3d9_dev->SetVertexDeclaration(Assets::VoteVertexDecl);
    d3d9_dev->SetVertexShader(Assets::VoteVS);
    d3d9_dev->SetStreamSource(0, Assets::VoteVB, 0, sizeof(VoteVertex));
    d3d9_dev->SetIndices(Assets::VoteIB);
    d3d9_dev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, g_pie_tri_count * 3, 0, g_pie_tri_count);

    d3d9_dev->SetTexture(0, prev_tex);
    d3d9_dev->SetRenderState(D3DRS_ZENABLE, z_enable);
    d3d9_dev->SetVertexShader(NULL);
}

int __fastcall post_frame_draw(void*) {
    auto ascii = AsciiManager::Instance;
    if (!ascii)
        return 1;
    
    uint32_t orig_color = ascii->color;
    uint32_t orig_shadow_color = ascii->shadow_color;
    float orig_scale_x = ascii->scale_x;
    float orig_scale_y = ascii->scale_y;
    uint32_t orig_style = ascii->style;
    uint32_t orig_hor_align = ascii->hor_align;
    uint32_t orig_ver_align = ascii->ver_align;

    if (Main::Instance.cur_mode == 4) {
        D3DVECTOR pos = { 4.0f, TitleScreen::Instance && TitleScreen::Instance->cur_state == 17 ? 440.0f : 460.0f, 0.0f };
        ascii->style = 6;
        ascii->shadow_color = D3DCOLOR_XRGB(0x00, 0x00, 0x00);
        ascii->ver_align = 1;
        ascii->hor_align = 1;

        switch (g_twitch_status) {
            case TWITCH_INIT_PENDING:
                ascii->color = D3DCOLOR_XRGB(0xFF, 0xFF, 0xFF);
                ascii->DrawShadowText(&pos, "Connecting to %s...", g_twitch_last_user);
                break;
            case TWITCH_INITIALIZED:
                ascii->color = D3DCOLOR_XRGB(0x91, 0x46, 0xFF);
                ascii->DrawShadowText(&pos, "Connected to %s", g_twitch_last_user);
                break;
            case TWITCH_FAILED:
                ascii->color = D3DCOLOR_XRGB(0xFF, 0x00, 0x00);
                ascii->DrawShadowText(&pos, "Failed to connect to %s!", g_twitch_last_user);
                break;
            case TWITCH_DISABLED:
                break;
        }
    }

    if (Main::Instance.cur_mode == 4 && Window::IsFullscreen()) {
        D3DVECTOR pos1 = { 4.0f, 4.0f, 0.0f };
        D3DVECTOR pos2 = { 4.0f, 20.0f, 0.0f };
        ascii->style = 6;
        ascii->color = D3DCOLOR_XRGB(0xFF, 0xFF, 0x00);
        ascii->shadow_color = D3DCOLOR_XRGB(0x00, 0x00, 0x00);
        ascii->ver_align = 1;
        ascii->hor_align = 1;
        ascii->DrawShadowText(&pos1, "Some effects only work in windowed mode!");
        ascii->DrawShadowText(&pos2, "You can switch modes by pressing Alt+Enter.");
    }

    ascii->style = 1;
    for (int i = 0; i < Effect::EnabledCount; i++) {
        D3DVECTOR pos = { 4.0f, 470.0f - i * 10.0f, 0.0f };
        //auto fade = std::min(0xFF, Effect::Enabled[i].frames_active * 8);
        auto fade = Effect::Enabled[i].frames_active > 60 ? 0xFF : (Effect::Enabled[i].frames_active % 8 < 4 ? 0x00 : 0xFF);
        ascii->color = D3DCOLOR_XRGB(0xFF, fade, fade);
        ascii->DrawShadowText(&pos, "%s", Effect::Enabled[i].name);
    }
    ascii->color = 0xFFFFFFFF;

    Effect::DrawAll();
    if (g_vote_state != VOTE_INACTIVE)
        draw_voting_overlay();
    
    ascii->color = orig_color;
    ascii->shadow_color = orig_shadow_color;
    ascii->scale_x = orig_scale_x;
    ascii->scale_y = orig_scale_y;
    ascii->style = orig_style;
    ascii->hor_align = orig_hor_align;
    ascii->ver_align = orig_ver_align;

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

extern "C" void __thiscall custom_anm_handler(AnmVM* self) {
    // Too lazy to parse parameters
    if (self->I[0] == 114514) {
        SoundManager::Instance.PlaySE(2, -192.0f);
    } else {
        LARGE_INTEGER qpc;
        QueryPerformanceCounter(&qpc);
        Rand::Seed(qpc.LowPart);
        SoundManager::Instance.PlaySE(51, 0.0f);
        CommonHooks::TitleScreenShake = 60;
    }
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

// (disabled) Automatically run the unlock code on boot
// This is here because the scorefile path gets overridden (scoreth18chaos.dat)
// Conveniently in the right spot to preload stuff for the loading screen edit
std::atomic_bool g_chaos_anm_loaded = false;
extern "C" void scorefile_init_hook() {
    ScoreFile::Init();
    //ScoreFile::UnlockCode();
    AnmManager::Instance->Preload(18, "chaos.anm");
    g_chaos_anm_loaded = true;
}

extern "C" int loading_screen_draw_hook() {
    static bool sprites_loaded = false;
    static bool sprites_deleted = false;
    static AnmVM* vm = nullptr;
    if (g_chaos_anm_loaded && !sprites_loaded) {
        auto anm = AnmManager::Instance->Preload(18, "chaos.anm");
        uint32_t id;
        vm = AnmManager::AllocateVM();
        anm->MakeVM(vm, 16);
        AnmManager::AddToUIBack(&id, vm);

        sprites_loaded = true;
    }
    if (sprites_loaded && !sprites_deleted && Window::Instance.loading_complete) {
        vm->pending_interrupt = 1;
        sprites_deleted = true;
    }
    return 1;
}

// Disables fastfail so thcrap can get crash logs
extern "C" BOOL __stdcall IsProcessorFeaturePresent_hook(DWORD ProcessorFeature) {
    if (ProcessorFeature == PF_FASTFAIL_AVAILABLE)
        return FALSE;
    return IsProcessorFeaturePresent(ProcessorFeature);
}

// All bomb structs are exactly the same size and the same constructors
// The vtable needs to be swapped out at runtime for CharacterSwap to not explode
// This only happens on bomb activation because doing it any other time might have some terrible consequences
extern "C" void __thiscall GameGlobals_UseBomb(void*);
extern "C" void __thiscall GameGlobals_UseBomb_hook(void* self) {
    GameGlobals_UseBomb(self);
    
    static constexpr uint32_t BOMB_VTBLS[4] = {0x4B6330, 0x4B6310, 0x4B62F0, 0x4B62D0};
    Bomb::Instance->vtbl = BOMB_VTBLS[Globals::Character];
}

// Works around some crash that happens with EoSDBooks(?)
// Specifically it seems to happen in EoSDBooksFade in the setf() (idx 45) handler
// No idea how that instruction is getting read in the first place...
extern "C" float* __thiscall EclThread_GetFloatPtrArg(void*, int);
extern "C" float* __thiscall EclThread_GetFloatPtrArg_hook(void* self, int idx) {
    static float dummy = 0.0f;
    float* ret = EclThread_GetFloatPtrArg(self, idx);
    return ret ? ret : &dummy;
}

// Works around a crash when RestartStage happens at the same time as OpenShop
extern "C" void __thiscall GameState_dtor_hook(GameState* self) {
    self->~GameState();
    
    // Normally this happens before the shop gets deleted, causing a crash if it's a stage transition
    GameState::Instance = nullptr;
    GameState::Unloaded = 1;
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

// RandomEasing intentionally breaks all of the interpolators,
// but unfortunately some scripts (e.g. Lily) use the interpolator value as the wait value
// This should prevent that from freezing the game
extern "C" int __thiscall EclThread_GetIntArg(void*, int);
extern "C" int __thiscall EclThread_GetIntArg_wait_hook(void* self, int pos) {
    return std::max(1, EclThread_GetIntArg(self, pos));
}

extern "C" float __thiscall EclThread_GetFloatArg(void*, int);
extern "C" float __thiscall EclThread_GetFloatArg_waitf_hook(void* self, int pos) {
    return std::max(1.0f, EclThread_GetFloatArg(self, pos));
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
