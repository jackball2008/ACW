#pragma comment(lib, "ws2_32.lib") 
#include <stdlib.h>
#include <iostream>
#include <winsock2.h>

using namespace std;


int main()
{
	cout<<"server start..."<<endl;
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
	if (s==INVALID_SOCKET) {
		cerr << "Create socket failed" << endl;
	} else if (bind(s, (sockaddr *)&peer, sizeof(peer))==SOCKET_ERROR) {
		cerr << "Bind failed with " << WSAGetLastError()  << endl;
	} else if (listen(s, 5)==SOCKET_ERROR) {
		cerr << "Listen failed with " << WSAGetLastError()  << endl;
	} else {

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
	}

	// Delay
	cout << "Waiting..." << endl; char ch; cin >> ch;

	// Cleanup windows sockets
	WSACleanup();
}
