cbuffer Constants {
    matrix proj;
    float3 misc; // sin, cos, y offset
};

struct VS_Input {
    float3 pos : POSITION;
    float2 uv : TEXCOORD;
    float4 col : COLOR;
};

struct VS_Output {
    float4 pos : SV_Position;
    float2 uv : TEXCOORD;
    float4 col : COLOR;
};

VS_Output main(VS_Input vin) {
    const float3 center = float3(578.0f, 451.0f + misc.z, 0.0f);
    vin.pos -= center - float3(0.0f, misc.z, 0.0f);
    float3 new_pos = (vin.pos.z == 0.0f ? float3(vin.pos.x * misc.y - vin.pos.y * misc.x, vin.pos.x * misc.x + vin.pos.y * misc.y, 0.0f) : vin.pos) + center;

    VS_Output vout;
    vout.pos = mul(float4(new_pos, 1.0f), proj) + float4(1.0f / 1280.0f, 1.0f / 960.0f, 0.0f, 0.0f);
    vout.uv = vin.uv;
    vout.col = vin.col;
    return vout;
}
