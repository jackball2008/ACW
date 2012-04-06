#include "ControllerThread.h"

const float MAX_LENGTH_IN_SQUARE = 0.1365685425f;
const float MIN_LENGTH_IN_SQUARE = 0.113137085f;

#define PRINTMOUSTPOSITION1

ControllerThread::ControllerThread(void)
{
	_springcount = 0;
}


ControllerThread::~ControllerThread(void)
{
}

int ControllerThread::run(){
	while(!_terminate){
		
		Sleep(10);

		if(_shapeShareObject->Acquire()){
			__try{

				//record springline status
				if(_shapeShareObject->left_down){
#ifdef PRINTMOUSTPOSITION
					cout<<"x = "<<_shapeShareObject->mouseposition.x<<" y = "<<_shapeShareObject->mouseposition.y<<" LR = "<<1<<endl;
#endif	
// 					if(_springcount<1)
// 						_springcount++;
					_springcount = 1;

// 					(_shapeShareObject->renderObjects.at(0))->points.at(0).x = 1;
// 					(_shapeShareObject->renderObjects.at(0))->points.at(0).y = 0;
// 					(_shapeShareObject->renderObjects.at(0))->points.at(1).x =-1;
// 					(_shapeShareObject->renderObjects.at(0))->points.at(1).y = 0;
// 					(_shapeShareObject->renderObjects.at(0))->isvisiable = true;
				}
				else{
#ifdef PRINTMOUSTPOSITION
					cout<<"x = "<<_shapeShareObject->mouseposition.x<<" y = "<<_shapeShareObject->mouseposition.y<<" LR = "<<0<<endl;
#endif	
					_springcount = 0;

// 					(_shapeShareObject->renderObjects.at(0))->points.at(0).x = 2;
// 					(_shapeShareObject->renderObjects.at(0))->points.at(0).y = 2;
// 					(_shapeShareObject->renderObjects.at(0))->points.at(1).x = 2;
// 					(_shapeShareObject->renderObjects.at(0))->points.at(1).y = 2;
// 					(_shapeShareObject->renderObjects.at(0))->isvisiable = false;
				}


				if(_springcount == 1){
					
					
				}
				else{
					
				}

			
				//////////////////////////////////////////////////////////////////////////
				/************************************************************************/
				/* judge the mouse position in triangle                                                                     */
				/************************************************************************/
				CheckMouseInShape();
				
				
			}__finally{
				_shapeShareObject->Release();
			}
		}

	}
	return 0;
}

void ControllerThread::CheckMouseInShape(){
	try{
		
		for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
			ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
			ite_vec_shape++){

				Shape* shape = *ite_vec_shape;
				vector<Point>& pa = shape->points;

				//check any pologon besides line
				if(shape->type >1){

					if(JudgePointInPologon(pa,_shapeShareObject->mouseposition,ORIGIN_P)){
						//change color
						shape->r = 1.0f;
						shape->g = 0.0f;
						shape->b = 0.0f;

						if(_shapeShareObject->left_down)
							shape->becontrolled = true;

					}else{
						shape->r = 1.0f;
						shape->g = 1.0f;
						shape->b = 0.0f;

						shape->becontrolled = false;
					}

				}

				//check line
				if(shape->type == 1){

					if(
						JudgeTwoLineAcroess(ORIGIN_P,_shapeShareObject->mouseposition,pa.at(0),pa.at(1))
						){
						shape->r = 1.0f;
						shape->g = 0.0f;
						shape->b = 0.0f;
					}
					else{
						shape->r = 1.0f;
						shape->g = 1.0f;
						shape->b = 0.0f;
					}
				}




		}
	}catch(vector<Shape*>::iterator){

	}

}
