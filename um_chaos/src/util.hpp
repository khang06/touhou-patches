#pragma once

#include <Windows.h>
#include <stdint.h>
#include <vector>
#include "settings.hpp"
#include "th18.hpp"

namespace Rand {
    extern uint32_t State;

    inline void Seed(uint32_t seed) {
        State = seed;
    }
    inline uint32_t Next() {
        // xorshift32
        uint32_t x = State;
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        State = x;
        return x;
    }
    inline int32_t Range(int32_t start, int32_t end) { // inclusive
        return Next() % (end - start + 1) + start; // Yes, there's modulo bias. I don't care
    }
    inline int32_t RangeFrames(float start, float end) {
        return Range((int)(start * 60.0f), (int)(end * 60.0f));
    }
    inline int32_t RangeEffectTime(float start, float end) {
        float mul = Settings::EffectTimeMultiplier / 10.0f;
        return RangeFrames(start * mul, end * mul);
    }
    inline float NextFloat() {
        union {
            uint32_t i;
            float f;
        } u;
        u.i = 0x3F800000 | (Next() >> 9); // [1, 2)
        return u.f - 1.0f; // [0, 1)
    }
}

class CodePatches {
public:
    struct Patch {
        void* addr;
        std::vector<uint8_t> orig;
    };

    std::vector<Patch> patches;

    ~CodePatches();
    void Clear();
    void Add(uint32_t addr, void* data, size_t size);
    void Add(void* addr, void* data, size_t size);
    void AddJmp(uint32_t addr, uint32_t func);
    void AddJmp(uint32_t addr, void* func);
    void AddCall(uint32_t addr, uint32_t func);
    void AddCall(uint32_t addr, void* func);
};

struct CodeCave;

namespace StupidWindowsStuff {
    extern HANDLE ActivationContext;
}

inline float WindowToGameX(float x) {
    auto& window = Window::Instance;
    return x * ((float)window.backbuffer_height / window.window_height) - (window.backbuffer_width - window.scaled_width) / 2.0f;
}
inline float WindowToGameY(float y) {
    auto& window = Window::Instance;
    return y * ((float)window.backbuffer_height / window.window_height) - (window.backbuffer_height - window.scaled_height) / 2.0f;
}
inline float GameToWindowX(float x) {
    auto& window = Window::Instance;
    return (x + (window.backbuffer_width - window.scaled_width) / 2.0f) * ((float)window.window_height / window.backbuffer_height);
}
inline float GameToWindowY(float y) {
    auto& window = Window::Instance;
    return (y + (window.backbuffer_height - window.scaled_height) / 2.0f) * ((float)window.window_height / window.backbuffer_height);
}
inline float PlayfieldToGameX(float x) {
    return (x + 32.0f) * Window::Instance.game_scale;
}
inline float PlayfieldToGameY(float y) {
    return (y + 16.0f) * Window::Instance.game_scale;
}
inline float GameToPlayfieldX(float x) {
    return x / Window::Instance.game_scale - 32.0f;
}
inline float GameToPlayfieldY(float y) {
    return y / Window::Instance.game_scale - 16.0f;
}

namespace Util {
    void Log(const char* format, ...);
}

static constexpr float TWO_PI = 6.2831855f;

static constexpr size_t CREDITS_COUNT = 9;
extern const char* CREDITS[CREDITS_COUNT];
