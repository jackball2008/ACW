#include "MyWnd.h"
#include "MyApp.h"

#include <strstream>
using namespace std;

//-----------------------------------------------------------------------------

void MyWnd::OnCreate() {
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	glFrustum(-1.0f, +1.0f, -1.0f, +1.0f, 1.0f, 20.0f);

	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 

	glViewport(0, 0, Width(), Height());
	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
}

void MyWnd::OnDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Camera
	glLoadIdentity(); 
	glTranslatef(0.0f, -5.0f, -7.0f);

	// Frame
	static unsigned long frameCount=0L;
	glRasterPos2f(0.0f, 0.0f);
	Printf("Frame = %lu", frameCount++);

	// Floor
	glColor3f (0.5f, 0.5f, 0.8f);
	glBegin(GL_QUADS);
		glVertex3f (-5.0f, -0.5f,  5.0f);
		glVertex3f ( 5.0f, -0.5f,  5.0f);
		glVertex3f ( 5.0f, -0.5f, -5.0f);
		glVertex3f (-5.0f, -0.5f, -5.0f);
	glEnd();

	// Ball
	if (_bToggleDisplay)
		glColor3f (1.0, 1.0, 1.0);
	else
		glColor3f (1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef (0.0, MyApp::Get().getBallPhysics()->height(), 0.0);

	

	GLUquadric *q = gluNewQuadric();
	gluSphere(q,0.5,100,100);
	gluDeleteQuadric(q);
	glPopMatrix();
	//
	glPushMatrix();
	glTranslatef (0.5, MyApp::Get().getBallPhysics2()->height(), 0.0);



	GLUquadric *q2 = gluNewQuadric();
	gluSphere(q2,0.5,100,100);
	gluDeleteQuadric(q2);
	glPopMatrix();
	//
	

	//second ball
	glPushMatrix();

	glPopMatrix();


	SwapBuffers();
}//OnDisplay

//-----------------------------------------------------------------------------

void MyWnd::OnIdle() {
	Redraw();
}//OnIdle

//-----------------------------------------------------------------------------

void MyWnd::OnKeyboard(int key, bool down)
{
	if (down) {
		_bToggleDisplay = !_bToggleDisplay;
		MyApp::Get().getBallPhysics()->terminate();
		MyApp::Get().getBallPhysics2()->terminate();
	}
}