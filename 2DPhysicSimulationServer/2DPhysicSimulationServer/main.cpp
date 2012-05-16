#pragma comment(lib, "ws2_32.lib") 
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <strstream>
#include <winsock2.h>

using namespace std;

#define DEFAULT_BUFLEN 512


struct TempData{
	int sender_id;
	float pos_x;
	float pos_y;
	float velocity_x;
	float velocity_y;

public:
	TempData(){
		sender_id = -99;
		pos_x = -99;
		pos_y = -99;
		velocity_x = -99;
		velocity_y = -99;
	}
};


int main()
{
	TempData tempData;





	cout<<"server start..."<<endl;
	cout<<"initialize buffer"<<endl;
	
	//char recvbuf[DEFAULT_BUFLEN];
	int recvbuflen = DEFAULT_BUFLEN;


	// Create version identifier
	WORD wVersionRequested = MAKEWORD( 2, 0 );

	// Startup windows sockets
	WSADATA wsaData;
	if ( WSAStartup( wVersionRequested, &wsaData )) {
		cerr << "Socket initialisation failed" << endl;
		return -1;
	}

	sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(9171);	// port 9171
	peer.sin_addr.S_un.S_addr = htonl( INADDR_ANY );

	// Create listening socket
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	//////////////////////////////////////////////////////////////////////////

	bool socketok = false;
	//char buffer;
	
	if (s==INVALID_SOCKET) {
		cerr << "Create socket failed" << endl;
	} else if (bind(s, (sockaddr *)&peer, sizeof(peer))==SOCKET_ERROR) {
		cerr << "Bind failed with " << WSAGetLastError()  << endl;
	} else if (listen(s, 5)==SOCKET_ERROR) {
		cerr << "Listen failed with " << WSAGetLastError()  << endl;
	} else {
		socketok = true;
		char buffer[128];

		while(1)
		{
			Sleep(10);
			SOCKET s1 = accept(s,NULL,NULL);
			//cout<<"s1 = "<<s1<<endl;
			if (s1==INVALID_SOCKET)
			{
				cerr << "Accept failed with " << WSAGetLastError() << endl;
			}
			else 
			{
				int recres = recv(s1,buffer,128,0);
				//cout<<"recres = "<<recres<<endl;
				if(recres==SOCKET_ERROR)
				{
					cerr << "Receive failed with " << WSAGetLastError() << endl;
				}
				else
				{
					//cout<<"receive ok"<<buffer<<endl;

					//start to analyze
					istrstream sin(buffer, 128-1);
					string word;
					sin>>word;
					//int type = -2;
					//type = word.compare("s");
					if(word.compare("s") == 0)
					{
						//receive a send position data
						//cout<<"+++"<<buffer<<endl;
						// read id
						sin>>word;
						int sender_id = atof(word.c_str());

						if(sender_id!=tempData.sender_id)
						{
							//x
							sin>>word;
							float pos_x = (float)atof(word.c_str());

							//y
							sin>>word;
							float pos_y = (float)atof(word.c_str());

							//v_x
							sin>>word;
							float v_x = (float)atof(word.c_str());

							//v_y
							sin>>word;
							float v_y = (float)atof(word.c_str());

							cout<<" x = "<<pos_x<<" y = "<<pos_y<<" vx = "<<v_x<<" vy = "<<v_y<<endl;

							tempData.sender_id = sender_id;
							tempData.pos_x = pos_x;
							tempData.pos_y = pos_y;
							tempData.velocity_x = v_x;
							tempData.velocity_y = v_y;
						}
						else
						{
							cout<<"resend..."<<endl;
						}
						



					}
					else if(word.compare("r") == 0)
					{
						//receive a request
						//cout<<"---"<<endl;
						// 
						sin>>word;

						int r_id = atof(word.c_str());

						//cout<<"request id = "<<r_id<<endl;


						if(tempData.sender_id!=-99 && r_id!= tempData.sender_id)
						{
							//send back data

							//x
							stringstream ss_x(stringstream::in|stringstream::out);
							ss_x<<tempData.pos_x;
							string x_str = ss_x.str();
							//y
							stringstream ss_y(stringstream::in|stringstream::out);
							ss_y<<tempData.pos_y;
							string y_str = ss_y.str();
							//v_x
							stringstream ss_v_x(stringstream::in|stringstream::out);
							ss_v_x<<tempData.velocity_x;
							string v_x_str = ss_v_x.str();
							//v_y
							stringstream ss_v_y(stringstream::in|stringstream::out);
							ss_v_y<<tempData.velocity_y;
							string v_y_str = ss_v_y.str();

							string datastr = " r ";

							datastr.append(x_str);
							datastr.append(" ");
							datastr.append(y_str);
							datastr.append(" ");
							datastr.append(v_x_str);
							datastr.append(" ");
							datastr.append(v_y_str);
							datastr.append(" ");
							datastr.append(" e ");



							//(char*)datastr.c_str()
							cout<<"send feed back = "<<datastr<<endl;
							//s1
							if (send(s1, (char*)datastr.c_str(), (int)strlen((char*)datastr.c_str()), 0)== SOCKET_ERROR)
							{
								cerr << "Send Request failed with " << WSAGetLastError() << endl;
							}
							else
							{
								//reset temp
								tempData.sender_id = -99;
								tempData.pos_x = -99;
								tempData.pos_y = -99;
								tempData.velocity_x = -99;
								tempData.velocity_y = -99;
							}




						}
					}







				}
			}
			closesocket(s1);
			
		}

		
	}



	// Delay
	cout << "input char to exit..." << endl; char ch; cin >> ch;

	// Cleanup windows sockets
	WSACleanup();
}
