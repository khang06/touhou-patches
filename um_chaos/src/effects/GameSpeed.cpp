#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class GameSpeed : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 30);
    float speed = Rand::NextFloat() + 0.5f;

    GameSpeed() {
        Globals::GameSpeed = speed;
    }

    virtual ~GameSpeed() {
        Globals::GameSpeed = copysignf(1.0f, Globals::GameSpeed);
    }

    virtual bool Update() {
        Globals::GameSpeed = copysignf(speed, Globals::GameSpeed);
        return --timer > 0;
    }
};
REGISTER_EFFECT(GameSpeed);
