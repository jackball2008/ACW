#pragma once
#include "IManager.h"
#include "IAssetManager.h"
#include "IInputManager.h"
#include "IRenderManager.h"
#include "IScriptManager.h"
#include "IGameSceneClass.h"


#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif



MXYGameEngineInterface ISceneManager : public IManager {
public:
	
	/************************************************************************/
	/* set main manager                                                                     */
	/************************************************************************/
	virtual void __declspec(DLL_OUTPUT) SetAssetManager(IAssetManager*) = 0;

	virtual void __declspec(DLL_OUTPUT) SetInputManager(IInputManager*) = 0;

	virtual void __declspec(DLL_OUTPUT) SetRenderManager(IRenderManager*) = 0;

	virtual void __declspec(DLL_OUTPUT) SetScriptManager(IScriptManager*) = 0;
	
	
	//play
	virtual void __declspec(DLL_OUTPUT) PlayScene(IGameSceneClass*,int* gs) = 0;
	
};