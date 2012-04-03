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

		if(_mouseShareObject->Acquire()){
			__try{
				float x = _mouseShareObject->u;
				float y = _mouseShareObject->v;
				_x = _mouseShareObject->u;
				_y = _mouseShareObject->v;
				_down = _mouseShareObject->left_down;
				/*int lr = 0;*/
				if(_mouseShareObject->left_down /*|| _mouseShareObject->right_down*/){
					cout<<"x = "<<x<<" y = "<<y<<" LR = "<<1<<endl;
// 					if(_mouseShareObject->left_down)
// 						lr = 1;
// 					if(_mouseShareObject->right_down)
// 						lr = 2;
				}
				else{
					/*lr = 0;*/
					cout<<"x = "<<x<<" y = "<<y<<" LR = "<<0<<endl;
				}

				/*cout<<"x = "<<x<<" y = "<<y<<" LR = "<<lr<<endl;*/
			}__finally{
				_mouseShareObject->Release();
			}
		}

		//share
		//Test();
// 		if(_shapeShareObject->Acquire()){
// 			__try{
// 				//compare the position with each shape
// 				for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
// 					ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
// 					ite_vec_shape++){
// 
// 
// 				}
// 
// 
// 			}__finally{
// 				_shapeShareObject->Release();
// 			}
// 		}
		
	}
	return 0;
}

void ControllerThread::Test(){
// 	if(_shapeShareObject->Acquire()){
// 		__try{
// 			//compare the position with each shape
// 			for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
// 				ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
// 				ite_vec_shape++){
// 
// 
// 			}
// 
// 
// 		}__finally{
// 			_shapeShareObject->Release();
// 		}
// 	}
}

