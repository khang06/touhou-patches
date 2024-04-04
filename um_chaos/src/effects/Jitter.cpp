#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class Jitter : public Effect {
public:
    size_t timer = Rand::Range(10 * 60, 30 * 60);

    virtual bool Update() {
        Player::Instance->pos_x += Rand::Range(-512, 512);
        Player::Instance->pos_y += Rand::Range(-512, 512);

        return --timer != 0;
    }
};
DEFINE_EFFECT(Jitter);
