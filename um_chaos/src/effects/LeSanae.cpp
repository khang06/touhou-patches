#include <d3d9.h>
#include "assets.hpp"
#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class LeSanae : public Effect {
public:
    static bool Enabled;
    static bool CopyingPlayfield;

    int timer = Rand::RangeFrames(10, 2 * 60);

    LeSanae() {
        Enabled = true;

        if (Assets::LeSanaeIcon) {
            SendMessageA(Main::Window, WM_SETICON, ICON_SMALL, (LPARAM)Assets::LeSanaeIcon);
            SendMessageA(Main::Window, WM_SETICON, ICON_BIG, (LPARAM)Assets::LeSanaeIcon);
        }
    }

    virtual ~LeSanae() {
        Enabled = false;

        if (Assets::GameIcon) {
            SendMessageA(Main::Window, WM_SETICON, ICON_SMALL, (LPARAM)Assets::GameIcon);
            SendMessageA(Main::Window, WM_SETICON, ICON_BIG, (LPARAM)Assets::GameIcon);
        }
    }

    virtual bool Update() {
        return --timer > 0;
    }
};
REGISTER_EFFECT(LeSanae);

bool LeSanae::Enabled = false;
bool LeSanae::CopyingPlayfield = false;

extern "C" __thiscall int lesanae_draw_sprite_playfield_hook(AnmManager* self, AnmVM* anm) {
    LeSanae::CopyingPlayfield = true;
    auto ret = self->DrawSprite(anm);
    LeSanae::CopyingPlayfield = false;
    return ret;
}

// Really stupid hack for title screen because I'm lazy
int32_t g_title_screen_shake = 0;

extern "C" __thiscall int lesanae_add_vertices_hook(AnmManager* self, ZunVertex* vertices) {
    if (LeSanae::Enabled && !LeSanae::CopyingPlayfield) {
        vertices[0].u = 0.0f;
        vertices[0].v = 0.0f;
        vertices[1].u = 1.0f;
        vertices[1].v = 0.0f;
        vertices[2].u = 0.0f;
        vertices[2].v = 1.0f;
        vertices[3].u = 1.0f;
        vertices[3].v = 1.0f;
    }
    if (g_title_screen_shake) {
        for (int i = 0; i < 4; i++) {
            vertices[i].x += Rand::Range(-g_title_screen_shake, g_title_screen_shake) * Window::Instance.game_scale;
            vertices[i].y += Rand::Range(-g_title_screen_shake, g_title_screen_shake) * Window::Instance.game_scale;
        }
    }
    return self->AddVertices(vertices);
}

extern "C" __stdcall HRESULT lesanae_set_texture_hook(IDirect3DDevice9* self, DWORD stage, IDirect3DBaseTexture9* tex) {
    return self->SetTexture(0, (!LeSanae::Enabled || LeSanae::CopyingPlayfield) ? tex : Assets::LeSanae);
}
