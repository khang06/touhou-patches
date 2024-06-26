#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class GameSpeed : public Effect {
public:
    int timer;
    float speed;

    GameSpeed() {
        if (true) {
            timer = Rand::RangeEffectTime(0.25, 5);
            speed = -1.0f;
        } else {
            timer = Rand::RangeEffectTime(10, 60);
            speed = Rand::NextFloat() * 1.5f + 0.5f;
        }

        Globals::GameSpeed = speed;
    }

    virtual ~GameSpeed() {
        Globals::GameSpeed = 1.0f;
    }

    virtual bool Update() {
        Globals::GameSpeed = speed;
        return --timer > 0;
    }
};
REGISTER_EFFECT(GameSpeed);
