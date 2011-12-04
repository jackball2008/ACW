#include "GameSprite.h"


GameSprite::GameSprite(void)
{
	hDC= NULL;
}


GameSprite::~GameSprite(void)
{
}

void GameSprite::Draw(){

}


// void GameSprite::DrawString(const char * str){
// 	/**
// 	static int isFirstCall = 1;
// 	static GLuint lists;
// 
// 	if ( isFirstCall ) { // 如果是第一次调用，执行初始化
// 		// 为每一个ASCII字符产生一个显示列表
// 		isFirstCall = 0;
// 
// 		// 申请MAX_CHAR个连续的显示列表编号
// 		lists = glGenLists(MAX_CHAR);
// 
// 		// 把每个字符的绘制命令都装到对应的显示列表中
// 		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
// 	}
// 	// 调用每个字符对应的显示列表，绘制每个字符
// 	for (; *str!='/0'; ++str)
// 		glCallList(lists + (*str));
// 		*/
// }
// 
// void GameSprite::DrawGraphic(){
// 
// }

/**
void GameSprite::drawCNString(const char* str) {
	int len, i;
	wchar_t* wstring;
	HDC hDC = wglGetCurrentDC();
	GLuint list = glGenLists(1);

	// 计算字符的个数
	// 如果是双字节字符的（比如中文字符），两个字节才算一个字符
	// 否则一个字节算一个字符
	len = 0;
	for(i=0; str[i]!='\0'; ++i)
	{
		if( IsDBCSLeadByte(str[i]) )
			++i;
		++len;
	}

	// 将混合字符转化为宽字符
	wstring = (wchar_t*)malloc((len+1) * sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, str, -1, wstring, len);
	wstring[len] = L'\0';

	// 逐个输出字符
	for(i=0; i<len; ++i)
	{
		wglUseFontBitmapsW(hDC, wstring[i], 1, list);
		glCallList(list);
	}

	// 回收所有临时资源
	free(wstring);
	glDeleteLists(list, 1);
}

void GameSprite::BuildGLFont(int fontHeight){
	HDC hDC =::GetDC(HWND_DESKTOP);

	int tFontHeight = -1* fontHeight;

	NormalFontBase = glGenLists(96);

	HFONT font = CreateFont(-tFontHeight,0,0,0,FW_BOLD,TRUE,FALSE,FALSE,ANSI_CHARSET,OUT_TT_PRECIS,CLIP_DEFAULT_PRECIS,ANTIALIASED_QUALITY,FF_DONTCARE|DEFAULT_PITCH,"Georgia");

	HFONT oldfont = (HFONT)SelectObject(hDC,font);
	wglUseFontBitmaps(hDC,32,96,NormalFontBase);

	SelectObject(hDC,oldfont);

	DeleteObject(font);

	SetBkMode(hDC,TRANSPARENT);

	NormalFont
}
*/

