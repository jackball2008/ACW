#include "MyWindow.h"
#include <iostream>
using namespace std;

MyWindow::MyWindow()
{
	ishold = false;
	left_down = false;
	last_left_down = false;

	mouse_x = mouse_y = 0;
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
	/////////////////////////////////////
	if(_shapeobject->left_hold)
		glColor3f(1.0f,0.0f,0.0f);
	else
		glColor3f(0.0f,1.0f,0.0f);
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2f(mouse_x, mouse_y);
	glEnd();


	if(_shapeobject->left_hold){

		//cout<<"s x = "<<_shapeShareObject->springLine->sp.x<<" s y = "<<_shapeShareObject->springLine->sp.y<<" e x = "<<_shapeShareObject->springLine->ep.x<<" e y = "<<_shapeShareObject->springLine->ep.y<<endl;
		//draw springline
		glColor3f(_shapeobject->springLine->r,_shapeobject->springLine->g,_shapeobject->springLine->b);
		glPointSize(4);
		glBegin(GL_LINES);
		glVertex2f(_shapeobject->springLine->sp.x, _shapeobject->springLine->sp.y);
		glVertex2f(_shapeobject->springLine->ep.x, _shapeobject->springLine->ep.y);

		glEnd();
	}



	
	int num =_shapeobject->renderObjects.size();
	for (int i=0;i<num;i++)
	{
		if (_shapeobject->Acquire()) {
			__try {
				RID = _shapeobject->renderObjects.at(i);
			} __finally {
				_shapeobject->Release();
			}
		}
		
				/*RID = _shapeobject->renderObjects.at(i);*/
		
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

void  MyWindow::OnMouseMove(int x, int y){
	if (_shapeobject->Acquire())
	{
		__try{
			if(Width()){
				mouse_x = 2.0f*(float)x/(float)Width()-1.0f;
				_shapeobject->springLine->sp.x=mouse_x;
			}
			if(Height()){

				mouse_y =2.0f*(float)y/(float)Height()-1.0f;
				_shapeobject->springLine->sp.y=mouse_y;
			}
			Redraw();
		}__finally{
			_shapeobject->Release();
		}
	}

}

void MyWindow::OnMouseButton(MouseButton button, bool down){

	
	//if(down) return;
	if(_shapeobject->Acquire()){
		__try{
			switch(button){
			case MBLeft:
				if(down)
				{
					if(last_left_down != down && last_left_down == false)
					{
						last_left_down = down;
						//cout<<"press down"<<endl;
						_shapeobject->left_hold = false;
					}
					if(last_left_down == down)//true
					{
						//cout<<"holding..."<<endl;
						_shapeobject->left_hold = true;
					}
					//_shapeShareObject->springLine->isvisiable = true;
				}
				else
				{
					if(last_left_down != down && last_left_down == true)
					{
						last_left_down = down;
						//cout<<"press up"<<endl;
					_shapeobject->left_hold = false;
					}
					//_shapeShareObject->springLine->isvisiable = false;

				}
				break;

			}

			Redraw();

		}__finally{
			_shapeobject->Release();
		}
	}

}