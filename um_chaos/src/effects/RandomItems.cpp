#include "effect.hpp"
#include "util.hpp"

class RandomItems : public Effect {
public:
    static int32_t MaxColor;
    size_t timer = Rand::RangeFrames(5, 10); // This one's kinda busted
    CodePatches patches;

    RandomItems() {
        constexpr uint32_t addrs[] = {
            0x40D30B,
            0x40D713,
            0x4291A7,
            0x429243,
            0x42D0EE,
            0x430493,
            0x430624,
            0x435045,
            0x45C20A,
        };
        for (auto x : addrs)
            patches.AddCall(x, (void*)SpawnItem);
    }

    virtual bool Update() {
        return --timer != 0;
    }

    static void* __thiscall SpawnItem(ItemManager* self, int id, int a3, int a4, float a5, float a6, int a7, int a8, int a9) {
        return self->SpawnItem(Rand::Range(1, 19), a3, a4, a5, a6, a7, a8, a9);
    }
};
REGISTER_EFFECT(RandomItems);
