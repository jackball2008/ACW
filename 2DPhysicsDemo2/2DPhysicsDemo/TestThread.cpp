#include "TestThread.h"


TestThread::TestThread(void)
{
}


TestThread::~TestThread(void)
{
}

int TestThread::run(){
	while(!_terminate){
		cout<<"***"<<endl;
		Sleep(1000);
	}
	return 0;
}
