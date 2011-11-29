#pragma once
#include "IManager.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

MXYGameEngineInterface ISceneManager : public IManager {
public:
	virtual void __declspec(DLL_OUTPUT) Initialize();


};