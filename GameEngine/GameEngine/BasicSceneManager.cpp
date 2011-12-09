#include "BasicSceneManager.h"


BasicSceneManager::BasicSceneManager(void):_hasAssetManager(false),_hasInputManager(false),_hasRenderManager(false),_hasScriptManager(false)
{
}


BasicSceneManager::~BasicSceneManager(void)
{
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


void BasicSceneManager::PlayScene(IGameSceneClass* scene,int* gs){
	scene->SetJumpNextSceneFlag(gs);
	scene->Running();
	_renderManager->RenderOpenGL(scene);
}