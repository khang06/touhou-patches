#include "effect.hpp"
#include "util.hpp"

class NoBulletEx : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;

    NoBulletEx() {
        patches.AddJmp(0x42403C, 0x4245A9);
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(NoBulletEx);
