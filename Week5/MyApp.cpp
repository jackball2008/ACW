#include "MyApp.h"
#include <math.h>

//-----------------------------------------------------------------------------

// The one and only instance of MyApp
static MyApp theApp;

//-----------------------------------------------------------------------------

MyApp::MyApp() {
	_ballPhys1 = new BallPhysics();
	_ballPhys2 = new BallPhysics();
}//MyApp

//-----------------------------------------------------------------------------

MyApp::~MyApp() {
	delete _ballPhys1;
	delete _ballPhys2;
}//~MyApp

//-----------------------------------------------------------------------------

void MyApp::OnCreate() {
	_ballPhys1->start();
	_ballPhys2->start();
}//OnCreate

//-----------------------------------------------------------------------------

void MyApp::OnDestroy() {
	_ballPhys1->terminate();
	_ballPhys1->waitForTermination();

	_ballPhys2->terminate();
	_ballPhys2->waitForTermination();
}//OnDestroy

//-----------------------------------------------------------------------------

MyApp & MyApp::Get() {
	return theApp;
}//Get

//-----------------------------------------------------------------------------
