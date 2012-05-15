#pragma once
#include "MyThread.h"
#include "ShareMem.h"
#include <iostream>
using namespace std;


struct Csend{
	float vpx;
	float vpy;
	float vvx;
	float vvy;
};

struct Crec{
	float vpx;
	float vpy;
	float vvx;
	float vvy;
};

class ClientThread :
	public MyThread
{
public:
	ClientThread(void);
	~ClientThread(void);
	void SetShapeObject(ShareMem *t){_shareobjectC=t;};
	int run();
	ShareMem *_shareobjectC;
	_RigidBody *_Rid;
	HANDLE threadC;
	void clientsocket();
	

};

