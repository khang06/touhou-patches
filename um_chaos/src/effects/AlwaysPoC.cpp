#include "effect.hpp"
#include "util.hpp"

class NoPoC {
public:
    static size_t ID;
};

class AlwaysPoC : public Effect {
public:
    static size_t ID;
    int timer = Rand::RangeEffectTime(10, 2 * 60);
    CodePatches patches;

    AlwaysPoC() {
        patches.AddJmp(0x445FE4, 0x445F63);
        patches.AddJmp(0x445B9A, 0x445F63);
    }

    virtual bool Update() {
        return --timer > 0;
    }

    static bool Allowed() {
        return !Effect::Infos[NoPoC::ID].enabled || Effect::Infos[NoPoC::ID].vote_choice;
    }
};
REGISTER_EFFECT(AlwaysPoC);

size_t AlwaysPoC::ID;
