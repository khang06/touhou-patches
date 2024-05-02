#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class Seija : public Effect {
public:
    int timer = Rand::RangeFrames(5, 30);
    int32_t interrupt = Rand::Range(0, 2) * 2 + 8;

    Seija() {
        SoundManager::Instance.PlaySE(52, 0.0f);
        Main::Instance.screen_anm4->pending_interrupt = interrupt;
    }

    virtual ~Seija() {
        Main::Instance.screen_anm4->pending_interrupt = interrupt + 1;
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(Seija);
