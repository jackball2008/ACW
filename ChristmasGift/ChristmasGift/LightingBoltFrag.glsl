uniform sampler2D Texture1;

varying vec2 Texcoord;

void main( void )
{
      vec4 c = texture2D( Texture1, Texcoord );
      
      if( c.r <= 0.05 || c.g <= 0.05 ||c.a<0.15)
      discard;
      else
      gl_FragColor = c;
    
}