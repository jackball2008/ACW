#pragma once

#include <stdarg.h>
// #include <gl\gl.h>                           
// #include <gl\glu.h>
#include <GXBase.h>
#include <stdio.h>
#include "mxyVector.h"

typedef mxy::vec3<float> vec3f;
typedef mxy::vec4<float> vec4f;

enum FONT_SPRITE_DRAW_TYPE{FONT_DRAW_NUM,FONT_DRAW_STR};
class FontGameSprite 
{
public:
	vec3f pos3f;
	vec3f scale3f;
	vec3f color3f;
	vec4f color4f;
	vec3f rotate3f;




	FontGameSprite(void);
	~FontGameSprite(void);

	GLuint	base;
	char* letter;
	int num;
	int fontHeight;

	char* displayStr;
	int displayNum;

	int drawType;

	HDC			hDC;

	GLvoid BuildFont(GLvoid);
	GLvoid glPrint(const char *fmt, ...);
	void Draw();
	
};

