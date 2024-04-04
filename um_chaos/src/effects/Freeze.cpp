#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class Freeze : public Effect {
public:
    size_t timer = Rand::Range(2 * 60, 10 * 60);

    Freeze() {
        GameState::Instance->flags |= 0x400;
    }

    virtual ~Freeze() {
        GameState::Instance->flags &= ~0x400;
    }

    virtual bool Update() {
        return --timer != 0;
    }
};
DEFINE_EFFECT(Freeze);
