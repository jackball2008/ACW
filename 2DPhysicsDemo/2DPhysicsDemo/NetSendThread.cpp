#include "NetSendThread.h"


NetSendThread::NetSendThread(void)
{
}


NetSendThread::~NetSendThread(void)
{
}

int NetSendThread::run(){
	while(!_terminate){
		//cout<<"net send"<<endl;
		Sleep(1000);
	}
	return 0;
}