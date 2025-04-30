#include "commonhooks.hpp"
#include "effect.hpp"
#include "util.hpp"

class Rainbow : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    float angle = 0.0f;

    Rainbow() {
        CommonHooks::Rainbow = true;
        
        CommonHooks::RainbowRed = 0xFF;
        CommonHooks::RainbowGreen = 0xFF;
        CommonHooks::RainbowBlue = 0xFF;
    }

    virtual ~Rainbow() {
        CommonHooks::Rainbow = false;
    }

    virtual bool Update() {
        float time = timer / 15.0f;
        CommonHooks::RainbowRed = sinf(time) * 127 + 128;
        CommonHooks::RainbowGreen = sinf(time + 2.0f) * 127 + 128;
        CommonHooks::RainbowBlue = sinf(time + 4.0f) * 127 + 128;
        return --timer > 0;
    }
};
REGISTER_EFFECT(Rainbow);
