#include "NetReceiveThread.h"


NetReceiveThread::NetReceiveThread(void)
{
	_sendshapeid = -99;
}


NetReceiveThread::~NetReceiveThread(void)
{
}

int NetReceiveThread::run(){
	while(!_terminate){
		
		if(_shapeShareObject->Acquire())
		{
			__try
			{

				CheckShapePos();





			}
			__finally{
				_shapeShareObject->Release();
			}


		}

		//cout<<"net working..."<<endl;
		Sleep(10);
	}
	return 0;
}


void NetReceiveThread::CheckShapePos()
{
	//if pos out of range, send it's position
	int objnum = _shapeShareObject->renderObjects.size();
	for(int i=0;i<objnum;i++)
	{
		Shape* shapeA = _shapeShareObject->renderObjects.at(i);
		if (shapeA->type != 1)
		{
			//make sure shape is not ground
			//if pos 
			// 
			if((shapeA->pos.x > 1 || shapeA->pos.x < -1) && shapeA->pos.y> 0 && shapeA->id != _sendshapeid && !shapeA->issent)
			{

				_sendshapeid = shapeA->id;
				shapeA->issent = true;
				//send it

				//assemble data
				// head x
				string big_head = " ";
				string x_head = "x ";
				string y_head = " y ";
				string vx_head = " q ";
				string vy_head = " w ";
				string end = " e";

				stringstream ss(stringstream::in|stringstream::out);

				ss<<shapeA->pos.x;
				string x_str = ss.str();

				ss<<shapeA->pos.y;
				string y_str = ss.str();

				ss<<shapeA->velocity.x;
				string vx_str = ss.str();

				ss<<shapeA->velocity.y;
				string vy_str = ss.str();


				big_head.append(x_head);
				big_head.append(x_str);


				big_head.append(y_head);
				big_head.append(y_str);

				big_head.append(vx_head);
				big_head.append(vx_str);

				big_head.append(vy_head);
				big_head.append(vy_str);

				big_head.append(end);

				cout<<big_head<<endl;







				

				//cout<<"send shape data, id = "<<shapeA->id<<endl;

			}

		}




	}




	//send


	//receive


}

void NetReceiveThread::ReceiveData()
{

}
void NetReceiveThread::SendData()
{

}