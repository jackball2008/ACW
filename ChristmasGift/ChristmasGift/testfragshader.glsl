#version 130

in vec4 Color;
//out vec4 FragColor;
void main() {
    //FragColor = vec4(Color, 1.0);
	gl_FragColor = Color;
	//gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}