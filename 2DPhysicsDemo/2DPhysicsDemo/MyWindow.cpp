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
	
	/************************************************************************/
	/* draw mouse points                                                                     */
	/************************************************************************/
	glColor3f(1.0f,1.0f,0.0f);
	glPointSize(5);
	glBegin(GL_POINTS);
	
	glVertex2f(_shapeShareObject->u, _shapeShareObject->v);
	glEnd();
	
	/*vector<Shape*> plist = _shapeShareObject->GetData();*/
	for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
		ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
		ite_vec_shape++){  
			
			
			Shape* shape = *ite_vec_shape;
			vector<Point>& pa = shape->points;
			/*vector<Point>* pa = &shape->points;*/
			if(shape->type == 1 && shape->visiable){
				//draw line


				glColor3f(shape->r,shape->g,shape->b);
				
				glBegin(GL_LINES);
				glVertex2f(pa.at(0).x, pa.at(0).y);
				glVertex2f(pa.at(1).x, pa.at(1).y);
				
				glEnd();





			}
			if(shape->type == 2 && shape->visiable){
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
			if(shape->type == 3 && shape->visiable){
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

}
void	MyWindow::OnKeyboard(int key, bool down){

}
void	MyWindow::OnMouseMove(int x, int y){

	if(_shapeShareObject->Acquire()){
		//now modify the shared memory
		__try{
			if(Width()){
				_shapeShareObject->old_u = _shapeShareObject->u;
				_shapeShareObject->u = 2.0f * (float)x / (float)Width() - 1.0f;
				
			}
			if(Height()){
				_shapeShareObject->old_v = _shapeShareObject->v;
				_shapeShareObject->v = 2.0f * (float)y / (float)Height() - 1.0f;
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
					_shapeShareObject->left_down = true;
				else
					_shapeShareObject->left_down = false;
				break;
			case MBRight:
				if(down)
					_shapeShareObject->right_down = true;
				else
					_shapeShareObject->right_down = false;
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