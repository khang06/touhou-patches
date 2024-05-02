#include "effect.hpp"
#include "util.hpp"

class FreezeOptions : public Effect {
public:
    int timer = Rand::RangeFrames(10, 2 * 60);
    CodePatches patches;

    FreezeOptions() {
        // UDoALG Ran option freezing compatibility hack
        if (*(uint8_t*)0x45BCDA == 0xE9) {
            patches.AddJmp(0x45BCDA, 0x45BD0B);
        } else {
            uint8_t patch = 0xEB; // jnz -> jmp
            patches.Add(0x45BCDE, &patch, sizeof(patch));
        }
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(FreezeOptions);
