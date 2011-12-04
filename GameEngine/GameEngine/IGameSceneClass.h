#pragma once
#include "MXYGameEngineInterfaceDefine.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

MXYGameEngineInterface IGameSceneClass {
public:

	virtual void __declspec(DLL_OUTPUT) Begin();
	virtual void __declspec(DLL_OUTPUT) Running();
	virtual void __declspec(DLL_OUTPUT) End();
	virtual void __declspec(DLL_OUTPUT) SetNextScene(IGameSceneClass* );
	virtual __declspec(DLL_OUTPUT) IGameSceneClass* GetNextScene();

	virtual void __declspec(DLL_OUTPUT) Draw();

};