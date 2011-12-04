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

	virtual void __declspec(DLL_OUTPUT) KeyboardInput(WPARAM& wParam);
	//LPARAM 
	virtual void __declspec(DLL_OUTPUT) MouseInput(const LPARAM& lp);

	/*virtual WPARAM __declspec(DLL_OUTPUT) GetKeyValue();*/
	virtual __declspec(DLL_OUTPUT) char&  GetvKeyValue();
	virtual void __declspec(DLL_OUTPUT) RecovervKey();
};