#pragma once
#include <windows.h>
#include <gl\gl.h> 
#include <stdio.h>
#include "mxyVector.h"
typedef mxy::vec3<float> vec3f;
typedef mxy::vec4<float> vec4f;

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif



class GameSprite
{
public:
	__declspec(DLL_OUTPUT) GameSprite(void);
	__declspec(DLL_OUTPUT) ~GameSprite(void);
	//set display type
	int displayType;
	vec3f pos3f;
	vec3f scale3f;
	vec3f color3f;
	vec4f color4f;
	vec3f rotate3f;

	HDC			hDC;

	


	virtual void __declspec(DLL_OUTPUT) Draw();


};

