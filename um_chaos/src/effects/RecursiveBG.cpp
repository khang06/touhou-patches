#include "effect.hpp"
#include "util.hpp"

class RecursiveBG : public Effect {
public:
    int timer = Rand::RangeFrames(10, 60);
    CodePatches patches;

    RecursiveBG() {
        uint8_t patch = 0xB0; // screen_anm1 -> screen_anm2
        patches.Add(0x4555AF, &patch, sizeof(patch));
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(RecursiveBG);
