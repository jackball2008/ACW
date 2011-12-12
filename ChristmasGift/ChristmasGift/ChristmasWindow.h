#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "GXBase.h"

#include "DisplayObjectModel.h"

#include "ModelController.h"
#include "Light.h"
#include "Materials.h"

#include "ChristmasTree.h"
#include "Sphere.h"
// #include "Sphere.h"
// #include "House.h"
// #include "Seat.h"
// #include "Ball.h"
// #include "Pool.h"
// #include "TestCube.h"

// #include "SmokeParticles.h"
// #include "SnowFlakeParticles.h"
// #include "FireParticles.h"

/*#include "FlashLighting.h"*/


using namespace gxbase;

enum seasons {Spring,Summer,Autumn,Winter};

class ChristmasWindow: public GLWindowEx
{
public:
	ChristmasWindow(void);
	/************************************************************************/
	/* main logic                                                                     */
	/************************************************************************/
	void	OnCreate();
	void	OnDisplay();
	void	OnIdle();
	void	OnKeyboard(int key, bool down);
	void	OnMouseMove(int x, int y);
	void	OnMouseButton(MouseButton button, bool down);
	void	OnUpdate();
	
	

	
	

	
private:
	/************************************************************************/
	/* object                                                                     */
	/************************************************************************/
	ChristmasTree* _tree;
	/************************************************************************/
	/*  tree roate                                             */
	/************************************************************************/
	bool _treeCrash;
	float _treeangle;
	const float _treeangleInc;
	/************************************************************************/
	/* tree shader program                                                                     */
	/************************************************************************/
	GLuint _tree_trunk_shader_programID;
	GLuint _tree_leaf_shader_programID;
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	ModelController* modelController;
	// change name to texture loader
	/************************************************************************/
	/* shader load program                                                                     */
	/************************************************************************/
	
	void	LoadShaders();
	void CheckShaderEnvironment();											//check shader environment
	GLuint LoadShaderFromFile(const char* vp,const char* fp);				//load shader
	GLuint GenerateShaderObject(std::string filename, GLenum shaderType);	//individual shader function  


	/************************************************************************/
	/* shader ID                                                                  */
	/************************************************************************/
	GLuint _cubeShaderProgramID;

	GLuint _HouseBodyProgramID;
	GLuint _HouseRoofProgramID;
	GLuint _TreeProgramID;
	GLuint _PoolProgramID;
	GLuint _ballProgramID;
	GLuint _FireParticleProgramID;
	GLuint _SmokeParticleProgramID;
	GLuint _SnowflakeParticleProgramID;
	/************************************************************************/
	/* particles                                                                     */
	/************************************************************************/
// 	SmokeParticles _smoke;
// 	SnowFlakeParticles _snowflake;
// 	FireParticles _fire;
	/************************************************************************/
	/* test materials  billboard practices                                                         */
	/************************************************************************/
// 	Materials _green;
 	void TestMethod();
	/*GLuint testtexid;*/
	/************************************************************************/
	/* reflection stencil buffer control                                                                     */
	/************************************************************************/
	bool _loadStencilBuffer;
	/************************************************************************/
	/* main light                                                                     */
	/************************************************************************/
	Lights _sunLight;
	Vector4f _sunPos;
	Sphere _sunSphere;
	Materials  _sunMaterial;
	/************************************************************************/
	/* spotlights                                                                     */
	/************************************************************************/
	Lights _spotlightRed,_spotlightGreen,_spotlightBlue,_spotlightWhite;
	bool _drawSpotLights;

	/************************************************************************/
	/* display object                                                                     */
	/************************************************************************/
	

// 	IDisplayObject* _house;
// 	IDisplayObject* _seat;
// 	IDisplayObject* _ball;
// 	
// 	IDisplayObject* _pool;
// 	DisplayObjectModel* _testObject;
// 
// 	FlashLighting *flashLight;
	/************************************************************************/
	/* simulating season changing                                                                     */
	/************************************************************************/
	seasons _currentSeason;
	/*long _seasonCounter;*/
	float _timerCounter;
	float _timeSpeedFactor;
	/************************************************************************/
	/* Simulation data                                               */
	/************************************************************************/
	const float _sunRunCycleAngleInc;
	float _sunRunCycleAngle;
	float _cameraAngle, _cameraPositionZ, _cameraRotation,_cameraHerical;
	bool _leftDown, _rightDown;
	/************************************************************************/
	/* shadow and mutil texture  Flag                                                                   */
	/************************************************************************/
	bool   _bHaveMultitex;	// do we have mulitexture support?
	bool   _bMultitex;		// using multitexturing?

	void CheckMultitextureSupport();
	void LoadCamera();
	void LoadBasicOpenGLParame();
	/************************************************************************/
	/* pause timer                                                                     */
	/************************************************************************/
	bool	Pause(int a);
	int		pauseCounter;




	/************************************************************************/
	/* lighting                                                                     */
	/************************************************************************/
	void	InitialiseLights();
	void	DrawSporLights();

	
// 	GLuint	GenerateShaderObject(std::string filename, GLenum shaderType);
// 	void	CheckShaderEnvironment();
// 	bool	GenerateShaderProgram(GLuint &programID, char* vPath, char* fPath);

	/************************************************************************/
	/* reflection                                                                     */
	/************************************************************************/
	void	LoadStencil();
	void	DrawReflection();
	/************************************************************************/
	/* Model Create                                                                     */
	/************************************************************************/
	void	InitialiseModels();

	void	InitialiseCamera();

	void	InitialiseParicles();

	//void	InitialiseShader();
};

