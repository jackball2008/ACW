#pragma comment(lib, "ws2_32.lib") 
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <strstream>
#include <winsock2.h>

using namespace std;

#define DEFAULT_BUFLEN 512



void ClearBuffer()
{
	

}


int main()
{
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
		char buffer[256];

		while(1)
		{
			SOCKET s1 = accept(s,NULL,NULL);
			cout<<"s1 = "<<s1<<endl;
			if (s1==INVALID_SOCKET)
			{
				cerr << "Accept failed with " << WSAGetLastError() << endl;
			}
			else 
			{
				int recres = recv(s1,buffer,256,0);
				cout<<"recres = "<<recres<<endl;
				if(recres==SOCKET_ERROR)
					cerr << "Receive failed with " << WSAGetLastError() << endl;
				else
				{
					cout<<"receive ok"<<buffer<<endl;

// 					if(send(s1,"2",1,0) == SOCKET_ERROR)
// 					{
// 						cerr << "Send failed with " << WSAGetLastError() << endl;
// 					}
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
