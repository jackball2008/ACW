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
#include "House.h"
#include "Seat.h"
#include "Ball.h"
#include "Pool.h"
#include "TestCube.h"

#include "SmokeParticles.h"
#include "SnowFlakeParticles.h"
#include "FireParticles.h"


using namespace gxbase;


class ChristmasWindow: public GLWindowEx
{
public:
	ChristmasWindow(void);
	/************************************************************************/
	/* main logic                                                                     */
	/************************************************************************/
	void OnCreate();
	void OnDisplay();
	void OnIdle();
	void OnKeyboard(int key, bool down);
	void OnMouseMove(int x, int y);
	void OnMouseButton(MouseButton button, bool down);
	void OnUpdate();
	
	/************************************************************************/
	/* lighting                                                                     */
	/************************************************************************/
	void InitialiseLights();
	void DrawSporLights();
	/************************************************************************/
	/* shadow                                                                     */
	/************************************************************************/
	void InitialiseShadow();
	void UpdateShadow();
	/************************************************************************/
	/* shader                                                                     */
	/************************************************************************/
	void LoadShaders();
	GLuint GenerateShaderObject(std::string filename, GLenum shaderType);
	void CheckShaderEnvironment();
	bool GenerateShaderProgram(GLuint &programID, char* vPath, char* fPath);

	/************************************************************************/
	/* reflection                                                                     */
	/************************************************************************/
	void LoadStencil();
	void DrawReflection();
	/************************************************************************/
	/* Model Create                                                                     */
	/************************************************************************/
	void InitialiseModels();

	void InitialiseCamera();

	void InitialiseParicles();

	void InitialiseShader();

	bool keepStatyIn(int a);
	int stayCounter;

	
private:
	ModelController* modelController;

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
	SmokeParticles _smoke;
	SnowFlakeParticles _snowflake;
	FireParticles _fire;
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
	/* shadow map         not work now                           */
	/************************************************************************/
// 	GLuint _shadow;
// 	Vector4f _shadowPlanepos;
// 	const Vector4f _PS, _PT, _PR, _PQ;
// 	bool _switch;
	/************************************************************************/
	/* display object                                                                     */
	/************************************************************************/
	IDisplayObject* _house;
	IDisplayObject* _seat;
	IDisplayObject* _ball;
	ChristmasTree* _tree;
	IDisplayObject* _pool;
	DisplayObjectModel* _testObject;
	/************************************************************************/
	/* simulating season changing                                                                     */
	/************************************************************************/
	seasons _currentSeason;
	/*long _seasonCounter;*/
	float _timerCounter;
	float _timeDecFactor;
	/************************************************************************/
	/* Simulation data                                               */
	/************************************************************************/
	const float _angleInc;
	float _angle;
	float _cameraAngle, _cameraPositionZ, _cameraRotation,_cameraHerical;
	bool _leftDown, _rightDown;
	/************************************************************************/
	/* shadow and mutil texture  Flag                                                                   */
	/************************************************************************/
	bool   _bHaveMultitex;	// do we have mulitexture support?
	bool   _bMultitex;		// using multitexturing?

	/************************************************************************/
	/*  tree roate                                             */
	/************************************************************************/
	bool _treeCrash;
	float _treeangle;
	const float _treeangleInc;
};

