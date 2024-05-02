#pragma once

#include <Windows.h>
#include <dsound.h>
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
    char gap0[0x54];            // 0x0
    float scale_x;              // 0x54
    float scale_y;              // 0x58
    char gap5C[0x438];          // 0x5C
    int32_t pending_interrupt;  // 0x494
};

class AnmEntry {
public:
    IDirect3DTexture9* d3d9_tex;
    char gap4[0x14];
};

class AnmLoaded {
public:
    char gap0[0x124];
    AnmEntry* entries;
};

class Main {
public:
    static Main Instance;
    static HWND Window;

    int SwitchMode();

    HINSTANCE hinstance;                    // 0x0
    IDirect3D9* d3d9;                       // 0x4
    IDirect3DDevice9* d3d9_device;          // 0x8
    char gapC[0xE8];                        // 0xC
    D3DPRESENT_PARAMETERS present_params;   // 0xF4
    char gap12C[0x80];                      // 0x12C
    IDirect3DSurface9* bg_render_target;    // 0x1AC
    IDirect3DSurface9* game_render_target;  // 0x1B0
    IDirect3DSurface9* backbuffer;          // 0x1B4
    char gap1B8[0x10];                      // 0x1B8
    AnmVM* screen_anm4;                     // 0x1C8
    char gap1CC[0x628];                     // 0x1CC
    uint32_t cur_mode;                      // 0x7F4
    uint32_t switch_target_mode;            // 0x7F8
    char gap7FC[0x30];                      // 0x7FC
    AnmLoaded* text_anm;                    // 0x82C
};

class CalcChain {
public:
    char gap0[4];
    uint32_t flags;

    static CalcChain* __stdcall Create(int(__fastcall* func)(void*));
    static int __stdcall RegisterCalc(void* func, int priority);
    static int __stdcall RegisterDraw(void* func, int priority);
};

struct ZunVertex {
    float x, y, z, w;
    DWORD color;
    float u, v;
};

class AnmLoaded;

class AnmManager {
public:
    static AnmManager* Instance;

    int DrawSprite(AnmVM* anm);
    int AddVertices(ZunVertex* vertices);
    AnmLoaded* Preload(int id, const char* filename);
    void FlushSprites();
};

class Timer {
public:
    uint32_t prev;
    uint32_t cur;
    float cur_float;
    uint32_t speed_idx_thing;
    uint32_t control;
};

// TODO: This should probably be a template
class InterpFloat {
public:
    float initial;
    float goal;
    float bezier_1;
    float bezier_2;
    float current;
    Timer timer;
    int end_time;
    int method;
};

class Player {
public:
    static Player* Instance;

    int CalcMove();

    char gap0[0x620];           // 0x0
    D3DVECTOR pos_float;        // 0x620
    uint32_t pos_x;             // 0x62C
    uint32_t pos_y;             // 0x630
    Timer death_timer;          // 0x634
    char gap648[0x47064];       // 0x648
    uint32_t death_state;       // 0x476AC
    char gap476B0[0xC4];        // 0x476B0
    Timer idk_timer;            // 0x47774
    char gap47788[0x14];        // 0x47788
    uint32_t flags;             // 0x4779C
    char gap477A0[0x1AC];       // 0x477A0
    InterpFloat scale_interp;   // 0x4794C
    float scale;                // 0x4797C
    char gap47980[8];           // 0x47980
    float item_attract_speed;   // 0x47988
};

// Called "GameThread" in ExpHP's repo, but I think that name is misleading
class GameState {
public:
    static GameState* Instance;

    void ClearStage();

    char gap0[0xB0];    // 0x0
    uint32_t flags;     // 0xB0
};

namespace Globals {
    extern float GameSpeed;
    extern uint32_t CurInput;
};

class Card {
public:
    char gap0[0x34];        // 0x0
    Timer recharge_timer;   // 0x34
};

template<typename T>
class ZUNList {
public:
    T* entry;
    ZUNList<T>* next;
    ZUNList<T>* prev;
    ZUNList<T>* idk;
};

class AbilityManager {
public:
    static AbilityManager* Instance;

    char gap0[0x18];            // 0x0
    ZUNList<Card> card_list;    // 0x18
};

class BulletManager {
public:
    static BulletManager* Instance;

    void ClearAll(int idk);
};

class LaserManager {
public:
    static LaserManager* Instance;

    void ClearAll(int idk, Player* player);
};

class SoundManager {
public:
    static SoundManager Instance;

    char gap0[0xC];
    LPDIRECTSOUND8* dsound;

    static void StopAllSounds();

    inline void PlaySE(int32_t id, float pos) {
        PlaySEStupid(UNUSED_DWORD, id, UNUSED_FLOAT, UNUSED_FLOAT, pos);
    }
    void SendMsg(int32_t id, int32_t arg, const char* str);
    bool HandleMsg(); // Not sure if this name is accurate

private:
    void __vectorcall PlaySEStupid(int32_t, int32_t id, float, float, float pos);
};

class AsciiManager {
public:
    static AsciiManager* Instance;

    char pad0[0x19228];     // 0x0
    uint32_t color;         // 0x19228
    uint32_t shadow_color;  // 0x1922C
    char pad19230[0x14];    // 0x19230
    uint32_t style;         // 0x19244
    uint32_t field_19248;   // 0x19248
    uint32_t field_1924C;   // 0x1924C
    uint32_t hor_align;     // 0x19250
    uint32_t ver_align;     // 0x19254

    void DrawDebugText(D3DVECTOR* pos, const char* format, ...);
    void DrawShadowText(D3DVECTOR* pos, const char* format, ...);
};

class AbilityShop {
public:
    static AbilityShop* Instance;

    char pad0[0xE3C];

    bool Init(D3DVECTOR* idk);
};

class ItemManager {
public:
    void* __thiscall SpawnItem(int id, int a3, int a4, float a5, float a6, int a7, int a8, int a9);
};

class Enemy {
public:
    char gap0[0x1214];
    int random_attack_cur_et; // 0x1214, supposedly unused?

    void ResolveSub(const char* name);
    int GetGlobal(int idx);
};

struct EclSub {
    const char* name;
    void* data;
};

class EclFileManager {
public:
    // vtable
    char pad4[4];
    uint32_t sub_count;
    char padC[0x80];
    EclSub* subroutines;

    virtual int LoadECLFile(const char* filename);
};

class EnemyInitData {
public:
    D3DVECTOR pos;              // 0x0
    uint32_t score_reward;      // 0xC
    uint32_t item;              // 0x10
    uint32_t hp;                // 0x14
    uint32_t mirrored;          // 0x18
    uint32_t field_1C;          // 0x1C
    int32_t ecl_int_vars[4];    // 0x20
    float ecl_float_vars[8];    // 0x30
    uint32_t parent_id;         // 0x50
};

class EnemyManager {
public:
    static EnemyManager* Instance;

    char pad0[0x170];
    AnmLoaded* enemy_ecls[6];
    EclFileManager* file_manager;

    static EnemyManager* __fastcall Create(const char* filename); 
    Enemy* MakeEnemy(const char* sub, EnemyInitData* init_data, int unused);
};

class Window {
public:
    static Window Instance;

    static inline bool IsFullscreen() {
        // There's a dedicated window choice variable,
        // but that doesn't get updated if the player switches window modes via Alt+Enter
        auto window_choice = (Instance.flags >> 2) & 0x1F;
        return window_choice < 3 || window_choice == 8 || window_choice == 9;
    }

    char pad0[0x2040];      // 0x0
    uint32_t flags;         // 0x2040
    char pad2044[0xC];      // 0x2044
    int scaled_width;       // 0x2050
    int scaled_height;      // 0x2054
    int window_width;       // 0x2058
    int window_height;      // 0x205C
    int display_width;      // 0x2060
    int display_height;     // 0x2064
    int backbuffer_width;   // 0x2068
    int backbuffer_height;  // 0x206C
    float game_scale;       // 0x2070
};

class ScoreFile {
public:
    static void Init();
    static void UnlockCode();
};

class TitleScreen {
public:
    char pad0[0x20];
    uint32_t transition_state;

    void SwitchMenuState(uint32_t state);
};

class Input {
public:
    static uint32_t Cur;
    static uint32_t Prev;
    static uint32_t Pressed;
    static uint32_t Released;
};
