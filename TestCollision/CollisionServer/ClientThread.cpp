#include "ClientThread.h"

float team;
ClientThread::ClientThread(void)
{
}


ClientThread::~ClientThread(void)
{
}

int ClientThread::run(){
	threadC =GetCurrentThread();
	while(!_terminate){
		Sleep(10);
		clientsocket();
	}
	return 0;

}

void ClientThread::clientsocket(){

	// Create version identifier
	WORD wVersionRequested = MAKEWORD( 2, 0 );

	// Startup windows sockets
	WSADATA wsaData;
	if ( WSAStartup( wVersionRequested, &wsaData )) {
		cerr << "Socket initialisation failed" << endl;
		
	}

	// Create socket data space
	sockaddr_in peer;
	peer.sin_family = AF_INET;
	peer.sin_port = htons(9171);	// port 9171
	peer.sin_addr.S_un.S_addr = inet_addr( "192.168.1.67" );

	// Create transfer socket
	char buffer;
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	if (s==INVALID_SOCKET) {
		cerr << "Create socket failed" << endl;
	} else if (connect(s, (sockaddr *)&peer, sizeof(peer))==SOCKET_ERROR) {
		cerr << "Connect to peer failed with " << WSAGetLastError() << endl;
	} else if (send(s, (char*)&team, sizeof(team), 0)==SOCKET_ERROR) {
		cerr << "Send failed with " << WSAGetLastError() << endl;
	} else if (recv(s, &buffer, 1, 0)==SOCKET_ERROR) {
		cerr << "Receive failed with " << WSAGetLastError()  << endl;
	} else {
		cout << "Message= " << buffer << endl;
	}
	// Cleanup windows sockets
	WSACleanup();
}