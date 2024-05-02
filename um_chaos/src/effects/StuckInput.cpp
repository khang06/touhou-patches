#include "effect.hpp"
#include "util.hpp"

extern "C" {
    uint32_t stuck_input_x = 0;
    uint32_t stuck_input_y = 0;
};

class StuckInput : public Effect {
public:
    static CodeCave Cave;

    int timer = Rand::RangeFrames(10, 60);
    CodePatches patches;

    StuckInput() {
        stuck_input_x = 0;
        stuck_input_y = 0;

        uint8_t patch[] = {
            // mov eax, &stuck_input_x
            0xB8, 0x41, 0x41, 0x41, 0x41,
            // mov ecx, &stuck_input_y
            0xB9, 0x41, 0x41, 0x41, 0x41,
            // 10 byte nop
            0x66, 0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00,
        };
        *(uint32_t**)&patch[1] = &stuck_input_x;
        *(uint32_t**)&patch[6] = &stuck_input_y;
        patches.Add(0x45B3CA, patch, sizeof(patch));
        patches.AddJmp(0x45B3DE, &Cave);
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(StuckInput);
