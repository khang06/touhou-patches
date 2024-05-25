#include "effect.hpp"
#include "th18.hpp"

class RedirectBullets : public Effect {
public:
    RedirectBullets() {
        for (auto cur = BulletManager::Instance->list_dummy_head.next; cur != nullptr; cur = cur->next) {
            auto& player_pos = Player::Instance->pos_float;
            auto& pos = cur->entry->position;
            auto& vel = cur->entry->velocity;
            if (abs(pos.x - player_pos.x) > 0.001 && abs(pos.y - player_pos.y) > 0.001) {
                float mag = sqrtf(vel.x * vel.x + vel.y * vel.y);
                float angle = atan2f(player_pos.y - pos.y, player_pos.x - pos.x);
                cur->entry->angle = angle;
                vel.x = mag * cosf(angle);
                vel.y = mag * sinf(angle);

                cur->entry->ex_flags &= ~8; // EX_ANGLE_ACCEL
            }
        }
    }
};
REGISTER_EFFECT(RedirectBullets);
