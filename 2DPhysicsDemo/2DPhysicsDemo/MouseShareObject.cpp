#include "MouseShareObject.h"


MouseShareObject::MouseShareObject(void):u(0),v(0),old_u(0),old_v(0),left_down(false), right_down(false)
{
	mutex = CreateMutex(NULL, FALSE, "mouseMutes");
}


MouseShareObject::~MouseShareObject(void)
{
	CloseHandle(mutex);
}

//need update to thread safe
// void MouseShareObject::SetMousePosition(const float&u, const float&v){
// 	//save old position
// 	old_u = u;
// 	old_v = v;
// 	//save new position
// 	u = u;
// 	v = v;
// 	cout<<"x = "<<u<<" y = "<<v<<endl;
// }
//need update to thread safe
// void MouseShareObject::SetMouseButton(const int&lr, const bool&down){
// 	if(lr == 1){
// 		left_down = down;
// 		cout<<"Left down"<<endl;
// 	}
// 	else{
// 		right_down = down;
// 		cout<<"right down"<<endl;
// 	}
// }

