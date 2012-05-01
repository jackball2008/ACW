#include "PhysicThread.h"
#include <iostream>
using namespace std;
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
			cout<<"1";

		}__finally{
			_shareobject->Release();
		}

		}
		

	}
	return 0;
}