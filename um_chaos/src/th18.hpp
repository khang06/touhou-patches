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
    char gap0[0x18];            // 0x0
    uint32_t layer;             // 0x18
    char gap1C[0x8];            // 0x1C
    int32_t sprite_id;          // 0x24
    char gap28[0x8];            // 0x28
    D3DVECTOR position;         // 0x30
    D3DVECTOR rotation;         // 0x3C
    D3DVECTOR angular_velocity; // 0x48
    float scale_x;              // 0x54
    float scale_y;              // 0x58
    char gap5C[0x370];          // 0x5C
    float scroll_speed_u;       // 0x3CC
    float scroll_speed_v;       // 0x3D0
    char gap3D4[0xC0];          // 0x3D4
    int32_t pending_interrupt;  // 0x494
    char gap498[0x8C];          // 0x498
    DWORD color1;               // 0x524
    DWORD color2;               // 0x528
    char gap52C[0x8];           // 0x52C
    union {
        uint32_t flags_low;     // 0x534
        struct {
            uint32_t visible : 1;
            uint32_t : 1;
            uint32_t __z_rotation : 1;
        };
    };
    union {
        uint32_t flags_high;    // 0x538
        struct {
            uint32_t : 25;
            uint32_t inherit_rotation : 1;
            uint32_t : 1;
            uint32_t colorize_children : 1;
        };
    };

    static void __stdcall QueueDeletion(AnmVM* vm);
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

    void MakeVM(AnmVM* vm, uint32_t script_id);
};

class Camera {
public:
    char gap0[0xE0];    // 0x0
    int32_t x;          // 0xE0
    int32_t y;          // 0xE4
    int32_t width;      // 0xE8
    int32_t height;     // 0xEC
    char gapF0[0x74];   // 0xF0
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
    char gap1CC[0x90];                      // 0x1CC
    Camera cameras[4];                      // 0x25C
    char gap7EC[0x8];                       // 0x7EC
    int32_t cur_mode;                       // 0x7F4
    int32_t switch_target_mode;             // 0x7F8
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

class AnmManager {
public:
    static AnmManager* Instance;

    static AnmVM* AllocateVM();
    static uint32_t* __stdcall AddToUIBack(uint32_t* id, AnmVM* vm);

    int DrawSprite(AnmVM* anm);
    int AddVertices(ZunVertex* vertices);
    AnmLoaded* Preload(int id, const char* filename);
    void FlushSprites();
    AnmVM* GetByID(uint32_t id);
    int DrawLayer(uint32_t layer);
};

// Stripped down a bit
// https://github.com/zero318/ClangAsmTest1/blob/f3f5e549659812ae34e91aca539f7710f2fc40c0/UM/UM_bullet_ex.cpp#L2158
struct Timer {
    int32_t previous; // 0x0
    int32_t current; // 0x4
    float current_f; // 0x8
    uint32_t scale_table_index; // 0xC
    union {
        uint32_t flags; // 0x10
        struct {
            uint32_t initialized : 1;
        };
    };
    // 0x14

    inline Timer() : initialized(false) {};

    inline void default_values() {
        this->current = 0;
        this->previous = -999999;
        this->current_f = 0.0f;
    }

private:
    inline void initialize_previous_force(int32_t value) volatile {
        this->previous = value;
    }
public:

    inline void initialize() {
        if (!this->initialized) {
            this->initialize_previous_force(-999999);
            this->scale_table_index = 0;
            this->initialized = true;
        }
    }

    inline void initialize_important() {
        if (!this->initialized) {
            this->scale_table_index = 0;
            this->initialized = true;
        }
    }
    inline void set_raw(int32_t time) {
        this->current = time;
        this->current_f = (float)time;
        this->previous = time - 1;
    }
    // 0x405D10
    inline void __thiscall set(int32_t time) {
        this->initialize_important();
        this->set_raw(time);
    }
    inline void reset() {
        this->set(0);
    }

    inline void initialize_and_reset() {
        this->initialize();
        this->set_raw(0);
    }
    inline void initialize_and_set(int32_t time) {
        this->initialize();
        this->set_raw(time);
    }
};

// Also stripped down a bit
// https://github.com/zero318/ClangAsmTest1/blob/f3f5e549659812ae34e91aca539f7710f2fc40c0/UM/UM_bullet_ex.cpp#L3631
template <typename T, size_t modes = 1>
struct ZUNInterp { //       0x58    0x44    0x30
    //                      T3      T2      T1
    T initial_value; //     0x0     0x0     0x0
    T final_value; //       0xC     0x8     0x4
    T bezier1; //           0x18    0x10    0x8
    T bezier2; //           0x24    0x18    0xC
    T current; //           0x30    0x20    0x10
    Timer time; //          0x3C    0x28    0x14
    int32_t end_time; //    0x50    0x3C    0x28
    int32_t mode[modes]; // 0x54    0x40    0x2C

    inline ZUNInterp<T, modes>() : end_time(0) {}

    // float: 0x41F600
    // Float2: 0x439600
    // Float3: 0x405A00
    // Float3Ex: 0x439940
    // ZUNAngle: 0x47CBF0
    inline void set_end_time(int32_t time) {
        this->end_time = time;
    }
    
    // Float3Ex: 0x439950
    inline void set_current(const T& value) {
        this->current = value;
    }
    
    // float: 0x41B790
    // Float2: 0x4395C0
    // Float3Ex: 0x439900
    inline void reset_end_time() {
        this->end_time = 0;
    }

    // float: 0x41F630
    // Float2: 0x439690
    // Float3: 0x405A10
    // ZUNAngle: 0x47CC40
    inline void set_mode(int32_t mode) {
        this->mode[0] = mode;
    }

    inline void set_mode_0() {
        this->mode[0] = 0;
    }

    // float: 0x41F620
    // Float2: 0x439670
    // Float3: 0x405A20
    // ZUNAngle: 0x47CC30
    inline void set_initial_value(const T& value) {
        this->initial_value = value;
    }

    // float: 0x41F610
    // Float2: 0x439650
    // Float3: 0x405A40
    // Float3Ex: 0x4399B0
    // ZUNAngle: 0x47CC20
    inline void set_final_value(const T& value) {
        this->final_value = value;
    }

    // float: 0x429A70
    // Float3: 0x405A60
    // Float3Ex: 0x439990
    // ZUNAngle: 0x47CC10
    inline void set_bezier1(const T& value) {
        this->bezier1 = value;
    }

    // float: 0x429A60
    // Float3: 0x405A80
    // Float3Ex: 0x439970
    // ZUNAngle: 0x47CC00
    inline void set_bezier2(const T& value) {
        this->bezier2 = value;
    }

    // float: 0x41F5D0
    // Float2: 0x4395D0
    // Float3: 0x405AA0
    // Float3Ex: 0x439910
    // ZUNAngle: 0x47CBC0
    inline void reset_timer() {
        this->time.reset();
    }

    inline void initialize(int32_t end_time, int32_t mode, const T& initial_value, const T& final_value) {
        this->set_end_time(end_time);
        this->set_mode(mode);
        this->set_bezier1({});
        this->set_bezier2({});
        this->set_initial_value(initial_value);
        this->set_final_value(final_value);
        this->reset_timer();
    }
};

class Player {
public:
    static Player* Instance;

    int CalcMove();

    char gap0[0x620];               // 0x0
    D3DVECTOR pos_float;            // 0x620
    uint32_t pos_x;                 // 0x62C
    uint32_t pos_y;                 // 0x630
    Timer death_timer;              // 0x634
    char gap648[0x47064];           // 0x648
    uint32_t death_state;           // 0x476AC
    char gap476B0[0xC4];            // 0x476B0
    Timer invuln_timer;             // 0x47774
    char gap47788[0x14];            // 0x47788
    uint32_t flags;                 // 0x4779C
    char gap477A0[0x1AC];           // 0x477A0
    ZUNInterp<float> scale_interp;  // 0x4794C
    float scale;                    // 0x4797C
    char gap47980[8];               // 0x47980
    float item_attract_speed;       // 0x47988
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
};

class Card {
public:
    virtual void Unk0();
    virtual void Unk4();
    virtual void Unk8();
    virtual void UnkC();
    virtual void Unk10();
    virtual void Unk14();
    virtual void OnLevelUp();

    char gap4[0x30];        // 0x4
    Timer recharge_timer;   // 0x34
};

class CardInfo {
public:
    const char* id_str;
    uint32_t id;

    static uint32_t __fastcall RandomCard(CardInfo** result, int min_type, int max_type, CardInfo** cards, int card_count);
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
    char gap28[0xC5C];          // 0x28
    uint32_t equipped[56];      // 0xC84

    void ClearCards(int reequip);
    int EquipCard(uint32_t id, uint32_t flags);
};

// https://github.com/zero318/ClangAsmTest1/blob/f3f5e549659812ae34e91aca539f7710f2fc40c0/UM/UM_bullet_ex.cpp#L10553
struct BulletEffectData {
    Timer timer; // 0x0
    union { // 0x14
        float speed;
        float acceleration;
    };
    union { // 0x18
        float angle;
        float angular_velocity;
    };
    union { // 0x1C
        D3DVECTOR position;
        D3DVECTOR size;
    };
    union { // 0x28
        D3DVECTOR velocity;
        D3DVECTOR acceleration_vec;
        D3DVECTOR target;
    };
    union { // 0x34
        int32_t duration;
        int32_t __offscreen_unknown;
    };
    union { // 0x38
        int32_t max_count;
        int32_t mode;
    };
    union { // 0x3C
        int32_t count;
        int32_t flags;
    };
    int32_t type; // 0x40
    int32_t __int_44; // 0x44
    // 0x48

    inline BulletEffectData() {}
};

class Bullet {
public:
    char gap0[0x20];                // 0x0
    uint32_t flags;                 // 0x20
    char gap24[0x614];              // 0x24
    D3DVECTOR position;             // 0x638
    D3DVECTOR velocity;             // 0x644
    char gap650[0x34];              // 0x650
    uint32_t ex_flags;              // 0x684
    char gap688[0x5E4];             // 0x688
    BulletEffectData effect_wrap;   // 0xC6C

    void CalcEx();
};

class EnemyShooter {
public:
    char gap0[0x14];    // 0x0
    float angle1;       // 0x14
    char gap18[0x470];  // 0x18
};

class BulletManager {
public:
    static BulletManager* Instance;

    char gap0[0xBC];                    // 0x0
    ZUNList<Bullet> list_dummy_head;    // 0xBC

    void ClearAll(int idk);
    int Draw();
    int ShootShooter(EnemyShooter* shooter, int idx1, int idx2, float angle);
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

    void DrawDebugText(const D3DVECTOR* pos, const char* format, ...);
    void DrawShadowText(const D3DVECTOR* pos, const char* format, ...);
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

class EnemyData {
public:
    char gap0[0x598];           // 0x0
    EnemyShooter shooters[16];  // 0x598

    int GetIntArg(int idx);
    inline float GetFloatArg(int idx) {
        // Has to return a float using xmm0
        return GetFloatArgStupid(UNUSED_DWORD, idx);
    }

private:
    float __vectorcall GetFloatArgStupid(int, int idx);
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
    static uint32_t Repeat;
    static uint32_t Pressed;
    static uint32_t Released;
};

class Bomb {
public:
    static Bomb* Instance;

    char gap0[0x64];    // 0x0
    uint32_t anm_id;    // 0x64
};

class MsgVM {
public:
    MsgVM(uint32_t idk);
    ~MsgVM();

    static char* __fastcall DecryptString(char* input);

    char gap0[0x40];                // 0x0
    uint32_t player_portraits[2];   // 0x40
    uint32_t enemy_portraits[4];    // 0x48
    char gap58[0xC];                // 0x58
    uint32_t dialogue_lines[2];     // 0x64
    uint32_t furigana_lines[2];     // 0x6C
    uint32_t intro;                 // 0x74
};

class Gui {
public:
    static Gui* Instance;
    
    char pad0[0x1B0];       // 0x0
    MsgVM* msg_vm;          // 0x1B0
    
    static inline bool is_msg_active() {
        return Instance->msg_vm != NULL;
    }
};

enum InputFlags : uint32_t {
    INPUT_SHOOT = 1,
    INPUT_BOMB = 2,
    INPUT_FOCUS = 8,
    INPUT_UP = 0x10,
    INPUT_DOWN = 0x20,
    INPUT_LEFT = 0x40,
    INPUT_RIGHT = 0x80,
    INPUT_PAUSE = 0x100,
    INPUT_ITEM = 0x400,
    INPUT_CHANGE = 0x800,
    INPUT_RETRY = 0x20000,
    INPUT_SCREENSHOT = 0x40000,
    INPUT_ENTER = 0x80000,
};
