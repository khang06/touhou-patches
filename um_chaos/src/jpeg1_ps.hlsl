sampler2D input_tex : register(s0) =
sampler_state 
{
    MinFilter = POINT;
    MagFilter = POINT;
    MipFilter = POINT;
};

cbuffer cbPerFrame : register(c0)
{
    float2 inv_resolution : register(c0);
    float strength : register(c1);
    float texcoord_scale : register(c2);
};

#define pi 3.14159265358979323846
#define a(x) (x!=0.?1.:1./sqrt(2.))

float3 toYCbCr(float3 rgb) {
    float3 RGB2Y =  float3(0.299, 0.587, 0.114);
    float3 RGB2Cb = float3(-0.169, -0.331, 0.500);
    float3 RGB2Cr = float3(0.500, -0.419, -0.081);
    float3 newmat = float3(dot(rgb, RGB2Y), dot(rgb, RGB2Cb), dot(rgb, RGB2Cr));
    float3 addit = float3(0.0,0.5,0.5);
    return newmat + addit;
}

float3 pre(float2 coord) {
    coord += float2(0.5f, 0.5f);
    return floor(256.0*(toYCbCr(tex2Dlod(input_tex, float4(coord * inv_resolution, 0, 0)).xyz) - .5));
}

float3 DCT8x8( float2 coord, float2 uv ) {
    float3 res = float3(0,0,0);
    for(float x = 0.; x < 8.; x++){
        for(float y = 0.; y < 8.; y++){
            res += pre(coord + float2(x,y)) *
                cos((2.*x+1.)*uv.x*pi/16.) *
                cos((2.*y+1.)*uv.y*pi/16.);
        }
    }
    return res * .25 * a(uv.x) * a(uv.y);
}

float4 main(float2 txcoord : TEXCOORD, float2 pos : VPOS) : SV_TARGET {
    float2 texcoord = pos;
    float2 uv = floor(texcoord-8.0*floor(texcoord/8.0));
    int CombmA, mA[64] = {  16,  11,  10,  16,  24,  40,  51,  61,
                12,  12,  14,  19,  26,  58,  60,  55,
                14,  13,  16,  24,  40,  57,  69,  56,
                14,  17,  22,  29,  51,  87,  80,  62,
                18,  22,  37,  56,  68, 109, 103,  77,
                24,  35,  55,  64,  81, 104, 113,  92,
                49,  64,  78,  87, 103, 121, 120, 101,
                72,  92,  95,  98, 112, 100, 103,  99
              };
    //uv range needs to be set to range of array. from lowest number to max value.
    float q = (1.0+strength*20.0)*float(CombmA = mA[int(uv.x+uv.y*8.)]);
    return float4((floor(.5+DCT8x8(8.*floor(texcoord/8.0),uv)/q))*q, 1.0f);
    //return float4(DCT8x8(8.*floor(texcoord/8.0),uv), 1.0f);
}
