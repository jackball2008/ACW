#version 130
// layout (location = 0) in vec3 VertexPosition;
// layout (location = 1) in vec4 VertexColor;
in vec3 VertexPosition;
in vec4 VertexColor;
out vec4 Color;

void main()
{
	//vec4 tempcolor = VertexColor;//vec4(1.0,1.0,0,1);
	Color = VertexColor;//tempcolor;//vec4(1.0, 0.0, 0.0, 1.0);
	gl_Position = ftransform();

}