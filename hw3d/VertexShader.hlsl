struct VSOUT
{
    float3 color : COLOR;
    float4 pos : SV_Position;
};

cbuffer CBuf
{
    row_major matrix transform;
};

VSOUT main( float2 pos : POSITION, float3 color: COLOR )
{
    VSOUT vso;
    vso.pos = mul(float4(pos.x, pos.y, 0.0f, 1.0f), transform);
    vso.color = color;
    return vso;
}