#include <Windows.h>
#include <stdio.h>
#include "assets.hpp"
#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

bool g_game_loaded = false;
bool g_game_stage_transition = false;
int g_effect_req = -1;

extern int orig_threadproc();
extern "C" int game_threadproc_hook() {
    orig_threadproc();

    printf("Game started\n");

    if (!g_game_stage_transition) {
        Rand::Seed(timeGetTime());
    }
    g_game_loaded = true;
    return 0;
}

extern "C" int __thiscall switch_mode_hook(Main* self) {
    if (self->cur_mode != self->switch_target_mode) {
        if (self->cur_mode == 7) {
            printf("Game ended\n");
            if (self->switch_target_mode != 12) {
                while (Effect::EnabledCount != 0)
                    Effect::Disable(0);
                g_game_stage_transition = false;
            } else {
                g_game_stage_transition = true;
            }
            g_game_loaded = false;
        }
    }
    return self->SwitchMode();
}

int __fastcall post_frame_update(void*) {
    if (!g_game_loaded)
        return 1;

    if (g_effect_req != -1) {
        Effect::Enable(g_effect_req);
        g_effect_req = -1;
    }
    Effect::UpdateAll();

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

extern "C" int entry_hook() {
    // Spawn a console window for debugging
    AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
    printf("UM:CE " __DATE__ "\n");
    printf("Loaded %zu effects\n", Effect::AllCount);
    for (size_t i = 0; i < Effect::AllCount; i++)
        printf("%zu %s\n", i, Effect::Infos[i].name);
    printf("\n");
    SetForegroundWindow(Main::Window);

    // Spawn debug console input thread
    CreateThread(NULL, 0, console_input_proc, NULL, 0, NULL);

    // Load assets
    Assets::Load();

    // Register post-frame update function
    auto node = CalcChain::Create(post_frame_update);
    node->flags |= 2;
    CalcChain::RegisterCalc(node, 1000);

    return 0;
}
