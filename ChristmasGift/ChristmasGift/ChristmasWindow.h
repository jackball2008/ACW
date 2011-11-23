#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "GXBase.h"
#include "ModelController.h"
#include "DisplayObjectModel.h"


#include "Light.h"
#include "Materials.h"

#include "ChristmasTree.h"
#include "Sphere.h"
#include "Particles.h"
#include "BasicParticles.h"
#include "PointPaticles.h"
#include "SmokeParticles.h"
#include "SnowFlakeParticles.h"
#include "FireParticles.h"

#include "glm/glm.hpp"

using namespace gxbase;

using glm::mat4;



#define USESHADER

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
	bool GenerateShaderProgram(GLuint &programID, GLuint &vID, GLuint &fID, char* vPath, char* fPath);

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


	
private:
	ModelController* modelController;

	/************************************************************************/
	/* shader                                                                     */
	/************************************************************************/
	GLuint _ballShaderProgramID;
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
// 	void TestMethod();
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
	GLuint _shadow;
	Vector4f _shadowPlanepos;
	const Vector4f _PS, _PT, _PR, _PQ;
	bool _switch;
	/************************************************************************/
	/* display object                                                                     */
	/************************************************************************/
	IDisplayObject* _house;
	IDisplayObject* _seat;
	IDisplayObject* _ball;
	DisplayObjectModel* _tree;
	IDisplayObject* _pool;
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
	/*                                                                      */
	/************************************************************************/
	
};

