#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define REGISTER_EFFECT(type_name) \
    Effect* effect_init_##type_name() { \
        return new type_name; \
    } \
    __attribute__((constructor)) void effect_ctor_##type_name() { \
        auto idx = Effect::AllCount++; \
        Effect::Infos[idx].name = #type_name; \
        Effect::Infos[idx].init = effect_init_##type_name; \
        Effect::Infos[idx].enabled = false; \
    }

class Effect;
struct EffectInfo {
    const char* name;
    Effect* (*init)();
    bool enabled;
};

struct EnabledEffect {
    const char* name;
    size_t id;
    uint32_t frames_active;
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
        Infos[id].enabled = true;
        Enabled[EnabledCount++] =  {
            .name = Infos[id].name,
            .id = id,
            .frames_active = 0,
            .inner = Infos[id].init(),
        };
    }

    static void Disable(size_t idx) {
        printf("Disabling %s...\n", Enabled[idx].name);
        Infos[Enabled[idx].id].enabled = false;
        delete Enabled[idx].inner;
        memmove(&Enabled[idx], &Enabled[idx + 1], (EnabledCount - idx - 1) * sizeof(EnabledEffect));
        EnabledCount--;
    }

    static void UpdateAll() {
        for (size_t i = 0; i < EnabledCount;) {
            Enabled[i].frames_active++;
            if (!Enabled[i].inner->Update())
                Disable(i);
            else
                i++;
        }
    }

    static void DrawAll() {
        for (size_t i = 0; i < EnabledCount; i++)
            Enabled[i].inner->Draw();
    }

    virtual ~Effect() {};
    virtual bool Update() { return true; };
    virtual void Draw() {};
};
