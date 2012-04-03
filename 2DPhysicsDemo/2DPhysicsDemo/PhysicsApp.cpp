#include "PhysicsApp.h"
#include <math.h>


static PhysicsApp theApp;
PhysicsApp::PhysicsApp(void)
{

	/************************************************************************/
	/* create working threads                                                                     */
	/************************************************************************/
	_netReceiveThread = new NetReceiveThread();
	_netSendThread = new NetSendThread();
	_controllerThread = new ControllerThread();
	_physicsThread = new PhysicsThread();
	_renderThread = new RenderThread();
}


PhysicsApp::~PhysicsApp(void)
{

	/************************************************************************/
	/* delete all working threads except window thread                                                                     */
	/************************************************************************/
	delete _netReceiveThread;
	delete _netSendThread;
	delete _controllerThread;
	delete _physicsThread;
	delete _renderThread;
}

// PhysicsApp &PhysicsApp::Get()
// {
// 
// 	return theApp;
// }

void PhysicsApp::OnCreate(){
	/************************************************************************/
	/* before all thread start, finish the initialize shape position                                                           */
	/************************************************************************/
	InitializeAllShpes();

	/************************************************************************/
	/* bound share objects                                                                     */
	/************************************************************************/
	_mywindow.SetShapeShareObject(&_shapeShareObject);
	_mywindow.SetMouseShareObject(&_mouseShareObject);

	_renderThread->SetShapeShareObject(&_shapeShareObject);
	/************************************************************************/
	/* window thread start                                                                     */
	/************************************************************************/
	_mywindow.Show();
	_mywindow.SetSize(768,768);
	_mywindow.SetPosition(0,0);



	_netReceiveThread->start();
	_netSendThread->start();
	_controllerThread->start();
	_physicsThread->start();
	_renderThread->start();



}

void PhysicsApp::OnDestroy(){

	/************************************************************************/
	/* terminate all working threads                                                                     */
	/************************************************************************/
	_netReceiveThread->terminate();
	_netReceiveThread->waitForTermination();

	_netSendThread->terminate();
	_netSendThread->waitForTermination();

	_controllerThread->terminate();
	_controllerThread->waitForTermination();

	_physicsThread->terminate();
	_physicsThread->waitForTermination();

	_renderThread->terminate();
	_renderThread->waitForTermination();
}

/************************************************************************/
/* private function                                                                     */
/************************************************************************/
void PhysicsApp::InitializeAllShpes(){
	//set line
	Shape* line = new Line();
	Point p1;
	p1.x = -1.0f;
	p1.y = -0.9f;
	Point p2;
	p2.x = 1.0f;
	p2.y = -0.9f;
	line->SetData(p1,p2,p2,p2,p2);
	
	//add
	_shapeShareObject.SetData(line);


	//set squares
	//25 * 4
	Point tristartp;
	for(int i = 0; i< 4; i ++){
		for( int j =0; j < 25 ; j ++){
			Point p1;
			p1.x = -0.5f + j * 0.04f;
			p1.y = -0.9f + i * 0.04f;

			Point p2;
			p2.x = p1.x + 0.04f;
			p2.y = p1.y;

			Point p3;
			p3.x = p2.x;
			p3.y = p2.y + 0.04f;

			Point p4;
			p4.x = p1.x;
			p4.y = p3.y;

			Point p5;
			p5.x = (float)(p1.x + p3.x + p2.x + p4.x)/4;
			p5.y = (float)(p1.y + p3.y + p2.y + p4.y)/4;

			Shape* square = new Square();
			square->SetData(p1,p2,p3,p4,p5);
			_shapeShareObject.SetData(square);

			if(i==3 && j==6){
				//setting triangle start position
				tristartp = p4;
			}

		}
	}

	//set triangles
	Point nextlevelstartp;
	float h = 0.03464101615f;	
	for(int i=5; i >0; i--){
		for(int j=0; j<i;j++){
			Point p1;
			p1 = tristartp;

			Point p2;

			p2.x = p1.x + 0.04f;
			p2.y = p1.y;

			Point p3;
			p3.x = p1.x + (p2.x - p1.x)/2;
			p3.y = p1.y + h;

			Point mid;
			mid.x = (p1.x + p2.x + p3.x)/3;
			mid.y = (p1.y + p2.y + p3.y)/3;

			//add
			Shape* triangle = new Triangle();
			triangle->SetData(p1,p2,p3,p3,mid);
			_shapeShareObject.SetData(triangle);
			if(j==0){
				nextlevelstartp = p3;
			}
			//set the second triangle start position
			tristartp = p2;
 
			//set the reverse triangle
			if( (j+1)<i  ){
				//reverse
				Point q1;
				q1 = p3;
				Point q2;
				q2 = p2;
				Point q3;
				q3.x = q1.x + 0.04f;
				q3.y = q1.y;

				Point qmid;
				qmid.x = (q1.x + q2.x + q3.x)/3;
				qmid.y = (q1.y + q2.y + q3.y)/3;

				Shape* triangle = new Triangle();
				triangle->SetData(q1,q2,q3,q3,qmid);
				_shapeShareObject.SetData(triangle);
			}
			

		}

		tristartp = nextlevelstartp;
	}
	



}