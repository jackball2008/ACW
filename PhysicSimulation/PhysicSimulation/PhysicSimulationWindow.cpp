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
	
	
	glViewport(0,0, Width(), Height());

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f,(GLfloat)Width()/(GLfloat)Height(),0.1f,100.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix

	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations



}
void	PhysicSimulationWindow::OnDisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	/************************************************************************/
	/* start to draw                                                                     */
	/************************************************************************/
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
void	PhysicSimulationWindow::OnUpdate(){

}
