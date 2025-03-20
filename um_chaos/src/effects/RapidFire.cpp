#include "effect.hpp"
#include "util.hpp"

class RapidFire : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;

    RapidFire() {
        static constexpr uint8_t patch[] = { 0x66, 0x90 };
        patches.Add(0x45EC3C, (void*)patch, sizeof(patch));
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(RapidFire);
