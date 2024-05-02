#include "effect.hpp"
#include "util.hpp"

// Written by zero318
class IcePhysics : public Effect {
public:
    static CodeCave Cave;

    int timer = Rand::RangeFrames(10, 60);
    CodePatches patches;

    IcePhysics() {
        patches.AddJmp(0x45B690, &Cave);
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(IcePhysics);
