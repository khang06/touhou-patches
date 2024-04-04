#pragma once

#include <stdio.h>
#include <string.h>

#define DEFINE_EFFECT(type_name) \
    Effect* effect_init_##type_name() { \
        return new type_name; \
    } \
    __attribute__((constructor)) void effect_ctor_##type_name() { \
        auto idx = Effect::AllCount++; \
        Effect::Infos[idx].name = #type_name; \
        Effect::Infos[idx].init = effect_init_##type_name; \
    }

class Effect;
struct EffectInfo {
    const char* name;
    Effect* (*init)();
};

struct EnabledEffect {
    const char* name;
    Effect* inner;
};

class Effect {
public:
    static constexpr size_t MAX_EFFECTS = 256;
    static size_t AllCount;
    static EffectInfo Infos[MAX_EFFECTS];
    static size_t EnabledCount;
    static EnabledEffect Enabled[MAX_EFFECTS];

    static void Enable(size_t id) {
        printf("Enabling %s...\n", Infos[id].name);
        Enabled[EnabledCount++] =  {
            .name = Infos[id].name,
            .inner = Infos[id].init()
        };
    }

    static void Disable(size_t idx) {
        printf("Disabling %s...\n", Enabled[idx].name);
        delete Enabled[idx].inner;
        memmove(&Enabled[idx], &Enabled[idx + 1], (EnabledCount - idx - 1) * sizeof(EnabledEffect));
        EnabledCount--;
    }

    static void UpdateAll() {
        for (size_t i = 0; i < EnabledCount;) {
            if (!Enabled[i].inner->Update())
                Disable(i);
            else
                i++;
        }
    }

    virtual ~Effect() {};
    virtual bool Update() { return true; };
};
