#version 130
//texture coord
out vec2 Texcoord;
out vec3 vp;
void main(void)
{
   Texcoord    = gl_MultiTexCoord0.xy;
   vp = gl_Vertex.xyz;


    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}