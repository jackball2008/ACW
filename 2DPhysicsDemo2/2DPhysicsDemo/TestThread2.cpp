#include "TestThread2.h"


TestThread2::TestThread2(void)
{
}


TestThread2::~TestThread2(void)
{
}

int TestThread2::run(){
	while(!_terminate){
		cout<<"___"<<endl;
		Sleep(1000);
	}
	return 0;
}