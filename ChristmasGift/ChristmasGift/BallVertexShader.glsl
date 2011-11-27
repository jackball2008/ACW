#version 130
///////////////////////////////
// variables
///////////////////////////////
out vec3 normal;
out vec3 lightVector;
out vec3 eyeVector;
out vec3 position;
out vec4 colour;

///////////////////////////////
// uniform
///////////////////////////////

///////////////////////////////
// functions
///////////////////////////////

void main()
{
	
	// generate the variables for the phong lighting and texturing
	position = vec3(gl_ModelViewMatrix * gl_Vertex * 2);
	normal = normalize(gl_NormalMatrix * gl_Normal);

	lightVector = normalize(gl_LightSource[0].position.xyz - position);
	colour = gl_Color;     

	eyeVector = normalize(-position);
	// Transforming The Vertex
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
}

