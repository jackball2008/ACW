#include "FontGameSprite.h"


FontGameSprite::FontGameSprite(void)
{
	fontHeight = -24;
	drawType = FONT_DRAW_NUM;
}


FontGameSprite::~FontGameSprite(void)
{
}

GLvoid FontGameSprite::BuildFont(GLvoid){
	HFONT	font;
	HFONT	oldfont;
	base = glGenLists(96);
	
	font = CreateFont( fontHeight,
		0,
		0,
		0,
		FW_BOLD,
		FALSE,
		FALSE,
		FALSE,
		ANSI_CHARSET,
		OUT_TT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		ANTIALIASED_QUALITY,
		FF_DONTCARE|DEFAULT_PITCH,
		"Courier New"
		);
	hDC = wglGetCurrentDC();
	oldfont = (HFONT)SelectObject(hDC, font);
	//wglUseFontBitmaps(hDC, 32, 96, base);
	wglUseFontBitmaps(hDC, 31, 96, base);

	SelectObject(hDC, oldfont);
	DeleteObject(font);
}
GLvoid FontGameSprite::glPrint(const char *fmt, ...){
	char		text[256];
	va_list		ap;
	if (fmt == NULL)
		return;
	va_start(ap, fmt);
	vsprintf_s(text, fmt, ap);
	//vsprintf(text, fmt, ap);
	va_end(ap);
	glPushAttrib(GL_LIST_BIT);
	glListBase(base - 31);
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);
	glPopAttrib();

}

void FontGameSprite::Draw(){
	if(drawType == FONT_DRAW_NUM)
		glPrint(letter,displayNum);
	if(drawType == FONT_DRAW_STR)
		glPrint(letter,displayStr);
}
