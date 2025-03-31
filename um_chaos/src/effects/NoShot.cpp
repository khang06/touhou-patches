#include "effect.hpp"
#include "util.hpp"

class NoShot : public Effect {
public:
    int timer = Rand::RangeEffectTime(5, 30);
    CodePatches patches;

    NoShot() {
        static constexpr uint8_t patch[] = {
            // xor eax, eax
            0x31, 0xC0,
            // ret 0x10
            0xC2, 0x10, 0x00
        };
        patches.Add(0x45E930, (void*)patch, sizeof(patch));
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(NoShot);
