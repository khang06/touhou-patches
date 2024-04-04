#include <d3d9.h>
#include <stdint.h>
#include "th18.hpp"
#include "assets.hpp"

extern "C" {
    __declspec(dllimport) WINAPI HRESULT D3DXCreateTextureFromFileInMemory(
        LPDIRECT3DDEVICE9 pDevice, LPCVOID pSrcData, UINT SrcDataSize, LPDIRECT3DTEXTURE9 *ppTexture);
}

IDirect3DTexture9* Assets::LeSanae = nullptr;

void Assets::Load() {
    uint32_t lesanae_size = 0;
    void* lesanae_img = GameUtil::LoadFile("lesanae.png", &lesanae_size, 0);
    D3DXCreateTextureFromFileInMemory(Main::Instance.d3d9_device, lesanae_img, lesanae_size, &Assets::LeSanae);
}
