#pragma once

#include <stdint.h>
#include <vector>

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
    void Add(uint32_t addr, void* data, size_t size);
    void Add(void* addr, void* data, size_t size);
    void AddJmp(uint32_t addr, uint32_t func);
    void AddJmp(uint32_t addr, void* func);
    void AddCall(uint32_t addr, uint32_t func);
    void AddCall(uint32_t addr, void* func);
};

struct CodeCave;
