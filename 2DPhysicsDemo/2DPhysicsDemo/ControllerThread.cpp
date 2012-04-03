#include "ControllerThread.h"


ControllerThread::ControllerThread(void)
{
}


ControllerThread::~ControllerThread(void)
{
}

int ControllerThread::run(){
	while(!_terminate){
		//cout<<"controller"<<endl;
		Sleep(100);

		if(_mouseShareObject->Acquire()){
			__try{
				float x = _mouseShareObject->u;
				float y = _mouseShareObject->v;
				int lr = 0;
				if(_mouseShareObject->left_down || _mouseShareObject->right_down){
					//_mouseShareObject->left_down = false;
					
					if(_mouseShareObject->left_down)
						lr = 1;
					if(_mouseShareObject->right_down)
						lr = 2;
				}
				else{
					lr = 0;
				}
// 				if(_mouseShareObject->right_down){
// 					//_mouseShareObject->right_down = false;
// 					lr = 2;
// 				}
// 				else{
// 					lr = 0;
// 				}
				cout<<"x = "<<x<<" y = "<<y<<" LR = "<<lr<<endl;
			}__finally{
				_mouseShareObject->Release();
			}
		}

		
	}
	return 0;
}
