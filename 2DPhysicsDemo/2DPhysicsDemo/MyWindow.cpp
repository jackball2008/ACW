#include "MyWindow.h"
#include "SpringLine.h"

MyWindow::MyWindow(void)
{
	ishold = false;
}


MyWindow::~MyWindow(void)
{
}

void	MyWindow::OnCreate(){
	GLWindowEx::OnCreate();
}
#define _DRAWMOUSELINE
#define _DRAWMOUSEPOINT
void	MyWindow::OnDisplay(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	/************************************************************************/
	/* draw mouse points                                                     */
	/************************************************************************/
#ifdef DRAWMOUSEPOINT
	glColor3f(1.0f,1.0f,0.0f);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(_shapeShareObject->mouseposition.x, _shapeShareObject->mouseposition.y);
	glEnd();
#endif
	//draw line
#ifdef DRAWMOUSELINE
	glColor3f(1.0f,1.0f,0.0f);
	glBegin(GL_LINES);
	glVertex2f(0.0f,0.0f);
	glVertex2f(_shapeShareObject->mouseposition.x, _shapeShareObject->mouseposition.y);
	glEnd();
#endif
	
	/*vector<Shape*> plist = _shapeShareObject->GetData();*/
	for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
		ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
		ite_vec_shape++){  
			
			
			Shape* shape = *ite_vec_shape;
			vector<Point>& pa = shape->points;
			/*vector<Point>* pa = &shape->points;*/

			//////////////////////////////////////////////////////////////////////////
			if(shape->type == 0 && shape->isvisiable){

				glColor3f(1.0f,0.0f,0.0f);
				glPointSize(3);
				glBegin(GL_POINTS);
				glVertex2f(pa.at(0).x, pa.at(0).y);
				glEnd();
				//draw springline
				glColor3f(shape->r,shape->g,shape->b);
				glBegin(GL_LINES);
				glVertex2f(pa.at(0).x, pa.at(0).y);
				glVertex2f(pa.at(1).x, pa.at(1).y);

				glEnd();
			}
			//////////////////////////////////////////////////////////////////////////
			if(shape->type == 1 && shape->isvisiable){
				//draw line

				glColor3f(shape->r,shape->g,shape->b);
				
				glBegin(GL_LINES);
				glVertex2f(pa.at(0).x, pa.at(0).y);
				glVertex2f(pa.at(1).x, pa.at(1).y);
				
				glEnd();

			}
			if(shape->type == 2 && shape->isvisiable){
				//draw triangles
				
				glColor3f(shape->r,shape->g,shape->b);
				glBegin(GL_LINE_LOOP);
				glVertex2f(pa.at(0).x, pa.at(0).y);
				glVertex2f(pa.at(1).x, pa.at(1).y);
				glVertex2f(pa.at(2).x, pa.at(2).y);
				glEnd();

				glPointSize(1);
				glBegin(GL_POINTS);
				glVertex2f(shape->middlepoint.x, shape->middlepoint.y);
				glEnd();
			}
			if(shape->type == 3 && shape->isvisiable){
				//draw squares
				
				
				glColor3f(shape->r,shape->g,shape->b);
				glBegin(GL_LINE_LOOP);
				glVertex2f(pa.at(0).x, pa.at(0).y);
				glVertex2f(pa.at(1).x, pa.at(1).y);
				glVertex2f(pa.at(2).x, pa.at(2).y);
				glVertex2f(pa.at(3).x, pa.at(3).y);
				glEnd();

				glPointSize(1);
				glBegin(GL_POINTS);
				glVertex2f(shape->middlepoint.x, shape->middlepoint.y);
				glEnd();
			}

	}

	SwapBuffers();
}
void	MyWindow::OnIdle(){
	Redraw();
}
void	MyWindow::OnKeyboard(int key, bool down){

}
void	MyWindow::OnMouseMove(int x, int y){

	if(_shapeShareObject->Acquire()){
		//now modify the shared memory
		__try{
			if(Width()){
				
				_currentmouseposition.x =  2.0f * (float)x / (float)Width() - 1.0f;
				_shapeShareObject->mouseposition.x = _currentmouseposition.x;
				
				if(ishold){
					(_shapeShareObject->renderObjects.at(0))->points.at(1).x = _currentmouseposition.x;
					
				}else{
					

					(_shapeShareObject->renderObjects.at(0))->points.at(0).x = _currentmouseposition.x;

					(_shapeShareObject->renderObjects.at(0))->points.at(1).x = _currentmouseposition.x;
				}

			}
			if(Height()){
				
				_currentmouseposition.y = 2.0f * (float)y / (float)Height() - 1.0f;
				_shapeShareObject->mouseposition.y =_currentmouseposition.y;
				
				if(ishold){
					(_shapeShareObject->renderObjects.at(0))->points.at(1).y = _currentmouseposition.y;
				}else{
					
					(_shapeShareObject->renderObjects.at(0))->points.at(0).y = _currentmouseposition.y;

					(_shapeShareObject->renderObjects.at(0))->points.at(1).y = _currentmouseposition.y;
				}
			}
			Redraw();

		}__finally{
			_shapeShareObject->Release();
		}


	}

}
void	MyWindow::OnMouseButton(MouseButton button, bool down){
	
	//if(down) return;
	if(_shapeShareObject->Acquire()){
		__try{
			switch(button){
			case MBLeft:
				if(down){
					_shapeShareObject->left_down = true;
					if(_shapeShareObject->last_left_down != _shapeShareObject->left_down && _shapeShareObject->last_left_down == false){
						_shapeShareObject->last_left_down = true;
						//set start point
						cout<<"press down"<<endl;
						ishold = false;
						_shapeShareObject->left_hold = false;
					}
					if(_shapeShareObject->last_left_down == _shapeShareObject->left_down){
						cout<<"press hold"<<endl;
						ishold = true;
						_shapeShareObject->left_hold = true;
					}

					(_shapeShareObject->renderObjects.at(0))->isvisiable = true;
				}
				else{
					_shapeShareObject->left_down = false;

					if(_shapeShareObject->last_left_down != _shapeShareObject->left_down && _shapeShareObject->last_left_down == true){
						_shapeShareObject->last_left_down = false;
						cout<<"press up"<<endl;

						//save spring point
						//start
						_shapeShareObject->springstartp.x = (_shapeShareObject->renderObjects.at(0))->points.at(0).x;
						_shapeShareObject->springstartp.y = (_shapeShareObject->renderObjects.at(0))->points.at(0).y;
						//end
						_shapeShareObject->springendp.x = (_shapeShareObject->renderObjects.at(0))->points.at(1).x;
						_shapeShareObject->springendp.y = (_shapeShareObject->renderObjects.at(0))->points.at(1).y;
						///////////////////


						ishold = false;
						_shapeShareObject->left_hold = false;
					}
					(_shapeShareObject->renderObjects.at(0))->isvisiable = false;
					
				}
				break;

			}

			Redraw();

		}__finally{
			_shapeShareObject->Release();
		}
	}

}

//use once
void MyWindow::SetShapeShareObject( ShapeShareObject* s){
	_shapeShareObject = s;
}
void MyWindow::SetMouseShareObject(MouseShareObject* p){
	_mouseShareObject = p;
}