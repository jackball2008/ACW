#pragma once

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif
//------------------------------------------------------------------------

#include "EngineObject.h"
#include "ErrorException.h"
#include <string>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <Windows.h>

using namespace std;

//------------------------------------------------------------------------

//Singleton Logging Object

class ErrorManager : public EngineObject
{
public:
    static __declspec(DLL_OUTPUT) ErrorManager* GetInstance();
    void __declspec(DLL_OUTPUT) Create(const string& filename);
    void __declspec(DLL_OUTPUT) Close();
    void __declspec(DLL_OUTPUT) LogException(ErrorException &e);
	void __declspec(DLL_OUTPUT) Output(const char* message);

	void __declspec(DLL_OUTPUT) TestMethod();

protected:
    __declspec(DLL_OUTPUT) ErrorManager();
    __declspec(DLL_OUTPUT) virtual ~ErrorManager();

private:
    void Flush();

    static ErrorManager _errorManager;
    stringstream _logBuffer;
    string getTimeString();
    ofstream _logFile;
};
