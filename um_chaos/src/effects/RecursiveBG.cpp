#include "effect.hpp"
#include "util.hpp"

class RecursiveBG : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;

    RecursiveBG() {
        {
            // Patch BG rendering
            static constexpr uint8_t patch = 0xB0; // screen_anm1 -> screen_anm2
            patches.Add(0x4555AF, (void*)&patch, sizeof(patch));
        }
        {
            // Patch enemy distortion effect render target ANM ID
            // Only applies when the fog effect is being created. Oh well!
            static constexpr uint8_t patch = 72;
            patches.Add(0x455D94, (void*)&patch, sizeof(patch));
        }
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(RecursiveBG);
