#version 130
//varying vec2 Texcoord;

void main( void )
{
    gl_Position = ftransform();
    //Texcoord    = gl_MultiTexCoord0.xy;
    gl_TexCoord[0] = gl_MultiTexCoord0;
    
}