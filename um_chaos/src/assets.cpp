#include <d3d9.h>
#include <stdint.h>
#include "th18.hpp"
#include "assets.hpp"

extern "C" {
    __declspec(dllimport) WINAPI HRESULT D3DXCreateTextureFromFileInMemory(
        LPDIRECT3DDEVICE9 pDevice, LPCVOID pSrcData, UINT SrcDataSize, LPDIRECT3DTEXTURE9 *ppTexture);
}

IDirect3DTexture9* Assets::LeSanae = nullptr;
IDirect3DTexture9* Assets::Flashlight = nullptr;
std::vector<const char*> Assets::StageAttacks;
std::vector<const char*> Assets::BossAttacks;

IDirect3DTexture9* load_img(const char* filename) {
    IDirect3DTexture9* ret = NULL;
    uint32_t img_size = 0;
    void* img = GameUtil::LoadFile(filename, &img_size, 0);
    D3DXCreateTextureFromFileInMemory(Main::Instance.d3d9_device, img, img_size, &ret);
    return ret;
}

void Assets::Load() {
    Assets::LeSanae = load_img("lesanae.png");
    Assets::Flashlight = load_img("flashlight.png");
}
