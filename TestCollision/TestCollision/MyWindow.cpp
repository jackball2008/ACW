#include "MyWindow.h"
#include <iostream>
using namespace std;

MyWindow::MyWindow()
{
	SetSize(600,600);
}


MyWindow::~MyWindow(void)
{
}

void MyWindow::OnCreate(){
	GLWindowEx::OnCreate();
	/*_myphysics.Initialize();*/
}

void  MyWindow::OnDisplay(){

	//float delta_t;
	

	glClear(GL_COLOR_BUFFER_BIT);
	
	int num =_shapeobject->renderObjects.size();
	for (int i=0;i<num;i++)
	{
		_RigidBody* RID = _shapeobject->renderObjects.at(i);

			glColor3f(1.0f,0.0f,0.0f);
		    glBegin(GL_LINE_LOOP);
			glVertex2f(RID->vFirstpoint.x,RID->vFirstpoint.y);
			glVertex2f(RID->vSecondpoint.x,RID->vSecondpoint.y);
			glVertex2f(RID->vThirdpoint.x,RID->vThirdpoint.y);
			glVertex2f(RID->vFourthpoint.x,RID->vFourthpoint.y);
			glEnd();

	}
	//for(vector<_RigidBody*>::iterator ite_vec_shape = _shapeobject->renderObjects.begin();
	//	ite_vec_shape != _shapeobject->renderObjects.end();ite_vec_shape++
	//	){
	//		
	//		_RigidBody * rigidbody = *ite_vec_shape;
	//		vector<Vector> &Pa = rigidbody->PiontPostion;
	//		glColor3f(1.0f,0.0f,0.0f);
	//		glBegin(GL_LINE_LOOP);
	//		glVertex2f(Pa.at(1).x,Pa.at(1).y);
	//		glVertex2f(Pa.at(2).x,Pa.at(2).y);
	//		glVertex2f(Pa.at(3).x,Pa.at(3).y);
	//		glVertex2f(Pa.at(4).x,Pa.at(4).y);
	//		glEnd();
	//}
	//for(int i = 0; i< 40; i ++){
	//	for( int j =0; j < 20 ; j ++){
	//glBegin(GL_LINE_LOOP);
	//glVertex2f(_myphysics.square[i][j].vFirstpoint.x,_myphysics.square[i][j].vFirstpoint.y);
	//glVertex2f(_myphysics.square[i][j].vSecondpoint.x,_myphysics.square[i][j].vSecondpoint.y);
	//glVertex2f(_myphysics.square[i][j].vThirdpoint.x,_myphysics.square[i][j].vThirdpoint.y);
	//glVertex2f(_myphysics.square[i][j].vFourthpoint.x,_myphysics.square[i][j].vFourthpoint.y);
	///*glVertex2f(_myphysics._rigidbody1.vFirstpoint.x,_myphysics._rigidbody1.vFirstpoint.y);
	//glVertex2f(_myphysics._rigidbody1.vSecondpoint.x,_myphysics._rigidbody1.vSecondpoint.y);
	//glVertex2f(_myphysics._rigidbody1.vThirdpoint.x,_myphysics._rigidbody1.vThirdpoint.y);
	//glVertex2f(_myphysics._rigidbody1.vFourthpoint.x,_myphysics._rigidbody1.vFourthpoint.y);*/
	//
	//glEnd();
	//	}
	//}


	////glColor3f(0.0f,1.0f,0.0f);
	////glBegin(GL_LINE_LOOP);
	////glVertex2f(_myphysics._rigidbody2.vFirstpoint.x,_myphysics._rigidbody2.vFirstpoint.y);
	////glVertex2f(_myphysics._rigidbody2.vSecondpoint.x,_myphysics._rigidbody2.vSecondpoint.y);
	////glVertex2f(_myphysics._rigidbody2.vThirdpoint.x,_myphysics._rigidbody2.vThirdpoint.y);
	////glVertex2f(_myphysics._rigidbody2.vFourthpoint.x,_myphysics._rigidbody2.vFourthpoint.y);
	////glEnd();

	//
	//
	//
	///*_myphysics.StepSimulation(0.001,&_myphysics._rigidbody1,&_myphysics._rigidbody2);*/
	//_myphysics.StepSimulation(0.001,_myphysics.square);
	SwapBuffers();
}

void	MyWindow::OnIdle(){
	Redraw();
}

void MyWindow::SetShapeObject(ShareMem *s){
	_shapeobject=s;
}