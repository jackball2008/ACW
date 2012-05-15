#pragma once
#include "MyThread.h"
#include "ShareMem.h"
#include <iostream>

using namespace std;

struct Ssend{
	float vpx;
	float vpy;
	float vvx;
	float vvy;
	int id;
	float fx;
	float fy;
	float sx;
	float sy;
	float tx;
	float ty;
	float frx;
	float fry;
};

struct Srec{
		float vpx;
		float vpy;
		float vvx;
		float vvy;
		int id;
		float fx;
		float fy;
		float sx;
		float sy;
		float tx;
		float ty;
		float frx;
		float fry;
};

class ServerThread :public
	MyThread
{
public:
	ServerThread(void);
	~ServerThread(void);
	void SetShapeOject(ShareMem*w){_shareobjectS=w;};
	int run();
	ShareMem *_shareobjectS;
	_RigidBody *_Rid,*_Cid;
	HANDLE threadS;
	void serversocket();
};

