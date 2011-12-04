#pragma once

#include "IInputManager.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

class BasicInputManager : public IInputManager
{
public:
	__declspec(DLL_OUTPUT) BasicInputManager(void);
	__declspec(DLL_OUTPUT) ~BasicInputManager(void);

	void __declspec(DLL_OUTPUT) Initialize();

	virtual void __declspec(DLL_OUTPUT) KeyboardInput(const UINT& msg);
	//LPARAM 
	virtual void __declspec(DLL_OUTPUT) MouseInput(const LPARAM& lp);
};

