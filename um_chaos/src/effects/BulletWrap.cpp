#include "effect.hpp"
#include "util.hpp"

class BulletWrap : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;

    BulletWrap() {
        {
            // Directly check wrap counter instead of ex flags
            static constexpr uint8_t patch[] = {
                // cmp dword ptr ds:[esi+0xCA0], 0
                0x83, 0xBE, 0xA0, 0x0C, 0x00, 0x00, 0x00,

                // 3-byte nop
                0x0F, 0x1F, 0x00
            };
            patches.Add(0x424641, (void*)&patch, sizeof(patch));
        }
        {
            // Invert branch condition
            static constexpr uint8_t patch = 0x85;
            patches.Add(0x42465C, (void*)&patch, sizeof(patch));
        }

        patches.AddCall(0x425AC3, (void*)CalcExHook);
    }

    virtual bool Update() {
        return --timer > 0;
    }

    static void __thiscall CalcExHook(Bullet* self) {
        //self->ex_flags |= 0x1000; // EX_WRAP
        self->effect_wrap.max_count = 1;
        self->effect_wrap.duration = 0;
        self->effect_wrap.flags = 0xF;

        self->CalcEx();
    }
};
REGISTER_EFFECT(BulletWrap);