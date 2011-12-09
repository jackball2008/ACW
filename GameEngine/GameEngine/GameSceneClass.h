#pragma once
#include "IGameSceneClass.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

class GameSceneClass : public IGameSceneClass
{
public:
	__declspec(DLL_OUTPUT) GameSceneClass(void){}
	virtual __declspec(DLL_OUTPUT) ~GameSceneClass(void){}

	

	IInputManager* inputManager;
	void __declspec(DLL_OUTPUT) SetInputManager(IInputManager* g){ inputManager = g; }

	int* nextSceneFlag;
	void __declspec(DLL_OUTPUT) SetJumpNextSceneFlag(int* f){ nextSceneFlag = f; }
};

