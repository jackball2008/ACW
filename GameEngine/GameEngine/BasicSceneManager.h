#pragma once
#include "ISceneManager.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif


class BasicSceneManager : public ISceneManager
{
public:
	__declspec(DLL_OUTPUT) BasicSceneManager(void);
	__declspec(DLL_OUTPUT) ~BasicSceneManager(void);

	void __declspec(DLL_OUTPUT) Initialize();

	virtual void __declspec(DLL_OUTPUT) SetAssetManager(IAssetManager*);

	virtual void __declspec(DLL_OUTPUT) SetInputManager(IInputManager*);

	virtual void __declspec(DLL_OUTPUT) SetRenderManager(IRenderManager*);

	virtual void __declspec(DLL_OUTPUT) MainLoop();
private:
	IAssetManager* _assetManager;
	IInputManager* _inputManager;
	IRenderManager* _renderManager;

	bool _hasAssetManager;
	bool _hasInputManager;
	bool _hasRenderManager;
};

