#pragma once
#include "IRenderManager.h"

#include <d3d9.h>
#include <d3dx9.h>

#include <gl\gl.h>                                // Header File For The OpenGL32 Library
#include <gl\glu.h>                               // Header File For The GLu32 Library
#include "GameSprite.h"
#include "FontGameSprite.h"
#include <stdarg.h>

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
	virtual __declspec(DLL_OUTPUT) ~BasicRenderManager(void);

	
	int width,height;
	
	HDC			hDC;// Private GDI Device Context
	virtual void __declspec(DLL_OUTPUT) InitializeOpenGL(HWND hwnd,int width,int height);
	virtual void __declspec(DLL_OUTPUT) RenderOpenGL(IGameSceneClass*);	


	LPDIRECT3D9             g_pD3D;       
	LPDIRECT3DDEVICE9       g_pd3dDevice;
	D3DXMATRIX g_matProj;  
	D3DXMATRIX g_matView;
	D3DXMATRIX g_matWorld;
	virtual void __declspec(DLL_OUTPUT) InitializeDX(HWND hwnd,int width,int height);


};

