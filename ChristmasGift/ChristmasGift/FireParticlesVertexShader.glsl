#version 130
///////////////////////////////
// uniform
///////////////////////////////
uniform vec4 cameraPos;

out vec3 normal;
out vec3 position;
out vec2 texture_coordinate;
out vec4 vpointColour;



void main( void )
{
// generate the variables for the phong lighting and texturing
   position = vec3(gl_ModelViewMatrix * gl_Vertex);
   vec3 camPos = cameraPos.xyz;
   camPos -= position;// - camPos;//vector
   float distance = length(camPos);
   float radius = 5.0;
   float psize = (radius * 10.0) / distance;
   gl_PointSize = psize;
   normal = normalize(gl_NormalMatrix * gl_Normal);
   texture_coordinate = vec2(gl_MultiTexCoord0);
   gl_TexCoord[0] = gl_MultiTexCoord0;
   vpointColour = gl_Color;

   // Transforming The Vertex
   gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
    
    
}