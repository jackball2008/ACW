#include "MyWindow.h"
// #include "Shape.h"
// #include "PhysicsApp.h"

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
	
	
	vector<Shape*> plist = _shapeShareObject->GetData();
	for(vector<Shape*>::iterator ite_vec_shape = plist.begin();   
		ite_vec_shape != plist.end();  
		ite_vec_shape++){  
			
			
			Shape* shape = *ite_vec_shape;
			vector<Point>* pa = shape->GetData();

			if(shape->GetType() == 1){
				//draw line


				glColor3f(1.0,1.0,0.0);
				
				glBegin(GL_LINES);
				glVertex2f(pa->at(0).x, pa->at(0).y);
				glVertex2f(pa->at(1).x, pa->at(1).y);
				
				glEnd();





			}
			if(shape->GetType() == 2){
				//draw triangles
				
				glColor3f(1.0,1.0,0.0);
				glBegin(GL_LINE_LOOP);
				glVertex2f(pa->at(0).x, pa->at(0).y);
				glVertex2f(pa->at(1).x, pa->at(1).y);
				glVertex2f(pa->at(2).x, pa->at(2).y);
				glEnd();

				glBegin(GL_POINTS);
				glVertex2f(pa->at(4).x, pa->at(4).y);
				glEnd();
			}
			if(shape->GetType() == 3){
				//draw squares
				
				
				glColor3f(1.0,1.0,0.0);
				glBegin(GL_LINE_LOOP);
				glVertex2f(pa->at(0).x, pa->at(0).y);
				glVertex2f(pa->at(1).x, pa->at(1).y);
				glVertex2f(pa->at(2).x, pa->at(2).y);
				glVertex2f(pa->at(3).x, pa->at(3).y);
				glEnd();

				
				glBegin(GL_POINTS);
				glVertex2f(pa->at(4).x, pa->at(4).y);
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

}
void	MyWindow::OnMouseButton(MouseButton button, bool down){

}

//use once
void MyWindow::SetShapeShareObject( ShapeShareObject* s){
	_shapeShareObject = s;
}
void MyWindow::SetMouseShareObject(MouseShareObject* p){
	_mouseShareObject = p;
}