#pragma once
#include "mythread.h"
#include <iostream>
#include <sstream>
#include "ShapeShareObject.h"
using namespace std;

class NetReceiveThread :
	public MyThread
{
private:
	int _sendshapeid;


	//share obj store all share data
	ShapeShareObject* _shapeShareObject;


	void CheckShapePos();
	void ReceiveData();
	void SendData();

public:
	NetReceiveThread(void);
	~NetReceiveThread(void);

	void SetShapeShareObject(ShapeShareObject* p){ _shapeShareObject = p; };

	int run();
};

