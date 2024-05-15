#include <cstddef>
#include <d3d9.h>
#include <stdint.h>
#include "th18.hpp"
#include "assets.hpp"

extern "C" {
    __declspec(dllimport) WINAPI HRESULT D3DXCreateTextureFromFileInMemory(
        LPDIRECT3DDEVICE9 pDevice, LPCVOID pSrcData, UINT SrcDataSize, LPDIRECT3DTEXTURE9 *ppTexture);
}

IDirect3DTexture9* Assets::LeSanae = nullptr;
HICON Assets::LeSanaeIcon = NULL;
IDirect3DTexture9* Assets::Flashlight = nullptr;
HICON Assets::GameIcon = NULL;

IDirect3DPixelShader9* Assets::JPEGPass1PS = NULL;
IDirect3DPixelShader9* Assets::JPEGPass2PS = NULL;
IDirect3DTexture9* Assets::JPEGPass1Tex = NULL;
IDirect3DSurface9* Assets::JPEGPass1RT = NULL;

std::vector<const char*> Assets::StageAttacks;
std::vector<const char*> Assets::BossAttacks;

IDirect3DTexture9* load_img(const char* filename) {
    IDirect3DTexture9* ret = NULL;
    uint32_t img_size = 0;
    void* img = GameUtil::LoadFile(filename, &img_size, 0);
    D3DXCreateTextureFromFileInMemory(Main::Instance.d3d9_device, img, img_size, &ret);
    free(img);
    return ret;
}

HICON load_icon(const char* filename) {
    uint32_t ico_size = 0;
    void* ico = GameUtil::LoadFile(filename, &ico_size, 0);
    HICON ret = CreateIconFromResource((PBYTE)ico, ico_size, TRUE, 0x30000);
    free(ico);
    return ret;
}

// Not used atm but could be used later
void load_vs(const char* filename, IDirect3DVertexShader9** out) {
    uint32_t vs_size = 0;
    void* vs = GameUtil::LoadFile(filename, &vs_size, 0);
    Main::Instance.d3d9_device->CreateVertexShader((DWORD*)vs, out);
    free(vs);
}

void load_ps(const char* filename, IDirect3DPixelShader9** out) {
    uint32_t ps_size = 0;
    void* ps = GameUtil::LoadFile(filename, &ps_size, 0);
    Main::Instance.d3d9_device->CreatePixelShader((DWORD*)ps, out);
    free(ps);
}

// This needs to be separate because D3DPOOL_DEFAULT objects need to be manually released and recreated for device resets
extern "C" void load_default_pool_assets() {
    Main::Instance.d3d9_device->CreateTexture(
        Window::Instance.backbuffer_width, Window::Instance.backbuffer_height, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A32B32G32R32F, D3DPOOL_DEFAULT, &Assets::JPEGPass1Tex, NULL);
    Assets::JPEGPass1Tex->GetSurfaceLevel(0, &Assets::JPEGPass1RT);
}

extern "C" void unload_default_pool_assets() {
    if (Assets::JPEGPass1RT) {
        Assets::JPEGPass1RT->Release();
        Assets::JPEGPass1RT = NULL;
    }
    if (Assets::JPEGPass1Tex) {
        Assets::JPEGPass1Tex->Release();
        Assets::JPEGPass1Tex = NULL;
    }
}

void Assets::Load() {
    Assets::LeSanae = load_img("lesanae.png");
    Assets::LeSanaeIcon = load_icon("lesanae.png");
    Assets::Flashlight = load_img("flashlight.png");
    Assets::GameIcon = LoadIconA((HINSTANCE)0x400000, "IDI_ICON3");

    load_ps("jpeg1_ps.fxc", &Assets::JPEGPass1PS);
    load_ps("jpeg2_ps.fxc", &Assets::JPEGPass2PS);

    load_default_pool_assets();
}
