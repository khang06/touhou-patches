#include "effect.hpp"
#include "util.hpp"

extern "C" {
    uint32_t slippery_x = 0;
    uint32_t slippery_y = 0;
};

class Slippery : public Effect {
public:
    static CodeCave Cave;

    size_t timer = Rand::RangeFrames(10, 2 * 60);
    CodePatches patches;

    Slippery() {
        slippery_x = 0;
        slippery_y = 0;

        uint8_t patch[] = {
            // mov eax, &slippery_x
            0xB8, 0x41, 0x41, 0x41, 0x41,
            // mov ecx, &slippery_y
            0xB9, 0x41, 0x41, 0x41, 0x41,
            // 10 byte nop
            0x66, 0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00,
        };
        *(uint32_t**)&patch[1] = &slippery_x;
        *(uint32_t**)&patch[6] = &slippery_y;
        patches.Add(0x45B3CA, patch, sizeof(patch));
        patches.AddJmp(0x45B3DE, &Cave);
    }

    virtual bool Update() {
        return --timer != 0;
    }
};
REGISTER_EFFECT(Slippery);
