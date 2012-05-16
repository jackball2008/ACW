
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

	char buffer[128];

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
		else if(recv(socketClient,buffer,128,0) == SOCKET_ERROR)
		{
			cerr << "Receive new shape data failed with " << WSAGetLastError() << endl;
		}
		else
		{
			//process new pos data
			istrstream sin(buffer,128-1);
			string word;
			sin>>word;

			if(word.compare("r")==0)
			{
				sin>>word;


				float pos_x = (float)atof(word.c_str());

				sin>>word;
				float pos_y = (float)atof(word.c_str());

				sin>>word;
				float v_x = (float)atof(word.c_str());

				sin>>word;
				float v_y = (float)atof(word.c_str());



				cout<<"get data x = "<<pos_x<<" y = "<<pos_y<<" v_x "<<v_x<<" v_y "<<v_y<<endl;

				//change speed
				if(v_y>0)v_y = v_y*-1;
				if((v_x>0 && pos_x>0) || (v_x<0 && pos_x<0)) pos_x = pos_x *-1;
				

				//add new shape
				int shape_id = _shapeShareObject->shape_id_index + 5;
				Shape* square = new Square();

				YPoint p1;
				p1.x = pos_x - 0.02f;
				p1.y = pos_y - 0.02f;

				YPoint p2;
				p2.x = p1.x + 0.04f;
				p2.y = p1.y;

				YPoint p3;
				p3.x = p2.x;
				p3.y = p2.y + 0.04f;

				YPoint p4;
				p4.x = p1.x;
				p4.y = p3.y;
				square->points.push_back(p1);
				square->points.push_back(p2);
				square->points.push_back(p3);
				square->points.push_back(p4);


				//set position

				square->pos.x = (float)(p1.x + p3.x + p2.x + p4.x)/4;
				square->pos.y = (float)(p1.y + p3.y + p2.y + p4.y)/4;

				//set speed
				square->velocity.x = v_x;
				square->velocity.y = v_y;

				//////////////////////////////////////////////////////////////////////////
				//square have two axises
				//set x axis
				YPoint ax;
				float x1 = (p3.x + p2.x)/2;

				float y1 = (p3.y + p2.y)/2;

				x1 = x1 - square->pos.x;
				y1 = y1 - square->pos.y;

				ax.x = x1;
				ax.y = y1;
				ax.Normalize();
				ax.z = 0.04f/2;
				//set y axis
				YPoint yx;
				ax.Right2D(yx);
				yx.z = 0.04f/2;

				square->project_axis.push_back(ax);
				square->project_axis.push_back(yx);
				//////////////////////////////////////////////////////////////////////////
				/*sid++;*/
				square->id = shape_id;
				_shapeShareObject->renderObjects.push_back(square);


			}
			
			

		}


	}



	closesocket(socketClient);

}
