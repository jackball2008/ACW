#version 130
///////////////////////////////
// variables
///////////////////////////////
out vec3 normal;
out vec3 lightVector;
out vec3 eyeVector;
out vec3 position;
out vec2 texture_coordinate;
out vec4 colour;
///////////////////////////////
// uniform
///////////////////////////////
uniform bool applyNormalMap; 

///////////////////////////////
// uniform
///////////////////////////////
uniform vec4 cameraPos;
///////////////////////////////
// functions
///////////////////////////////

void main()
{
   colour = gl_Color;
   // generate the variables for the phong lighting and texturing
   position = vec3(gl_ModelViewMatrix * gl_Vertex);
   normal = normalize(gl_NormalMatrix * gl_Normal);
   texture_coordinate = vec2(gl_MultiTexCoord0);

   vec3 c1 = cross( gl_Normal, vec3(0.0, 0.0, 1.0) ); 
   vec3 c2 = cross( gl_Normal, vec3(0.0, 1.0, 0.0) ); 

   vec3 tangent;
   vec3 binormal;

   if( length(c1)>length(c2) )
   {
      tangent = c1;   
   }
   else
   {
      tangent = c2;   
   }

   tangent = normalize(tangent);

   binormal = cross(tangent, gl_Normal); 
   binormal = normalize(binormal);

   lightVector = normalize(gl_LightSource[0].position.xyz - position);

   mat3 tangentSpace;
   tangentSpace[0] = tangent;
   tangentSpace[1] = binormal;
   tangentSpace[2] = normal;

   if (applyNormalMap)
   {
      lightVector = tangentSpace * lightVector;
   }

   eyeVector = normalize(cameraPos.xyz - position);
   if (applyNormalMap)
   {
      eyeVector = tangentSpace * eyeVector;
   }

   // Transforming The Vertex
   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}

