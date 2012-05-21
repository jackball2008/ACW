#include "PhysicsApp.h"
#include <math.h>

const float EDGE_LENGTH = 0.04f;
static PhysicsApp theApp;
PhysicsApp::PhysicsApp(void)
{

	/************************************************************************/
	/* create working threads                                                                     */
	/************************************************************************/
	_netWorkThread = new NetReceiveThread();
	//_netSendThread = new NetSendThread();
	_physicsThread = new PhysicsThread();
}


PhysicsApp::~PhysicsApp(void)
{

	/************************************************************************/
	/* delete all working threads except window thread                                                                     */
	/************************************************************************/
	delete _netWorkThread;
	//delete _netSendThread;
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

	//////////////////////////////////////////////////////////////////////////
	_netWorkThread->SetShapeShareObject(&_shapeShareObject);
	_netWorkThread->start();
	



}

void PhysicsApp::OnDestroy(){

	/************************************************************************/
	/* terminate all working threads                                                                     */
	/************************************************************************/
	_netWorkThread->terminate();
	_netWorkThread->waitForTermination();

// 	_netSendThread->terminate();
// 	_netSendThread->waitForTermination();



	_physicsThread->terminate();
	_physicsThread->waitForTermination();


}

/************************************************************************/
/* private function                                                                     */
/************************************************************************/
#define DRAWTRIANGLE
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
	for(int i = 0; i<3/*4*/; i ++){
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
			if(i==2 && j==6){
				//setting triangle start position
				tristartp = p4;
			}

		}
	}

	//add test triangle
	/*
	Shape* triangle = new Triangle();

	YPoint sp1;
	sp1.x = 0;//tristartp;
	sp1.y = 0;
	YPoint sp2;

	sp2.x = sp1.x + 0.04f;
	sp2.y = sp1.y;

	YPoint sp3;
	sp3.x = sp1.x + (sp2.x - sp1.x)/2;
	sp3.y = sp1.y + 0.03464101615f;

	triangle->points.push_back(sp1);
	triangle->points.push_back(sp2);
	triangle->points.push_back(sp3);
	//set position

	triangle->pos.x = (sp1.x + sp2.x + sp3.x)/3;
	triangle->pos.y = (sp1.y + sp2.y + sp3.y)/3;

	//triangle have three axises
	//set 1 axis
	YPoint axis1;
	float x1 = (sp1.x+sp2.x)/2;
	float y1 = (sp1.y+sp2.y)/2;
	x1 = x1 - triangle->pos.x;
	y1 = y1 - triangle->pos.y;
	float len1 = sqrt(x1*x1+y1*y1);
	axis1.x = x1;
	axis1.y = y1;
	axis1.Normalize();
	axis1.z = len1;

	//set 2 axis
	YPoint axis2;
	float x2 = (sp2.x+sp3.x)/2;
	float y2 = (sp2.y+sp3.y)/2;
	x2 = x2 - triangle->pos.x;
	y2 = y2 - triangle->pos.y;
	float len2 = sqrt(x2*x2+y2*y2);
	axis2.x = x2;
	axis2.y = y2;
	axis2.Normalize();
	axis2.z = len2;

	//set 3 axis
	YPoint axis3;
	float x3 = (sp3.x+sp1.x)/2;
	float y3 = (sp3.y+sp1.y)/2;
	x3 = x3 - triangle->pos.x;
	y3 = y3 - triangle->pos.y;
	float len3 = sqrt(x3*x3+y3*y3);
	axis3.x = x3;
	axis3.y = y3;
	axis3.Normalize();
	axis3.z = len3;

	triangle->project_axis.push_back(axis1);
	triangle->project_axis.push_back(axis2);
	triangle->project_axis.push_back(axis3);

	sid++;
	triangle->id = sid;

	_shapeShareObject.renderObjects.push_back(triangle);
	*/

	//set triangles
	/////////////////////////////
#ifdef DRAWTRIANGLE

	YPoint nextlevelstartp;
	float h = 0.03464101615f;	
	for(int i=0/*5*/; i<2 /*>0*/; i++/*--*/){
		//for(int j=0; j<i;j++){

			Shape* triangle = new Triangle();

			YPoint p1;
			p1 = tristartp;
			
			YPoint p2;

			p2.x = p1.x + 0.04f;
			p2.y = p1.y;

			YPoint p3;
			p3.x = p1.x + (p2.x - p1.x)/2;
			p3.y = p1.y + h;

			triangle->points.push_back(p1);
			triangle->points.push_back(p2);
			triangle->points.push_back(p3);
			//set position
			
			triangle->pos.x = (p1.x + p2.x + p3.x)/3;
			triangle->pos.y = (p1.y + p2.y + p3.y)/3;

			//triangle have three axises
			//set 1 axis
			YPoint axis1;
			float x1 = (p1.x+p2.x)/2;
			float y1 = (p1.y+p2.y)/2;
			x1 = x1 - triangle->pos.x;
			y1 = y1 - triangle->pos.y;
			float len1 = sqrt(x1*x1+y1*y1);
			axis1.x = x1;
			axis1.y = y1;
			axis1.Normalize();
			axis1.z = len1;

			//set 2 axis
			YPoint axis2;
			float x2 = (p2.x+p3.x)/2;
			float y2 = (p2.y+p3.y)/2;
			x2 = x2 - triangle->pos.x;
			y2 = y2 - triangle->pos.y;
			float len2 = sqrt(x2*x2+y2*y2);
			axis2.x = x2;
			axis2.y = y2;
			axis2.Normalize();
			axis2.z = len2;

			//set 3 axis
			YPoint axis3;
			float x3 = (p3.x+p1.x)/2;
			float y3 = (p3.y+p1.y)/2;
			x3 = x3 - triangle->pos.x;
			y3 = y3 - triangle->pos.y;
			float len3 = sqrt(x3*x3+y3*y3);
			axis3.x = x3;
			axis3.y = y3;
			axis3.Normalize();
			axis3.z = len3;

			triangle->project_axis.push_back(axis1);
			triangle->project_axis.push_back(axis2);
			triangle->project_axis.push_back(axis3);
			
			sid++;
			triangle->id = sid;
			
			_shapeShareObject.renderObjects.push_back(triangle);
// 			if(j==0){
// 				nextlevelstartp = p3;
// 			}
			//set the second triangle start position
			tristartp.x = p2.x+0.04;
			tristartp.y = p2.y;
 
			//set the reverse triangle
			/**
			if( (j+1)<i  ){
				Shape* triangle = new Triangle();
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

				
				triangle->points.push_back(p1);
				triangle->points.push_back(p2);
				triangle->points.push_back(p3);


				//triangle have three axises
				//set 1 axis
				YPoint axis1;
				float x1 = (q1.x+q2.x)/2;
				float y1 = (q1.y+q2.y)/2;
				x1 = x1 - triangle->pos.x;
				y1 = y1 - triangle->pos.y;
				float len1 = sqrt(x1*x1+y1*y1);
				axis1.x = x1;
				axis1.y = y1;
				axis1.Normalize();
				axis1.z = len1;

				//set 2 axis
				YPoint axis2;
				float x2 = (q2.x+q3.x)/2;
				float y2 = (q2.y+q3.y)/2;
				x2 = x2 - triangle->pos.x;
				y2 = y2 - triangle->pos.y;
				float len2 = sqrt(x2*x2+y2*y2);
				axis2.x = x2;
				axis2.y = y2;
				axis2.Normalize();
				axis2.z = len2;

				//set 3 axis
				YPoint axis3;
				float x3 = (q3.x+q1.x)/2;
				float y3 = (q3.y+q1.y)/2;
				x3 = x3 - triangle->pos.x;
				y3 = y3 - triangle->pos.y;
				float len3 = sqrt(x3*x3+y3*y3);
				axis3.x = x3;
				axis3.y = y3;
				axis3.Normalize();
				axis3.z = len3;

				triangle->project_axis.push_back(axis1);
				triangle->project_axis.push_back(axis2);
				triangle->project_axis.push_back(axis3);



				sid++;
				triangle->id = sid;
				_shapeShareObject.renderObjects.push_back(triangle);
			}
			*/

		//}

		tristartp = nextlevelstartp;
	}
#endif	
	/////////////////////////////
	//save id
	_shapeShareObject.shape_id_index = sid;

}