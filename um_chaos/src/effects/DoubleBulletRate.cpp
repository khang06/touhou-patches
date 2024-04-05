#include "effect.hpp"
#include "util.hpp"

// This modifies *every* wait instruction!
class DoubleBulletRate : public Effect {
public:
    static CodeCave DiffWaitCave;
    static CodeCave WaitCave;
    static CodeCave WaitFCave;

    size_t timer = Rand::RangeFrames(10, 2 * 60);
    CodePatches patches;

    DoubleBulletRate() {
        patches.AddCall(0x435FAD, &DiffWaitCave);
        patches.AddCall(0x435FD6, &DiffWaitCave);
        patches.AddCall(0x435F85, &DiffWaitCave);
        patches.AddJmp(0x48B73B, &WaitCave);
        patches.AddJmp(0x48B755, &WaitFCave);
    }

    virtual bool Update() {
        return --timer != 0;
    }
};
REGISTER_EFFECT(DoubleBulletRate);
