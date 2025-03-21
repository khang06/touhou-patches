#include "effect.hpp"
#include "th18.hpp"

class EoSDBooks : public Effect {
public:
    EoSDBooks() {
        EnemyInitData init = {
            .pos = {
                .x = 0.0f,
                .y = 128.0f,
                .z = 0.0f,
            },
            .hp = 8000,
        };
        EnemyManager::Instance->MakeEnemy("EoSDBooksMain", &init, 0);
    }
};
REGISTER_EFFECT(EoSDBooks);
