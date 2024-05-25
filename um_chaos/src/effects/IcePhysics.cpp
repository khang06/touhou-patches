#include "effect.hpp"
#include "util.hpp"

// Written by zero318
class IcePhysics : public Effect {
public:
    static CodeCave Cave;

    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;

    IcePhysics() {
        // Fix player getting launched if they aren't moving when this activates
        Player::Instance->last_vel = Player::Instance->cur_vel;

        patches.AddJmp(0x45B690, &Cave);
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(IcePhysics);
