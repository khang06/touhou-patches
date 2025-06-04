// clang++ -m32 -msse -msse2 -mfpmath=sse -O2 -c mouse_controls.cpp -o mouse_controls.obj

#define NOMINMAX
#include <Windows.h>
#include <algorithm>
#include <d3d9.h>

extern "C" HWND g_window;
extern "C" uint32_t g_window_flags;

struct Player {
    char gap0[2172];
    D3DVECTOR pos_float;
    int pos_x_subpixel;
    int pos_y_subpixel;
    char gap890[120];
    D3DVECTOR death_pos;
    char gap914[20];
    int death_state;
    char gap92C[24];
    char death_timer[0x14];
    char gap958[33736];
    int field_8D20;

    static int __stdcall CalcMove(Player* self);
};

inline float WindowScale() {
    uint32_t mode = (g_window_flags >> 2) & 3;
    switch (mode) {
        case 2:
            return 1.5f;
        case 3:
            return 2.0f;
        default:
            return 1.0f;
    }
}
inline float GameToPlayfieldX(float x) {
    return x - 32.0f;
}
inline float GameToPlayfieldY(float y) {
    return y - 16.0f;
}

extern "C" int __stdcall calc_move_hook(Player* self) {
    Player::CalcMove(self);

    // Don't try to use the mouse position if the window got minimized
    if (IsIconic(g_window))
        return 0;

    POINT p;
    float scale = WindowScale(); // Yes this could just be saved at boot
    GetCursorPos(&p);
    ScreenToClient(g_window, &p);
    float px = std::max(-184.0f, std::min(GameToPlayfieldX(p.x / scale) - 192.0f, 184.0f));
    float py = std::max(32.0f, std::min(GameToPlayfieldY(p.y / scale), 432.0f));

    self->pos_float.x = px;
    self->pos_x_subpixel = px * 128.0f;
    self->pos_float.y = py;
    self->pos_y_subpixel = py * 128.0f;

    return 0;
}
