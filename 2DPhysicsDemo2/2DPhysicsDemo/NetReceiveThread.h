#pragma once
//#define _WINSOCKAPI_
//#pragma comment(lib, "ws2_32.lib")

//#include <winsock2.h>

#include "mythread.h"
//#include "SocketProcesser.h"
#include <iostream>
#include <sstream>
#include "ShapeShareObject.h"

using namespace std;

class NetReceiveThread :
	public MyThread
{
private:
	int _sendshapeid;

	//SocketProcesser sp;


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

