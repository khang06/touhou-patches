#include "effect.hpp"
#include "util.hpp"

extern "C" float ecl_wait_mul = 1.0f;

class EclWaitMul : public Effect {
public:
    static CodeCave DiffWaitCave;
    static CodeCave WaitCave;
    static CodeCave WaitFCave;

    int timer = Rand::RangeEffectTime(10, 2 * 60);
    CodePatches patches;

    EclWaitMul() {
        ecl_wait_mul = Rand::NextFloat() * 1.5f + 0.5f; 

        patches.AddCall(0x435FAD, &DiffWaitCave);
        patches.AddCall(0x435FD6, &DiffWaitCave);
        patches.AddCall(0x435F85, &DiffWaitCave);
        patches.AddJmp(0x48B73B, &WaitCave);
        patches.AddJmp(0x48B755, &WaitFCave);
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(EclWaitMul);
