#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class Rewind : public Effect {
public:
    int timer = Rand::RangeEffectTime(0.25, 5);

    Rewind() {
        Globals::GameSpeed = -abs(Globals::GameSpeed);
    }

    virtual ~Rewind() {
        Globals::GameSpeed = abs(Globals::GameSpeed);
    }

    virtual bool Update() {
        Globals::GameSpeed = -abs(Globals::GameSpeed);
        return --timer > 0;
    }
};
//REGISTER_EFFECT(Rewind);
