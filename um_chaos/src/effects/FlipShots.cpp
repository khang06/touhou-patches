#include "effect.hpp"
#include "util.hpp"

class FlipShots : public Effect {
public:
    static CodeCave Cave;

    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;

    FlipShots() {
        patches.AddJmp(0x45E46A, &Cave);
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(FlipShots);
