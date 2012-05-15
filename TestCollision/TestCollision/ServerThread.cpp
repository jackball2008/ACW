#include "ServerThread.h"


ServerThread::ServerThread(void)
{
}


ServerThread::~ServerThread(void)
{
}

int ServerThread::run(){

	threadS = GetCurrentThread();
	while(!_terminate){

		Sleep(10);
		serversocket();
	}
	return 0;
}

void ServerThread::serversocket(){

	struct Ssend Serversend;
	struct Srec Serverec;
	int number = _shareobjectS->renderObjects.size();

	for(int i=0; i<number;i++){
		_Rid=_shareobjectS->renderObjects.at(i);
		Serversend.vpx=_Rid->vPosition.x;
		Serversend.vpy=_Rid->vPosition.y;
		Serversend.vvx=_Rid->vVelocity.x;
		Serversend.vvy=_Rid->vVelocity.y;


		WORD wVersionRequested = MAKEWORD( 2, 0 );

		// Startup windows sockets
		WSADATA wsaData;
		if ( WSAStartup( wVersionRequested, &wsaData )) {
			cerr << "Socket initialisation failed" << endl;
			
		}
		//create socket data space
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
			SOCKET s1 = accept(s, NULL, NULL);
			if (s1==INVALID_SOCKET) {
				cerr << "Accept failed with " << WSAGetLastError() << endl;
			} else if (recv(s1, (char*)&Serverec, sizeof(Serverec), 0)==SOCKET_ERROR) {
				cerr << "Receive failed with " << WSAGetLastError() << endl;
			} else {
				
				if (send(s1, (char*)&Serversend, sizeof(Serversend), 0)==SOCKET_ERROR) {
					cerr << "Send failed with " << WSAGetLastError() << endl;
				}
			}
		}

		// Delay
		_Rid->vPosition.x=Serverec.vpx;
		_Rid->vPosition.y=Serverec.vpy;
		_Rid->vVelocity.x=Serverec.vvx;
		_Rid->vVelocity.y=Serverec.vvy;

		// Cleanup windows sockets
		WSACleanup();
		
	}

}