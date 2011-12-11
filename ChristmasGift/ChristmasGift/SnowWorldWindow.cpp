#include "SnowWorldWindow.h"


SnowWorldWindow::SnowWorldWindow(void):_angleInc(30)
{
	_bHaveMultitex = false;	// do we have mulitexture support?
	_bMultitex = false;	
	//////////////////////////////////////////////////////////////////////////
	_angle = 0.0f;
	//camera
	_cameraAngle = 30.0;
	_cameraPositionZ = -5.0;
	_cameraRotation = 0.0;
	_cameraHerical = 0.0;
	


	//initialize window
	SetSize(512,512);
	SetDepthBits(24);
	SetTitle("Snow World From Xiaoyu Ma");
}


SnowWorldWindow::~SnowWorldWindow(void)
{
}

void SnowWorldWindow::OnCreate(){
	GLWindowEx::OnCreate();

	// does this driver support multitexture?
	_bHaveMultitex = glex::Supports( "GL_ARB_multitexture" );
	if (!_bHaveMultitex) {
		// warn the user if multitexture not supported
		cout<<"GL_ARB_multitexture NOT found"<<endl;
	}

	// if it supports multitexture, turn it on
	_bMultitex = _bHaveMultitex;

	// clear window first: it might take a moment before image loads
	glClear(GL_COLOR_BUFFER_BIT);
	SwapBuffers();
	// turns vsync off so the frame rate is not limited
	wglSwapIntervalEXT(0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0f,(GLfloat)Width()/(GLfloat)Height(),0.01f,100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glShadeModel(GL_SMOOTH);
	glViewport(0,0, Width(), Height());
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	// track material ambient and diffuse from surface color, call it before glEnable(GL_COLOR_MATERIAL)
	//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	// remove back faces
	glEnable(GL_CULL_FACE);

	world.CreateWorld();


}
void SnowWorldWindow::OnDisplay(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(0.0f, 0.0f,_cameraPositionZ);
	glRotatef(_cameraAngle, 1.0,0.0,0.0);
	glRotatef(_cameraRotation, 0.0, 1.0, 0.0);
	//////////////////////////////////////////////////////////////////////////
	world.Draw();
	//////////////////////////////////////////////////////////////////////////
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glColor3f(1.0,1.0,1.0);
	glEnable(GL_LIGHTING);
	SwapBuffers();
}
void SnowWorldWindow::OnIdle(){
	Redraw();
}
void SnowWorldWindow::OnKeyboard(int key, bool down){
	if (!down) return;
	switch( tolower(key) ){
	case 'a': 
		_cameraAngle += 5.0;
		break;
	case 'z':
		_cameraAngle -= 5.0;
		break;
	case 's': 
		_cameraHerical += 5.0;
		break;
	case 'x':
		_cameraHerical -= 5.0;
		break;
	}
}
void SnowWorldWindow::OnMouseMove(int x, int y){
	static int temp_x, temp_y;
	if(_leftDown) {
		_cameraPositionZ += (y-temp_y)*0.05f;
	}
	if(_rightDown) {
		_cameraRotation += (x-temp_x)*0.5f;
	}
	temp_x = x;
	temp_y = y;
}
void SnowWorldWindow::OnMouseButton(MouseButton button, bool down){
	if (down) {
		switch(button) {
		case MBLeft: 
			_leftDown = true;
			break;
		case MBRight:
			_rightDown = true;
			break;
		default:
			break;
		}
	} else {
		switch(button) {
		case MBLeft: 
			_leftDown = false;
			break;
		case MBRight:
			_rightDown = false;
			break;
		default:
			break;
		}
	}
}
void SnowWorldWindow::OnUpdate(){

}
