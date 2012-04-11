#include "ControllerThread.h"

const float MAX_LENGTH_IN_SQUARE = 0.1365685425f;
const float MIN_LENGTH_IN_SQUARE = 0.113137085f;

#define PRINTMOUSTPOSITION1

ControllerThread::ControllerThread(void)
{
	/*_springcount = 0;*/
}


ControllerThread::~ControllerThread(void)
{
}

int ControllerThread::run(){
	while(!_terminate){
		
		Sleep(10);

		if(_shapeShareObject->Acquire()){
			__try{
#ifdef PRINTMOUSTPOSITION
				//record springline status
				if(_shapeShareObject->left_down){
#ifdef PRINTMOUSTPOSITION
					cout<<"x = "<<_shapeShareObject->mouseposition.x<<" y = "<<_shapeShareObject->mouseposition.y<<" LR = "<<1<<endl;
#endif	
				}
				else{
#ifdef PRINTMOUSTPOSITION
					cout<<"x = "<<_shapeShareObject->mouseposition.x<<" y = "<<_shapeShareObject->mouseposition.y<<" LR = "<<0<<endl;
#endif	

				}
#endif

				//////////////////////////////////////////////////////////////////////////
				/************************************************************************/
				/* judge the springline start point position in triangle                                                                     */
				/************************************************************************/
				//CheckSpringLineStartPointInShape();
				
				
			}__finally{
				_shapeShareObject->Release();
			}
		}

	}
	return 0;
}

void ControllerThread::CheckSpringLineStartPointInShape(){
	try{
		
		for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
			ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
			ite_vec_shape++){

				Shape* shape = *ite_vec_shape;
				vector<Point>& pa = shape->points;

				//check any pologon besides line
				if(shape->type >1){
					//(_shapeShareObject->renderObjects.at(0))->points.at(0)
					//_shapeShareObject->mouseposition
					if(JudgePointInPologon(pa,(_shapeShareObject->renderObjects.at(0))->points.at(0),ORIGIN_P))
					{
						

						if(_shapeShareObject->left_hold){

							shape->becontrolled = true;
							//change color
							shape->r = 1.0f;
							shape->g = 0.0f;
							shape->b = 0.0f;
						}else{
							shape->r = 1.0f;
							shape->g = 1.0f;
							shape->b = 0.0f;

							shape->becontrolled = false;
						}
							

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
						JudgeTwoLineAcroess(ORIGIN_P,(_shapeShareObject->renderObjects.at(0))->points.at(0),pa.at(0),pa.at(1))
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
