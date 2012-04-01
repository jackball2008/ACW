#include "PhysicsThread.h"


PhysicsThread::PhysicsThread(void)
{
}


PhysicsThread::~PhysicsThread(void)
{
}

int PhysicsThread::run(){
	while(!_terminate){
		//cout<<"physics"<<endl;
		Sleep(1000);
	}
	return 0;
}
