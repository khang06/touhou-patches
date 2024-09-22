// clang++ -m32 -msse -msse2 -mfpmath=sse "-IC:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include" -O2 -c gohei_debug.cpp -o gohei_debug.obj

#include <Windows.h>
#include <cmath>
#include <stdint.h>
#include <d3d9.h>
#include <d3dx9.h>

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

extern "C" {
    __declspec(dllimport) HRESULT WINAPI D3DXCreateLine(LPDIRECT3DDEVICE9 pDevice, LPD3DXLINE* ppLine);
}

class CalcChain {
public:
    uint32_t priority;
    uint32_t flags;
    int(__fastcall* calc)(void*);
    int(__fastcall* init)(void*);
    int(__fastcall* destroy)(void*);
    int list_node;
    BYTE gap18[12];
    void* this_ptr;

    static CalcChain* __stdcall Create(int(__fastcall*)(void*));
    static int __stdcall RegisterCalc(CalcChain* chain, int priority);
    static int __stdcall RegisterDraw(CalcChain* chain, int priority);
};

class Timer {
public:
    int prev;
    int cur;
    float cur_float;
    float *speed;
    int control;
};

class PosVel {
public:
    D3DVECTOR pos;
    char gapC[12];
    float speed;
    float angle;
    char gap20[20];
    D3DVECTOR vel;
    __int32 field_40;
};

class PlayerBullet;
class ShtShooter {
public:
    char fire_rate;
    char start_delay;
    __int16 dmg;
    float off_x;
    float off_y;
    __int32 hitbox_x;
    __int32 hitbox_y;
    float angle;
    float speed;
    __int32 field_1C;
    char option;
    char sht_special;
    __int16 anm;
    __int16 sfx_id;
    __int16 field_26;
    int (__fastcall *init)(PlayerBullet *, int);
    int (__thiscall *tick)(PlayerBullet *);
    __int32 field_30;
    __int32 field_34;
    __int32 field_38;
    char gap3C[24];
    __int32 field_54;
};

class PlayerBulletList {
public:
    PlayerBullet *entry;
    PlayerBullet *next;
    PlayerBullet *prev;
    void *field_C;
};

class PlayerBullet {
public:
    PlayerBulletList list;
    uint32_t flags;
    uint32_t anm_id;
    Timer active_timer;
    Timer unfocus_timer;
    Timer idk_timer;
    PosVel pos_vel;
    uint32_t state;
    void *target;
    uint32_t target_id;
    char gapA4[8];
    __int32 dmg;
    __int32 hitbox_x;
    __int32 hitbox_y;
    float field_B8;
    ShtShooter *shooter;
    void *damage_src;
    char gapC4[8];
    __int32 field_CC;
};

class Player {
public:
    static Player* Instance;

    char gap0[0x5E0];           // 0x0
    D3DVECTOR pos;              // 0x5E0
    char gap5EC[0xDC];          // 0x5EC
    PlayerBullet bullets[256];  // 0x6C8
    PlayerBulletList free_head; // 0xD668
    char gapD6D8[0xAC60];       // 0xD6D8
    Timer shoot_timer;          // 0x18338
    uint32_t gohei_active[4];   // 0x1834C
};

class Ascii {
public:
    static Ascii* Instance;

    char gap0[0x191B0]; // 0x0
    uint32_t color;     // 0x191B0

    void Draw(float* pos, const char* format, ...);
};

class AnmVM {
public:
    char gap0[0x548];   // 0x0
    Timer vm_time;      // 0x548

    void GetBounds(D3DVECTOR* bounds);
};

class AnmManager {
public:
    static AnmManager* Instance;

    void FlushSprites();
    AnmVM* GetByID(uint32_t id);
};

class Window {
public:
    static Window Instance;

    char gap0[0x2054];  // 0x0
    float game_scale;   // 0x2054
    int32_t low_res_x;  // 0x2058
    int32_t low_res_y;  // 0x205C
};

class Enemy {
public:
    char gap0[0x1314];      // 0x0
    uint32_t cur_anm_id;    // 0x1314
};

class EnemyManager {
public:
    static EnemyManager* Instance;

    inline static Enemy* GetHomingTarget(D3DVECTOR* pos, float radius) {
        return GetHomingTargetStupid(UNUSED_DWORD, UNUSED_DWORD, pos, UNUSED_FLOAT, UNUSED_FLOAT, radius);
    }
private:
    static Enemy* __vectorcall GetHomingTargetStupid(int32_t, int32_t, D3DVECTOR*, float, float, float); 
};

inline float PlayfieldAnmToGameX(float x) {
    return (x - Window::Instance.low_res_x + 32.0f) * Window::Instance.game_scale;
}
inline float PlayfieldAnmToGameY(float y) {
    return (y - Window::Instance.low_res_y + 16.0f) * Window::Instance.game_scale;
}

inline float PlayfieldToGameX(float x) {
    return (x + 192.0f + 32.0f) * Window::Instance.game_scale;
}
inline float PlayfieldToGameY(float y) {
    return (y + 16.0f) * Window::Instance.game_scale;
}

extern "C" IDirect3DDevice9* g_device;
LPD3DXLINE g_line = nullptr;

void draw_anm_bounds(AnmVM* anm, uint32_t col, float* width = nullptr, float* height = nullptr) {
    D3DVECTOR bounds[4];
    anm->GetBounds(bounds);

    D3DXVECTOR2 points[] = {
        {PlayfieldAnmToGameX(bounds[0].x), PlayfieldAnmToGameY(bounds[0].y)},
        {PlayfieldAnmToGameX(bounds[1].x), PlayfieldAnmToGameY(bounds[1].y)},
        {PlayfieldAnmToGameX(bounds[3].x), PlayfieldAnmToGameY(bounds[3].y)},
        {PlayfieldAnmToGameX(bounds[2].x), PlayfieldAnmToGameY(bounds[2].y)},
        {PlayfieldAnmToGameX(bounds[0].x), PlayfieldAnmToGameY(bounds[0].y)},
    };
    g_line->SetAntialias(FALSE);
    g_line->SetWidth(4.0f);
    g_line->Draw(points, _countof(points), 0xFF000000);
    g_line->SetWidth(2.0f);
    g_line->Draw(points, _countof(points), col);

    // The main (invisible) gohei sprite doesn't rotate so this is fine
    if (width)
        *width = bounds[1].x - bounds[0].x;
    if (height)
        *height = bounds[2].y - bounds[0].y;
}

void draw_circle(D3DVECTOR* pos, float radius, uint32_t col) {
    static constexpr int POINT_COUNT = 128;
    D3DXVECTOR2 points[POINT_COUNT];

    for (int i = 0; i < POINT_COUNT - 1; i++) {
        points[i].x = PlayfieldToGameX(pos->x + radius * cosf(6.28318548f * ((float)i / POINT_COUNT)));
        points[i].y = PlayfieldToGameY(pos->y + radius * sinf(6.28318548f * ((float)i / POINT_COUNT)));
    }
    points[POINT_COUNT - 1] = points[0];

    g_line->SetAntialias(TRUE);
    g_line->SetWidth(4.0f);
    g_line->Draw(points, _countof(points), 0xFF000000);
    g_line->SetWidth(2.0f);
    g_line->Draw(points, _countof(points), col);
}

int __fastcall draw_func(void*) {
    float pos[3] = {0.0, 0.0, 0.0};
    if (Ascii::Instance && Player::Instance && EnemyManager::Instance) {
        AnmManager::Instance->FlushSprites();

        auto player = Player::Instance;
        //draw_circle(&Player::Instance->pos, 160.0f, 0xFFFF0000);

        auto initial_target = EnemyManager::GetHomingTarget(&player->pos, 160.0f);

        bool any_active = false;
        for (auto& bullet : player->bullets) {
            if (bullet.state == 1 && bullet.shooter->sht_special == 2) {
                any_active = true;
                break;
            }
        }

        Ascii::Instance->color = (player->shoot_timer.cur % 3) ? 0xFFFFFFFF : 0xFF00FF00;
        Ascii::Instance->Draw(pos, "Shoot timer: %d", player->shoot_timer.cur);
        pos[1] += 8.0f;

        Ascii::Instance->color = (!player->gohei_active[0] && any_active) ? 0xFF00FF00 : 0xFFFFFFFF;
        Ascii::Instance->Draw(pos, "Gohei active: %u", player->gohei_active[0]);
        pos[1] += 8.0f;

        Ascii::Instance->color = initial_target ? 0xFFFFFFFF : 0xFF00FF00;
        Ascii::Instance->Draw(pos, "Initial target: 0x%p", initial_target);
        pos[1] += 8.0f;

        Ascii::Instance->color = 0xFFFFFFFF;
        Ascii::Instance->Draw(pos, "Free list: ");
        pos[0] = 72.0f;
        auto cur = player->free_head.next;
        for (int i = 0; i < 16; i++) {
            Ascii::Instance->Draw(pos, "%03u", ((uint32_t)cur - (uint32_t)player->bullets) / sizeof(PlayerBullet));
            cur = cur->list.next;
            if (!cur)
                break;
            pos[0] += 24.0f;
        }
        pos[0] = 0.0f;
        pos[1] += 8.0f;

        if (initial_target) {
            auto anm = AnmManager::Instance->GetByID(initial_target->cur_anm_id);
            if (anm)
                draw_anm_bounds(anm, 0xFFFF0000);
        }

        pos[1] = 40.0f;
        for (int i = 0; i < _countof(player->bullets); i++) {
            auto& bullet = player->bullets[i];
            if (bullet.state && bullet.shooter->sht_special == 2) {
                auto anm = AnmManager::Instance->GetByID(bullet.anm_id);
                float anm_width = 0.0f;
                float anm_height = 0.0f;
                if (anm)
                    draw_anm_bounds(anm, (bullet.state == 2) ? 0x80FFFFFF : 0xFFFFFFFF, &anm_width, &anm_height);

                if (bullet.state == 2) {
                    if (anm) {
                        auto& pos_vel = bullet.pos_vel;
                        float frames_until_offscreen = INFINITY;
                        if (bullet.pos_vel.vel.x > 0)
                            frames_until_offscreen = min(frames_until_offscreen, ((192.0f + anm_width / 2.0f) - pos_vel.pos.x) / pos_vel.vel.x + 1.0f);
                        else
                            frames_until_offscreen = min(frames_until_offscreen, ((-192.0f - anm_width / 2.0f) - pos_vel.pos.x) / pos_vel.vel.x + 1.0f);
                        if (bullet.pos_vel.vel.y > 0)
                            frames_until_offscreen = min(frames_until_offscreen, ((448.0f + anm_height / 2.0f) - pos_vel.pos.y) / pos_vel.vel.y + 1.0f);
                        else
                            frames_until_offscreen = min(frames_until_offscreen, ((-anm_height / 2.0f) - pos_vel.pos.y) / pos_vel.vel.y + 1.0f);

                        if (isfinite(frames_until_offscreen)) {
                            frames_until_offscreen = max(ceil(frames_until_offscreen), 10 - bullet.active_timer.cur);
                            Ascii::Instance->color = (11 - (anm ? anm->vm_time.cur : 11) >= (int)frames_until_offscreen) ?
                                ((player->shoot_timer.cur != -1 && (player->shoot_timer.cur + (int)frames_until_offscreen) % 3 == 0) ? 0xFF00FF00 : 0xFFFFFF00) :
                                0xFFFF0000;
                        } else {
                            frames_until_offscreen = INFINITY;
                            Ascii::Instance->color = 0xFFFF0000;
                        }

                        Ascii::Instance->Draw(
                            pos, "[%03d] State: %d, Despawn: %d, Offscreen: %.0f",
                            i, bullet.state, 11 - (anm ? anm->vm_time.cur : 11), frames_until_offscreen
                        );
                    } else {
                        Ascii::Instance->color = 0xFFFF0000;
                        Ascii::Instance->Draw(
                            pos, "[%03d] State: %d, Despawned :(",
                            i, bullet.state
                        );
                    }
                } else {
                    Ascii::Instance->color = 0xFFFFFFFF;
                    Ascii::Instance->Draw(
                        pos, "[%03d] State: %d, Target: 0x%p, Unfocus: %d, Speed: %f",
                        i, bullet.state, bullet.target, 12 - bullet.unfocus_timer.cur, bullet.pos_vel.speed
                    );
                }
                pos[1] += 8.0f;
            }
        }
        Ascii::Instance->color = 0xFFFFFFFF;

        /*
        auto player = Player::Instance;
        draw_circle(&Player::Instance->pos, 160.0f, 0xFFFF0000);
        for (int i = 0; i < _countof(player->bullets); i++) {
            auto& bullet = player->bullets[i];
            if (bullet.state && bullet.shooter->sht_special == 2)
                draw_circle(&bullet.pos_vel.pos, 320.0f, 0xFF00FF00);
        }
        */
    }
    return 1;
}

extern "C" int hook_entry() {
    auto draw = CalcChain::Create(draw_func);
    draw->flags |= 2;
    CalcChain::RegisterDraw(draw, 66);

    if (FAILED(D3DXCreateLine(g_device, &g_line)))
        __debugbreak();
    return 0;
}
