#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class AlmostQuit : public Effect {
public:
    static CodePatches Patches;

    // Prevent the game from overwriting the menu cursor position when opening the submenu
    static void __thiscall MenuSystemSetPosHook(void*, int) {
        Patches.Clear();
    }

    AlmostQuit() {
        auto pause = PauseMenu::Instance;
        pause->Pause();
        pause->submenu = 9;
        pause->menu.entry_count = 7;
        pause->menu.cur_pos = Rand::Next() & 1;
        pause->transition_timer.set(20);

        Patches.AddCall(0x4595D4, (void*)MenuSystemSetPosHook);
    }
};
REGISTER_EFFECT(AlmostQuit);

CodePatches AlmostQuit::Patches;
