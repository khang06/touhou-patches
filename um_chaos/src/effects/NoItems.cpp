#include "effect.hpp"
#include "util.hpp"

class NoItems : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;

    NoItems() {
        static constexpr uint8_t patch[] = {
            // ret 0x20
            0xC2, 0x20, 0x00
        };
        patches.Add(0x446F40, (void*)patch, sizeof(patch));
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(NoItems);
