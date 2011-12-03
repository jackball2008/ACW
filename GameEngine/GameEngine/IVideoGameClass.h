#pragma once
#include "MXYGameEngineInterfaceDefine.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

MXYGameEngineInterface IVideoGameClass {
public:
	virtual void __declspec(DLL_OUTPUT) Initialize();
	virtual void __declspec(DLL_OUTPUT) RunGameLogic();

};