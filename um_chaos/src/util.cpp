#include <Windows.h>
#include <vector>
#include <stdint.h>
#include "settings.hpp"
#include "util.hpp"

namespace Rand {
    uint32_t State;
}

CodePatches::~CodePatches() {
    Clear();
}
void CodePatches::Clear() {
    for (auto& x : patches) {
        DWORD old_prot;
        VirtualProtect(x.addr, x.orig.size(), PAGE_EXECUTE_READWRITE, &old_prot);
        memcpy(x.addr, x.orig.data(), x.orig.size());
        VirtualProtect(x.addr, x.orig.size(), old_prot, &old_prot);
    }
    patches.clear();
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

namespace StupidWindowsStuff {
    static HANDLE ActivationContext = NULL;
}

extern "C" __declspec(dllimport) void log_vprintf(const char* format, va_list va);
namespace Util {
    void Log(const char* format, ...) {
        va_list va;
        va_list va2;
        va_start(va, format);
        va_copy(va2, va);
        log_vprintf(format, va);
        va_end(va);
        if (Settings::DebugConsole)
            vprintf(format, va2);
        va_end(va2);
    }
}

const char* CREDITS[CREDITS_COUNT] = {
    "Bravidunno: Effect ideas, MurderousLily",
    "Guy: Effect ideas",
    "Khangaroo: Lead procrastinator",
    "NeoNickz: Effect ideas, ECL help",
    "rory618: JPEG/DCT shader (HLSL port by Matsilagi)",
    "Schotsl: Original uwuifer implementation",
    "TESM: Effect ideas",
    "zero318: Effect ideas, IcePhysics, Twitch IRC code, RE and ECL help",
    "Everyone in ZUNcode: Being very cool people",
};
