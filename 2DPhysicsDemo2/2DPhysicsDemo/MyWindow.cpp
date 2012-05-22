#include "MyWindow.h"
#include "SpringLine.h"
//#include "PhysicsApp.h"

MyWindow::MyWindow(void)
{
	ishold = false;
	left_down = false;
	last_left_down = false;

	mouse_x = mouse_y = 0;

	//hDC = extra->m_hdc;
	//InitializeHUD();

}


MyWindow::~MyWindow(void)
{
}

void	MyWindow::InitializeHUD()
{
	//HUD initialize

	num_of_objs_own = new FontGameSprite();

	num_of_objs_own->letter = "Question";

	
	//specila setting
	num_of_objs_own->drawType = FONT_DRAW_STR;
	num_of_objs_own->displayStr = "No Signal";
	num_of_objs_own->fontHeight = -15;

	num_of_objs_own->color3f.x = 1.0;
	num_of_objs_own->color3f.y = 1.0;
	num_of_objs_own->color3f.z = 1.0;
	num_of_objs_own->pos3f.x = -0.1f;
	num_of_objs_own->pos3f.y = 0.2f;
	num_of_objs_own->num = 1;
	num_of_objs_own->BuildFont();

	


}



void	MyWindow::OnCreate(){
	GLWindowEx::OnCreate();
}


void	MyWindow::OnDisplay(){


	
	glClear(GL_COLOR_BUFFER_BIT /*| GL_DEPTH_BUFFER_BIT*/);
	
	
	
	//HUD
// 	glPushMatrix();
// 	glTranslatef(0.0f,0.0f,-1.0f);
// 	glColor3f(num_of_objs_own->color3f.x,num_of_objs_own->color3f.y,num_of_objs_own->color3f.z);
// 	glRasterPos2f(num_of_objs_own->pos3f.x,num_of_objs_own->pos3f.y);
// 	num_of_objs_own->Draw();
// 	glPopMatrix();

	/************************************************************************/
	/* draw mouse position   holding red , unholding green                                                                  */
	/************************************************************************/
	if(_shapeShareObject->left_hold)
		glColor3f(1.0f,0.0f,0.0f);
	else
		glColor3f(0.0f,1.0f,0.0f);
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2f(mouse_x, mouse_y);
	glEnd();
	/************************************************************************/
	/* draw mouse position end                                                                     */
	/************************************************************************/

	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* draw spring                                                                     */
	/************************************************************************/
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
	/************************************************************************/
	/* draw spring end                                                                     */
	/************************************************************************/

	
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



// 	glDisable(GL_LIGHTING);
// 	glColor3f(1.0f,0.0,0.0);
// 	glRasterPos2f(-0.1f,-0.9f);
// 	Printf("Font");
// 	glEnable(GL_LIGHTING);

	SwapBuffers();


}
void	MyWindow::OnIdle(){

	//////////////////////////////////////////////////////////////////////////
	Redraw();
	//////////////////////////////////////////////////////////////////////////

}
void	MyWindow::OnKeyboard(int key, bool down){



	if (!down) return;


	if(_shapeShareObject->Acquire())
	{
		__try{

			switch( tolower(key) )
			{
				case 'p':
					_shapeShareObject->paused = !_shapeShareObject->paused;
					break;

				case 'b':
					//PhysicsApp &papp = PhysicsApp::Get().m_shared;
					break;

			}


		}__finally{
			_shapeShareObject->Release();
		}
	}



	


}
void	MyWindow::OnMouseMove(int x, int y){

	if(_shapeShareObject->Acquire()){
		//now modify the shared memory
		__try{
			if(Width()){
				//_shapeShareObject->mouse_x = 2.0f * (float)x / (float)Width() - 1.0f;
				mouse_x = 2.0f * (float)x / (float)Width() - 1.0f;
				_shapeShareObject->springLine->sp.x = mouse_x;
			}
			if(Height()){
				//_shapeShareObject->mouse_y = 2.0f * (float)y / (float)Height() - 1.0f;
				mouse_y = 2.0f * (float)y / (float)Height() - 1.0f;
				_shapeShareObject->springLine->sp.y = mouse_y;
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
					//_shapeShareObject->springLine->isvisiable = true;
				}
				else
				{
					if(last_left_down != down && last_left_down == true)
					{
						last_left_down = down;
						//cout<<"press up"<<endl;
						_shapeShareObject->left_hold = false;
					}
					//_shapeShareObject->springLine->isvisiable = false;

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