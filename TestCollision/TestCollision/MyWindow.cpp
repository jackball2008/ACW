#include "MyWindow.h"


MyWindow::MyWindow()
{
	SetSize(400,200);
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
	for(int i = 0; i< 40; i ++){
		for( int j =0; j < 20 ; j ++){
	glBegin(GL_LINE_LOOP);
	glVertex2f(_myphysics.square[i][j].vFirstpoint.x,_myphysics.square[i][j].vFirstpoint.y);
	glVertex2f(_myphysics.square[i][j].vSecondpoint.x,_myphysics.square[i][j].vSecondpoint.y);
	glVertex2f(_myphysics.square[i][j].vThirdpoint.x,_myphysics.square[i][j].vThirdpoint.y);
	glVertex2f(_myphysics.square[i][j].vFourthpoint.x,_myphysics.square[i][j].vFourthpoint.y);
	/*glVertex2f(_myphysics._rigidbody1.vFirstpoint.x,_myphysics._rigidbody1.vFirstpoint.y);
	glVertex2f(_myphysics._rigidbody1.vSecondpoint.x,_myphysics._rigidbody1.vSecondpoint.y);
	glVertex2f(_myphysics._rigidbody1.vThirdpoint.x,_myphysics._rigidbody1.vThirdpoint.y);
	glVertex2f(_myphysics._rigidbody1.vFourthpoint.x,_myphysics._rigidbody1.vFourthpoint.y);*/
	
	glEnd();
		}
	}


	//glColor3f(0.0f,1.0f,0.0f);
	//glBegin(GL_LINE_LOOP);
	//glVertex2f(_myphysics._rigidbody2.vFirstpoint.x,_myphysics._rigidbody2.vFirstpoint.y);
	//glVertex2f(_myphysics._rigidbody2.vSecondpoint.x,_myphysics._rigidbody2.vSecondpoint.y);
	//glVertex2f(_myphysics._rigidbody2.vThirdpoint.x,_myphysics._rigidbody2.vThirdpoint.y);
	//glVertex2f(_myphysics._rigidbody2.vFourthpoint.x,_myphysics._rigidbody2.vFourthpoint.y);
	//glEnd();

	delta_t = (float)App::GetDeltaTime();
	
	
	/*_myphysics.StepSimulation(0.001,&_myphysics._rigidbody1,&_myphysics._rigidbody2);*/
	_myphysics.StepSimulation(0.001,_myphysics.square);
	SwapBuffers();
}

void	MyWindow::OnIdle(){
	Redraw();
}
