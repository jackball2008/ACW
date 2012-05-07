#include "MyWindow.h"
#include "SpringLine.h"

MyWindow::MyWindow(void)
{
	ishold = false;
	left_down = false;
	last_left_down = false;
}


MyWindow::~MyWindow(void)
{
}

void	MyWindow::OnCreate(){
	GLWindowEx::OnCreate();
}


void	MyWindow::OnDisplay(){


	
	glClear(GL_COLOR_BUFFER_BIT);

	/************************************************************************/
	/* draw mouse position   holding red , unholding green                                                                  */
	/************************************************************************/
	if(_shapeShareObject->left_hold)
		glColor3f(1.0f,0.0f,0.0f);
	else
		glColor3f(0.0f,1.0f,0.0f);
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2f(_shapeShareObject->mouse_x, _shapeShareObject->mouse_y);
	glEnd();
	/************************************************************************/
	/* draw mouse position end                                                                     */
	/************************************************************************/

	//////////////////////////////////////////////////////////////////////////
	if(_shapeShareObject->left_hold){
		
		//cout<<"s x = "<<_shapeShareObject->springLine->sp.x<<" s y = "<<_shapeShareObject->springLine->sp.y<<" e x = "<<_shapeShareObject->springLine->ep.x<<" e y = "<<_shapeShareObject->springLine->ep.y<<endl;
		//draw springline
		glColor3f(_shapeShareObject->springLine->r,_shapeShareObject->springLine->g,_shapeShareObject->springLine->b);
		glPointSize(4);
		glBegin(GL_LINES);
		glVertex2f(_shapeShareObject->springLine->sp.x, _shapeShareObject->springLine->sp.y);
		glVertex2f(_shapeShareObject->springLine->ep.x, _shapeShareObject->springLine->ep.y);

		glEnd();
	}

	
	//Draw squares and triangles
	for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
		ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
		ite_vec_shape++){  
			
			Shape* shape = *ite_vec_shape;
// 			if(shape == NULL) 
// 				cout<<"error"<<endl;
			vector<YPoint>& pa = shape->points;
			//draw line
			if(shape->type == 1)
			{
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
				glVertex2f(shape->pos.x, shape->pos.y);
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
				glVertex2f(shape->pos.x, shape->pos.y);
				glEnd();
			}

	}

	SwapBuffers();


}
void	MyWindow::OnIdle(){

	//////////////////////////////////////////////////////////////////////////
	Redraw();
	//////////////////////////////////////////////////////////////////////////

}
void	MyWindow::OnKeyboard(int key, bool down){

}
void	MyWindow::OnMouseMove(int x, int y){

	if(_shapeShareObject->Acquire()){
		//now modify the shared memory
		__try{
			if(Width()){
				_shapeShareObject->mouse_x = 2.0f * (float)x / (float)Width() - 1.0f;
			}
			if(Height()){
				_shapeShareObject->mouse_y = 2.0f * (float)y / (float)Height() - 1.0f;
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
				if(down)
				{
					if(last_left_down != down && last_left_down == false)
					{
						last_left_down = down;
						//cout<<"press down"<<endl;
						_shapeShareObject->left_hold = false;
					}
					if(last_left_down == down)//true
					{
						//cout<<"holding..."<<endl;
						_shapeShareObject->left_hold = true;
					}
					_shapeShareObject->springLine->isvisiable = true;
				}
				else
				{
					if(last_left_down != down && last_left_down == true)
					{
						last_left_down = down;
						//cout<<"press up"<<endl;
						_shapeShareObject->left_hold = false;
					}
					_shapeShareObject->springLine->isvisiable = false;

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