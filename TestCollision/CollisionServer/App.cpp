#include "App.h"

static MyApp theApp;

MyApp::MyApp(void)
{
	_physicsThread= new PhysicThread();
}


MyApp::~MyApp(void)
{
	delete _physicsThread;
}

void MyApp::OnCreate(){

	Initializeposition();
	
	_mywindow.SetShapeObject(&_shapeobject);
	_physicsThread->SetShapeObject(&_shapeobject);
	_physicsThread->start();
	

}

void MyApp::OnDestroy(){

	_physicsThread->terminate();
	_physicsThread->waitForTermination();
}



void MyApp::Initializeposition(){
	for(int i = 0; i< 10; i ++){
		for( int j =0; j < 10; j ++){
			_RigidBody* square = new _RigidBody();
			//Vector p0;
			//p0.x= -0.9f+i*0.04f;
			//p0.y= -0.9f+j*0.04f;
			//Vector p1;
			//p1.x=p0.x-0.02f;
			//p1.y=p0.y+0.02f;
			//Vector p2;
			//p2.x=p0.x+0.02f;
			//p2.y=p0.y+0.02f;
			//Vector p3;
			//p3.x=p0.x+0.02f;
			//p3.y=p0.y-0.02f;
			//Vector p4;
			//p4.x=p0.x-0.02f;
			//p4.y=p0.y-0.02f;
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

			//square->PiontPostion.push_back(square->vPosition);
			//square->PiontPostion.push_back(square->vFirstpoint);
			//square->PiontPostion.push_back(square->vSecondpoint);
			//square->PiontPostion.push_back(square->vThirdpoint);
			//square->PiontPostion.push_back(square->vFourthpoint);
			_shapeobject.renderObjects.push_back(square);
		}
	}
	//----------- special-------------//
	_RigidBody *s;
	 s=_shapeobject.renderObjects.at(0);
	 /*s->vPosition.x=-0.99f;*/
	 s->vVelocity.x=2.1f;
	 s->vVelocity.y=2.1f;
}