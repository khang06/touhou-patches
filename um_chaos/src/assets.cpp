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

void Assets::Load() {
    Assets::LeSanae = load_img("lesanae.png");
    Assets::LeSanaeIcon = load_icon("lesanae.png");
    Assets::Flashlight = load_img("flashlight.png");
    Assets::GameIcon = LoadIconA((HINSTANCE)0x400000, "IDI_ICON3");
}
