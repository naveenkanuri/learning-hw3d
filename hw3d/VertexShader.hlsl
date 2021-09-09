struct VSOUT
{
    float3 color : COLOR;
    float4 pos : SV_Position;
};

VSOUT main( float2 pos : POSITION, float3 color: COLOR )
{
    VSOUT vso;
    vso.pos = float4(pos.x, pos.y, 0.0f, 1.0f);
    vso.color = color;
    return vso;
}