#pragma once
#include "IManager.h"
#include "IAssetManager.h"
#include "IInputManager.h"
#include "IRenderManager.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

MXYGameEngineInterface ISceneManager : public IManager {
public:
	virtual void __declspec(DLL_OUTPUT) Initialize();
	/************************************************************************/
	/* set main manager                                                                     */
	/************************************************************************/
	virtual void __declspec(DLL_OUTPUT) SetAssetManager(IAssetManager*);

	virtual void __declspec(DLL_OUTPUT) SetInputManager(IInputManager*);

	virtual void __declspec(DLL_OUTPUT) SetRenderManager(IRenderManager*);

	/************************************************************************/
	/* main loop function                                                                     */
	/************************************************************************/

	virtual void __declspec(DLL_OUTPUT) MainLoop();


	
};