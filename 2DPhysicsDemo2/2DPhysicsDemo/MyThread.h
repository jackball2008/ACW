#pragma once
#include "GXBase.h"
using namespace gxbase;
#include <process.h>

class MyThread
{


protected:
	HANDLE _hThread;	
	bool _terminate;

	static unsigned __stdcall threadFunc(void *param) {
		if (param)
			return ((MyThread*)param)->run();
		return 1;  // Return error
	}
private:
	

public:
	


	MyThread() : _hThread(0), _terminate(false) {}
	virtual ~MyThread() {}

	void terminate() { _terminate = true; }
	bool isTerminated() const { return _terminate; }

	HANDLE start(){
		unsigned threadId=0;
		_hThread = (HANDLE)_beginthreadex(
			NULL,		// no security attributes (child cannot inherited handle)
			1024*1024,	// 1MB stack size
			threadFunc,	// code to run on new thread
			this,		// pointer to host application class
			0,			// run immediately (could create suspended)
			&threadId	// OUT: returns thread ID
			);
		return _hThread;
	};

	void waitForTermination(){
		// wait for it to stop
		WaitForSingleObject(_hThread, INFINITE);
		// close thread handle
		CloseHandle(_hThread);
		_hThread=0;
	};

	virtual int run() = 0;
};

