#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class ItemRepel : public Effect {
public:
    size_t timer = Rand::RangeFrames(10, 2 * 60);
    CodePatches patches;

    ItemRepel() {
        uint8_t patch[] = {0x5C}; // addss -> subss
        patches.Add(0x44611D, patch, sizeof(patch));
        
        Player::Instance->item_attract_speed = -abs(Player::Instance->item_attract_speed);
    }

    virtual ~ItemRepel() {
        Player::Instance->item_attract_speed = abs(Player::Instance->item_attract_speed);
    }

    virtual bool Update() {
        return --timer != 0;
    }
};
REGISTER_EFFECT(ItemRepel);
