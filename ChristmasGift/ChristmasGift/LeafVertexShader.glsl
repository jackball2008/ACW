#version 130

//phone lighting
out vec3 normal;
out vec3 lightVector;
out vec3 eyeVector;
out vec3 position;
out vec4 colour;
//texture coord
out vec2 Texcoord;
void main( void )
{
   position = vec3(gl_ModelViewMatrix * gl_Vertex * 2);
   normal = normalize(gl_NormalMatrix * gl_Normal);

   lightVector = normalize(gl_LightSource[0].position.xyz - position);
   colour = gl_Color;     

   eyeVector = normalize(-position);
   // Transforming The Vertex
   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

   Texcoord    = gl_MultiTexCoord0.xy;   
}