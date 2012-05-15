#pragma once
#include <winsock2.h>
#pragma comment(lib, "Ws2_32.lib")
#include "mythread.h"

#include <iostream>
#include <sstream>
#include "ShapeShareObject.h"

using namespace std;

class NetReceiveThread :
	public MyThread
{
private:
	//socket
	WORD wVersionRequested;
	WSADATA wsaData;

	sockaddr_in peer;
	SOCKET socketClient;

	bool connectedOk;
	
	void InitSocket();
	
	//////////////////////////////////////////////////////////////////////////
	
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

