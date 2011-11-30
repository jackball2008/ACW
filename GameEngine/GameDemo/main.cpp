#include "GameClassDefine.h"
#include "MainFunctionDefine.h"
#include "ManagerDefine.h"


void main( int argc, const char* argv[])
{

	
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

	myGame.Initialize();
	myGame.InitializeMainMenu();

}

