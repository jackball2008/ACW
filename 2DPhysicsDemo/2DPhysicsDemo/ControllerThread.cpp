#include "ControllerThread.h"

const float MAX_LENGTH_IN_SQUARE = 0.1365685425f;
const float MIN_LENGTH_IN_SQUARE = 0.113137085f;

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
// 				float x = _shapeShareObject->u;
// 				float y = _shapeShareObject->v;
// 				_x = _shapeShareObject->u;
// 				_y = _shapeShareObject->v;
// 				_down = _shapeShareObject->left_down;
				
				if(_shapeShareObject->left_down){
					cout<<"x = "<<_shapeShareObject->mouseposition.x<<" y = "<<_shapeShareObject->mouseposition.y<<" LR = "<<1<<endl;

				}
				else{
					
					cout<<"x = "<<_shapeShareObject->mouseposition.x<<" y = "<<_shapeShareObject->mouseposition.y<<" LR = "<<0<<endl;
				}
				
				//////////////////////////////////////////////////////////////////////////
				/************************************************************************/
				/* judge the mouse position in triangle                                                                     */
				/************************************************************************/
				CheckMouseInShape();
				

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

void ControllerThread::CheckMouseInShape(){
	try{
		//int k = _shapeShareObject->renderObjects.size();

		for(vector<Shape*>::iterator ite_vec_shape = _shapeShareObject->renderObjects.begin();   
			ite_vec_shape !=  _shapeShareObject->renderObjects.end();  
			ite_vec_shape++){

				Shape* shape = *ite_vec_shape;
				vector<Point>& pa = shape->points;

				/************************************************************************/
				/* int inside(struct   TPoint   tr[],struct   TPoint   p){ 
				int   i; 
				for   (i=0;i <3;i++) 
				if   (mul(p,tr[i],tr[(i+1)%3])*mul(p,tr[(i+2)%3],tr[(i+1)%3])> 0) 
				return   0; 
				return   1; 
				} 

				int   inside2(struct   TPoint   tr[],struct   TPoint   p){ 
				if   (fabs(area(tr[0],tr[1],tr[2])- 
				area(p,tr[1],tr[2])- 
				area(tr[0],p,tr[2])- 
				area(tr[0],tr[1],p)) <1.0e-20) 
				return   1; 
				else 
				return   0; 
				}                                                                     */
				/************************************************************************/


				//check triangle
				if(shape->type == 2){
					bool intriangle = false;
					for(int i= 0;i < 3; i++){
						//mul(p,tr[i],tr[(i+1)%3])*mul(p,tr[(i+2)%3],tr[(i+1)%3])> 0
						if(Mul(_shapeShareObject->mouseposition,pa.at(i),pa.at((i+1)%3)) * Mul(_shapeShareObject->mouseposition, pa.at((i + 2)%3), pa.at((i+1)%3)) > 0)
							intriangle = false;

					}

					if(!intriangle){
						shape->r = 1.0f;
						shape->g = 0.0f;
						shape->b = 0.0f;
					}else{
						shape->r = 1.0f;
						shape->g = 1.0f;
						shape->b = 0.0f;
					}

// 					for(int i=0; i<3;i++)
// 					{
// 						if(Mul())
// 
// 					}
				}



				//check square
				if(shape->type ==3){

				}


				//check line
				if(shape->type == 1){
					if(_shapeShareObject->mouseposition.y <= pa.at(0).y){
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
