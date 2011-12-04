#pragma once
#include "gamesprite.h"
#include <stdarg.h>
#include <stdarg.h>

class FontGameSprite :
	public GameSprite
{
public:
	FontGameSprite(void);
	~FontGameSprite(void);

	GLuint	base;
	GLvoid BuildFont(GLvoid);
	GLvoid glPrint(const char *fmt, ...);

};

