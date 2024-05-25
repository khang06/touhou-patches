#include "effect.hpp"
#include "util.hpp"

class NoFocus : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 2 * 60);
    CodePatches patches;

    NoFocus() {
        static constexpr uint8_t patch[] = {0x33, 0xD2, 0x90}; // xor edx, edx; nop
        patches.Add(0x45B403, (void*)&patch, sizeof(patch));
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(NoFocus);
