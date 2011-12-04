#pragma once
#include "IManager.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

MXYGameEngineInterface IInputManager : public IManager {
public:
	virtual void __declspec(DLL_OUTPUT) Initialize();

	virtual void __declspec(DLL_OUTPUT) KeyboardInput(const UINT& msg);
	//LPARAM 
	virtual void __declspec(DLL_OUTPUT) MouseInput(const LPARAM& lp);
};