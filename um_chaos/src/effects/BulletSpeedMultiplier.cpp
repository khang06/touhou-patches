#include "effect.hpp"
#include "util.hpp"

extern "C" float bulletspeedmultiplier_mul[2] = {1.0f, 1.0f};

// TODO: Handle the other ways bullet speed gets changed
class BulletSpeedMultiplier : public Effect {
public:
    static CodeCave Cave;

    int timer = Rand::RangeFrames(10, 2 * 60);
    CodePatches patches;

    BulletSpeedMultiplier() {
        float mul = Rand::NextFloat() * 1.5f + 0.5f; 
        bulletspeedmultiplier_mul[0] = mul;
        bulletspeedmultiplier_mul[1] = mul;

        patches.AddJmp(0x434241, &Cave);
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(BulletSpeedMultiplier);
