#pragma once

#include <d3d9.h>
#include <vector>

class Assets {
public:
    static void Load();

    static IDirect3DTexture9* LeSanae;
    static HICON LeSanaeIcon;
    static IDirect3DTexture9* Flashlight;
    static HICON GameIcon;

    static IDirect3DPixelShader9* JPEGPass1PS;
    static IDirect3DPixelShader9* JPEGPass2PS;
    static IDirect3DTexture9* JPEGPass1Tex;
    static IDirect3DSurface9* JPEGPass1RT;

    static void* StickyKeys;
    
    static std::vector<const char*> StageAttacks;
    static std::vector<const char*> BossAttacks;
};
