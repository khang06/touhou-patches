#include "effect.hpp"
#include "th18.hpp"

class MomoyoButterflies : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);

    MomoyoButterflies() {
        EnemyInitData init = {
            .pos = {
                .x = 0.0f,
                .y = 0.0f,
                .z = 0.0f,
            },
            .hp = 8000,
            .ecl_int_vars = {
                timer
            }
        };
        EnemyManager::Instance->MakeEnemy("MomoyoButterflies", &init, 0);
    }

    virtual bool Update() {
        // Nice time complexity here
        for (auto cur = BulletManager::Instance->list_dummy_head.next; cur != nullptr; cur = cur->next) {
            Bullet* butterfly = cur->entry;
            if (butterfly->ex_react == 1234) {
                for (auto cur2 = BulletManager::Instance->list_dummy_head.next; cur2 != nullptr; cur2 = cur2->next) {
                    Bullet* bullet = cur2->entry;
                    float dist_x = bullet->position.x - butterfly->position.x;
                    float dist_y = bullet->position.y - butterfly->position.y;
                    if (bullet->ex_react != 1234 && !bullet->affected_by_func && dist_x * dist_x + dist_y * dist_y < 484.0f) {
                        bullet->affected_by_func = 1;
                        bullet->destroy_script_id = 221;
                        bullet->Destroy(0);
                    }
                }
            }
        }
        return --timer > 0;
    }
};
REGISTER_EFFECT(MomoyoButterflies);
