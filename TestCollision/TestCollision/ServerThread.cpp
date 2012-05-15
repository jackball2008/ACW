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

		Sleep(5);
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
		Serversend.id =i;

		Serversend.fx=_Rid->vFirstpoint.x;
		Serversend.fy=_Rid->vFirstpoint.y;

		Serversend.sx=_Rid->vSecondpoint.x;
		Serversend.sy=_Rid->vSecondpoint.y;

		Serversend.tx= _Rid->vThirdpoint.x;
		Serversend.ty=_Rid->vThirdpoint.y;

		Serversend.frx=_Rid->vFourthpoint.x;
		Serversend.fry=_Rid->vFourthpoint.y;


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
		_Cid=_shareobjectS->renderObjects.at(Serverec.id);
		_Cid->vPosition.x=Serverec.vpx;
		_Cid->vPosition.y=Serverec.vpy;
		_Cid->vVelocity.x=Serverec.vvx;
		_Cid->vVelocity.y=Serverec.vvy;

		_Cid->vFirstpoint.x=Serverec.fx;
		_Cid->vFirstpoint.y=Serverec.fy;

		_Cid->vSecondpoint.x=Serverec.sx;
		_Cid->vSecondpoint.y=Serverec.sy;

		_Cid->vThirdpoint.x=Serverec.tx;
		_Cid->vThirdpoint.y=Serverec.ty;

		_Cid->vFourthpoint.x=Serverec.frx;
		_Cid->vFourthpoint.y=Serverec.fry;
		// Cleanup windows sockets
		WSACleanup();
		
	}

}