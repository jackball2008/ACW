#pragma once
#include "ISceneManager.h"
#include "GameSceneClass.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif


class BasicSceneManager : public ISceneManager
{
public:
	__declspec(DLL_OUTPUT) BasicSceneManager(void);
	virtual __declspec(DLL_OUTPUT) ~BasicSceneManager(void);



	virtual void __declspec(DLL_OUTPUT) SetAssetManager(IAssetManager*);

	virtual void __declspec(DLL_OUTPUT) SetInputManager(IInputManager*);

	virtual void __declspec(DLL_OUTPUT) SetRenderManager(IRenderManager*);

	virtual void __declspec(DLL_OUTPUT) SetScriptManager(IScriptManager*);

	IAssetManager* _assetManager;
	IInputManager* _inputManager;
	IRenderManager* _renderManager;
	IScriptManager* _scriptManager;

	bool _hasAssetManager;
	bool _hasInputManager;
	bool _hasRenderManager;
	bool _hasScriptManager;



	virtual void __declspec(DLL_OUTPUT) PlayScene(IGameSceneClass*,int* gs);

};

