#include "RenderThread.h"


RenderThread::RenderThread(void)
{

}


RenderThread::~RenderThread(void)
{
}

int RenderThread::run(){
	while(!_terminate){
		//cout<<"render"<<endl;
		/*Render();*/
		Sleep(100);
	}
	return 0;
}

void RenderThread::SetShapeShareObject( ShapeShareObject* s){
	_shapeShareObject = s;
}

void RenderThread::Render(){
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.0,1.0,0.0);




	//vector<Shape*> plist = PhysicsApp::Get().GetElements();
	/*_shapeShareObject*/
	vector<Shape*> plist = _shapeShareObject->GetData();
	for(vector<Shape*>::iterator ite_vec_shape = plist.begin();   
		ite_vec_shape != plist.end();  
		ite_vec_shape++){  


			Shape* shape = *ite_vec_shape;
			vector<Point>* pa = &shape->points;//  shape->GetData();

			if(shape->GetType() == 1){
				//draw line


				glColor3f(1.0,1.0,0.0);
				//glLineWidth(5);
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

				/*glPointSize(5);*/
				glBegin(GL_POINTS);
				glVertex2f(pa->at(4).x, pa->at(4).y);
				glEnd();
			}

	}




	/*SwapBuffers();*/
}