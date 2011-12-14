#version 130
///////////////////////////////
// fg uniform
///////////////////////////////
uniform sampler2D ColorTexture;

//texture coord
in vec2 Texcoord;
///////////////////////////////
// fg uniform
///////////////////////////////
out vec4 fragColour;
void main(void)
{
	

   vec4 baseColor = texture2D( ColorTexture, Texcoord );
   
   fragColour = vec4(1.0,1.0,1.0,1.0);

   /**
   if(baseColor.a < 0.15)
      //discard;
	  
   else{
       vec4 texColor = baseColor;// + phongModel;//mix(color0, color1, color0.a*-1);
       fragColour = texColor;// texture2D( ColorTexture, Texcoord );  
   }
   */
}