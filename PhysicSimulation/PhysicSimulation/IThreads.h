#pragma once

// #include "GXBase.h"
// using namespace gxbase;
// #include <process.h>

class IThreads{
public:
	virtual void terminate()=0;
	virtual bool isTerminated() const=0;
	/*virtual HANDLE start()=0;*/
	virtual void waitForTermination()=0;
	virtual int run() = 0;
};