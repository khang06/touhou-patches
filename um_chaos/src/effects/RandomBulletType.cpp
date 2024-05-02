#include "effect.hpp"
#include "util.hpp"

class RandomBulletType : public Effect {
public:
    static int32_t MaxColor;
    int timer = Rand::RangeFrames(10, 2 * 60);
    CodePatches patches;

    RandomBulletType() {
        patches.AddCall(0x434045, (void*)ReadType);
        patches.AddCall(0x434055, (void*)ReadColor);
    }

    virtual bool Update() {
        return --timer > 0;
    }

    static __thiscall int ReadType(void*, int) {
        static constexpr int32_t MAX_COLORS[] = {
            // 0 to 16
            15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
            // 17
            3,
            // 18 to 24
            7, 7, 7, 7, 7, 7, 7,
            // 25 to 28
            0, 0, 0, 0,
            // 29 to 31
            7, 7, 7,
            // 32
            3,
            // 33
            7,
            // 34 to 38
            15, 15, 15, 15, 15,
            // 39 to 42
            0, 0, 0, 0,
            // 43
            7
        };
        auto ret = Rand::Range(0, 43);
        MaxColor = MAX_COLORS[ret];
        return ret;
    }

    static __thiscall int ReadColor(void*, int) {
        return Rand::Range(0, MaxColor);
    }
};
REGISTER_EFFECT(RandomBulletType);

int32_t RandomBulletType::MaxColor = 0;
