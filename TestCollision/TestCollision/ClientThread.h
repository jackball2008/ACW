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

struct Crec{
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

class ClientThread :
	public MyThread
{
public:
	ClientThread(void);
	~ClientThread(void);
	void SetShapeObject(ShareMem *t){_shareobjectC=t;};
	int run();
	ShareMem *_shareobjectC;
	_RigidBody *_Rid,*_Cid;
	HANDLE threadC;
	void clientsocket();
	

};

