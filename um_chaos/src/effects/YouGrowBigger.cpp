#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class YouGrowBigger : public Effect {
public:
    int timer = Rand::RangeFrames(10, 2 * 60);
    CodePatches patches;

    YouGrowBigger() {
        // Allow shooting after size change
        uint8_t patch[] = {0x66, 0x90};
        patches.Add(0x45C978, patch, sizeof(patch));
        
        // Don't reset scale on player initialization/reset
        patches.AddJmp(0x45AB6A, 0x45AB7A);
        patches.AddJmp(0x45ADA4, 0x45ADB8);

        Player::Instance->flags |= 0x10;
        SoundManager::Instance.PlaySE(75, 0.0f);

        Player::Instance->scale_interp.initialize(120, 0, 1.0f, 2.0f);
    }

    virtual ~YouGrowBigger() {
        Player::Instance->flags &= ~0x10;
        Player::Instance->scale = 1.0f;
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(YouGrowBigger);
