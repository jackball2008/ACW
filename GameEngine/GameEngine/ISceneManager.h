#pragma once
#include "IManager.h"
#include "IAssetManager.h"
#include "IInputManager.h"
#include "IRenderManager.h"
#include "IScriptManager.h"

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
	virtual void __declspec(DLL_OUTPUT) SetAssetManager(IAssetManager*);// = 0;

	virtual void __declspec(DLL_OUTPUT) SetInputManager(IInputManager*);

	virtual void __declspec(DLL_OUTPUT) SetRenderManager(IRenderManager*);

	virtual void __declspec(DLL_OUTPUT) SetScriptManager(IScriptManager*);

	/************************************************************************/
	/* play main loop function                                                                     */
	/************************************************************************/
	virtual void __declspec(DLL_OUTPUT) OperateCurrentGameScene(bool *con);
	//update level
	virtual void __declspec(DLL_OUTPUT) CreateCurrentSceneEnvironment();
	//play game
	virtual void __declspec(DLL_OUTPUT) RunningGameInCurrentSceneEnvironment();
	//end game scene
	virtual void __declspec(DLL_OUTPUT) EndCurrentSceneEnvironment();
	


	
};