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

	float delta_t, temp_time;

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,0.0f,0.0f);

	temp_time = (float)App::GetTime();
	delta_t = temp_time-current_time;
	current_time = temp_time;
	_myphysics.StepSimulation(current_time);

}

void	MyWindow::OnIdle(){

}