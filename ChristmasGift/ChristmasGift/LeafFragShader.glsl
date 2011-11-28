#version 120
//#extension GL_ARB_draw_buffers : require
//#extension GL_EXT_gpu_shader4 : require


varying vec3 normal;
varying vec3 tangentS;
varying vec3 tangentT;
varying vec3 position;

varying vec2 texCoord;


uniform sampler2D baseTex;
uniform sampler2D normalTex;

void main() {

	
	vec3 bumpNormal = texture2D( normalTex, texCoord).xyz * 2.0 - 1.0;
	vec4 base = texture2D( baseTex, texCoord);
	
	if (base.a < 0.75)
	    discard;
	
	bumpNormal = bumpNormal.x * tangentS + bumpNormal.y * tangentT + bumpNormal.z * normal;
	
	bumpNormal = faceforward( bumpNormal, normalize(position), bumpNormal);
	
	gl_FragData[0] = vec4( position, 0.0);
	gl_FragData[1] = vec4( bumpNormal * 0.5 + 0.5, base.a);
	gl_FragData[2] = vec4( base.rgb, 0.0);
	
}