#include "effect.hpp"
#include "th18.hpp"

// This doesn't work as intended but it's still pretty funny
class Respawn : public Effect {
public:
    virtual bool Update() {
        Player::Instance->death_state = 0;
        return false;
    }
};
DEFINE_EFFECT(Respawn);
