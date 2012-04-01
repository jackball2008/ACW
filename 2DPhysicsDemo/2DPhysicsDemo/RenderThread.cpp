#include "RenderThread.h"


RenderThread::RenderThread(void)
{
}


RenderThread::~RenderThread(void)
{
}

int RenderThread::run(){
	while(!_terminate){
		//cout<<"render"<<endl;
		Sleep(1000);
	}
	return 0;
}
