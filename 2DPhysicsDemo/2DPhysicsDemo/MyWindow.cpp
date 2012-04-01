#include "MyWindow.h"


MyWindow::MyWindow(void)
{
}


MyWindow::~MyWindow(void)
{
}

void	MyWindow::OnCreate(){
	GLWindowEx::OnCreate();
}
void	MyWindow::OnDisplay(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0.0);

	glBegin(GL_TRIANGLES);
	glVertex2f(-0.9f, -0.9f);
	glVertex2f(+0.9f,-0.9f);
	glVertex2f(0.0f,0.9f);
	glEnd();

	SwapBuffers();
}
void	MyWindow::OnIdle(){

}
void	MyWindow::OnKeyboard(int key, bool down){

}
void	MyWindow::OnMouseMove(int x, int y){

}
void	MyWindow::OnMouseButton(MouseButton button, bool down){

}