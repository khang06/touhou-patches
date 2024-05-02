#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class YouGrowBigger : public Effect {
public:
    int timer = Rand::RangeFrames(10, 2 * 60);
    CodePatches patches;

    YouGrowBigger() {
        uint8_t patch[] = {0x66, 0x90};
        patches.Add(0x45C978, patch, sizeof(patch));

        Player::Instance->flags |= 0x10;
        SoundManager::Instance.PlaySE(75, 0.0f);
        
        // TODO: I really need to write a helper function for this
        auto& interp = Player::Instance->scale_interp;
        interp.initial = 1.0f;
        interp.goal = 2.0f; // Shinmy's 4x scale is too OP for this
        interp.bezier_1 = 0.0f;
        interp.bezier_2 = 0.0f;
        interp.end_time = 120;
        interp.method = 0;
        if ((interp.timer.control & 1) == 0) {
            interp.timer.cur = 0;
            interp.timer.prev = -999999;
            interp.timer.cur_float = 0.0f;
            interp.timer.speed_idx_thing = 0;
            interp.timer.control |= 1;
        }
        interp.timer.cur = 0;
        interp.timer.cur_float = 0.0;
        interp.timer.prev = -1;
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
