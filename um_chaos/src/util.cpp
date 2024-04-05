#include <Windows.h>
#include <vector>
#include <stdint.h>
#include "util.hpp"

namespace Rand {
    uint32_t g_rand_state;

    void Seed(uint32_t seed) {
        g_rand_state = seed;
    }
    uint32_t Next() {
        // xorshift32
        uint32_t x = g_rand_state;
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        g_rand_state = x;
        return x;
    }
    int32_t Range(int32_t start, int32_t end) { // inclusive
        return Next() % (end - start + 1) + start; // Yes, there's modulo bias. I don't care
    }
    int32_t RangeFrames(float start, float end) {
        return Range((int)(start * 60.0f), (int)(end * 60.0f));
    }
    float NextFloat() {
        union {
            uint32_t i;
            float f;
        } u;
        u.i = 0x3F800000 | (Next() >> 9); // [1, 2)
        return u.f - 1.0f; // [0, 1)
    }
}

CodePatches::~CodePatches() {
    for (auto& x : patches) {
        DWORD old_prot;
        VirtualProtect(x.addr, x.orig.size(), PAGE_EXECUTE_READWRITE, &old_prot);
        memcpy(x.addr, x.orig.data(), x.orig.size());
        VirtualProtect(x.addr, x.orig.size(), old_prot, &old_prot);
    }
}
void CodePatches::Add(uint32_t addr, void* data, size_t size) {
    Add((void*)addr, data, size);
}
void CodePatches::Add(void* addr, void* data, size_t size) {
    std::vector<uint8_t> orig;
    orig.resize(size);
    memcpy(orig.data(), addr, size);

    DWORD old_prot;
    VirtualProtect(addr, size, PAGE_EXECUTE_READWRITE, &old_prot);
    memcpy(addr, data, size);
    VirtualProtect(addr, size, old_prot, &old_prot);

    patches.push_back(Patch {
        .addr = addr,
        .orig = std::move(orig),
    });
}
void CodePatches::AddJmp(uint32_t addr, uint32_t func) {
    AddJmp(addr, (void*)func);
}
void CodePatches::AddJmp(uint32_t addr, void* func) {
    BYTE patch[5];
    patch[0] = 0xE9;
    *(uint32_t*)(patch + 1) = (uint32_t)func - (uint32_t)addr - 5;
    Add(addr, patch, sizeof(patch));
}
void CodePatches::AddCall(uint32_t addr, uint32_t func) {
    AddCall(addr, (void*)func);
}
void CodePatches::AddCall(uint32_t addr, void* func) {
    BYTE patch[5];
    patch[0] = 0xE8;
    *(uint32_t*)(patch + 1) = (uint32_t)func - (uint32_t)addr - 5;
    Add(addr, patch, sizeof(patch));
}
