#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class Jitter : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);

    virtual bool Update() {
        Player::Instance->pos_x += Rand::Range(-256, 256);
        Player::Instance->pos_y += Rand::Range(-256, 256);

        return --timer > 0;
    }
};
REGISTER_EFFECT(Jitter);
