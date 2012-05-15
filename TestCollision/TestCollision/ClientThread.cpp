#include "ClientThread.h"


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

	struct Csend Clientsend;
	struct Csend Clientrec;
	int  number = _shareobjectC->renderObjects.size();

	for(int i=0;i<number;i++){

		_Rid= _shareobjectC->renderObjects.at(i);
	Clientsend.vpx=_Rid->vPosition.x;
	Clientsend.vpy=_Rid->vPosition.y;
	Clientsend.vvx=_Rid->vVelocity.x;
	Clientsend.vvy=_Rid->vVelocity.y;


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
	
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	if (s==INVALID_SOCKET) {
		cerr << "Create socket failed" << endl;
	} else if (connect(s, (sockaddr *)&peer, sizeof(peer))==SOCKET_ERROR) {
		cerr << "Connect to peer failed with " << WSAGetLastError() << endl;
	} else if (send(s, (char*)&Clientsend, sizeof(Clientsend), 0)==SOCKET_ERROR) {
		cerr << "Send failed with " << WSAGetLastError() << endl;
	} else if (recv(s, (char*)&Clientrec, sizeof(Clientrec), 0)==SOCKET_ERROR) {
		cerr << "Receive failed with " << WSAGetLastError()  << endl;
	} else {
		_Rid->vPosition.x= Clientrec.vpx;
		_Rid->vPosition.y=Clientrec.vpy;
		_Rid->vVelocity.x=Clientrec.vvx;
		_Rid->vVelocity.y=Clientrec.vvy;
	}
	// Cleanup windows sockets
	WSACleanup();
	}
}