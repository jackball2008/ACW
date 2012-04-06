#include "PhysicsThread.h"


PhysicsThread::PhysicsThread(void)
{
}


PhysicsThread::~PhysicsThread(void)
{
}

int PhysicsThread::run(){
	while(!_terminate){
		/*cout<<"physics"<<endl;*/
		Sleep(10);
		//
		if(_shapeShareObject->Acquire()){
			__try{

				TraceMouseMove();
			}__finally{
				_shapeShareObject->Release();
			}
		}



	}
	return 0;
}

void PhysicsThread::TraceMouseMove(){
	/*try{*/
		for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
			ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
			ite_vec_shape++){
				Shape* shape = *ite_vec_shape;
				vector<Point>& pa = shape->points;

				/** work not well
				if(shape->type>1 && shape->becontrolled){
					float mx = _shapeShareObject->mouseposition.x - _shapeShareObject->old_mouseposition.x;
					float my = _shapeShareObject->mouseposition.y - _shapeShareObject->old_mouseposition.y;

					for(int i=0;i<pa.size();i++){
						pa.at(i).x = pa.at(i).x + mx;
						pa.at(i).y = pa.at(i).y + my;
					}

					shape->middlepoint.x = shape->middlepoint.x + mx;
					shape->middlepoint.y = shape->middlepoint.y + my;

				}
				*/

		}

// 	}catch(vector<Shape*>::iterator){
// 
// 	}
}
