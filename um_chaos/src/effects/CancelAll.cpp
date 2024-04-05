#include "effect.hpp"
#include "th18.hpp"

class CancelAll : public Effect {
public:
    virtual bool Update() {
        BulletManager::Instance->CancelAll(0);
        LaserManager::Instance->CancelAll(1, nullptr);
        return false;
    }
};
REGISTER_EFFECT(CancelAll);
