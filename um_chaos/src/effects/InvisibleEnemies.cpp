#include "effect.hpp"
#include "util.hpp"

class InvisibleEnemies : public Effect {
public:
    int timer = Rand::RangeEffectTime(5, 30);
    CodePatches patches;

    static int __thiscall DrawSpriteHook(AnmManager* self, AnmVM* vm) {
        if (vm->preloaded_idx1 >= 10 && vm->preloaded_idx1 <= 17)
            return 0;
        return self->DrawSprite(vm);
    }

    InvisibleEnemies() {
        patches.AddCall(0x4882B8, (void*)DrawSpriteHook);
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(InvisibleEnemies);
