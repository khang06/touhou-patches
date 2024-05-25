#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <util.hpp>

#define REGISTER_EFFECT(type_name) \
    Effect* effect_init_##type_name() { \
        return new type_name; \
    } \
    template<typename T> \
    __attribute__((constructor)) void effect_ctor_##type_name() { \
        auto idx = Effect::AllCount++; \
        Effect::Infos[idx].name = #type_name; \
        Effect::Infos[idx].init = effect_init_##type_name; \
        Effect::Infos[idx].enabled = false; \
        Effect::Infos[idx].vote_choice = false; \
        if constexpr (requires { T::ID; }) \
            T::ID = idx; \
        if constexpr (requires { T::Allowed; }) \
            Effect::Infos[idx].allowed = T::Allowed; \
        else \
            Effect::Infos[idx].allowed = nullptr; \
    } \
    template void effect_ctor_##type_name<type_name>();

class Effect;
struct EffectInfo {
    const char* name;
    Effect* (*init)();
    bool (*allowed)();
    bool enabled;
    bool vote_choice;
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
    static size_t PossibleChoices[MAX_EFFECTS];

    virtual ~Effect() {};
    virtual bool Update() { return false; };
    virtual void Draw() {};

    static void Enable(size_t id);
    static void EnableRandom();
    static void Disable(size_t idx);
    static void UpdateAll();
    static void DrawAll();

    static bool VoteChoices(size_t* choices, size_t count);
    static size_t UpdatePossibleChoices();
};
