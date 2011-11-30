#include "GameClassDefine.h"
#include "MainFunctionDefine.h"
#include "ManagerDefine.h"


void main( int argc, const char* argv[])
{

	
	InitializeGameClass();

	/************************************************************************/
	/* stop auto close                                                                     */
	/************************************************************************/
	int k;
	cin>>k;
}

void InitializeGameClass(){
	myGame.assetManager = new BasicAssetManager();
	myGame.inputManager = new BasicInputManager();
	myGame.renderManager = new BasicRenderManager();
	myGame.scriptManager = new BasicScriptManager();
	
	//myGame.sceneManager = new BasicSceneManager();
	myGame.sceneManager = new GameSceneManager();

	//very important
	BindSceneManagerAndOtherManagers();
	
	myGame.Initialize();
	myGame.InitializeMainMenu();

	//enter main loop
	myGame.GameStateMainLoop();
	
}



void BindSceneManagerAndOtherManagers(){
	myGame.sceneManager->SetAssetManager(myGame.assetManager);
	myGame.sceneManager->SetInputManager(myGame.inputManager);
	myGame.sceneManager->SetRenderManager(myGame.renderManager);
	myGame.sceneManager->SetScriptManager(myGame.scriptManager);

}


void TestMethod(){
	std::cout<<"Main Test Method"<<endl;
}
