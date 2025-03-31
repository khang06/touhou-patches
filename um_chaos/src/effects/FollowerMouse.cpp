#include "assets.hpp"
#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

constexpr int ANIM_TABLE[5][8] = {
    {0,  0,  0,  0,  0,  1,  2,  3},
    {19, 18, 17, 16, 15, 14, 13, 12},
    {4,  5,  6,  7,  8,  9,  10, 11},
    {16, 17, 18, 19, 23, 22, 21, 20},
    {7,  6,  5,  4,  0,  1,  2,  3},
};

// TODO: This only looks right on 1280x960
class FollowerMouse : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);

    HWND overlay = NULL;
    float overlay_x = 0.0f;
    float overlay_y = 0.0f;

    size_t frames_active = 0;
    int anim_frame = 17; // Skip turning anim for neutral position
    int last_x_dir = 0;
    int anim_idx = 0;
    int last_sprite_idx = -1;

    FollowerMouse() {
        HMONITOR monitor = MonitorFromWindow(Main::Window, MONITOR_DEFAULTTONEAREST);
        MONITORINFO info = {
            .cbSize = sizeof(MONITORINFO)
        };
        GetMonitorInfo(monitor, &info);

        POINT p = {
            .x = (LONG)GameToWindowX(PlayfieldToGameX(192.0f)),
            .y = (LONG)GameToWindowY(PlayfieldToGameY(64.0f))
        };
        ClientToScreen(Main::Window, &p);

        //overlay_x = Rand::Range(info.rcMonitor.left, info.rcMonitor.right);
        //overlay_y = info.rcMonitor.top - 64;
        overlay_x = p.x;
        overlay_y = p.y;

        overlay = CreateWindowExA(
            WS_EX_TOPMOST | WS_EX_LAYERED | WS_EX_TOOLWINDOW,
            "FollowerMouseClass",
            "FollowerMouse",
            WS_VISIBLE,
            -32000, -32000,
            64, 64,
            NULL, NULL, NULL, NULL
        );

        SetForegroundWindow(Main::Window);
        SetCursor(LoadCursorA(NULL, IDC_ARROW));
        
        EnemyInitData init = {
            .pos = {
                .x = 0.0f,
                .y = -16.0f,
                .z = 0.0f,
            },
            .hp = 1000
        };
        EnemyManager::Instance->MakeEnemy("FollowerMouseDummy", &init, 0);
    }

    virtual ~FollowerMouse() {
        DestroyWindow(overlay);
        if (Window::IsFullscreen())
            SetCursor(LoadCursorA(NULL, NULL));
    }

    virtual bool Update() {
        if (++frames_active < 60)
            return true;

        ShowWindow(overlay, SW_SHOWNOACTIVATE);
        UpdateWindow(overlay);

        POINT cursor;
        GetCursorPos(&cursor);

        int delta_x = cursor.x - overlay_x;
        int delta_y = cursor.y - overlay_y;
        float cursor_dist = sqrtf(delta_x * delta_x + delta_y * delta_y);
        if (cursor_dist < 8.0f) {
            Player::Instance->Kill();
            return false;
        } else if (cursor_dist < 256.0f) {
            int jitter_max = (256.0f - cursor_dist) / 48.0f;
            SetCursorPos(cursor.x + Rand::Range(-jitter_max, jitter_max), cursor.y + Rand::Range(-jitter_max, jitter_max));
        }

        float angle = atan2f(delta_y, delta_x);
        float x_vel = cosf(angle) * 1.5f;
        overlay_x += x_vel;
        overlay_y += sinf(angle) * 1.5f;
        SetWindowPos(overlay, HWND_TOP, overlay_x - 32, overlay_y - 32, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);

        // Pasted from decomp lmao
        int x_dir = x_vel >= -0.06f ? x_vel > 0.06f : -1;
        if (last_x_dir != x_dir) {
            if (last_x_dir == -1) {
                anim_idx = 3 - (x_dir != 0);
            } else {
                if (last_x_dir) {
                    if (last_x_dir == 1) {
                        anim_idx = 1;
                        if (!x_dir)
                            anim_idx = 4;
                    }
                } else {
                    anim_idx = (x_dir != -1) + 1;
                }
            }
            anim_frame = 0;
            last_x_dir = x_dir;
        }

        int sprite_idx;
        if (anim_frame++ >= 17)
            sprite_idx = ANIM_TABLE[anim_idx][4 + (anim_frame - 17) / 5 % 4];
        else
            sprite_idx = ANIM_TABLE[anim_idx][min(anim_frame / 4, 3)];

        if (sprite_idx != last_sprite_idx) {
            HDC dc = CreateCompatibleDC(NULL);
            SelectObject(dc, Assets::BlueFairy);
            SIZE size = {
                .cx = 64,
                .cy = 64,
            };
            POINT pos = {
                .x = sprite_idx * 64,
                .y = 0,
            };
            BLENDFUNCTION blend = {
                .BlendOp = AC_SRC_OVER,
                .BlendFlags = 0,
                .SourceConstantAlpha = 255,
                .AlphaFormat = AC_SRC_ALPHA,
            };
            UpdateLayeredWindow(overlay, NULL, NULL, &size, dc, &pos, 0, &blend, ULW_ALPHA);
            DeleteDC(dc);
            last_sprite_idx = sprite_idx;
        }

        MSG msg;
        while (PeekMessageA(&msg, overlay, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessageA(&msg);
        }

        return --timer > 0;
    }
};

// This one was interesting on a technical level, but isn't very fun to play
//REGISTER_EFFECT(FollowerMouse);
