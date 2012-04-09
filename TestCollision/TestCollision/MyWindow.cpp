#include "MyWindow.h"


MyWindow::MyWindow()
{
	SetSize(512,512);
}


MyWindow::~MyWindow(void)
{
}

void MyWindow::OnCreate(){
	GLWindowEx::OnCreate();
	_myphysics.Initialize();
}

void  MyWindow::OnDisplay(){

	float delta_t;


	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(_myphysics._rigidbody1.vFirstpoint.x,_myphysics._rigidbody1.vFirstpoint.y);
	glVertex2f(_myphysics._rigidbody1.vSecondpoint.x,_myphysics._rigidbody1.vSecondpoint.y);
	glVertex2f(_myphysics._rigidbody1.vThirdpoint.x,_myphysics._rigidbody1.vThirdpoint.y);
	glVertex2f(_myphysics._rigidbody1.vFourthpoint.x,_myphysics._rigidbody1.vFourthpoint.y);
	glEnd();



	glColor3f(0.0f,1.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(_myphysics._rigidbody2.vFirstpoint.x,_myphysics._rigidbody2.vFirstpoint.y);
	glVertex2f(_myphysics._rigidbody2.vSecondpoint.x,_myphysics._rigidbody2.vSecondpoint.y);
	glVertex2f(_myphysics._rigidbody2.vThirdpoint.x,_myphysics._rigidbody2.vThirdpoint.y);
	glVertex2f(_myphysics._rigidbody2.vFourthpoint.x,_myphysics._rigidbody2.vFourthpoint.y);
	glEnd();

	delta_t = (float)App::GetDeltaTime();
	
	_myphysics.StepSimulation(delta_t,&_myphysics._rigidbody1,&_myphysics._rigidbody2);
	SwapBuffers();
}

void	MyWindow::OnIdle(){
	Redraw();
}