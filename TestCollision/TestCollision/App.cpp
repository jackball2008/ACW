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

	for(int i = 0; i< 40; i ++){
		for( int j =0; j < 20 ; j ++){
			_RigidBody* square = new _RigidBody();
			Vector p0;
			p0.x= -0.9f+i*0.04f;
			p0.y= -0.9f+j*0.04f;
			Vector p1;
			p1.x=p0.x-0.02f;
			p1.y=p0.y+0.02f;
			Vector p2;
			p2.x=p0.x+0.02f;
			p2.y=p0.y+0.02f;
			Vector p3;
			p3.x=p0.x+0.02f;
			p3.y=p0.y-0.02f;
			Vector p4;
			p4.x=p0.x-0.02f;
			p4.y=p0.y-0.02f;

			square->PiontPostion.push_back(p0);
			square->PiontPostion.push_back(p1);
			square->PiontPostion.push_back(p2);
			square->PiontPostion.push_back(p3);
			square->PiontPostion.push_back(p4);
			_shapeobject.renderObjects.push_back(square);
		}
	}
}