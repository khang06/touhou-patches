#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class GameSpeed : public Effect {
public:
    size_t timer;
    float speed;

    GameSpeed() {
        if (Rand::Range(1, 10) == 1) {
            timer = Rand::RangeFrames(0, 5);
            speed = -1.0f;
        } else {
            timer = Rand::RangeFrames(10, 2 * 60);
            speed = Rand::NextFloat() * 1.75f + 0.25f;
        }

        Globals::GameSpeed = speed;
    }

    virtual ~GameSpeed() {
        Globals::GameSpeed = 1.0f;
    }

    virtual bool Update() {
        Globals::GameSpeed = speed;
        return --timer != 0;
    }
};
REGISTER_EFFECT(GameSpeed);
