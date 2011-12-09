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
	virtual __declspec(DLL_OUTPUT) ~BasicInputManager(void);


	/************************************************************************/
	/* keyboard                                                                     */
	/************************************************************************/
	WPARAM key;
	char vkey;
	virtual void __declspec(DLL_OUTPUT) KeyboardInput(WPARAM& wParam);
	//LPARAM 
	/************************************************************************/
	/* mouse                                                                     */
	/************************************************************************/
	virtual void __declspec(DLL_OUTPUT) MouseInput(const LPARAM& lp);
	//get key
	virtual __declspec(DLL_OUTPUT) char&  GetvKeyValue();
	virtual void __declspec(DLL_OUTPUT) RecovervKey();
	UINT keyvalue;
	virtual __declspec(DLL_OUTPUT) UINT  GetKeyValue();
	

};

