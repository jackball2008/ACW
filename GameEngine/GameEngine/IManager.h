#pragma once
#include <Windows.h>
#include "ErrorManager.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

#define MXYGameEngineInterface class __declspec(novtable)

MXYGameEngineInterface IManager {
	public:
		virtual void __declspec(DLL_OUTPUT) Initialize();

};