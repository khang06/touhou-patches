#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class ChimataKnives : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 2 * 60);

    virtual bool Update() {
        // -1 = divide color by 2
        // -2 = keep current color
        // -3 = multiply color by 2 and add 1 (max 6)
        static constexpr int8_t knife_colors[] = {
            // 0 to 16
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            // 17 (too lazy and this doesn't show up much)
            0,
            // 18 to 24
            -2, -2, -2, -2, -2, -2, -2,
            // 25 to 28
            1, 2, 3, 6,
            // 29 to 31
            -2, -2, -2,
            // 32
            -3,
            // 33
            -2,
            // 34 to 38
            -1, -1, -1, -1, -1,
            // 39 to 42
            1, 3, 6, 2,
            // 43 to 45
            -2, -2, -2,
            // 46 to 47
            0, 0
        };
        static constexpr BulletExArgs knives_ex[] = {
            {
                .r = 0.01f,
                .s = -9999994.0f,
                .a = 1,
                .type = EX_VELTIME,
            },
            {
                // b populated per-bullet
                .a = 21,
                .type = EX_SETSPRITE,
            },
            {
                .a = 100,
                .type = EX_WAIT,
            },
            {
                .r = 2.0f,
                .s = 1000000.0f,
                .a = 180,
                .type = EX_VELTIME,
            },
            {
                .type = EX_NONE,
            }
        };

        for (auto cur = BulletManager::Instance->list_dummy_head.next; cur != nullptr; cur = cur->next) {
            Bullet* bullet = cur->entry;

            float dist_x = Player::Instance->pos_float.x - bullet->position.x;
            float dist_y = Player::Instance->pos_float.y - bullet->position.y;
            if (bullet->affected_by_func) {
                if (bullet->ex_idx == 3) {
                    float angle = (dist_x > 0.0001f || dist_y > 0.0001f) ? atan2f(dist_y, dist_x) : 1.5707964f;
                    bullet->angle = angle;
                    bullet->velocity.x = cosf(angle) * 0.01f;
                    bullet->velocity.y = sinf(angle) * 0.01f;
                }
            } else {
                if (dist_x * dist_x + dist_y * dist_y < 9216.0f) {
                    int new_color = knife_colors[bullet->type];
                    switch (new_color) {
                        case -1:
                            new_color = bullet->color / 2;
                            break;
                        case -2:
                            new_color = bullet->color;
                            break;
                        case -3:
                            new_color = min(bullet->color * 2 + 1, 6);
                            break;
                    }

                    memcpy(bullet->ex_args, knives_ex, sizeof(knives_ex));
                    bullet->ex_args[1].b = new_color;

                    bullet->ex_idx = 0;
                    bullet->ex_flags = 0;
                    bullet->affected_by_func = 1;
                }
            }
        }

        return --timer > 0;
    }
};
REGISTER_EFFECT(ChimataKnives);
