#include "effect.hpp"
#include "util.hpp"

extern "C" float bullet_speed_mul[2] = {1.0f, 1.0f};

// TODO: Handle the other ways bullet speed gets changed
class BulletSpeedMul : public Effect {
public:
    static CodeCave Cave;

    int timer = Rand::RangeEffectTime(10, 2 * 60);
    CodePatches patches;

    BulletSpeedMul() {
        float mul = Rand::NextFloat() * 1.5f + 0.5f; 
        bullet_speed_mul[0] = mul;
        bullet_speed_mul[1] = mul;

        patches.AddJmp(0x434241, &Cave);
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(BulletSpeedMul);
