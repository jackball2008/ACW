#include "App.h"

static MyApp theApp;

MyApp::MyApp(void)
{
	_physicsThread= new PhysicThread();
	_clientThread = new ClientThread();
}


MyApp::~MyApp(void)
{
	delete _physicsThread;
	delete _clientThread;
}

void MyApp::OnCreate(){

	Initializeposition();
	
	_mywindow.SetShapeObject(&_shapeobject);


	_clientThread->SetShapeObject(&_shapeobject);
	_clientThread->start();

	_physicsThread->SetShapeObject(&_shapeobject);
	_physicsThread->start();
	

}

void MyApp::OnDestroy(){

	_clientThread->terminate();
	_clientThread->waitForTermination();

	_physicsThread->terminate();
	_physicsThread->waitForTermination();
}



void MyApp::Initializeposition(){
	for(int i = 0; i< 10; i ++){
		for( int j =0; j < 10; j ++){
			_RigidBody* square = new _RigidBody();

			square->vPosition.x= -0.9f+i*0.04;
			square->vPosition.y= -0.9f+j*0.04;

			square->vFirstpoint.x= square->vPosition.x-0.02f;
			square->vFirstpoint.x= square->vPosition.x-0.02f;
			square->vFirstpoint.y= square->vPosition.y+0.02f;

			square->vSecondpoint.x= square->vPosition.x+0.02f;
			square->vSecondpoint.y= square->vPosition.y+0.02f;

			square->vThirdpoint.x= square->vPosition.x+0.02f;
			square->vThirdpoint.y= square->vPosition.y-0.02f;

			square->vFourthpoint.x= square->vPosition.x-0.02f;
			square->vFourthpoint.y= square->vPosition.y-0.02f;


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