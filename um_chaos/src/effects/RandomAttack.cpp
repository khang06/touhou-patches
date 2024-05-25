#include "assets.hpp"
#include "effect.hpp"
#include "util.hpp"

class RandomAttack : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 2 * 60);
    CodePatches patches;

    RandomAttack() {
        patches.AddCall(0x48B314, (void*)ResolveSubHook);
    }

    virtual bool Update() {
        return --timer > 0;
    }

    static __thiscall void ResolveSubHook(Enemy* self, const char* name) {
        auto len = strlen(name);
        if ((len > 3 && !memcmp(&name[len - 3], "_at", 3)) ||
            (len > 4 && !memcmp(&name[len - 4], "_at", 3)) ||
            (len >= 15 && !memcmp(name, "ItemCarryLilyAt", 15))
        ) {
            const char* new_name = nullptr;
            if (!strncmp(name, "Boss", 4) || !strncmp(name, "MBoss", 5))
                new_name = Assets::BossAttacks[Rand::Range(0, Assets::BossAttacks.size() - 1)];
            else
                new_name = Assets::StageAttacks[Rand::Range(0, Assets::StageAttacks.size() - 1)];
            Util::Log("Overriding %s with %s\n", name, new_name);
            self->random_attack_cur_et = (self->random_attack_cur_et + 1) & 15;
            self->ResolveSub(new_name);
        } else {
            self->ResolveSub(name);
        }
    }
};
REGISTER_EFFECT(RandomAttack);
