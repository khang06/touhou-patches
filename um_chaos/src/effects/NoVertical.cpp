#include "effect.hpp"
#include "util.hpp"

class NoVertical : public Effect {
public:
    size_t timer = Rand::Range(5 * 60, 15 * 60);
    CodePatches patches;

    NoVertical() {
        uint8_t patch[] = {0x31, 0xC0}; // xor eax, eax
        patches.Add(0x45B427, patch, sizeof(patch));
    }

    virtual bool Update() {
        return --timer != 0;
    }
};
DEFINE_EFFECT(NoVertical);
