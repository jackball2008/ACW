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
	GameSceneClass* nextGameScene;





};

