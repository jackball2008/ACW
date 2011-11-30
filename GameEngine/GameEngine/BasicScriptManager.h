#pragma once
#include "IScriptManager.h"
class BasicScriptManager : public IScriptManager
{
public:
	__declspec(DLL_OUTPUT) BasicScriptManager(void);
	__declspec(DLL_OUTPUT) ~BasicScriptManager(void);


	void __declspec(DLL_OUTPUT) Initialize();
};

