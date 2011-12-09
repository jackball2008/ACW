#pragma once
#include "IManager.h"
#include "IGameSceneClass.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

MXYGameEngineInterface IRenderManager : public IManager {
public:
	virtual void __declspec(DLL_OUTPUT) InitializeOpenGL(HWND hwnd,int width,int height) = 0;
	
	virtual void __declspec(DLL_OUTPUT) RenderOpenGL(IGameSceneClass*) = 0;	

	virtual void __declspec(DLL_OUTPUT) InitializeDX(HWND hwnd,int width,int height) = 0;
};