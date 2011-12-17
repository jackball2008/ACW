#version 130
///////////////////////////////
// uniforms
///////////////////////////////
uniform sampler2D ColorTexture;

in vec3 normal;
in vec3 position;   
in vec2 texture_coordinate;
in vec4 vpointColour;

out vec4 fragColour;

void main( void )
{

    // get the colour from the texture
   vec4 textureCoefficient = texture2D(ColorTexture, gl_PointCoord.st); // use the colour from the texture instead of white
   
   textureCoefficient *= vpointColour;
   
   fragColour = textureCoefficient;
   
   if (fragColour.a < 0.5)
   {
      discard;
   }
    
}