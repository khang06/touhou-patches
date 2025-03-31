#include "effect.hpp"
#include "util.hpp"

class NoAnmRotation : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;

    NoAnmRotation() {
        static constexpr uint8_t zero = 0;
        patches.Add(0x481CC5, (void*)&zero, sizeof(zero));
        patches.Add(0x481CC7, (void*)&zero, sizeof(zero));
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(NoAnmRotation);
