struct VS_Input {
    float2 pos : POSITION;
    float2 uv : TEXCOORD;
};

struct VS_Output {
    float4 pos : SV_Position;
    float2 uv : TEXCOORD;
};

VS_Output main(VS_Input vin) {
    VS_Output vout;
    vout.pos = float4(vin.pos, 0.0f, 1.0f);
    vout.uv = vin.uv;
    return vout;
}
