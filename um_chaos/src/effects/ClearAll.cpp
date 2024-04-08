#include "effect.hpp"
#include "th18.hpp"

class ClearAll : public Effect {
public:
    virtual bool Update() {
        BulletManager::Instance->ClearAll(0);
        LaserManager::Instance->ClearAll(1, nullptr);
        return false;
    }
};
REGISTER_EFFECT(ClearAll);
