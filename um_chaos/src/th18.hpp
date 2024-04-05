#pragma once

#include <Windows.h>
#include <cstdint>
#include <d3d9.h>
#include <stdint.h>

// Thanks zero318 for the stupid MSVC calling convention BS workaround
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"

template <typename T>
static inline constexpr T garbage_value(void) {
  T garbage;
  return garbage;
}

#define GARBAGE_VALUE(type) garbage_value<type>()
#define GARBAGE_ARG(type) GARBAGE_VALUE(type)

#pragma clang diagnostic pop

#define UNUSED_DWORD (GARBAGE_ARG(int32_t))
#define UNUSED_FLOAT (GARBAGE_ARG(float))

namespace GameUtil {
    void* __fastcall LoadFile(const char* path, uint32_t* bytes_read, uint32_t mode);
}    

class AnmVM {
public:
    char gap0[0x494];
    int32_t pending_interrupt;
};

class Main {
public:
    static Main Instance;
    static HWND Window;

    int SwitchMode();

    HINSTANCE hinstance;            // 0x0
    IDirect3D9* d3d9;               // 0x4
    IDirect3DDevice9* d3d9_device;  // 0x8
    char gapC[0x1BC];               // 0xC
    AnmVM* screen_anm4;             // 0x1C8
    char gap1CC[0x628];             // 0x1CC
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

class AnmManager {
public:
    int DrawSprite(AnmVM* anm);
    int AddVertices(ZunVertex* vertices);
};

class Timer {
public:
    uint32_t prev;
    uint32_t cur;
    float cur_float;
    uint32_t speed_idx_thing;
    uint32_t control;
};

class Player {
public:
    static Player* Instance;

    char gap0[0x62C];       // 0x0
    uint32_t pos_x;         // 0x62C
    uint32_t pos_y;         // 0x630
    Timer death_timer;      // 0x634
    char gap648[0x47064];   // 0x648
    uint32_t death_state;   // 0x476AC
    char gap476B0[0xC4];    // 0x476B0
    Timer idk_timer;
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

class BulletManager {
public:
    static BulletManager* Instance;

    void CancelAll(int idk);
};

class LaserManager {
public:
    static LaserManager* Instance;

    void CancelAll(int idk, Player* player);
};

class SoundManager {
public:
    static SoundManager Instance;

    inline void PlaySE(int32_t id, float pos) {
        PlaySEStupid(UNUSED_DWORD, id, UNUSED_FLOAT, UNUSED_FLOAT, pos);
    }

private:
    void __vectorcall PlaySEStupid(int32_t, int32_t id, float, float, float pos);
};
