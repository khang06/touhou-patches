#pragma once

#include <Windows.h>
#include <stdint.h>
#include <vector>
#include "th18.hpp"

namespace Rand {
    void Seed(uint32_t seed);
    uint32_t Next();
    int32_t Range(int32_t start, int32_t end);
    int32_t __vectorcall RangeFrames(float start, float end);
    float __vectorcall NextFloat();
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
