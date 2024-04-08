#pragma once

#include <Windows.h>
#include <stdint.h>
#include <vector>
#include "th18.hpp"

namespace Rand {
    void Seed(uint32_t seed);
    uint32_t Next();
    int32_t Range(int32_t start, int32_t end);
    int32_t RangeFrames(float start, float end);
    float NextFloat();
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

inline float PlayfieldToScreenX(float x) {
    return (x + 32.0f) * Globals::UIScale;
}
inline float PlayfieldToScreenY(float y) {
    return (y + 16.0f) * Globals::UIScale;
}
inline float ScreenToPlayfieldX(float x) {
    return x / Globals::UIScale - 32.0f;
}
inline float ScreenToPlayfieldY(float y) {
    return y / Globals::UIScale - 16.0f;
}
