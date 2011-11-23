#version 400
int vec3 VertexPosition;
int vec3 VertexColor;

out vec3 Color;

void main()
{
	Color = VertecColor;
	gl_Position = vec4( VertexPosition ,1.0);
}
