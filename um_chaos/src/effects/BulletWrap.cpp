#include "effect.hpp"
#include "util.hpp"

class BulletWrap : public Effect {
public:
    int timer = Rand::RangeFrames(10, 60);
    CodePatches patches;

    BulletWrap() {
        patches.AddCall(0x425AC3, (void*)&CalcExHook);
    }

    virtual bool Update() {
        return --timer > 0;
    }

    static void __thiscall CalcExHook(Bullet* self) {
        self->CalcEx();

        self->ex_flags |= 0x1000; // EX_WRAP
        self->effect_wrap.max_count = 1;
        self->effect_wrap.duration = 0;
        self->effect_wrap.flags = 0xF;
    }
};
REGISTER_EFFECT(BulletWrap);
