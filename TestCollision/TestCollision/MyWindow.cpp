#include "MyWindow.h"


MyWindow::MyWindow(void)
{
}


MyWindow::~MyWindow(void)
{
}

void MyWindow::OnCreate(){
	GLWindowEx::OnCreate();
	
}

void  MyWindow::OnDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);

}

void	MyWindow::OnIdle(){

}