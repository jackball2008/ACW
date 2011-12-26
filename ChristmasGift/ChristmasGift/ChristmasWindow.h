#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "GXBase.h"

#include "DisplayObjectModel.h"

#include "Light.h"
#include "Materials.h"

#include "ChristmasTree.h"
#include "Sphere.h"

#include "Seat.h"

#include "Pool.h"
#include "HouseBody.h"
#include "HouseRoof.h"
#include "HouseChemry.h"
#include "SnowParticleSys.h"
#include "FireParticles.h"

#include "SmokeParticles.h"

#include "LightingBolt.h"
#include "Ball.h"
#include "SeatBody.h"
using namespace gxbase;

enum seasons {Spring,Summer,Autumn,Winter};
enum winter_status{winterbegin,winterlast,winterend,happynewyear};

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
	/* fbo bloom                                                                     */
	/************************************************************************/
	GLuint fboID;
	GLuint _textureID;
	GLuint _depthID;

	void CreateFBO();
	void DisplayFBO();
	/************************************************************************/
	/* important varible                                                                     */
	/************************************************************************/
 	GLfloat _cameraPos[4];
	GLfloat mdl[16];
	float camera_org[4];

	/************************************************************************/
	/* object                                                                     */
	/************************************************************************/
	ChristmasTree* _tree;
	Seat* _seatSurface;
	Pool* _pool;
	HouseBody* _houseBody;
	HouseRoof* _houseRoof;
	HouseChemry* _houseChemry;
	Ball* _ball;
	SeatBody* _seatBody;

	SnowParticleSys* _snowflake;
	LightingBolt* _lightingBolt;
	FireParticles* _fire;
	SmokeParticles* _smoke;

	winter_status win_status;
	/************************************************************************/
	/*  tree roate                                             */
	/************************************************************************/
	/*bool _treeCrash;*/
	/*float _treeangle;*/
	/*const float _treeangleInc;*/
	/************************************************************************/
	/* tree shader program                                                                     */
	/************************************************************************/
// 	GLuint _tree_trunk_shader_programID;
// 	GLuint _tree_leaf_shader_programID;
	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	//ModelController* modelController;
	// change name to texture loader
	/************************************************************************/
	/* load texture                                                                     */
	/************************************************************************/
	void LoadTexture(std::string fileName, GLuint &textureID);
	/************************************************************************/
	/* shader load program                                                                     */
	/************************************************************************/
	/************************************************************************/
	/* camera world position                                                                     */
	/************************************************************************/
	void CalculateCameraWorldPosition();


	//void	LoadShaders();
	void CheckShaderEnvironment();											//check shader environment
	GLuint LoadShaderFromFile(const char* vp,const char* fp);				//load shader
	GLuint GenerateShaderObject(std::string filename, GLenum shaderType);	//individual shader function  


	/************************************************************************/
	/* shader ID                                                                  */
	/************************************************************************/
// 	GLuint _cubeShaderProgramID;
// 
// 	GLuint _HouseBodyProgramID;
// 	GLuint _HouseRoofProgramID;
// 	GLuint _TreeProgramID;
// 	GLuint _PoolProgramID;
// 	GLuint _ballProgramID;
// 	GLuint _FireParticleProgramID;
// 	GLuint _SmokeParticleProgramID;
// 	GLuint _SnowflakeParticleProgramID;
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
 	
	/*GLuint testtexid;*/
	/************************************************************************/
	/* reflection stencil buffer control                                                                     */
	/************************************************************************/
/*	bool _loadStencilBuffer;*/
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
	/* Model Create                                                                     */
	/************************************************************************/
	void	LoadModels();
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
	

	void	InitialiseCamera();

	void	InitialiseParicles();

	//void	InitialiseShader();
};

