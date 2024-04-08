#pragma once

#include <d3d9.h>
#include <vector>

class Assets {
public:
    static void Load();

    static IDirect3DTexture9* LeSanae;
    static IDirect3DTexture9* Flashlight;
    static std::vector<const char*> StageAttacks;
    static std::vector<const char*> BossAttacks;
};
