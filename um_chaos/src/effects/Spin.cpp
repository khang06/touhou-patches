#include <d3d9.h>
#include "commonhooks.hpp"
#include "effect.hpp"
#include "util.hpp"

class Spin : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    float angle = 0.0f;

    Spin() {
        CommonHooks::Spin = true;

        CommonHooks::SpinSin = 0.0f;
        CommonHooks::SpinCos = 1.0f;
    }

    virtual ~Spin() {
        CommonHooks::Spin = false;
    }

    virtual bool Update() {
        angle = fmodf(angle + 0.1f, TWO_PI);
        CommonHooks::SpinSin = sinf(angle);
        CommonHooks::SpinCos = cosf(angle);
        return --timer > 0;
    }
};
REGISTER_EFFECT(Spin);
