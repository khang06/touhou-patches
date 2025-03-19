#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class FairyJumpscare : public Effect {
public:
    FairyJumpscare() {
        auto& player_pos = Player::Instance->pos_float;
        float angle = (abs(player_pos.x) > 0.001f || abs(224.0f - player_pos.y) > 0.001f) ? atan2f(224.0f - player_pos.y, -player_pos.x) : 1.570796f;
        EnemyInitData init = {
            .pos = {
                .x = 600.0f * cosf(angle) - 192.0f,
                .y = 600.0f * sinf(angle) + 224.0f,
                .z = 0.0f,
            },
            .hp = 1000,
            .ecl_int_vars = {
                Rand::Range(1, 4) == 1,
                Rand::Range(1, 4) == 1,
            }
        };
        EnemyManager::Instance->MakeEnemy("FairyJumpscare", &init, 0);
    }
};
REGISTER_EFFECT(FairyJumpscare);
