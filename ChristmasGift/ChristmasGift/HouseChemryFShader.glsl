#version 130
uniform sampler2D ColorTexture;

//varying vec2 Texcoord;

void main( void )
{
    //gl_FragColor = texture2D( ColorTexture, Texcoord );
    gl_FragColor = texture2D( ColorTexture, gl_TexCoord[0].st * 5 );
    
}