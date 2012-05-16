
#include "NetReceiveThread.h"


NetReceiveThread::NetReceiveThread(void)
{
	_sendshapeid = -99;

	//socket initialize
	wVersionRequested = MAKEWORD( 2, 0 );
	connectedOk = false;

	InitSocket();

	//init sender id
	//_sendshapeid
	srand((unsigned)time(NULL));
	_sendshapeid = (rand()%300) + 1;

}


NetReceiveThread::~NetReceiveThread(void)
{
	WSACleanup();
}


void NetReceiveThread::InitSocket()
{
	bool socketInitOk = false;
	//int err = WSAStartup( wVersionRequested, &wsaData );

	if (WSAStartup( wVersionRequested, &wsaData )) {
		cerr << "Socket initialisation failed" << endl;
		socketInitOk = false;
	}
	else
	{
		socketInitOk = true;
	}

	// Create socket data space
	if(socketInitOk)
	{
		//SOCKADDR_IN 
		peer.sin_family = AF_INET;
		peer.sin_port = htons(9171);	// port 9171
		peer.sin_addr.S_un.S_addr = inet_addr( "192.168.1.167" );


	}
	else
	{
		closesocket(socketClient);
		WSACleanup();
	}
	


}




int NetReceiveThread::run(){
	while(!_terminate){
		//cout<<"net working..."<<endl;
		Sleep(100);
		//do the work
		if(_shapeShareObject->Acquire())
		{
			__try
			{
				//check and send data
				CheckShapePos();
				//check there is data on the server
				SendAndReceiveRequestData();

			}
			__finally{
				_shapeShareObject->Release();
			}


		}

		
	}
	return 0;
}

#define MAX_DATA_LENGTH 128
void NetReceiveThread::CheckShapePos()
{
	//if pos out of range, send it's position
	int objnum = _shapeShareObject->renderObjects.size();
	for(int i=0;i<objnum;i++)
	{
		Shape* shapeA = _shapeShareObject->renderObjects.at(i);
		if (shapeA->type != 1)
		{
			//make sure shape is not ground
			//if pos 
			// 
			if((shapeA->pos.x > 1 || shapeA->pos.x < -1) && shapeA->pos.y> 0 && shapeA->id != _sendshapeid && !shapeA->issent)
			{

				//_sendshapeid = shapeA->id;
				shapeA->issent = true;
				//send it

				//assemble data
				// head x
				string big_head = " ";
				string type = " s ";
				string sender_id_head = " id ";
				string x_head = " x ";
				string y_head = " y ";
				string vx_head = " q ";
				string vy_head = " w ";
				string end = " e";

				stringstream ssid(stringstream::in|stringstream::out);
				ssid<<_sendshapeid;
				string id_str = ssid.str();

				stringstream ss0(stringstream::in|stringstream::out);

				ss0<<shapeA->pos.x;
				string x_str = ss0.str();
				
				
				stringstream ss1(stringstream::in|stringstream::out);
				ss1<<shapeA->pos.y;
				string y_str = ss1.str();

				stringstream ss2(stringstream::in|stringstream::out);
				ss2<<shapeA->velocity.x;
				string vx_str = ss2.str();

				stringstream ss3(stringstream::in|stringstream::out);
				ss3<<shapeA->velocity.y;
				string vy_str = ss3.str();


				big_head.append(type);

				//big_head.append(sender_id_head);
				big_head.append(" ");
				big_head.append(id_str);

				//big_head.append(x_head);
				big_head.append(" ");
				big_head.append(x_str);


				//big_head.append(y_head);
				big_head.append(" ");
				big_head.append(y_str);

				//big_head.append(vx_head);
				big_head.append(" ");
				big_head.append(vx_str);

				//big_head.append(vy_head);
				big_head.append(" ");
				big_head.append(vy_str);

				big_head.append(end);



				cout<<"send data = "<<big_head<<endl;
				//////////////////////////////////////////////////////////////////////////
				//add blank in the end
				//////////////////////////////////////////////////////////////////////////
				//////////////////////////////////////////////////////////////////////////
				/***/
				int current_data_len = (int)strlen((char*)big_head.c_str());
				if(current_data_len<MAX_DATA_LENGTH)
				{
					int left_len = MAX_DATA_LENGTH - current_data_len;

					for(int i = 0; i< left_len;i++)
					{
						big_head.append(" ");
					}

				}

				SendPosData((char*)big_head.c_str());

			}

		}




	}




	//send


	//receive


}

void NetReceiveThread::SendPosData(const char *datap)
{
	socketClient = socket(AF_INET, SOCK_STREAM, 0);

	if (socketClient==INVALID_SOCKET) {
		cerr << "Create socket failed" << endl;
	}

	if (connect(socketClient, (sockaddr *)&peer, sizeof(peer))==SOCKET_ERROR) {
		cerr << "Connect to peer failed with " << WSAGetLastError() << endl;
	} 
	else
	{
		//cout<<"connect server ok"<<endl;
		int sendres  = send(socketClient, datap, (int)strlen(datap), 0);
		//cout<<"sendres = "<<sendres<<endl;

		if( sendres == SOCKET_ERROR)
		{
			cerr << "Send failed with " << WSAGetLastError() << endl;
		}


	}
	closesocket(socketClient);
}

void NetReceiveThread::SendAndReceiveRequestData()
{
	string big_head = " r ";

	stringstream ssid(stringstream::in|stringstream::out);
	ssid<<_sendshapeid;
	string id_str = ssid.str();

	big_head.append(id_str);


	int current_data_len = (int)strlen((char*)big_head.c_str());
	if(current_data_len<MAX_DATA_LENGTH)
	{
		int left_len = MAX_DATA_LENGTH - current_data_len;

		for(int i = 0; i< left_len;i++)
		{
			big_head.append(" ");
		}

	}

	char *datap = (char*)big_head.c_str();

	socketClient = socket(AF_INET, SOCK_STREAM, 0);

	if (socketClient==INVALID_SOCKET) {
		cerr << "Create socket failed" << endl;
	}

	if (connect(socketClient, (sockaddr *)&peer, sizeof(peer))==SOCKET_ERROR) {
		cerr << "Connect to peer failed with " << WSAGetLastError() << endl;
	} 
	else
	{
		//cout<<"connect server ok"<<endl;
		int sendres  = send(socketClient, datap, (int)strlen(datap), 0);
		//cout<<"sendres = "<<sendres<<endl;

		if( sendres == SOCKET_ERROR)
		{
			cerr << "Send failed with " << WSAGetLastError() << endl;
		}


	}



	closesocket(socketClient);

}
