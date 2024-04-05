#include "effect.hpp"
#include "th18.hpp"

class Respawn : public Effect {
public:
    virtual bool Update() {
        Player::Instance->death_state = 0;
        Player::Instance->death_timer.cur_float = 0.0f;
        Player::Instance->death_timer.cur = 0;
        Player::Instance->idk_timer.cur_float = 280.0f;
        Player::Instance->idk_timer.cur = 280;
        return false;
    }
};
REGISTER_EFFECT(Respawn);
