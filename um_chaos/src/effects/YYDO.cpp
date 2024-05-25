#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class YYDO : public Effect {
public:
    int count = Rand::Range(1, 3);

    YYDO() {
        EnemyInitData init = {
            .pos = {
                .x = 0.0f,
                .y = 128.0f,
                .z = 0.0f,
            },
            .hp = 8000,
            .ecl_int_vars = {
                count
            }
        };
        EnemyManager::Instance->MakeEnemy("YYDO", &init, 0);
    }
};
REGISTER_EFFECT(YYDO);
