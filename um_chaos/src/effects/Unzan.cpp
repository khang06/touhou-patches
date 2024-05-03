#include "effect.hpp"
#include "th18.hpp"

// TODO: Maybe this should have two fists on Hard or above like the actual card
class Unzan : public Effect {
public:
    int count = Rand::Range(1, 10);
    int timer = 0;

    virtual bool Update() {
        if (--timer <= 0) {
            bool bottom = Rand::Range(1, 15) == 1;
            EnemyInitData init = {
                .pos = {
                    .x = Player::Instance->pos_float.x,
                    .y = bottom ? 640.0f : -96.0f,
                    .z = 0.0f,
                },
                .hp = 1000,
                .ecl_float_vars = {
                    bottom ? -1.570796f : 1.570796f
                }
            };
            EnemyManager::Instance->MakeEnemy((count & 1) ? "UnzanArmR" : "UnzanArmL", &init, 0);

            if (--count == 0)
                return false;
            timer = 120;
        }
        return true;
    }
};
REGISTER_EFFECT(Unzan);
