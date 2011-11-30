#include "GameClassDefine.h"
#include "MainFunctionDefine.h"
#include "ManagerDefine.h"


void main( int argc, const char* argv[])
{
/*	GameSceneManager gm;*/
	//gm.Initialize();

	
	//testP = &GameSceneManager::TestMethod;
// 	TestP tp = &GameSceneManager::TestMethod;
// 	
// 	InitP init = &GameSceneManager::Initialize;
// 
// 	(gm.*init)();
// 	(gm.*tp)(256);
// 
// 
// 	
// 
	InitializeGameClass();
	int k;
	cin>>k;

}

void InitializeGameClass(){
	myGame.assetManager = new BasicAssetManager();
	myGame.inputManager = new BasicInputManager();
	myGame.renderManager = new BasicRenderManager();
	myGame.sceneManager = new BasicSceneManager();
	myGame.scriptManager = new BasicScriptManager();

	myGame.scriptManager->Initialize();
}

