#include "effect.hpp"
#include "util.hpp"

class ItemNoGrav : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;

    ItemNoGrav() {
        static constexpr uint8_t patch[] = {0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00}; // fancy 8-byte nop
        patches.Add(0x445C7D, (void*)&patch, sizeof(patch));
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(ItemNoGrav);
