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
	
	
	__declspec(DLL_OUTPUT) GameSceneClass():renderType(OPENGL){ /*renderType = OPENGL;*/  }
	//__declspec(DLL_OUTPUT) GameSceneClass(const int& rt=OPENGL);//{ renderType = rt;  }
	virtual __declspec(DLL_OUTPUT) ~GameSceneClass(void){}

	

	IInputManager* inputManager;
	void __declspec(DLL_OUTPUT) SetInputManager(IInputManager* g){ inputManager = g; }

	int* nextSceneFlag;
	void __declspec(DLL_OUTPUT) SetJumpNextSceneFlag(int* f){ nextSceneFlag = f; }

	int renderType;
	virtual void __declspec(DLL_OUTPUT) SetRenderType(const int& type){ renderType = type; }
};

