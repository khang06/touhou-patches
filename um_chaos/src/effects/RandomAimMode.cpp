#include "effect.hpp"
#include "util.hpp"

class RandomAimMode : public Effect {
public:
    static float angle_adjustment;

    int timer = Rand::RangeEffectTime(10, 2 * 60);
    CodePatches patches;

    RandomAimMode() {
        angle_adjustment = 0.0f;
        patches.AddCall(0x43483E, (void*)ReadAim);
        patches.AddCall(0x4341DF, (void*)ReadAngle1);
    }

    virtual bool Update() {
        return --timer > 0;
    }

    static __thiscall int ReadAim(EnemyData* self, int) {
        int orig_type = self->GetIntArg(1);
        int new_type = Rand::Range(0, 12);
        bool orig_aimed = (orig_type & 1) == (orig_type >= 8);
        bool new_aimed = (new_type & 1) == (new_type >= 8);

        // TODO: This doesn't work all the time but IDK if I can do anything about that
        if (!orig_aimed && new_aimed)
            angle_adjustment = -1.570796f;
        else if (orig_aimed && !new_aimed)
            angle_adjustment = 1.570796f;
        else
            angle_adjustment = 0.0f;

        //printf("%d to %d with adjustment %f\n", orig_type, new_type, angle_adjustment);

        return new_type;
    }

    static __vectorcall float ReadAngle1(EnemyData* self, int, int) {
        return self->GetFloatArg(1) + angle_adjustment;
    }
};
REGISTER_EFFECT(RandomAimMode);

float RandomAimMode::angle_adjustment = 0.0f;
