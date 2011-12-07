#include "KinectInputManager.h"
#include <windows.h>


#include <MSR_NuiApi.h>

KinectInputManager::KinectInputManager(void)
{
}


KinectInputManager::~KinectInputManager(void)
{
	ReleaseHardware();
}

void KinectInputManager::Initialize(){
	InitializeKinect();
}

void KinectInputManager::InitializeKinect(){
	NextDepthFrameEvent = CreateEvent(NULL,TRUE,FALSE,NULL);
	NextSkeletonEvent = CreateEvent(NULL,TRUE,FALSE,NULL);
	StopKinectEvent = CreateEvent(NULL,FALSE,FALSE,NULL);


	HRESULT hr;
	hr= NuiInitialize(
		NUI_INITIALIZE_FLAG_USES_DEPTH_AND_PLAYER_INDEX |
		NUI_INITIALIZE_FLAG_USES_SKELETON
		);
	if(FAILED(hr)){
		try{
			throw ErrorException(1, "Could not initialize kinect device", __FILE__, __LINE__);
		}
		catch(ErrorException& e)
		{
			ErrorManager* Log = ErrorManager::GetInstance();
			Log->Create("KinectInitialize.txt");
			Log->Output("*****ERROR*****");
			Log->LogException(e);
			Log->Output("***************");
			Log->Close();
		}
		//MessageBox(_windowHandle,"Could not initialize kinect device","ERROR",MB_OK|MB_ICONEXCLAMATION);
	}

	hr = NuiSkeletonTrackingEnable(NextSkeletonEvent,0);

	hr = NuiImageStreamOpen(
		NUI_IMAGE_TYPE_DEPTH_AND_PLAYER_INDEX,
		NUI_IMAGE_RESOLUTION_320x240,
		0,
		2,
		NextDepthFrameEvent,
		&_depthStream
		);
	KinectThreadHandle = CreateThread(NULL,0,KinectProcessThread,this,0,NULL);

}

void KinectInputManager::ReleaseHardware(){

	if(StopKinectEvent != NULL){

		SetEvent(StopKinectEvent);

		if(KinectThreadHandle!=NULL){
			WaitForSingleObject(KinectThreadHandle,INFINITE);
			CloseHandle(KinectThreadHandle);
		}
		CloseHandle(StopKinectEvent);
	}

	NuiShutdown();

	if(NextSkeletonEvent && ( NextSkeletonEvent != INVALID_HANDLE_VALUE)){
		CloseHandle(NextSkeletonEvent);
		NextSkeletonEvent = NULL;
	}
	if(NextDepthFrameEvent && ( NextDepthFrameEvent != INVALID_HANDLE_VALUE ) ){
		CloseHandle(NextDepthFrameEvent);
		NextDepthFrameEvent = NULL;
	}

}

DWORD WINAPI KinectInputManager::KinectProcessThread(LPVOID pParam){
	KinectInputManager* app = (KinectInputManager*)pParam;
	HANDLE hEvents[3];
	hEvents[0] = app->StopKinectEvent;
	hEvents[2] = app->NextDepthFrameEvent;
	hEvents[1] = app->NextSkeletonEvent;

	int eventID;

	while(true){

		eventID = WaitForMultipleObjects(sizeof(hEvents)/sizeof(hEvents[0]),hEvents,FALSE, 100);

		//stop event
		if(eventID == 0)
			break;
		//process events
		switch(eventID){
		case 2:
			app->DepthEventHandler();
			break;
		case 1:
			app->SkeletonEventHandler();
			break;
		}

	}

	return 0;

}

void KinectInputManager::DepthEventHandler(){}

void KinectInputManager::SkeletonEventHandler(){
	NUI_SKELETON_FRAME skeletonFrame;

	HRESULT hr = NuiSkeletonGetNextFrame(0,&skeletonFrame);

	bool foundSkeleton = false;
	for(int i = 0;i< NUI_SKELETON_COUNT;i++){
		if(skeletonFrame.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED){
			foundSkeleton = true;
		}
	}

	//quite if there are no actively tracked skeletons
	if(!foundSkeleton){
		return;
	}

	NuiTransformSmooth(&skeletonFrame,NULL);

	//go though skeletons to find the active ones
	for(int i = 0;i < NUI_SKELETON_COUNT;i++){
		if(skeletonFrame.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED){
			BuildSkeleton(&skeletonFrame.SkeletonData[i],i);
		}
	}

}

void KinectInputManager::BuildSkeleton(NUI_SKELETON_DATA* skeletonData,int& i){
	for(int i = 0;i<NUI_SKELETON_POSITION_COUNT;i++){
		(skeletonSprite->SkeletonPoints[i]).x = skeletonData->SkeletonPositions[i].x;
		(skeletonSprite->SkeletonPoints[i]).y = skeletonData->SkeletonPositions[i].y;
	} 
}
void KinectInputManager::SetSkeletonDataOuptTarget(SkeletonGameSprite *sp){
	skeletonSprite = sp;
}
