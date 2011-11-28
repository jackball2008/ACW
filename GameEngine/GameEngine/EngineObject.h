#pragma once

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif


class EngineObject
{
public:
	__declspec(DLL_OUTPUT) EngineObject();
	__declspec(DLL_OUTPUT) virtual ~EngineObject();
};

