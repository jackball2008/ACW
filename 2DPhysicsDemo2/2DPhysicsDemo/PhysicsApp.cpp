#include "PhysicsApp.h"
#include <math.h>

const float EDGE_LENGTH = 0.04f;
static PhysicsApp theApp;
PhysicsApp::PhysicsApp(void)
{

	/************************************************************************/
	/* create working threads                                                                     */
	/************************************************************************/
	_netReceiveThread = new NetReceiveThread();
	_netSendThread = new NetSendThread();
	_physicsThread = new PhysicsThread();
}


PhysicsApp::~PhysicsApp(void)
{

	/************************************************************************/
	/* delete all working threads except window thread                                                                     */
	/************************************************************************/
	delete _netReceiveThread;
	delete _netSendThread;
	delete _physicsThread;
}



void PhysicsApp::OnCreate(){
	/************************************************************************/
	/* before all thread start, finish the initialize shape position                                                           */
	/************************************************************************/
	InitializeAllShpes();
	/************************************************************************/
	/* bound share objects                                                                     */
	/************************************************************************/
	//main thread
	_mywindow.SetShapeShareObject(&_shapeShareObject);
	
	_physicsThread->SetShapeShareObject(&_shapeShareObject);
	/************************************************************************/
	/* window thread start                                                                     */
	/************************************************************************/
	_mywindow.Show();
	//_mywindow.SetSize(1024,768);
	_mywindow.SetSize(768,768);
	//_mywindow.SetSize(480,480);
	_mywindow.SetPosition(512,0);

	
	_physicsThread->start();
	



}

void PhysicsApp::OnDestroy(){

	/************************************************************************/
	/* terminate all working threads                                                                     */
	/************************************************************************/
	_netReceiveThread->terminate();
	_netReceiveThread->waitForTermination();

	_netSendThread->terminate();
	_netSendThread->waitForTermination();



	_physicsThread->terminate();
	_physicsThread->waitForTermination();


}

/************************************************************************/
/* private function                                                                     */
/************************************************************************/
#define DRAWTRIANGLE1
#define ADDTESTSQUARE1
void PhysicsApp::InitializeAllShpes(){
	int sid = 0;
	
	Shape* ground = new Line();
	YPoint p1;
	p1.x = -1.0f;
	p1.y = -0.9f;
	YPoint p2;
	p2.x = 1.0f;
	p2.y = -0.9f;
	ground->points.push_back(p1);
	ground->points.push_back(p2);
	//ground->SetData(p1,p2);
	//set position
	ground->pos.x = (p1.x + p2.x) / 2;
	ground->pos.y = (p1.y + p2.y) / 2;
	sid++;
	ground->id = sid;
	//set axis, ground only have one axis
	YPoint ax;
	ax.x = p1.x - p2.x;
	ax.y = p1.y - p2.y;
	ax.Normalize();
	ax.Right2D();
	//ax.z = 0 = len;
	ground->project_axis.push_back(ax);
	//set 
	_shapeShareObject.renderObjects.push_back(ground);
	

	//set squares
	//25 * 4
	YPoint tristartp;
	for(int i = 0; i<2 /*4*/; i ++){
		for( int j =0; j <25 /*25*/ ; j ++){
			Shape* square = new Square();
			//set points
			YPoint p1;
			p1.x = -0.5f + j * EDGE_LENGTH;
			p1.y = 0.9f + i * EDGE_LENGTH;

			YPoint p2;
			p2.x = p1.x + EDGE_LENGTH;
			p2.y = p1.y;

			YPoint p3;
			p3.x = p2.x;
			p3.y = p2.y + EDGE_LENGTH;

			YPoint p4;
			p4.x = p1.x;
			p4.y = p3.y;
			square->points.push_back(p1);
			square->points.push_back(p2);
			square->points.push_back(p3);
			square->points.push_back(p4);
			
			
			//set position
			
			square->pos.x = (float)(p1.x + p3.x + p2.x + p4.x)/4;
			square->pos.y = (float)(p1.y + p3.y + p2.y + p4.y)/4;

			
			//////////////////////////////////////////////////////////////////////////
			//square have two axises
			//set x axis
			YPoint ax;
			float x1 = (p3.x + p2.x)/2;
			
			float y1 = (p3.y + p2.y)/2;
			
			x1 = x1 - square->pos.x;
			y1 = y1 - square->pos.y;
			
			ax.x = x1;
			ax.y = y1;
			ax.Normalize();
			ax.z = EDGE_LENGTH/2;
			//set y axis
			YPoint yx;
			ax.Right2D(yx);
			yx.z = EDGE_LENGTH/2;
			
			square->project_axis.push_back(ax);
			square->project_axis.push_back(yx);
			//////////////////////////////////////////////////////////////////////////
			sid++;
			square->id = sid;
			_shapeShareObject.renderObjects.push_back(square);
			if(i==3 && j==6){
				//setting triangle start position
				tristartp = p4;
			}

		}
	}

	//set triangles
	/////////////////////////////
#ifdef DRAWTRIANGLE

	YPoint nextlevelstartp;
	float h = 0.03464101615f;	
	for(int i=5; i >0; i--){
		for(int j=0; j<i;j++){
			YPoint p1;
			p1 = tristartp;

			YPoint p2;

			p2.x = p1.x + 0.04f;
			p2.y = p1.y;

			YPoint p3;
			p3.x = p1.x + (p2.x - p1.x)/2;
			p3.y = p1.y + h;

			YPoint mid;
			mid.x = (p1.x + p2.x + p3.x)/3;
			mid.y = (p1.y + p2.y + p3.y)/3;

			//add
			Shape* triangle = new Triangle();
			triangle->SetData(p1,p2,p3);
			sid++;
			triangle->id = sid;
			triangle->pos = mid;
			
			_shapeShareObject.renderObjects.push_back(triangle);
			if(j==0){
				nextlevelstartp = p3;
			}
			//set the second triangle start position
			tristartp = p2;
 
			//set the reverse triangle
			if( (j+1)<i  ){
				//reverse
				YPoint q1;
				q1 = p3;
				YPoint q2;
				q2 = p2;
				YPoint q3;
				q3.x = q1.x + 0.04f;
				q3.y = q1.y;

				YPoint qmid;
				qmid.x = (q1.x + q2.x + q3.x)/3;
				qmid.y = (q1.y + q2.y + q3.y)/3;

				Shape* triangle = new Triangle();
				triangle->SetData(q1,q2,q3);
				sid++;
				triangle->id = sid;
				triangle->pos = qmid;
				
				_shapeShareObject.renderObjects.push_back(triangle);
			}
			

		}

		tristartp = nextlevelstartp;
	}
#endif	
	/////////////////////////////


}