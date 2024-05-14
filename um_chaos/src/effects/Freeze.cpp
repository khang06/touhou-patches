#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class Freeze : public Effect {
public:
    int timer = Rand::RangeEffectTime(1, 5);

    Freeze() {
        GameState::Instance->flags |= 0x400;
        SoundManager::StopAllSounds();
        SoundManager::Instance.SendMsg(6, 0, "Pause");
        while (SoundManager::Instance.HandleMsg())
            ;
    }

    virtual ~Freeze() {
        GameState::Instance->flags &= ~0x400;
        SoundManager::Instance.SendMsg(7, 0, "UnPause");
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(Freeze);
