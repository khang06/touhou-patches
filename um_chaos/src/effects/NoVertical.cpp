#include "effect.hpp"
#include "util.hpp"

// Hack to make NoVertical work with MouseControls
bool g_novertical_enabled = false;

class NoVertical : public Effect {
public:
    int timer = Rand::RangeFrames(10, 2 * 60);
    CodePatches patches;

    NoVertical() {
        // This patch is much longer than it should be because the original assembly interleaved the moves with the comparison
        // I only have enough space to zero eax with "xor eax, eax", but that messes with the zero flag
        // ...so I have to shift all of the instructions to happen before the comparison
        uint8_t patch[] = {
            // mov eax, dword ptr ds:[eax]
            0x8B, 0x00,
            // mov dword ptr ss:[esp+8], eax
            0x89, 0x44, 0x24, 0x08,
            // xor eax, eax
            0x31, 0xC0,
            // mov dword ptr ss:[esp+0x10], eax
            0x89, 0x44, 0x24, 0x10,
            // cmp dword ptr ds:[edi+0x476CC], 0
            0x83, 0xBF, 0xCC, 0x76, 0x04, 0x00, 0x00
        };
        patches.Add(0x45B41A, patch, sizeof(patch));
        g_novertical_enabled = true;
    }

    ~NoVertical() {
        g_novertical_enabled = false;
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(NoVertical);
