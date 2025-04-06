#pragma once

#include <d3d9.h>
#include <vector>

typedef struct {
    float x, y, z;
    float u, v;
    D3DCOLOR col;
} VoteVertex;

class Assets {
public:
    static void Load();

    static IDirect3DTexture9* LeSanae;
    static HICON LeSanaeIcon;
    static IDirect3DTexture9* Flashlight;
    static HICON GameIcon;
    static HBITMAP BlueFairy;
    static HBITMAP Kogasa;
    static IDirect3DTexture9* SubwaySurfers;

    static IDirect3DPixelShader9* JPEGPass1PS;
    static IDirect3DPixelShader9* JPEGPass2PS;
    static IDirect3DTexture9* JPEGPass1Tex;
    static IDirect3DSurface9* JPEGPass1RT;

    static IDirect3DVertexDeclaration9* VoteVertexDecl;
    static IDirect3DVertexShader9* VoteVS;
    static IDirect3DVertexBuffer9* VoteVB;
    static IDirect3DIndexBuffer9* VoteIB;
    
    static std::vector<const char*> StageAttacks;
    static std::vector<const char*> BossAttacks;
    
    static bool VotePieResetPending;
};
