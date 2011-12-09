#pragma once
#include <Windows.h>
#include "MXYGameEngineInterfaceDefine.h"
#include "ErrorManager.h"

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

MXYGameEngineInterface IManager {
	

};