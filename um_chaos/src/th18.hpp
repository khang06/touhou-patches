#pragma once

#include <Windows.h>
#include <cstdint>
#include <d3d9.h>
#include <stdint.h>

namespace GameUtil {
    void* __fastcall LoadFile(const char* path, uint32_t* bytes_read, uint32_t mode);
}

class Main {
public:
    static Main Instance;
    static HWND Window;

    int SwitchMode();

    HINSTANCE hinstance;            // 0x0
    IDirect3D9* d3d9;               // 0x4
    IDirect3DDevice9* d3d9_device;  // 0x8
    char gapC[0x7E8];               // 0xC
    uint32_t cur_mode;              // 0x7F4
    uint32_t switch_target_mode;    // 0x7F8
};

class CalcChain {
public:
    char gap0[4];
    uint32_t flags;

    static CalcChain* __stdcall Create(int(__fastcall* func)(void*));
    static int __stdcall RegisterCalc(void* func, int priority);
};

struct ZunVertex {
    float x, y, z, w;
    DWORD color;
    float u, v;
};

class AnmVM {};

class AnmManager {
public:
    int DrawSprite(AnmVM* anm);
    int AddVertices(ZunVertex* vertices);
};

class Player {
public:
    static Player* Instance;

    char gap0[0x62C];       // 0x0
    uint32_t pos_x;         // 0x62C
    uint32_t pos_y;         // 0x630
    char gap634[0x47078];   // 0x634
    uint32_t death_state;   // 0x476AC
};

// Called "GameThread" in ExpHP's repo, but I think that name is misleading
class GameState {
public:
    static GameState* Instance;

    char gap0[0xB0];    // 0x0
    uint32_t flags;     // 0xB0
};

namespace Globals {
    extern float GameSpeed;
};

class Timer {
public:
    uint32_t prev;
    uint32_t cur;
    float cur_float;
    uint32_t speed_idx_thing;
    uint32_t control;
};

class Card {
public:
    char gap0[0x34];        // 0x0
    Timer recharge_timer;   // 0x34
};

// TODO: These lists should be turned into a template class
class CardList {
public:
    Card* entry;
    CardList* next;
    CardList* prev;
    CardList* idk;
};

class AbilityManager {
public:
    static AbilityManager* Instance;

    char gap0[0x18];    // 0x0
    CardList card_list; // 0x18
};
