#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class Follower : public Effect {
public:
    Follower() {
        EnemyInitData init = {
            .pos = {
                .x = Rand::NextFloat() * 384.0f - 192.0f,
                .y = -16.0f,
                .z = 0.0f,
            },
            .hp = 1000,
            .ecl_int_vars = {
                Rand::RangeEffectTime(10, 60)
            }
        };
        EnemyManager::Instance->MakeEnemy("Follower", &init, 0);
    }
};
REGISTER_EFFECT(Follower);
