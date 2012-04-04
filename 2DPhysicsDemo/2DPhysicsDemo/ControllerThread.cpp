#include "ControllerThread.h"


ControllerThread::ControllerThread(void)
{
	_x = 0;
	_y = 0;
	_down = false;
}


ControllerThread::~ControllerThread(void)
{
}

int ControllerThread::run(){
	while(!_terminate){
		
		Sleep(10);

		if(_shapeShareObject->Acquire()){
			__try{
				float x = _shapeShareObject->u;
				float y = _shapeShareObject->v;
				_x = _shapeShareObject->u;
				_y = _shapeShareObject->v;
				_down = _shapeShareObject->left_down;
				
				if(_shapeShareObject->left_down){
					cout<<"x = "<<x<<" y = "<<y<<" LR = "<<1<<endl;

				}
				else{
					
					cout<<"x = "<<x<<" y = "<<y<<" LR = "<<0<<endl;
				}

				//////////////////////////////////////////////////////////////////////////
				/************************************************************************/
				/* judge the mouse position in triangle                                                                     */
				/************************************************************************/
				Test();
				

				//////////////////////////////////////////////////////////////////////////



				
			}__finally{
				_shapeShareObject->Release();
			}
		}

		//share
		//Test();

		
	}
	return 0;
}

void ControllerThread::Test(){
	try{
		for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
			ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
			ite_vec_shape++){

		}
	}catch(vector<Shape*>::iterator){

	}

}
