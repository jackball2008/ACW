#version 120
//#extension GL_EXT_gpu_shader4 : require


varying vec3 normal;
varying vec3 tangentS;
varying vec3 tangentT;
varying vec3 position;

varying vec2 texCoord;

void main() {

	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
	
	position = (gl_ModelViewMatrix * gl_Vertex).xyz;
	
	//transform tangents and normal
	normal = gl_NormalMatrix * gl_Normal;
	tangentS = gl_NormalMatrix * gl_MultiTexCoord1.xyz;
	tangentT = gl_NormalMatrix * gl_MultiTexCoord2.xyz;
	
	texCoord = gl_MultiTexCoord0.st;
	
}