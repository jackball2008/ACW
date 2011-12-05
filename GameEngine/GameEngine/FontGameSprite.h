#pragma once
#include "gamesprite.h"
#include <stdarg.h>


#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif


class FontGameSprite :
	public GameSprite
{
public:
	__declspec(DLL_OUTPUT)  FontGameSprite(void);
	__declspec(DLL_OUTPUT)  ~FontGameSprite(void);

	GLuint	base;
	char* letter;
	int num;

	int displayNum;
	virtual  GLvoid __declspec(DLL_OUTPUT) BuildFont(GLvoid);
	virtual  GLvoid __declspec(DLL_OUTPUT) glPrint(const char *fmt, ...);
	virtual void __declspec(DLL_OUTPUT) Draw();
};

