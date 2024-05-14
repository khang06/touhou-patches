#include "assets.hpp"
#include "effect.hpp"
#include "util.hpp"

typedef struct {
    float x, y, z;
} MinimalVertex;

// https://github.com/Matsilagi/RSRetroArch/blob/main/Shaders/JPEG.fx
// https://www.shadertoy.com/view/llfyz4
class JPEG : public Effect {
public:
    static float strength;
    static bool fade_in_finished;
    int timer = Rand::RangeEffectTime(10, 2 * 60);
    CodePatches patches;

    JPEG() {
        strength = 0.0f;
        fade_in_finished = false;
        patches.AddJmp(0x455D39, (void*)&backbuffer_switch_hook);
    }

    static int backbuffer_switch_hook() {
        constexpr uint16_t indices[6] = {
            0, 1, 2,
            1, 2, 3,
        };
        constexpr MinimalVertex vertices[4] = {
            {-1, 1,  0},
            {1,  1,  0},
            {-1, -1, 0},
            {1,  -1, 0},
        };

        auto d3d9_dev = Main::Instance.d3d9_device;
        constexpr D3DMATRIX identity = {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
        D3DMATRIX orig_world;
        D3DMATRIX orig_view;
        D3DMATRIX orig_proj;
        D3DMATRIX orig_tex0;
        d3d9_dev->GetTransform(D3DTS_WORLD, &orig_world);
        d3d9_dev->SetTransform(D3DTS_WORLD, &identity);
        d3d9_dev->GetTransform(D3DTS_VIEW, &orig_view);
        d3d9_dev->SetTransform(D3DTS_VIEW, &identity);
        d3d9_dev->GetTransform(D3DTS_PROJECTION, &orig_proj);
        d3d9_dev->SetTransform(D3DTS_PROJECTION, &identity);
        d3d9_dev->GetTransform(D3DTS_TEXTURE0, &orig_tex0);
        d3d9_dev->SetTransform(D3DTS_TEXTURE0, &identity);

        if (!fade_in_finished) {
            strength = min(strength + 0.01f, 2.0f);
            if (strength == 2.0f)
                fade_in_finished = true;
        }
        float constant[8] = {
            1.0f / Window::Instance.backbuffer_width, 1.0f / Window::Instance.backbuffer_height, 0.0f, 0.0f,
            strength, 0.0f, 0.0f, 0.0f,
        };
        d3d9_dev->SetPixelShaderConstantF(0, constant, 2);

        d3d9_dev->SetRenderTarget(0, Assets::JPEGPass1RT);
        d3d9_dev->SetPixelShader(Assets::JPEGPass1PS);
        d3d9_dev->SetFVF(D3DFVF_XYZ);
        d3d9_dev->SetTexture(0, Main::Instance.text_anm->entries[3].d3d9_tex);
        d3d9_dev->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000, 1.0f, 0);
        d3d9_dev->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, 6, 2, indices, D3DFMT_INDEX16, vertices, sizeof(MinimalVertex));

        d3d9_dev->SetRenderTarget(0, Main::Instance.game_render_target);
        d3d9_dev->SetPixelShader(Assets::JPEGPass2PS);
        d3d9_dev->SetTexture(0, Assets::JPEGPass1Tex);
        d3d9_dev->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000, 1.0f, 0);
        d3d9_dev->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, 6, 2, indices, D3DFMT_INDEX16, vertices, sizeof(MinimalVertex));

        d3d9_dev->SetRenderTarget(0, Main::Instance.backbuffer);
        d3d9_dev->SetTransform(D3DTS_WORLD, &orig_world);
        d3d9_dev->SetTransform(D3DTS_VIEW, &orig_view);
        d3d9_dev->SetTransform(D3DTS_PROJECTION, &orig_proj);
        d3d9_dev->SetTransform(D3DTS_TEXTURE0, &orig_tex0);
        d3d9_dev->SetPixelShader(NULL);
        return 1;
    }

    virtual bool Update() {
        if (timer <= 0) {
            strength = max(0.0f, strength - 0.01f);
            if (strength == 0.0f)
                return false;
        } else {
            timer--;
        }
        return true;
    }
};
REGISTER_EFFECT(JPEG);

float JPEG::strength = 0.0f;
bool JPEG::fade_in_finished = false;
