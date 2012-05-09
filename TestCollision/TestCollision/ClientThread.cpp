#include "ClientThread.h"


ClientThread::ClientThread(void)
{
}


ClientThread::~ClientThread(void)
{
}

int ClientThread::run(){
	threadC =GetCurrentThread();
	return 0;

}