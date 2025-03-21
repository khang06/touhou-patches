#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class ChangeDifficulty : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    int orig_diff;

    ChangeDifficulty() {
        orig_diff = Globals::Difficulty;
        if (orig_diff == 0)
            Globals::Difficulty = 1;
        else if (orig_diff == 3)
            Globals::Difficulty = 2;
        else
            Globals::Difficulty += Rand::Range(0, 1) ? 1 : -1;
    }

    static bool Allowed() {
        // Don't do this on extra
        return Globals::Difficulty != 4;
    }

    virtual ~ChangeDifficulty() {
        Globals::Difficulty = orig_diff;
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(ChangeDifficulty);
