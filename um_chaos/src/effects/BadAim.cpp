#define _USE_MATH_DEFINES
#include <math.h>
#include "effect.hpp"
#include "util.hpp"

class BadAim : public Effect {
public:
    int timer = Rand::RangeFrames(10, 2 * 60);
    CodePatches patches;

    // Needs extra int arguments because the original function was stdcall and took 1 argument
    static float __vectorcall AngleToPlayerHook(int, int, int, float ret) {
        return ret + Rand::NextFloat() * (float)M_PI_4 - ((float)M_PI_4 / 2.0f);
    }

    static int __thiscall ShootShooterHook(BulletManager* self, EnemyShooter* shooter, int idx1, int idx2, float angle) {
        return self->ShootShooter(shooter, idx1, idx2, angle + Rand::NextFloat() * M_PI_4 - (M_PI_4 / 2.0f));
    }

    BadAim() {
        patches.AddJmp(0x45CC18, (void*)&AngleToPlayerHook);
        patches.AddCall(0x4278C9, (void*)&ShootShooterHook);
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(BadAim);
