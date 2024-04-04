#include "effect.hpp"
#include "util.hpp"

class ItemRepel : public Effect {
public:
    size_t timer = Rand::Range(5 * 60, 15 * 60);
    CodePatches patches;

    ItemRepel() {
        uint8_t patch[] = {0x5C}; // addss -> subss
        patches.Add(0x44611D, patch, sizeof(patch));
    }

    virtual bool Update() {
        return --timer != 0;
    }
};
DEFINE_EFFECT(ItemRepel);
