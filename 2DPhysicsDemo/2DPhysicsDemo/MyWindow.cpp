#include "MyWindow.h"
#include "Shape.h"
#include "PhysicsApp.h"

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
	glColor3f(1.0,1.0,0.0);

// 	glBegin(GL_TRIANGLES);
// 	glVertex2f(-0.9f, -0.9f);
// 	glVertex2f(+0.9f,-0.9f);
// 	glVertex2f(0.0f,0.9f);
// 	glEnd();

// 	glColor3f(1.0,1.0,0.0);
// 	glLineWidth(10);
// 	glBegin(GL_LINES);
// 	glVertex2f(-0.5f, 0.0f);
// 	glVertex2f(+0.5f, 0.0f);
// 
// 	glEnd();
	

	vector<Shape*> plist = PhysicsApp::Get().GetElements();

	for(vector<Shape*>::iterator ite_vec_shape = plist.begin();   
		ite_vec_shape != plist.end();  
		ite_vec_shape++){  
			
			
			Shape* shape = *ite_vec_shape;
// 			int k = shape->GetType();
// 			k = 99;
			//(*ite_vec_shape)++;  
			if(shape->GetType() == 1){
				//draw line
				//get p1 p2
				vector<Point>* pa = shape->GetData();
				
// 				float x1 = pa->at(0).x;
// 				float y1 = pa->at(0).y;
// 				float x2 = pa->at(1).x;
// 				float y2 = pa->at(1).y;

				glColor3f(1.0,1.0,0.0);
				//glLineWidth(5);
				glBegin(GL_LINES);
				glVertex2f(pa->at(0).x, pa->at(0).y);
				glVertex2f(pa->at(1).x, pa->at(1).y);
				
				glEnd();

// 				glBegin(GL_TRIANGLES);
// 				glVertex2f(-0.9f, -0.9f);
// 				glVertex2f(+0.9f,-0.9f);
// 				glVertex2f(0.0f,0.9f);
// 				glEnd();



			}
			if(shape->GetType() == 2){
				//draw triangles
			}
			if(shape->GetType() == 3){
				//draw squares
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