#include "effect.hpp"
#include "util.hpp"

#define SE_COUNT 84

class RandomSounds : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;
    static int shuffle_table[SE_COUNT];

    RandomSounds() {
        for (int i = 0; i < SE_COUNT; i++)
            shuffle_table[i] = i;
        
        // Skip shuffling the shooting sound effects to maybe not destroy people's ears as much
        for (int i = 2; i < SE_COUNT - 2; i++) {
            int j = Rand::Range(i, SE_COUNT - 1 - 2);
            std::swap(shuffle_table[i], shuffle_table[j]);
        }

        patches.AddCall(0x453499, (void*)HandleMsg_hook);
    }

    virtual bool Update() {
        return --timer > 0;
    }

    static int __thiscall HandleMsg_hook(SoundManager* self) {
        for (int i = 0; i < _countof(self->queued_sound_ids); i++) {
            if (i < 0)
                break;
            self->queued_sound_ids[i] = shuffle_table[self->queued_sound_ids[i]];
        }
        return self->HandleMsg();
    }
};
REGISTER_EFFECT(RandomSounds);

int RandomSounds::shuffle_table[SE_COUNT];
