#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class Jitter : public Effect {
public:
    size_t timer = Rand::RangeFrames(10, 2 * 60);

    virtual bool Update() {
        Player::Instance->pos_x += Rand::Range(-512, 512);
        Player::Instance->pos_y += Rand::Range(-512, 512);

        return --timer != 0;
    }
};
REGISTER_EFFECT(Jitter);
