#include <d3d9.h>
#include "assets.hpp"
#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class LeSanae : public Effect {
public:
    static bool Enabled;
    static bool CopyingPlayfield;

    size_t timer = Rand::Range(10 * 60, 30 * 60);

    LeSanae() {
        Enabled = true;
    }

    virtual ~LeSanae() {
        Enabled = false;
    }

    virtual bool Update() {
        return --timer != 0;
    }
};
DEFINE_EFFECT(LeSanae);

bool LeSanae::Enabled = false;
bool LeSanae::CopyingPlayfield = false;

extern "C" __thiscall int lesanae_draw_sprite_playfield_hook(AnmManager* self, AnmVM* anm) {
    LeSanae::CopyingPlayfield = true;
    auto ret = self->DrawSprite(anm);
    LeSanae::CopyingPlayfield = false;
    return ret;
}

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
    return self->AddVertices(vertices);
}

extern "C" __stdcall HRESULT lesanae_set_texture_hook(IDirect3DDevice9* self, DWORD stage, IDirect3DBaseTexture9* tex) {
    return self->SetTexture(0, (!LeSanae::Enabled || LeSanae::CopyingPlayfield) ? tex : Assets::LeSanae);
}
