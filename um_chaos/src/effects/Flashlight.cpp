#include "assets.hpp"
#include "effect.hpp"
#include "th18.hpp"
#include "util.hpp"

class FirstPerson {
public:
    static size_t ID;
};

// Also known as "Not Mystia"
// This is (not really) a direct port from osu!
// See https://github.com/ppy/osu/blob/master/osu.Game.Rulesets.Osu/Mods/OsuModFlashlight.cs
class Flashlight : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    D3DVECTOR pos = Player::Instance->pos_float;
    float radius = 6400.0f;
    float target_radius = 750.0f;
    int dim = 0;
    int target_dim = 0;

    virtual bool Update() {
        if (radius > target_radius)
            radius = std::max(radius - 160.0f, target_radius);
        else if (radius < target_radius)
            radius = std::min(radius + 160.0f, target_radius);

        //pos.x += (Player::Instance->pos_float.x - pos.x) * 0.25848765432f;
        //pos.y += (Player::Instance->pos_float.y - pos.y) * 0.25848765432f;
        if (Effect::Infos[FirstPerson::ID].enabled) {
            pos.x = 0.0f;
            pos.y = 224.0f; 
        } else {
            pos = Player::Instance->pos_float;
        }

        if (timer < 30)
            target_radius = 6400.0f;

        bool focused = (Input::Cur & INPUT_FOCUS) != 0;
        target_dim = focused ? 205 : 0;

        return --timer > 0;
    }

    virtual void Draw() {
        static constexpr uint16_t indices[12] = {
            0, 1, 2,
            1, 2, 3,

            4, 5, 6,
            5, 6, 7,
        };
        static ZunVertex vertices[8] = {
            {0, 0, 0, 1, 0xFF000000, 0, 0},
            {0, 0, 0, 1, 0xFF000000, 1, 0},
            {0, 0, 0, 1, 0xFF000000, 0, 1},
            {0, 0, 0, 1, 0xFF000000, 1, 1},

            {0,    0,   0, 1, 0xCD000000, 0,     0},
            {1280, 0,   0, 1, 0xCD000000, 0.001, 0},
            {0,    960, 0, 1, 0xCD000000, 0,     0.001},
            {1280, 960, 0, 1, 0xCD000000, 0.001, 0.001},
        };

        const float scaled_radius = radius * Window::Instance.game_scale;
        float px = PlayfieldToGameX(pos.x * Main::Instance.screen_anm4->scale_x + 192.0f);
        float py = PlayfieldToGameY((pos.y - 224.0f) * Main::Instance.screen_anm4->scale_y + 224.0f);
        vertices[0].x = px - scaled_radius;
        vertices[0].y = py - scaled_radius;
        vertices[1].x = px + scaled_radius;
        vertices[1].y = py - scaled_radius;
        vertices[2].x = px - scaled_radius;
        vertices[2].y = py + scaled_radius;
        vertices[3].x = px + scaled_radius;
        vertices[3].y = py + scaled_radius;

        if (dim > target_dim)
            dim = std::max(dim - 32, target_dim);
        else if (dim < target_dim)
            dim = std::min(dim + 32, target_dim);

        DWORD dim_col = dim << 24;
        for (int i = 4; i < 8; i++)
            vertices[i].color = dim_col;

        auto d3d9_dev = Main::Instance.d3d9_device;
        DWORD z_enable;
        IDirect3DBaseTexture9* prev_tex = nullptr;
        AnmManager::Instance->FlushSprites();
        d3d9_dev->GetRenderState(D3DRS_ZENABLE, &z_enable);
        d3d9_dev->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
        d3d9_dev->GetTexture(0, &prev_tex);
        d3d9_dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
        d3d9_dev->SetTexture(0, Assets::Flashlight);
        d3d9_dev->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, 12, 4, indices, D3DFMT_INDEX16, vertices, sizeof(ZunVertex));
        d3d9_dev->SetTexture(0, prev_tex);
        d3d9_dev->SetRenderState(D3DRS_ZENABLE, z_enable);
    }
};
REGISTER_EFFECT(Flashlight);
