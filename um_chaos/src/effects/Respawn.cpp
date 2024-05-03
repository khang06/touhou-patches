#include "effect.hpp"
#include "th18.hpp"

class Respawn : public Effect {
public:
    virtual bool Update() {
        Player::Instance->death_state = 0;
        Player::Instance->death_timer.set(0);
        Player::Instance->invuln_timer.set(280);
        return false;
    }
};
REGISTER_EFFECT(Respawn);
