#include "IThreads.h"

#include "GXBase.h"
using namespace gxbase;
#include <process.h>

class BaseThread: public IThreads{
private:
	HANDLE _hThread;
	bool _terminate;

	static unsigned __stdcall threadFunc(void *param) {
		if (param)
			return ((BaseThread*)param)->run();
		return 1;  // Return error
	}

public:
	BaseThread() : _hThread(0), _terminate(false) {}
	virtual ~BaseThread(){}


	void terminate() { _terminate = true; }
	bool isTerminated() const { return _terminate; }

	void waitForTermination(){
		// wait for it to stop
		WaitForSingleObject(_hThread, INFINITE);
		// close thread handle
		CloseHandle(_hThread);
		_hThread=0;
	};
	//need to override
	virtual int run() = 0;
	//thread function
	HANDLE start();
};