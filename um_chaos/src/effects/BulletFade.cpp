#include "commonhooks.hpp"
#include "effect.hpp"

class BulletFade : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);

    BulletFade() {
        CommonHooks::BulletFade = true;
    }

    virtual ~BulletFade() {
        CommonHooks::BulletFade = false;
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(BulletFade);
