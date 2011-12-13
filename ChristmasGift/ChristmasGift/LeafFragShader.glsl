#version 130

///////////////////////////////
// variables
///////////////////////////////
in vec3 normal;
in vec3 position;   
in vec3 lightVector;
in vec3 eyeVector; 
in vec4 colour;

///////////////////////////////
// fg uniform
///////////////////////////////
uniform sampler2D ColorTexture;
uniform sampler2D NormalMapTexture;
in vec2 Texcoord;
///////////////////////////////
// fg uniform
///////////////////////////////
out vec4 fragColour;
void main( void )
{
     vec4 texColor;
    vec4 color0 = texture2D( ColorTexture, Texcoord );  
    vec4 color1 =  texture2D( NormalMapTexture, Texcoord );
    
    
    vec4 baseColour = colour;
      
   vec4 ambientIntensity   = vec4(0.0,0.0,0.0,1.0);
   vec4 diffuseIntensity   = vec4(0.5,0.5,0.5,1.0);
   vec4 specularIntensity  = vec4(0.7,0.7,0.7,1.0);

   float ambientCoefficient = 0.0;
   float diffuseCoefficient = 0.95;
   float specularCoefficient = 1.0;
   float specularShininess = 20.0;
   
   vec3 reflectionVector;
   
   reflectionVector = normalize(-reflect(lightVector,normal)); 
  
   //calculate Ambient Term:  
   vec4 ambientLightIntensity = ambientIntensity * ambientCoefficient * baseColour;    

   //calculate Diffuse Term:  
   vec4 diffuseLightIntensity = diffuseIntensity * diffuseCoefficient * max(dot(normal,lightVector), 0.0) * baseColour;   
   
   // calculate Specular Term:
   vec4 specularLightIntensity = specularIntensity * specularCoefficient * pow(max(dot(reflectionVector,eyeVector),0.0),specularShininess) * baseColour;   
  
   // write Total Color: 
   vec4 phongModel =  ambientLightIntensity + diffuseLightIntensity + specularLightIntensity;
   
   
    if(color0.a < 0.15)
      discard;
   else{
       texColor = color0 + phongModel;//mix(color0, color1, color0.a*-1);
       fragColour = texColor;// texture2D( ColorTexture, Texcoord );  
   }
       
}