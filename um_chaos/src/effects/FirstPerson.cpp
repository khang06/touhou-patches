#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class FirstPerson : public Effect {
public:
    static size_t ID;
    int timer = Rand::RangeEffectTime(10, 60);

    virtual ~FirstPerson() {
        auto anm = Main::Instance.screen_anm4;
        bool anchor_x = anm->anchor_x;
        bool anchor_y = anm->anchor_y;
        Main::Instance.screen_anm4->position.x = (32.0f + (anchor_x ? 0.0f : 192.0f)) * Window::Instance.game_scale;
        Main::Instance.screen_anm4->position.y = (16.0f + (anchor_y ? 0.0f : 224.0f)) * Window::Instance.game_scale;
    }

    virtual bool Update() {
        // Assuming that neither axis uses anchor type 2
        auto anm = Main::Instance.screen_anm4;
        bool anchor_x = anm->anchor_x;
        bool anchor_y = anm->anchor_y;
        anm->position.x = (32.0f - (Player::Instance->pos_float.x * anm->scale_x + 192.0f) + (anchor_x ? 192.0f : 384.0f)) * Window::Instance.game_scale;
        anm->position.y = (16.0f - ((Player::Instance->pos_float.y - 224.0f) * anm->scale_y + 224.0f) + (anchor_y ? 224.0f : 448.0f)) * Window::Instance.game_scale;

        return --timer > 0;
    }
};
REGISTER_EFFECT(FirstPerson);

size_t FirstPerson::ID;
