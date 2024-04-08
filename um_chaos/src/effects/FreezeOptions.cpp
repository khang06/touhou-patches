#include "effect.hpp"
#include "util.hpp"

class FreezeOptions : public Effect {
public:
    size_t timer = Rand::RangeFrames(10, 2 * 60);
    CodePatches patches;

    FreezeOptions() {
        uint8_t patch = 0xEB; // jnz -> jmp
        patches.Add(0x45BCDE, &patch, sizeof(patch));
    }

    virtual bool Update() {
        return --timer != 0;
    }
};
REGISTER_EFFECT(FreezeOptions);
