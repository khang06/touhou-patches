#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class Freeze : public Effect {
public:
    size_t timer = Rand::RangeFrames(0, 10);

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
REGISTER_EFFECT(Freeze);
