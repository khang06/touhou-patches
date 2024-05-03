#include "effect.hpp"
#include "util.hpp"

class FreezeOptions : public Effect {
public:
    int timer = Rand::RangeFrames(10, 2 * 60);
    CodePatches patches;

    FreezeOptions() {
        patches.AddJmp(0x45BCDA, 0x45BD0B);
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(FreezeOptions);
