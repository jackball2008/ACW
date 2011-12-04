#include "BasicSceneManager.h"


BasicSceneManager::BasicSceneManager(void):_hasAssetManager(false),_hasInputManager(false),_hasRenderManager(false),_hasScriptManager(false)
{
}


BasicSceneManager::~BasicSceneManager(void)
{
}

void BasicSceneManager::Initialize(){
	//MessageBoxA(0,"Scene Manager Initialize ok ","", MB_OK);
	/**
	try{
		if(!_hasAssetManager)
			throw ErrorException(1, "No AssetManager", __FILE__, __LINE__);
		else
			_assetManager->Initialize();

		if(!_hasInputManager)
			throw ErrorException(1, "No InputManager", __FILE__, __LINE__);
		else
			_inputManager->Initialize();

		if(!_hasRenderManager)
			throw ErrorException(1, "No RenderManager", __FILE__, __LINE__);
		else
			_renderManager->Initialize();
	}
	catch(ErrorException& e)
	{
		ErrorManager* Log = ErrorManager::GetInstance();
		Log->Create("SceneManagerLog.txt");
		Log->Output("*****ERROR*****");
		Log->LogException(e);
		Log->Output("***************");
		Log->Close();
	}
	*/
}

void BasicSceneManager::SetAssetManager(IAssetManager* am){
	_assetManager = am;
	_hasAssetManager = true;
}

void BasicSceneManager::SetInputManager(IInputManager* im){
	_inputManager = im;
	_hasInputManager = true;
}

void BasicSceneManager::SetRenderManager(IRenderManager* rm){
	_renderManager = rm;
	_hasRenderManager = true;
}

void BasicSceneManager::SetScriptManager(IScriptManager* sm){
	_scriptManager = sm;
	_hasScriptManager = true;
}

/************************************************************************/
/* main loop function                                                                     */
/************************************************************************/
void BasicSceneManager::OperateCurrentGameScene(bool *con){

	//1, creat scene : make or load or initialize game scene unit
	CreateCurrentSceneEnvironment();

	//2, play
	RunningGameInCurrentSceneEnvironment();


	//3, end process
	EndCurrentSceneEnvironment();
	//when game run to the end
	// this is the last Scene
	std::cout<<"BasicSceneManager::OperateCurrentGameScene"<<endl;
	*con = false;
}
//update level
void BasicSceneManager::CreateCurrentSceneEnvironment(){

}
//update game elements
void BasicSceneManager::RunningGameInCurrentSceneEnvironment(){

}

void BasicSceneManager::EndCurrentSceneEnvironment(){

}

/************************************************************************/
/* Main Menu                                                                     */
/************************************************************************/
void BasicSceneManager::SetMainMenu(GameMenuClass* m){
	mainMenu = m;
}
/************************************************************************/
/* Game state running callback                                                                    */
/************************************************************************/
//CHOOSEMENU
void BasicSceneManager::RunChooseMenu(int* gs){






}
//GAMEPLAYING
void BasicSceneManager::RunGamePlaying(int* gs){

}
//SHOWSCORE
void BasicSceneManager::RunShowScore(int* gs){

}
//GAMEEXIT
void BasicSceneManager::RunGameExit(int* gs){

}

//Draw
void BasicSceneManager::DrawScene(){




}