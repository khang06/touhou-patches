#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class Seija : public Effect {
public:
    int timer = Rand::RangeFrames(5, 30);
    int32_t interrupt = Rand::Range(0, 2) * 2 + 8;
    CodePatches patches;

    Seija() {
        SoundManager::Instance.PlaySE(52, 0.0f);
        Main::Instance.screen_anm4->pending_interrupt = interrupt;

        // Don't reset screen_anm4's transforms between stages
        uint8_t patch[] = {0x0F, 0x1F, 0x44, 0x00, 0x00}; // 5-byte nop
        patches.Add(0x44326B, patch, sizeof(patch));
    }

    virtual ~Seija() {
        Main::Instance.screen_anm4->pending_interrupt = interrupt + 1;
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(Seija);
