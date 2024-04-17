#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class YouGrowBigger : public Effect {
public:
    size_t timer = Rand::RangeFrames(10, 2 * 60);
    CodePatches patches;

    YouGrowBigger() {
        uint8_t patch[] = {0x66, 0x90};
        patches.Add(0x45C978, patch, sizeof(patch));

        Player::Instance->flags |= 0x10;
        Player::Instance->scale = 4.0f;
    }

    virtual ~YouGrowBigger() {
        Player::Instance->flags &= ~0x10;
        Player::Instance->scale = 1.0f;
    }

    virtual bool Update() {
        return --timer != 0;
    }
};
REGISTER_EFFECT(YouGrowBigger);
