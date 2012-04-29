#include "PhysicThread.h"


PhysicThread::PhysicThread(void)
{
}


PhysicThread::~PhysicThread(void)
{
}

int PhysicThread::run(){
	thread =GetCurrentThread();

	while(!_terminate){
		Sleep(2);
		if (_shareobject->Acquire())
		{ __try{


		}__finally{
			_shareobject->Release();
		}

		}
		

	}
	return 0;
}