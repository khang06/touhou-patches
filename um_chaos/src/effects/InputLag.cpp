#include "effect.hpp"
#include "util.hpp"

#define LAG_LEN 8

extern "C" uint32_t __stdcall update_dinput(uint32_t other_inputs);

class InputLag : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;
    static size_t cur_idx;
    static uint32_t queue[LAG_LEN];

    InputLag() {
        patches.AddCall(0x401E01, (void*)update_dinput_hook);
        for (int i = 0; i < LAG_LEN; i++)
            queue[i] = Input::Cur;
        cur_idx = 0; 
    }

    virtual bool Update() {
        return --timer > 0;
    }

    static uint32_t __stdcall update_dinput_hook(uint32_t other_inputs) {
        queue[cur_idx] = update_dinput(other_inputs);
        cur_idx = (cur_idx + 1) % LAG_LEN;

        return queue[cur_idx];
    }
};
REGISTER_EFFECT(InputLag);

size_t InputLag::cur_idx;
size_t InputLag::queue[LAG_LEN];
