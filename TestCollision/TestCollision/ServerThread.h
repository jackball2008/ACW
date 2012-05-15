#pragma once
#include "MyThread.h"
#include "ShareMem.h"
#include <iostream>

using namespace std;

struct Ssend{
	float vpx;
	float vpy;
	float vvx;
	float vvy;};

struct Srec{
		float vpx;
		float vpy;
		float vvx;
		float vvy;};

class ServerThread :public
	MyThread
{
public:
	ServerThread(void);
	~ServerThread(void);
	void SetShapeOject(ShareMem*w){_shareobjectS=w;};
	int run();
	ShareMem *_shareobjectS;
	_RigidBody *_Rid;
	HANDLE threadS;
	void serversocket();
};

