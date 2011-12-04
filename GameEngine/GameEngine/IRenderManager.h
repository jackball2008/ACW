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
	virtual void __declspec(DLL_OUTPUT) Initialize();

	virtual void __declspec(DLL_OUTPUT) SetRenderType(int type);

	virtual void __declspec(DLL_OUTPUT) SetWindowSize(int width, int height);


	virtual void __declspec(DLL_OUTPUT) InitializeOpenGL(HWND hwnd,int width,int height);
	virtual void __declspec(DLL_OUTPUT) RenderOpenGL(IGameSceneClass*);	
};