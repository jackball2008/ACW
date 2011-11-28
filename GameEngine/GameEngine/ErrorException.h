#pragma once

//------------------------------------------------------------------------

#include <string>
#include <sstream>
#include <iostream>
#include <exception>

#ifdef _WINDLL
#define DLL_OUTPUT dllexport
#else
#define DLL_OUTPUT dllimport
#endif

using namespace std;

//------------------------------------------------------------------------

//Custom exception class

class ErrorException : public exception
{
public:
	__declspec(DLL_OUTPUT) ErrorException();
	__declspec(DLL_OUTPUT) ErrorException(int errorNumber, const string &errorDesc, const string &srcFileName, int lineNumber);
	__declspec(DLL_OUTPUT) ~ErrorException() throw();

	// Override std::exception::what
	const char* what();

private:
	int _errorNumber;
	string _errorDesc;
	string _srcFileName;
	int _lineNumber;
	string _errText;
};