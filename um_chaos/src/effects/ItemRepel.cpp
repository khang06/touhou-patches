#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class ItemRepel : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;

    ItemRepel() {
        static constexpr uint8_t patch = 0x5C; // addss -> subss
        patches.Add(0x44611D, (void*)&patch, sizeof(patch));

        // Don't reset item attract speed on player reset
        patches.AddJmp(0x45AE67, 0x45AE71);
        
        Player::Instance->item_attract_speed = -abs(Player::Instance->item_attract_speed);
    }

    virtual ~ItemRepel() {
        Player::Instance->item_attract_speed = abs(Player::Instance->item_attract_speed);
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(ItemRepel);
