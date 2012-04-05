#include "ControllerThread.h"

const float MAX_LENGTH_IN_SQUARE = 0.1365685425f;
const float MIN_LENGTH_IN_SQUARE = 0.113137085f;

#define PRINTMOUSTPOSITION1

ControllerThread::ControllerThread(void)
{
// 	_x = 0;
// 	_y = 0;
// 	_down = false;
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
				if(_shapeShareObject->left_down){

					cout<<"x = "<<_shapeShareObject->mouseposition.x<<" y = "<<_shapeShareObject->mouseposition.y<<" LR = "<<1<<endl;

					

				}
				else{

					cout<<"x = "<<_shapeShareObject->mouseposition.x<<" y = "<<_shapeShareObject->mouseposition.y<<" LR = "<<0<<endl;

					
				}
#endif				
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
		//int k = _shapeShareObject->renderObjects.size();

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



				//check square  no use
				/**
				if(shape->type ==4){
					//JudgePointInSquare
					if(JudgePointInPologon(pa,_shapeShareObject->mouseposition,ORIGIN_P))
					{

						shape->r = 1.0f;
						shape->g = 0.0f;
						shape->b = 0.0f;
					}
					else
					{
						shape->r = 1.0f;
						shape->g = 1.0f;
						shape->b = 0.0f;

					}


				}
				*/

				//check line
				if(shape->type == 1){
// 					bool acroess = false;
// 					int k = pa.size();
// 					acroess = JudgeTwoLineAcroess(ORIGIN_P,_shapeShareObject->mouseposition,pa.at(0),pa.at(1));


					if(/*_shapeShareObject->mouseposition.y <= pa.at(0).y*//*acroess*/
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
