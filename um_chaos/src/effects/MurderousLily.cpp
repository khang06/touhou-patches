#include "effect.hpp"
#include "th18.hpp"

// From Bravidunno
class MurderousLily : public Effect {
public:
    MurderousLily() {
        EnemyInitData init = {
            .pos = {
                .x = 0.0f,
                .y = -32.0f,
                .z = 0.0f,
            },
            .item = 7,
            .hp = 7000,
        };
        EnemyManager::Instance->MakeEnemy("ItemCarryLilyEx", &init, 0);
    }
};
REGISTER_EFFECT(MurderousLily);
