#pragma once
#include "ISceneManager.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif


class BasicSceneManager : public ISceneManager
{
public:
	__declspec(DLL_OUTPUT) BasicSceneManager(void);
	__declspec(DLL_OUTPUT) ~BasicSceneManager(void);

	void __declspec(DLL_OUTPUT) Initialize();

	
};

