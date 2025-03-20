#include "commonhooks.hpp"
#include "effect.hpp"
#include "util.hpp"

class ScreenShake : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);

    virtual bool Update() {
        CommonHooks::TitleScreenShake = 4;
        return --timer > 0;
    }
};
REGISTER_EFFECT(ScreenShake);
