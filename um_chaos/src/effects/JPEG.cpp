#include "assets.hpp"
#include "effect.hpp"
#include "util.hpp"

typedef struct {
    float x, y, z;
} MinimalVertex;

#define CHECK(x) (some_error_happened |= FAILED(x))

// https://github.com/Matsilagi/RSRetroArch/blob/main/Shaders/JPEG.fx
// https://www.shadertoy.com/view/llfyz4
class JPEG : public Effect {
public:
    static bool some_error_happened;
    static float strength;
    static bool fade_in_finished;
    int timer = Rand::RangeEffectTime(10, 60);
    CodePatches patches;

    JPEG() {
        strength = 0.0f;
        fade_in_finished = false;
        patches.AddJmp(0x455D39, (void*)&backbuffer_switch_hook);
    }

    static int backbuffer_switch_hook() {
        static constexpr uint16_t indices[6] = {
            0, 1, 2,
            1, 2, 3,
        };
        static constexpr MinimalVertex vertices[4] = {
            {-1, 1,  0},
            {1,  1,  0},
            {-1, -1, 0},
            {1,  -1, 0},
        };

        auto d3d9_dev = Main::Instance.d3d9_device;
        static constexpr D3DMATRIX identity = {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
        D3DMATRIX orig_world;
        D3DMATRIX orig_view;
        D3DMATRIX orig_proj;
        D3DMATRIX orig_tex0;
        CHECK(d3d9_dev->GetTransform(D3DTS_WORLD, &orig_world));
        CHECK(d3d9_dev->SetTransform(D3DTS_WORLD, &identity));
        CHECK(d3d9_dev->GetTransform(D3DTS_VIEW, &orig_view));
        CHECK(d3d9_dev->SetTransform(D3DTS_VIEW, &identity));
        CHECK(d3d9_dev->GetTransform(D3DTS_PROJECTION, &orig_proj));
        CHECK(d3d9_dev->SetTransform(D3DTS_PROJECTION, &identity));
        CHECK(d3d9_dev->GetTransform(D3DTS_TEXTURE0, &orig_tex0));
        CHECK(d3d9_dev->SetTransform(D3DTS_TEXTURE0, &identity));

        if (!fade_in_finished) {
            strength = std::min(strength + 0.01f, 1.5f);
            if (strength == 1.5f)
                fade_in_finished = true;
        }
        float constant[12] = {
            1.0f / 640.0f, 1.0f / 480.0f, 0.0f, 0.0f,
            strength, 0.0f, 0.0f, 0.0f,
            1.0f / (Window::Instance.backbuffer_width / 640.0f), 0.0f, 0.0f, 0.0f,
        };
        CHECK(d3d9_dev->SetPixelShaderConstantF(0, constant, 3));

        CHECK(d3d9_dev->SetRenderTarget(0, Assets::JPEGPass1RT));
        CHECK(d3d9_dev->SetPixelShader(Assets::JPEGPass1PS));
        CHECK(d3d9_dev->SetFVF(D3DFVF_XYZ));
        CHECK(d3d9_dev->SetTexture(0, Main::Instance.text_anm->entries[3].d3d9_tex));
        CHECK(d3d9_dev->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000, 1.0f, 0));
        CHECK(d3d9_dev->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, 6, 2, indices, D3DFMT_INDEX16, vertices, sizeof(MinimalVertex)));

        CHECK(d3d9_dev->SetRenderTarget(0, Main::Instance.game_render_target));
        CHECK(d3d9_dev->SetPixelShader(Assets::JPEGPass2PS));
        CHECK(d3d9_dev->SetTexture(0, Assets::JPEGPass1Tex));
        CHECK(d3d9_dev->Clear(0, NULL, D3DCLEAR_TARGET, 0xFF000000, 1.0f, 0));
        CHECK(d3d9_dev->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, 6, 2, indices, D3DFMT_INDEX16, vertices, sizeof(MinimalVertex)));

        CHECK(d3d9_dev->SetRenderTarget(0, Main::Instance.backbuffer));
        CHECK(d3d9_dev->SetTransform(D3DTS_WORLD, &orig_world));
        CHECK(d3d9_dev->SetTransform(D3DTS_VIEW, &orig_view));
        CHECK(d3d9_dev->SetTransform(D3DTS_PROJECTION, &orig_proj));
        CHECK(d3d9_dev->SetTransform(D3DTS_TEXTURE0, &orig_tex0));
        CHECK(d3d9_dev->SetPixelShader(NULL));
        return 1;
    }

    virtual bool Update() {
        if (timer <= 0) {
            strength = std::max(0.0f, strength - 0.01f);
            if (strength == 0.0f)
                return false;
        } else {
            timer--;
        }
        return !some_error_happened;
    }
    
    static bool Allowed() {
        return !some_error_happened;
    }
};
REGISTER_EFFECT(JPEG);

float JPEG::strength = 0.0f;
bool JPEG::fade_in_finished = false;
bool JPEG::some_error_happened = false;

