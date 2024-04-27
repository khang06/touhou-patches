#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class RestartStage : public Effect {
public:
    static CodePatches Patches;

    // Prevent the game from freeing the current stage's ANM
    static void __thiscall FreePreloadedAnmHook(void*, int) {
        Patches.Clear();
    }

    virtual bool Update() {
        // Trying to restart the stage while the player is respawning crashes the game
        if (Player::Instance->death_state != 1)
            return true;

        Patches.AddCall(0x41BDC6, (void*)&FreePreloadedAnmHook);
        Main::Instance.switch_target_mode = 12;
        return false;
    }
};
REGISTER_EFFECT(RestartStage);

CodePatches RestartStage::Patches;
