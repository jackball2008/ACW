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
	__declspec(DLL_OUTPUT) GameSceneClass(void);
	__declspec(DLL_OUTPUT) ~GameSceneClass(void);

	//member veriable
	int sceneID;
	bool isLastScene;
	IGameSceneClass* nextGameScene;


	virtual void __declspec(DLL_OUTPUT) Begin();
	virtual void __declspec(DLL_OUTPUT) Running();
	virtual void __declspec(DLL_OUTPUT) End();
	virtual void __declspec(DLL_OUTPUT) SetNextScene(IGameSceneClass* );
	virtual __declspec(DLL_OUTPUT) IGameSceneClass*  GetNextScene();


};

