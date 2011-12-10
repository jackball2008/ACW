#pragma once
#include "IRenderManager.h"
#include <gl\gl.h>                                // Header File For The OpenGL32 Library
#include <gl\glu.h>                               // Header File For The GLu32 Library


#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif



class BasicRenderManager : public IRenderManager
{
public:
	__declspec(DLL_OUTPUT) BasicRenderManager(void);
	virtual __declspec(DLL_OUTPUT) ~BasicRenderManager(void);

	
	int width,height;
	
	HDC			hDC;// Private GDI Device Context

	
	virtual void __declspec(DLL_OUTPUT) InitializeISceneRender(HWND hwnd,int width,int height);
	virtual void __declspec(DLL_OUTPUT) RenderIScene(IGameSceneClass*);	

};

