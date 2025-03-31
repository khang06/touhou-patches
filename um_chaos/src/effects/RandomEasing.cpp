#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

#define EASING_COUNT 32

extern float __vectorcall InterpEasing(int type, float, float progress, float total);

class RandomEasing : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;
    static int shuffle_table[EASING_COUNT];

    RandomEasing() {
        for (int i = 0; i < EASING_COUNT; i++)
            shuffle_table[i] = i;

        static constexpr uint32_t targets[] = {
            0x406A1D,
            0x41F4AB,
            0x41F808,
            0x4398B6,
            0x439CFE,
            0x439E2F,
            0x47CB76,
            0x47CEF1,
            0x47D0F4,
            0x47D3F2,
        };
        for (int i = 0; i < _countof(targets); i++)
            patches.AddCall(targets[i], (void*)InterpEasing_hook);
    }

    virtual bool Update() {
        if ((timer & 15) == 0) {
            for (int i = 0; i < EASING_COUNT - 2; i++) {
                int j = Rand::Range(i, EASING_COUNT - 1 - 2);
                std::swap(shuffle_table[i], shuffle_table[j]);
            }
        }
        return --timer > 0;
    }

    static float __vectorcall InterpEasing_hook(int type, float, float progress, float total) {
        return InterpEasing(shuffle_table[type], UNUSED_FLOAT, -total - progress, total);
    }
};
REGISTER_EFFECT(RandomEasing);

int RandomEasing::shuffle_table[EASING_COUNT];
