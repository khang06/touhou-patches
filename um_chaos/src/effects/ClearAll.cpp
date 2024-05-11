#include "effect.hpp"
#include "th18.hpp"

class ClearAll : public Effect {
public:
    ClearAll() {
        BulletManager::Instance->ClearAll(0);
        LaserManager::Instance->ClearAll(1, nullptr);
    }
};
REGISTER_EFFECT(ClearAll);
