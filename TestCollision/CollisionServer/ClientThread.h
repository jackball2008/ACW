#pragma once
#include "MyThread.h"
#include "ShareMem.h"
#include <iostream>
using namespace std;
class ClientThread :
	public MyThread
{
public:
	ClientThread(void);
	~ClientThread(void);
	void SetShapeObject(ShareMem *t){_shareobjectC=t;};
	int run();
	ShareMem *_shareobjectC;
	HANDLE threadC;
	void clientsocket();
};

