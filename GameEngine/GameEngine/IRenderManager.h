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
	/*virtual void __declspec(DLL_OUTPUT) InitializeRenderSys(HWND hwnd,int width,int height,const int& type) = 0;*/

	virtual void __declspec(DLL_OUTPUT) InitializeISceneRender(HWND hwnd,int width,int height) = 0;
	
	virtual void __declspec(DLL_OUTPUT) RenderIScene(IGameSceneClass*) = 0;	

// 	virtual void __declspec(DLL_OUTPUT) InitializeDX(HWND hwnd,int width,int height) = 0;
// 
// 	virtual void __declspec(DLL_OUTPUT) RenderDX(IGameSceneClass*) = 0;
// 
// 	virtual void __declspec(DLL_OUTPUT) Render(IGameSceneClass*) = 0;
};