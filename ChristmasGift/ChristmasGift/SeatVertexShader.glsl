#version 130
//texture coord
out vec2 Texcoord;

void main(void)
{
   Texcoord    = gl_MultiTexCoord0.xy;


    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}