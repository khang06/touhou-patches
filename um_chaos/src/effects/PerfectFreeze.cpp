#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class PerfectFreeze : public Effect {
public:
    PerfectFreeze() {
        static constexpr int8_t freeze_colors[] = {
            // 0 to 8
            15, 15, 15, 15, 15, 15, 15, 15, 15,
            // 9 is annoying because the proper sprite got replaced with the red glowy kunai
            0,
            // 10 to 16
            15, 15, 15, 15, 15, 15, 15,
            // 17
            -1,
            // 18 to 24
            7, 7, 7, 7, 7, 7, 7,
            // 25 to 28
            0, 0, 0, 0,
            // 29 to 31
            7, 7, 7,
            // 32
            -1,
            // 33
            7,
            // 34 to 38
            15, 15, 15, 15, 15,
            // 39 to 42
            0, 0, 0, 0,
            // 43 to 45
            7, 7, 7,
            // 46 to 47
            -1, -1
        };
        static constexpr BulletExArgs freeze_ex[] = {
            {
                // a and b populated per-bullet
                .type = EX_SETSPRITE,
            },
            {
                .r = ECL_NULL,
                .s = 0.0f,
                .type = EX_VEL,
            },
            {
                .a = 180,
                .type = EX_WAIT,
            },
            {
                // s populated per-bullet
                .r = 0.01f,
                .a = 220,
                .type = EX_ACCEL,
            },
            {
                .type = EX_NONE,
            }
        };

        for (auto cur = BulletManager::Instance->list_dummy_head.next; cur != nullptr; cur = cur->next) {
            Bullet* bullet = cur->entry;

            memcpy(bullet->ex_args, freeze_ex, sizeof(freeze_ex));
            bullet->ex_args[0].a = bullet->type;
            bullet->ex_args[0].b = freeze_colors[bullet->type] == -1 ? bullet->color : freeze_colors[bullet->type];
            bullet->ex_args[3].s = Rand::NextFloat() * 6.2831855f - 3.1415927f;

            bullet->ex_idx = 0;
            bullet->ex_flags = 0;
        }
    }
};
REGISTER_EFFECT(PerfectFreeze);
