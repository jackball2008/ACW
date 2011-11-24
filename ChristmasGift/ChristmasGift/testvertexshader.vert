#version 400
layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec4 VertexColor;
//in vec3 VertexPosition;
//in vec4 VertexColor;
out vec4 Color;
void main()
{
	//vec4 tempcolor = VertexColor;
	Color = VertexColor;
   gl_Position = ftransform();
}