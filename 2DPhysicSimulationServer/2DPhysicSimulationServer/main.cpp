#pragma comment(lib, "ws2_32.lib") 
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <strstream>
#include <winsock2.h>

using namespace std;

#define DEFAULT_BUFLEN 512


int main()
{
	cout<<"server start..."<<endl;
	cout<<"initialize buffer"<<endl;
	char recvbuf[DEFAULT_BUFLEN];
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
	char buffer;
	SOCKET s1;//send socket
	if (s==INVALID_SOCKET) {
		cerr << "Create socket failed" << endl;
	} else if (bind(s, (sockaddr *)&peer, sizeof(peer))==SOCKET_ERROR) {
		cerr << "Bind failed with " << WSAGetLastError()  << endl;
	} else if (listen(s, 5)==SOCKET_ERROR) {
		cerr << "Listen failed with " << WSAGetLastError()  << endl;
	} else {
		socketok = true;
		/**
		// Create transfer socket
		char buffer;
		SOCKET s1 = accept(s, NULL, NULL);
		if (s1==INVALID_SOCKET) {
			cerr << "Accept failed with " << WSAGetLastError() << endl;
		} else if (recv(s1, &buffer, 1, 0)==SOCKET_ERROR) {
			cerr << "Receive failed with " << WSAGetLastError() << endl;
		} else {
			cout << "Message= " << buffer << endl;
			if (send(s1, "2", 1, 0)==SOCKET_ERROR) {
				cerr << "Send failed with " << WSAGetLastError() << endl;
			}
		}
		*/
	}

	if(!socketok)
	{
		cout<<"Error happened, EXIT"<<endl;
		WSACleanup();
	}

	while(socketok)
	{
		s1 = accept(s, NULL, NULL);
		if (s1==INVALID_SOCKET) {
			cerr << "Accept failed with " << WSAGetLastError() << endl;
		} else if (recv(s1, recvbuf, recvbuflen, 0)==SOCKET_ERROR) {
			cerr << "Receive failed with " << WSAGetLastError() << endl;
		} else {
			istrstream sin(recvbuf, recvbuflen-1);
			string word;
			sin>>word;
			int rx = -2;
			rx = word.compare("x");
			if(rx == 0)
			{
				cout<<"get x"<<endl;
				sin>>word;
				float xv = atof(word.c_str());
				cout<<"x = "<<xv<<endl;
			}

			cout << "Message= " << recvbuf << endl;
			if (send(s1, "2", 1, 0)==SOCKET_ERROR) {
				cerr << "Send failed with " << WSAGetLastError() << endl;
			}
		}
	}

	// Delay
	cout << "input char to exit..." << endl; char ch; cin >> ch;

	// Cleanup windows sockets
	WSACleanup();
}
