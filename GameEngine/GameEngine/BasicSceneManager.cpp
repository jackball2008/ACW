#include "BasicSceneManager.h"


BasicSceneManager::BasicSceneManager(void):_hasAssetManager(false),_hasInputManager(false),_hasRenderManager(false)
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

void BasicSceneManager::MainLoop(){

}