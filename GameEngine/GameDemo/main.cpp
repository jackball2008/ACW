#include "GameClassDefine.h"
#include "MainFunctionDefine.h"
#include "ManagerDefine.h"

#define USEOPENGL

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
	/************************************************************************/
	/* initialize every manager                                                                     */
	/************************************************************************/
	/************************************************************************/
	/* rendermanager initialize                                                                     */
	/************************************************************************/
#ifdef USEOPENGL
	myGame.renderManager->SetRenderType(OPENGL);
#else
	myGame.renderManager->SetRenderType(DIECTX);
#endif
	myGame.renderManager->Initialize();

	

	/************************************************************************/
	/* game ini and go                                                                     */
	/************************************************************************/
	myGame.Initialize();
	myGame.InitializeMainMenu();
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
