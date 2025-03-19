#include "effect.hpp"
#include "util.hpp"

class NoRNG : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;

    NoRNG() {
        static constexpr uint8_t nop3[] = {0x0F, 0x1F, 0x00};
        static constexpr uint8_t nop7[] = {0x0F, 0x1F, 0x80, 0x00, 0x00, 0x00, 0x00};
        patches.Add(0x402710, (void*)&nop3, sizeof(nop3));
        patches.Add(0x4027A3, (void*)&nop3, sizeof(nop3));
        patches.Add(0x463792, (void*)&nop7, sizeof(nop7));
        patches.Add(0x46E0C2, (void*)&nop7, sizeof(nop7));
        patches.Add(0x46E157, (void*)&nop7, sizeof(nop7));
        patches.Add(0x46E1E0, (void*)&nop7, sizeof(nop7));
        patches.Add(0x4705B2, (void*)&nop7, sizeof(nop7));
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(NoRNG);
