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
	/*_controllerThread = new ControllerThread();*/
	_physicsThread = new PhysicsThread();
	/*_renderThread = new RenderThread();*/
}


PhysicsApp::~PhysicsApp(void)
{

	/************************************************************************/
	/* delete all working threads except window thread                                                                     */
	/************************************************************************/
	delete _netReceiveThread;
	delete _netSendThread;
	/*delete _controllerThread;*/
	delete _physicsThread;
	/*delete _renderThread;*/
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
	

	//controller thread
	
	/*_controllerThread->SetShapeShareObject(&_shapeShareObject);*/
	_physicsThread->SetShapeShareObject(&_shapeShareObject);
	/************************************************************************/
	/* window thread start                                                                     */
	/************************************************************************/
	_mywindow.Show();
	//_mywindow.SetSize(768,768);
	_mywindow.SetSize(480,480);
	_mywindow.SetPosition(1024,0);

	
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

// 	_controllerThread->terminate();
// 	_controllerThread->waitForTermination();

	_physicsThread->terminate();
	_physicsThread->waitForTermination();

// 	_renderThread->terminate();
// 	_renderThread->waitForTermination();
}

/************************************************************************/
/* private function                                                                     */
/************************************************************************/
#define DRAWTRIANGLE1
#define ADDTESTSQUARE1
void PhysicsApp::InitializeAllShpes(){
	int sid = 0;
	//set springline
	/**
	SpringLine *springLine = new SpringLine();
	YPoint sp;
	sp.x = ORIGIN_SPRING_X;
	sp.y = ORIGIN_SPRING_Y;
	YPoint ep;
	ep.x = ORIGIN_SPRING_X;
	ep.y = ORIGIN_SPRING_Y;
	springLine->SetData(sp,ep);
	sid++;
	springLine->id = sid;

	_shapeShareObject.renderObjects.push_back(springLine);
	*/
	//set ground
	/**
	Shape* ground = new Line();
	YPoint p1;
	p1.x = -1.0f;
	p1.y = -0.9f;
	YPoint p2;
	p2.x = 1.0f;
	p2.y = -0.9f;
	YPoint lmid;
	lmid.x = (p1.x + p2.x) / 2;
	lmid.y = (p1.y + p2.y) / 2;
	ground->SetData(p1,p2);
	sid++;
	ground->id = sid;
	ground->middlepoint = lmid;

	_shapeShareObject.renderObjects.push_back(ground);
	*/


#ifdef ADDTESTSQUARE
	{
		YPoint tp1;
		tp1.x = 0.02f+0.5f;
		tp1.y = 0.02f;
		YPoint tp2;
		tp2.x = -0.02f+0.5f;
		tp2.y = 0.02f;
		YPoint tp3;
		tp3.x = -0.02f+0.5f;
		tp3.y = -0.02f;
		YPoint tp4;
		tp4.x = 0.02f+0.5f;
		tp4.y = -0.02f;
		YPoint tpm;
		tpm.x = 0.0f+0.5f;
		tpm.y = 0.0f;
		Shape* tsquare = new Square();
		tsquare->SetData(tp1,tp2,tp3,tp4);
		sid++;
		tsquare->id = sid;
		tsquare->middlepoint = tpm;
		_shapeShareObject.renderObjects.push_back(tsquare);

	}
#endif

	//set squares
	//25 * 4
	YPoint tristartp;
	for(int i = 0; i<2 /*4*/; i ++){
		for( int j =0; j <1 /*25*/ ; j ++){
			YPoint p1;
			p1.x = -0.5f + j * 0.04f;
			p1.y = -0.9f + i * 0.04f;

			YPoint p2;
			p2.x = p1.x + 0.04f;
			p2.y = p1.y;

			YPoint p3;
			p3.x = p2.x;
			p3.y = p2.y + 0.04f;

			YPoint p4;
			p4.x = p1.x;
			p4.y = p3.y;

			YPoint p5;
			p5.x = (float)(p1.x + p3.x + p2.x + p4.x)/4;
			p5.y = (float)(p1.y + p3.y + p2.y + p4.y)/4;

			Shape* square = new Square();
			//////////////////////////////////////////////////////////////////////////
			square->xw = 0.02f;
			square->yw = 0.02f;
			float x1 = (p3.x - p2.x)/2;
			float y1 = (p3.y - p2.y)/2;
			x1 = x1 - p5.x;
			y1 = y1 - p5.y;
			float len = sqrt(x1*x1 + y1*y1);
			//unit direction vector
			square->dx = x1/len;
			square->dy = y1/len;
			square->px = p5.x;
			square->py = p5.y;
			//////////////////////////////////////////////////////////////////////////
			square->SetData(p1,p2,p3,p4);
			sid++;
			square->id = sid;
			square->middlepoint = p5;
			/*_shapeShareObject.SetData(square);*/
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
			triangle->middlepoint = mid;
			
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
				triangle->middlepoint = qmid;
				
				_shapeShareObject.renderObjects.push_back(triangle);
			}
			

		}

		tristartp = nextlevelstartp;
	}
#endif	
	/////////////////////////////


}