#include "PhysicSimulationWindow.h"


PhysicSimulationWindow::PhysicSimulationWindow(void)
{
}

/**
PhysicSimulationWindow::~PhysicSimulationWindow(void)
{
}
*/

/************************************************************************/
/* void	OnCreate();
void	OnDisplay();
void	OnIdle();
void	OnKeyboard(int key, bool down);
void	OnMouseMove(int x, int y);
void	OnMouseButton(MouseButton button, bool down);
void	OnUpdate();                                                                     */
/************************************************************************/
void	PhysicSimulationWindow::OnCreate(){
	
	GLWindowEx::OnCreate();
	
}
void	PhysicSimulationWindow::OnDisplay(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0.0);

	glBegin(GL_TRIANGLES);
	glVertex2f(-0.9f, -0.9f);
	glVertex2f(+0.9f,-0.9f);
	glVertex2f(0.0f,0.9f);
	glEnd();

	SwapBuffers();
}
void	PhysicSimulationWindow::OnIdle(){

}
void	PhysicSimulationWindow::OnKeyboard(int key, bool down){

}
void	PhysicSimulationWindow::OnMouseMove(int x, int y){

}
void	PhysicSimulationWindow::OnMouseButton(MouseButton button, bool down){

}

void	PhysicSimulationWindow::OnResize(){

}
void	PhysicSimulationWindow::OnUpdate(){

}
