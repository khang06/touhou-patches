#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class YouGrowBigger : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 30);
    CodePatches patches;

    YouGrowBigger() {
        // Allow shooting after size change
        static constexpr uint8_t patch[] = {0x66, 0x90};
        patches.Add(0x45C978, (void*)&patch, sizeof(patch));
        
        // Don't reset scale on player reset
        patches.AddJmp(0x45ADA4, 0x45ADB8);

        // Nerf the hitbox scaling multiplier even more (from 3.6x)
        // The hitbox dot size might be a bit misleading now. Oh well...
        static constexpr float new_multiplier = 1.2f;
        patches.Add(0x4B9244, (void*)&new_multiplier, sizeof(new_multiplier));

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
