 #pragma comment(lib, "ws2_32.lib") 
#include <stdlib.h>
#include <iostream>
#include <winsock2.h>
#include <sstream>
using namespace std;


int main()
{
	//test code
	string head = "x ";

	float val = 3.14f;
	stringstream ss(stringstream::in|stringstream::out);
	ss<<val;
	string test = ss.str();
	head.append(test);
	cout<<test<<endl;
	char *testc = (char*)head.c_str();



	cout<<"ok"<<endl;
	// Create version identifier
	WORD wVersionRequested = MAKEWORD( 2, 0 );

	// Startup windows sockets
	WSADATA wsaData;
	if ( WSAStartup( wVersionRequested, &wsaData )) {
		cerr << "Socket initialisation failed" << endl;
		return -1;
	}

	// Create socket data space
	sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(9171);	// port 9171
	peer.sin_addr.S_un.S_addr = inet_addr( "127.0.0.1" );

	// Create transfer socket
	char *sendbuf = "12345";
	
	char buffer;
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	if (s==INVALID_SOCKET) {
		cerr << "Create socket failed" << endl;
	} else if (connect(s, (sockaddr *)&peer, sizeof(peer))==SOCKET_ERROR) {
		cerr << "Connect to peer failed with " << WSAGetLastError() << endl;
	} 
	//send data
	else if (send(s, testc, (int)strlen(testc), 0)==SOCKET_ERROR) {
		cerr << "Send failed with " << WSAGetLastError() << endl;
	}
	//receive data
	else if (recv(s, &buffer, 1, 0)==SOCKET_ERROR) {
		cerr << "Receive failed with " << WSAGetLastError()  << endl;
	} else {
		cout << "Message= " << buffer << endl;
	}
	// Cleanup windows sockets
	WSACleanup();

	int n; cin >> n;
}
