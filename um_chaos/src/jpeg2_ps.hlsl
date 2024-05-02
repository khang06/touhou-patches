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
};

#define pi 3.14159265358979323846
#define a(x) (x!=0.?1.:1./sqrt(2.))

float3 toRGB(float3 ybr) {
    return mul( float3x3(
        1., 0.00,     1.402,
        1.,-0.344136,-0.714136,
        1., 1.772,    0.00), ybr-float3(0,.5,.5));
}

float3 inp(float2 coord){
    //return tex2Dfetch(input_tex, float4(int2(coord.xy),0,0)).xyz;
    coord += float2(0.5f, 0.5f);
    return tex2Dlod(input_tex, float4(coord.xy * inv_resolution, 0, 0)).xyz;
}

float3 IDCT8x8(float2 coord, float2 xy ) {
    float3 res = float3(0.0,0.0,0.0);
    for(float u = 0.; u < 8.0; u++){
        for(float v = 0.; v < 8.0; v++){
            res += inp(coord + float2(u,v)) *
                a(u) * a(v) *
                cos((2.*xy.x+1.)*u*pi/16.) *
                cos((2.*xy.y+1.)*v*pi/16.);
        }
    }
    return res * .25;
}


float4 main(float2 txcoord : TEXCOORD, float2 pos : VPOS) : SV_TARGET {
    float2 texcoord = pos;
    float2 uv = floor(texcoord-8.0*floor(texcoord/8.0));
    return float4(toRGB(IDCT8x8(8.*floor(texcoord/8.),uv)/256.+.5), 1.0f);
}
