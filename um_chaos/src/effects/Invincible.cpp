#include "effect.hpp"
#include "th18.hpp"

class Invincible : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);

    virtual bool Update() {
        Player::Instance->invuln_timer.set(2);
        return --timer > 0;
    }
};
REGISTER_EFFECT(Invincible);
