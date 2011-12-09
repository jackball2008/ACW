#pragma once
#include "MXYGameEngineInterfaceDefine.h"
#include "IInputManager.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

MXYGameEngineInterface IGameSceneClass {
public:

	virtual void __declspec(DLL_OUTPUT) Begin() = 0;
	virtual void __declspec(DLL_OUTPUT) Running() = 0;
	virtual void __declspec(DLL_OUTPUT) End() = 0;


	virtual void __declspec(DLL_OUTPUT) Draw() = 0;

	virtual void __declspec(DLL_OUTPUT) SetInputManager(IInputManager*) = 0;

	virtual void __declspec(DLL_OUTPUT) SetJumpNextSceneFlag(int*) = 0;

};