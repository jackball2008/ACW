#pragma once
#include "IRenderManager.h"
/*#include "BasicSceneManager.h"*/

#include <gl\gl.h>                                // Header File For The OpenGL32 Library
#include <gl\glu.h>                               // Header File For The GLu32 Library


#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

enum RENDER_TYPE{OPENGL,DIECTX};

class BasicRenderManager : public IRenderManager
{
public:
	__declspec(DLL_OUTPUT) BasicRenderManager(void);
	__declspec(DLL_OUTPUT) ~BasicRenderManager(void);

	virtual void __declspec(DLL_OUTPUT) Initialize();
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	int renderType;
	void __declspec(DLL_OUTPUT) SetRenderType(int type);
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	int width,height;
	void __declspec(DLL_OUTPUT) SetWindowSize(int width, int height);
	
	HDC			hDC;//=NULL;		// Private GDI Device Context
	virtual void __declspec(DLL_OUTPUT) InitializeOpenGL(HWND hwnd,int width,int height);
	virtual void __declspec(DLL_OUTPUT) RenderOpenGL();	
};

