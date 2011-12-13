#version 130
///////////////////////////////
// uniforms
///////////////////////////////
uniform sampler2D ColorTexture;
uniform sampler2D NormalMapTexture;

 
uniform bool applyTexture;
uniform bool applyNormalMap;


///////////////////////////////
// variables
///////////////////////////////
in vec3 normal;
in vec3 position;   
in vec3 lightVector;
in vec3 eyeVector; 
in vec2 texture_coordinate;

in vec4 colour;

out vec4 fragColour;


void main()
{   
   vec4 baseColour = colour;

   normalize(lightVector);
   normalize(eyeVector);
   // get the colour from the texture
   vec4 textureCoefficient = vec4(1.0,1.0,1.0,1.0); // set colour to white
   if (applyTexture)
   {
      textureCoefficient = texture2D(ColorTexture, texture_coordinate); // use the colour from the texture instead of white
   }
   
   vec4 fragmentColour = vec4(0.0,0.0,0.0,1.0); // initialise fragment(pixel) colour to black
      
   vec4 ambientIntensity   = vec4(0.0,0.0,0.0,1.0) ;//* baseColour;
   vec4 diffuseIntensity   = vec4(1.0,1.0,1.0,1.0) + baseColour;
   vec4 specularIntensity  = vec4(1.0,1.0,1.0,1.0) + baseColour;

   float ambientCoefficient = 0.0;
   float diffuseCoefficient = 0.95;
   float specularCoefficient = 1.0;
   float specularShininess = 1.0;
   
   vec3 normalVector = normal;
   
   if(applyNormalMap)
   {
      normalVector = normalize( texture2D(NormalMapTexture, texture_coordinate).xyz * 2.0 - 1.0);
   }

   vec3 reflectionVector = normalize(-reflect(lightVector,normalVector));  
 
   //calculate Ambient Term:  
   vec4 ambientLightIntensity = ambientIntensity * ambientCoefficient * textureCoefficient;    

   //calculate Diffuse Term:  
   vec4 diffuseLightIntensity = diffuseIntensity * diffuseCoefficient * max(dot(normalVector,lightVector), 0.0) * textureCoefficient;   
   
   // calculate Specular Term:
   vec4 specularLightIntensity = specularIntensity * specularCoefficient * pow(max(dot(reflectionVector,eyeVector),0.0),specularShininess) * textureCoefficient;   
  
   // write Total Color: 
   vec4 phongModel =  ambientLightIntensity + diffuseLightIntensity + specularLightIntensity;
   fragmentColour += phongModel; 
   if(textureCoefficient.a < 0.15)
      discard;
   else
      fragColour = fragmentColour;
}

