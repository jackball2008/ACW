#version 130
///////////////////////////////
// uniforms
///////////////////////////////
///////////////////////////////
// variables
///////////////////////////////
in vec3 normal;
in vec3 position;   
in vec3 lightVector;
in vec3 eyeVector; 
in vec4 colour;

out vec4 fragColour;


void main()
{   
   
   // get the colour from the texture
   
   vec4 fragmentColour = vec4(0.0,0.0,0.0,1.0); // initialise fragment(pixel) colour to black

   
   vec4 baseColour = colour;
      
   vec4 ambientIntensity   = vec4(0.0,0.0,0.0,1.0);
   vec4 diffuseIntensity   = vec4(0.5,0.5,0.5,0.2);
   vec4 specularIntensity  = vec4(1.0,1.0,1.0,1.0);

   float ambientCoefficient = 0.0;
   float diffuseCoefficient = 0.95;
   float specularCoefficient = 1.0;
   float specularShininess = 20.0;
   
   

   vec3 reflectionVector = normalize(-reflect(lightVector,normal));  
 
   //calculate Ambient Term:  
   vec4 ambientLightIntensity = ambientIntensity * ambientCoefficient * baseColour;    

   //calculate Diffuse Term:  
   vec4 diffuseLightIntensity = diffuseIntensity * diffuseCoefficient * max(dot(normal,lightVector), 0.0) * baseColour;   
   
   // calculate Specular Term:
   vec4 specularLightIntensity = specularIntensity * specularCoefficient * pow(max(dot(reflectionVector,eyeVector),0.0),specularShininess) * baseColour;   
  
   // write Total Color: 
   vec4 phongModel =  ambientLightIntensity + diffuseLightIntensity + specularLightIntensity;
   fragmentColour += phongModel; 
   
   fragmentColour.a = 0.5;
   
   fragColour = fragmentColour;
}


