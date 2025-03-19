#include "effect.hpp"
#include "util.hpp"

class AlwaysPoC {
public:
    static size_t ID;
};

class NoPoC : public Effect {
public:
    static size_t ID;
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;

    NoPoC() {
        static constexpr uint8_t nop6[] = {0x66, 0x0f, 0x1f, 0x44, 0x00, 0x00};
        patches.Add(0x446003, (void*)nop6, sizeof(nop6));
        patches.Add(0x445BB9, (void*)nop6, sizeof(nop6));
    }

    virtual bool Update() {
        return --timer > 0;
    }

    static bool Allowed() {
        return !Effect::Infos[NoPoC::ID].enabled || Effect::Infos[AlwaysPoC::ID].vote_choice;
    }
};
REGISTER_EFFECT(NoPoC);

size_t NoPoC::ID;
