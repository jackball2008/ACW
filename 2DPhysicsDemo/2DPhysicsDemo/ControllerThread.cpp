#include "ControllerThread.h"


ControllerThread::ControllerThread(void)
{
}


ControllerThread::~ControllerThread(void)
{
}

int ControllerThread::run(){
	while(!_terminate){
		//cout<<"controller"<<endl;
		Sleep(1000);
	}
	return 0;
}
