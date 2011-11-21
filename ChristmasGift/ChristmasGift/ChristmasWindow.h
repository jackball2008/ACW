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

#include "Particles.h"
#include "BasicParticles.h"
#include "PointPaticles.h"
#include "SmokeParticles.h"

using namespace gxbase;




#define SEASONLENGTH 3*30*24*60*60

#define USESHADER

class ChristmasWindow: public GLWindowEx
{
public:
	ChristmasWindow(void);
	
	void OnCreate();
	void OnDisplay();
	void OnIdle();
	void OnKeyboard(int key, bool down);
	void initialiseLights();
	void initShadow();
	void updateShadow();
	void OnMouseMove(int x, int y);
	void OnMouseButton(MouseButton button, bool down);
	void OnUpdate();
	void drawSporLights();

	/************************************************************************/
	/* shader                                                                     */
	/************************************************************************/
	void loadShaders();
	GLuint generateShaderObject(std::string filename, GLenum shaderType);

	/************************************************************************/
	/* reflection                                                                     */
	/************************************************************************/
	void LoadStencil();
	void DrawReflection();
	/************************************************************************/
	/* shader function                                                                     */
	/************************************************************************/
	
private:
	ModelController* modelController;

	/************************************************************************/
	/* test materials  billboard practices                                                         */
	/************************************************************************/
	Materials _green;
	
	void TestMethod();
	
	SmokeParticles _smoke;

	/*GLuint testtexid;*/

	
	/************************************************************************/
	/* reflection stencil buffer control                                                                     */
	/************************************************************************/
	bool _loadStencilBuffer;
	/************************************************************************/
	/* shader                                                                     */
	/************************************************************************/
	GLuint _shaderProgramID;
	/************************************************************************/
	/* main light                                                                     */
	/************************************************************************/
	Lights _sun;
	Vector4f _sunPos;
	/************************************************************************/
	/* spotlights                                                                     */
	/************************************************************************/
	Lights _spotlightRed,_spotlightGreen,_spotlightBlue,_spotlightWhite;
	bool _drawSpotLights;
	/************************************************************************/
	/* shadow map         not work now                           */
	/************************************************************************/
	GLuint _shadow;
	Vector4f _planepos;
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
	long _seasonCounter;
	float _timerCounter;
	float _timeDecFactor;
	/************************************************************************/
	/* Simulation data                                               */
	/************************************************************************/
	const float _angleInc;
	float _angle;
	float _cameraAngle, _cameraPosition, _cameraRotation,_cameraHerical;
	bool _leftDown, _rightDown;
	/************************************************************************/
	/* shadow and mutil texture                                                                     */
	/************************************************************************/
	bool   _bHaveMultitex;	// do we have mulitexture support?
	bool   _bMultitex;		// using multitexturing?

	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	
};

