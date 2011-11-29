#pragma once
#include "IAssetManager.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif


class BasicAssetManager : public IAssetManager
{
public:
	__declspec(DLL_OUTPUT) BasicAssetManager(void);
	__declspec(DLL_OUTPUT) ~BasicAssetManager(void);

	void __declspec(DLL_OUTPUT) Initialize();

};

