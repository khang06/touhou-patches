#define _USE_MATH_DEFINES
#include <math.h>
#include "th18.hpp"
#include "util.hpp"
#include "effect.hpp"

class Wind : public Effect {
public:
    int timer = Rand::RangeEffectTime(5, 30);
    float strength = 0.0f;
    bool fade_in_finished = false;
    float unit_x;
    float unit_y;

    Wind() {
        float angle = Rand::NextFloat() * TWO_PI - (float)M_PI;
        unit_x = cosf(angle);
        unit_y = sinf(angle);
    }

    virtual bool Update() {
        if (!fade_in_finished) {
            strength = std::min(strength + 0.01f, 3.0f);
            if (strength >= 2.5f)
                fade_in_finished = true;
        }

        float vel_x = unit_x * strength;
        float vel_y = unit_y * strength;
        Player::Instance->pos_x += vel_x * 128.0f;
        Player::Instance->pos_y += vel_y * 128.0f;
        /*
        // Too many safespots...
        for (auto cur = BulletManager::Instance->list_dummy_head.next; cur != nullptr; cur = cur->next) {
            cur->entry->position.x += vel_x;
            cur->entry->position.y += vel_y;
        }
        */
        for (auto& item : ItemManager::Instance->items) {
            if (item.state) {
                item.pos.x += vel_x;
                item.pos.y += vel_y;
            }
        }

        if (timer <= 0) {
            strength = std::max(0.0f, strength - 0.01f);
            if (strength <= 0.0f)
                return false;
        } else {
            timer--;
        }
        return true;
    }
};
REGISTER_EFFECT(Wind);
