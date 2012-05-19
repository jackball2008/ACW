#include "App.h"

static MyApp theApp;

MyApp::MyApp(void)
{
	_physicsThread= new PhysicThread();
	_clientThread = new ClientThread();
	/*_serverThread = new ServerThread();*/
}


MyApp::~MyApp(void)
{
	delete _physicsThread;
	delete _clientThread;
	/*delete _serverThread;*/
}

void MyApp::OnCreate(){

	Initializeposition();
	
	_mywindow.SetShapeObject(&_shapeobject);

	/*_serverThread->SetShapeOject(&_shapeobject);
	_serverThread->start();*/

	_clientThread->SetShapeObject(&_shapeobject);
	_clientThread->start();

	_physicsThread->SetShapeObject(&_shapeobject);
	_physicsThread->start();
	
	

}

void MyApp::OnDestroy(){

	//_serverThread->terminate();
	//_serverThread->waitForTermination();

	_clientThread->terminate();
	_clientThread->waitForTermination();

	_physicsThread->terminate();
	_physicsThread->waitForTermination();
}



void MyApp::Initializeposition(){
	for(int i = 0; i< 10; i ++){
		for( int j =0; j < 10; j ++){
			_RigidBody* square = new _RigidBody();

			square->vPosition.x= -0.9f+i*square->fLength;
			square->vPosition.y= 0.9f+j*square->fLength;

			square->vFirstpoint.x= square->vPosition.x-square->fWidth;
			square->vFirstpoint.x= square->vPosition.x-square->fWidth;
			square->vFirstpoint.y= square->vPosition.y+square->fWidth;

			square->vSecondpoint.x= square->vPosition.x+square->fWidth;
			square->vSecondpoint.y= square->vPosition.y+square->fWidth;

			square->vThirdpoint.x= square->vPosition.x+square->fWidth;
			square->vThirdpoint.y= square->vPosition.y-square->fWidth;

			square->vFourthpoint.x= square->vPosition.x-square->fWidth;
			square->vFourthpoint.y= square->vPosition.y-square->fWidth;

			

			if(i%3==1){
				square->r=0.5f;
				square->b=0.0f;
				square->fMass=3.0f;
			}
			if(i%3==2){
				square->r=0.0f;
				square->b=0.5f;
				square->fMass=2.0f;
			}
			
		

			_shapeobject.renderObjects.push_back(square);
		}
	}
	//----------- special-------------//
	//_RigidBody *s;
	// s=_shapeobject.renderObjects.at(0);
	// /*s->vPosition.x=-0.99f;*/
	// s->vVelocity.x=2.1f;
	// s->vVelocity.y=2.1f;
}