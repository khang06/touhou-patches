#include "effect.hpp"
#include "util.hpp"

class BulletWrap : public Effect {
public:
    static CodeCave EtNewCave;

    size_t timer = Rand::RangeFrames(10, 60);
    CodePatches patches;

    BulletWrap() {
        patches.AddJmp(0x433E9D, &EtNewCave);
    }

    virtual bool Update() {
        return --timer != 0;
    }
};
REGISTER_EFFECT(BulletWrap);
