#version 130
in vec3 VertexPosition;
in vec3 VertexColor;
out vec3 Color;

void main()
{
   Color = VertexColor;
   vec3 temp = vec3(VertexPosition.x,VertexPosition.y,VertexPosition.z);
   temp.x = VertexPosition.x/100;
   gl_Position =  vec4( temp, 1.0 );
}