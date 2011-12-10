#pragma once
#include <windows.h>
#include "ISprite.h"
#include <gl\gl.h>                           
#include <gl\glu.h>
#include <stdio.h>
#include "mxyVector.h"

typedef mxy::vec3<float> vec3f;
typedef mxy::vec4<float> vec4f;

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

class GameSprite : public ISprite
{
public:
	__declspec(DLL_OUTPUT) GameSprite(void):hDC(NULL){ };
	virtual __declspec(DLL_OUTPUT) ~GameSprite(void){};
	
	vec3f pos3f;
	vec3f scale3f;
	vec3f color3f;
	vec4f color4f;
	vec3f rotate3f;
	//used for font display
	HDC			hDC;

};


#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_DIFFUSE) 

class DirectXGameSprite : public GameSprite
{
public:
	__declspec(DLL_OUTPUT) DirectXGameSprite(void){ };
	virtual __declspec(DLL_OUTPUT) ~DirectXGameSprite(void){};

};

