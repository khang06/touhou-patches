#include "assets.hpp"
#include "effect.hpp"
#include "util.hpp"

class SubwaySurfers : public Effect {
public:
    int timer = Rand::RangeEffectTime(10, 60);
    int frame = 0;

    virtual bool Update() {
        frame++;
        return --timer > 0;
    }

    virtual void Draw() {
        float u = ((frame >> 2) & 31) * (1.0f / 32.0f);
        float v = ((frame >> 7) & 31) * (1.0f / 32.0f);

        static constexpr uint16_t indices[6] = {
            0, 1, 2,
            1, 2, 3,
        };
        ZunVertex vertices[4] = {
            {836,  28,  0, 1, 0xFFFFFFFF, u, v},
            {1268, 28,  0, 1, 0xFFFFFFFF, u + (1.0f / 32.0f), v},
            {836,  460, 0, 1, 0xFFFFFFFF, u, v + (1.0f / 32.0f)},
            {1268, 460, 0, 1, 0xFFFFFFFF, u + (1.0f / 32.0f), v + (1.0f / 32.0f)},
        };

        auto d3d9_dev = Main::Instance.d3d9_device;
        DWORD z_enable;
        DWORD mag_filter;
        IDirect3DBaseTexture9* prev_tex = nullptr;
        AnmManager::Instance->FlushSprites();
        d3d9_dev->GetRenderState(D3DRS_ZENABLE, &z_enable);
        d3d9_dev->SetRenderState(D3DRS_ZENABLE, D3DZB_FALSE);
        d3d9_dev->GetSamplerState(0, D3DSAMP_MAGFILTER, &mag_filter);
        d3d9_dev->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
        d3d9_dev->GetTexture(0, &prev_tex);
        d3d9_dev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1);
        d3d9_dev->SetTexture(0, Assets::SubwaySurfers);
        d3d9_dev->DrawIndexedPrimitiveUP(D3DPT_TRIANGLELIST, 0, 6, 2, indices, D3DFMT_INDEX16, vertices, sizeof(ZunVertex));
        d3d9_dev->SetTexture(0, prev_tex);
        d3d9_dev->SetRenderState(D3DRS_ZENABLE, z_enable);
        d3d9_dev->SetSamplerState(0, D3DSAMP_MAGFILTER, mag_filter);
    }
};
REGISTER_EFFECT(SubwaySurfers);
