#include "NetReceiveThread.h"


NetReceiveThread::NetReceiveThread(void)
{
}


NetReceiveThread::~NetReceiveThread(void)
{
}

int NetReceiveThread::run(){
	while(!_terminate){
		//cout<<"net receive"<<endl;
		Sleep(1000);
	}
	return 0;
}
