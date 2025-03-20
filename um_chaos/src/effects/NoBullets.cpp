#include "effect.hpp"
#include "util.hpp"

class NoBullets : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;

    NoBullets() {
        static constexpr uint8_t patch[] = {
            // mov al, 1
            0xB0, 0x01,
            // ret 0x10
            0xC2, 0x10, 0x00
        };
        patches.Add(0x424FE0, (void*)patch, sizeof(patch));
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(NoBullets);
