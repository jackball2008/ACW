#version 130
// layout (location = 0) in vec3 VertexPosition;
// layout (location = 1) in vec3 VertexColor;
in vec3 VertexPosition;
in vec3 VertexColor;
//out vec3 Color;
void main()
{
   gl_Position = ftransform();
}