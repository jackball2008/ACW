#include "ChristmasWindow.h"

#define SEASONLENGTH 3*30*24*60*60


#define DRAWREFLECTION
#define ALLOWSEATCULLFACE1

#define DRAWSEAT




/*(0.64,1.0,0.51*/
const float pool_pos_x = 0.55;
const float pool_pos_y = -0.06;
const float pool_pos_z = 0.53;
/*0.5,0.5,0.5*/
const float pool_scal_x = 0.58;
const float pool_scal_y = 0.58;
const float pool_scal_z = 0.58;
/************************************************************************/
/* tree and reflection  glTranslatef(0.65,-1.0,0.0);
glScalef(0.25,0.25,0.25);                                                                   */
/************************************************************************/
const float tree_pos_x = 0.6;
const float tree_pos_y = 0.0;
const float tree_pos_z = -0.2;
const float tree_scal_x = 0.2;
const float tree_scal_y = 0.2;
const float tree_scal_z = 0.2;


ChristmasWindow::ChristmasWindow(void) :
	//_treeangleInc(10),//tree crash angle inc
	_sunRunCycleAngleInc(30)
{
	SetSize(512,512);
	SetDepthBits(24);
	SetTitle("Christmas Gift From Xiaoyu Ma email: maxiaoyuzdz@gmail.com");

	//stencilbuffer
	_loadStencilBuffer = true;
	_drawSpotLights = false;
	//multitexture support check
	_bMultitex = _bHaveMultitex = false;
	_sunRunCycleAngle = 0.0f;
	_currentSeason = Spring;
	_timerCounter = 0;
	_timeSpeedFactor = 1;

// 	_treeCrash = false;
// 	_treeangle = 0.0;
	pauseCounter = 0;
}




void ChristmasWindow::OnCreate()
{
	GLWindowEx::OnCreate();

	CheckMultitextureSupport();

	LoadCamera();

	LoadBasicOpenGLParame();
	//////////////////////////////////////////////////////////////////////////
	InitialiseLights();
	//////////////////////////////////////////////////////////////////////////
	LoadShaders();
	//////////////////////////////////////////////////////////////////////////
	InitialiseModels();
	//////////////////////////////////////////////////////////////////////////
	InitialiseCamera();
	//////////////////////////////////////////////////////////////////////////
	InitialiseParicles();
	
}






/************************************************************************/
/* update function                                                                     */
/************************************************************************/
bool ChristmasWindow::Pause(int a){
	pauseCounter++;
	if(pauseCounter >= a){
		pauseCounter = 0;
		return true;
	}
	else{
		return false;
	}
}
void ChristmasWindow::OnUpdate(){
	float deltaTime = (float)App::GetDeltaTime();
	_timerCounter = _timerCounter + deltaTime;
	
	float tempDelataTime = deltaTime * _timeSpeedFactor;

	/************************************************************************/
	/* update particles                                                                     */
	/************************************************************************/
// 	_smoke.Update(tempDelataTime);
// 	_snowflake.Update(tempDelataTime);
// 	_fire.Update(tempDelataTime);

	/************************************************************************/
	/* update light spirce rotate angle                                                                     */
	/************************************************************************/
	_sunRunCycleAngle += _sunRunCycleAngleInc * tempDelataTime;
	if(_sunRunCycleAngle > 360.0f) 
		_sunRunCycleAngle -=360.0f;
	/************************************************************************/
	/* tree operation                                                                     */
	/************************************************************************/
	//crash
// 	if(_treeCrash){
// 		_treeangle += _treeangleInc * tempDelataTime;
// 		if(_treeangle > 90){
// 			_treeangle = 0;
// 			_treeCrash = false;
// 			_tree->TreeState = TREEDOWNEND;
// 		}
// 	}
	
	_tree->Update(tempDelataTime);
	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* season loop    main loop                                                     */
	/************************************************************************/
	if(Spring == _currentSeason ){
		if(START == _tree->TreeState){
			_tree->TreeState = GROWING;
			/************************************************************************/
			/* do spring operation                                                                     */
			/************************************************************************/

		}
		
		if( _tree->TreeState == SYNCLIVE  ){
			_currentSeason = Summer;
			
		}

	}
	
	if(Summer ==  _currentSeason){
		if(SYNCLIVE == _tree->TreeState){
			_tree->TreeState = LEAFGROWING;
		}
		
		if(LEAFGROWING == _tree->TreeState ){
			
			
		}
		if( LEAFGROWEND == _tree->TreeState ){
 			_currentSeason = Autumn;

		}

	}
	
	if( Autumn == _currentSeason){
		if(LEAFGROWEND == _tree->TreeState){
			_tree->TreeState = LEAFCOLORBROWN;
		}

		if(LEAFCOLORBROWN == _tree->TreeState){

		}
		if(LEAFCOLORBROWNEND == _tree->TreeState){

		}
		
		if( LEAFDOWN ==  _tree->TreeState){
			
			/*std::cout<<"ww"<<std::endl;*/
		}
		if( LEAFDOWNEND == _tree->TreeState){
			//cout<<"lging"<<endl;
			_currentSeason = Winter;
		}

		
	}
	
	if(Winter == _currentSeason ){
		if(LEAFDOWNEND == _tree->TreeState){
			_tree->TreeState = FIREING;

		}

		if(FIREING == _tree->TreeState){

		}

		if(FIREEND == _tree->TreeState){

			_tree->TreeState = TREEDOWNING;
		}
		
		if(TREEDOWNING == _tree->TreeState){
			//_treeCrash = true;
		}
		if( TREEDOWNEND == _tree->TreeState){
			/*_currentSeason = Winter;*/
			
			_tree->reset();
			_tree->TreeState = START;
			_currentSeason = Spring;

		}

		
	}
	
}



void ChristmasWindow::LoadStencil()
{
	bool temp = false;
	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
	glEnable(GL_STENCIL_TEST);
	glStencilFunc(GL_ALWAYS, 1, 1);
	glStencilOp(GL_REPLACE,GL_REPLACE,GL_REPLACE);
	glFrontFace(GL_CW);
	glPushMatrix();
		glTranslatef(pool_pos_x,pool_pos_y,pool_pos_z);
		glRotatef(-270,1,0,0);
		glScalef(pool_scal_x,pool_scal_y,pool_scal_z);
/*		_pool->Draw();*/
		
	glPopMatrix();
	glFrontFace(GL_CCW);
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	glStencilFunc(GL_EQUAL, 1, 1);
	glStencilOp(GL_KEEP,GL_KEEP,GL_KEEP);

}

void ChristmasWindow::DrawReflection()
{

	glPushMatrix();
	// reflect all objects about y=0 plane 
	glScalef(1.0, -1.0, 1.0);	
	glTranslatef(tree_pos_x,-tree_pos_y,tree_pos_z);
 	glScalef(tree_scal_x,tree_scal_y,tree_scal_z);
	/*glRotatef(_treeangle,0,0,1);*/
	// and front faces become back faces and visa-versa
	glCullFace(GL_FRONT);

	_tree->Draw();
	
	glCullFace(GL_BACK);
	glPopMatrix();



	
}

void ChristmasWindow::OnDisplay()
{
	this->OnUpdate();

	
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glPushMatrix();
		glTranslatef(0.0f, 0.0f,_cameraPositionZ);
		glRotatef(_cameraAngle, 1.0,0.0,0.0);
		glRotatef(_cameraRotation, 0.0, 1.0, 0.0);

		/*flashLight->Draw();*/

		if(_drawSpotLights){
			glDisable(GL_LIGHT0);
			_spotlightRed.apply();
			_spotlightGreen.apply();
			_spotlightBlue.apply();
			_spotlightWhite.apply();
			DrawSporLights();
		}
		else{
			glEnable(GL_LIGHT0);
			glDisable(GL_LIGHT1);
			glDisable(GL_LIGHT2);
			glDisable(GL_LIGHT3);
			glDisable(GL_LIGHT4);
		}
		

		

		glPushMatrix();
			//glRotatef(-4*_sunRunCycleAngle, 0.0, 0.0, 1.0);
			_sunLight.setPosition(Vector4f(6.0,6.0,0.0,1.0));
			glTranslatef(6.0,6.0,0.0);
			_sunMaterial.apply();
			_sunSphere.draw();
		glPopMatrix();

		
		/************************************************************************/
		/* draw smoke                                                                     */
		/************************************************************************/
		glPushMatrix();
			glTranslatef(-1.4f,1.06,0);
// 			if(_smoke.working){
// 				_smoke.Draw();
// 			}
			
		glPopMatrix();

		/************************************************************************/
		/* draw snoke                                                                     */
		/************************************************************************/
		glPushMatrix();
		glTranslatef(0,0.1,0);
// 			if(_snowflake.working){
// 				_snowflake.setCameraPos(0.0f, 0.0f,_cameraPositionZ);
// 				_snowflake.Draw();
// 			}
		glPopMatrix();


		glPushMatrix();
			glTranslatef(0.0f,1.06f,0.0f);
// 			if(_fire.working){
// 				_fire.Draw();
// 			}
		glPopMatrix();
		
#ifdef DRAWSEAT

		glPushMatrix();
			glRotatef(-90.0f,1.0,0.0,0.0);
/*			_seat->Draw();*/
		glPopMatrix();

#endif
		glPushMatrix();
			glTranslatef(-1.0,0.28,0.0f);
			glScalef(0.25,0.25,0.25);
			glRotatef(-90,1.0,0.0,0.0);
/*			_house->Draw();*/
		glPopMatrix();

		//glUseProgram(_TreeProgramID);
		glPushMatrix();
			glTranslatef(tree_pos_x,tree_pos_y,tree_pos_z);
			glScalef(tree_scal_x,tree_scal_y,tree_scal_z);
			/*glRotatef(_treeangle,0,0,1);*/
			_tree->Draw();
		glPopMatrix();
		//glUseProgram(0);


		// 		glUseProgram(_shaderProgramID);
		// 		glUseProgram(0);	
#ifdef DRAWREFLECTION
		/************************************************************************/
		/* draw reflection                                                                     */
		/************************************************************************/
		glDepthMask(GL_FALSE);
		if (_loadStencilBuffer)
		{
			LoadStencil();
		}

		DrawReflection();

		glDisable(GL_STENCIL_TEST);
		glDepthMask(GL_TRUE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glFrontFace(GL_CW);
		glPushMatrix();
			glTranslatef(pool_pos_x,pool_pos_y,pool_pos_z);
			glRotatef(-90,1,0,0);
			glScalef(pool_scal_x,pool_scal_y,pool_scal_z);
/*			_pool->Draw();*/
		glPopMatrix();
		glFrontFace(GL_CCW);
		glDisable(GL_BLEND);
#endif
		
#ifdef DRAWREFLECTION
		glDisable(GL_STENCIL_TEST);
		glDepthMask(GL_TRUE);
		glEnable(GL_BLEND);
#endif
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		glPushMatrix();
			glTranslatef(pool_pos_x,pool_pos_y,pool_pos_z);
			glRotatef(-90,1,0,0);
			glScalef(pool_scal_x,pool_scal_y,pool_scal_z);
/*			_pool->Draw();*/
		glPopMatrix();
		
#ifdef DRAWREFLECTION
		glDisable(GL_BLEND);
#endif
		
		/************************************************************************/
		/* last draw the ball                                                                     */
		/************************************************************************/
		glUseProgram(_ballProgramID);
		glPushMatrix();
			glTranslatef(0.0f, 2.3f, 0.0f);
			glScalef(3,3,3);
/*			_ball->Draw();*/
		glPopMatrix();
		glUseProgram(0);
		//////////////////////////////////////////////////////////////////////////
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glColor3f(1.0,1.0,1.0);
	glEnable(GL_LIGHTING);
	SwapBuffers();

}
void ChristmasWindow::OnIdle()
{
	Redraw();
}

void ChristmasWindow::OnKeyboard(int key, bool down)
{
	if (!down) return;
	switch( tolower(key) ) {
		case 'a': 
			_cameraAngle += 5.0;
			break;
		case 'z':
			_cameraAngle -= 5.0;
			break;
		case 's': 
			_cameraHerical += 5.0;
			break;
		case 'x':
			_cameraHerical -= 5.0;
			break;
		case 'p':
			_timeSpeedFactor = _timeSpeedFactor * 0.5;
			cout<<"Increase Speed +"<<endl;
			break;
		case 'o':
			_timeSpeedFactor = _timeSpeedFactor * 2.0;
			cout<<"Decrease Speed -"<<endl;
			break;
		
		case 'l':
			_drawSpotLights = !_drawSpotLights;
			break;
		case 'u':
/*			_smoke.working = !_smoke.working;*/
			break;
		case 'y':
/*			_snowflake.working = !_snowflake.working;*/
			break;
		case 't':
/*			_fire.working = !_fire.working;*/
			break;
		default:
			break;
	}
}
void ChristmasWindow::OnMouseMove(int x, int y) {
	static int temp_x, temp_y;
	if(_leftDown) {
		_cameraPositionZ += (y-temp_y)*0.05f;
	}
	if(_rightDown) {
		_cameraRotation += (x-temp_x)*0.5f;
	}
	temp_x = x;
	temp_y = y;
}

void ChristmasWindow::OnMouseButton(MouseButton button, bool down) {
	if (down) {
		switch(button) {
		case MBLeft: 
			_leftDown = true;
			break;
		case MBRight:
			_rightDown = true;
			break;
		default:
			break;
		}
	} else {
		switch(button) {
		case MBLeft: 
			_leftDown = false;
			break;
		case MBRight:
			_rightDown = false;
			break;
		default:
			break;
		}
	}
}



void ChristmasWindow::DrawSporLights(){
	_spotlightRed.setPosition(Vector4f(0,8,0,1.0f));
	_spotlightRed.setDirection(Vector4f(1.0f,-4.0f,0.0f,0.0f));
	_spotlightGreen.setPosition(Vector4f(0,3,0,1.0f));
	_spotlightGreen.setDirection(Vector4f(-1.0f,-4.0f,0.0f, 0.0f));
	_spotlightBlue.setPosition(Vector4f(0,3,0,1.0f));
	_spotlightBlue.setDirection(Vector4f(0.0f,-4.0f,1.0f, 0.0f));
	_spotlightWhite.setPosition(Vector4f(0,3,0,1.0f));
	_spotlightWhite.setDirection(Vector4f(0.0f,-4.0f,-1.0f, 0.0f));

}



void ChristmasWindow::InitialiseLights(){
	/************************************************************************/
	/* initialize lighting                                                                     */
	/************************************************************************/
	_sunLight.create(0, Color::black(), Color::white());

	/************************************************************************/
	/*                                                                      */
	/************************************************************************/
	_spotlightRed.create(1,Color::black(),Color::red());
	_spotlightRed.setSpot(30.0,100.0f);

	_spotlightGreen.create(2,Color::black(),Color::green());
	_spotlightGreen.setSpot(30.0,100.0f);

	_spotlightBlue.create(3,Color::black(),Color::blue());//
	_spotlightBlue.setSpot(30.0,100.0f);

	_spotlightWhite.create(4,Color::black(),Color::white());
	_spotlightWhite.setSpot(30.0,100.0f);

	// turn the global ambient off by setting it to zero
	
	//GLfloat cc[4] = {0.5,0.5,0.5,1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,/*cc*/ Color::black().rgba());

	_sunLight.apply();

	_spotlightRed.apply();
	_spotlightGreen.apply();
	_spotlightBlue.apply();
	_spotlightWhite.apply();

	_sunSphere.create(0.1f, 10, 10, false);
	_sunMaterial.create(Color::black(), Color::black(), Color(0.7,0.7,0.7,0.7));

}


void ChristmasWindow::InitialiseModels(){
	/************************************************************************/
	/* test for modelcontroller       test passed                           */
	/************************************************************************/
	modelController = ModelController::GetInstance();
	/************************************************************************/
	/* load texture together                                                */
	/************************************************************************/
	//modelController->LoadTexture();

	/************************************************************************/
	/* test                                                                     */
	/************************************************************************/
// 	_testObject = new TestCube();
// 	_testObject->setEnableShaderProgram(true);
// 	_testObject->setShaderProgramID(_cubeShaderProgramID);
// 	modelController->AssemblyModelFromFile2(_testObject,"cube.mxy",modelController->_textures[0]);
	/************************************************************************/
	/* start to create model in this scene                                   */
	/************************************************************************/
// 	_house = new House();
// 	_house->setRenderTexture(true);
// 	_house->setRenderMaterials(false);
// 	modelController->AssemblyModelFromFile(_house,"House2.mxy",modelController->_textures[0]);

	
	/************************************************************************/
	/* seat                                                                     */
	/************************************************************************/
#ifdef DRAWSEAT

// 	_seat = new Seat();
// 	_seat->setRenderTexture(true);
// 	_seat->setRenderMaterials(false);
// 	modelController->AssemblyModelFromFile(_seat,"ground.mxy",modelController->_textures[2]);
#endif
	/************************************************************************/
	/* tree                                                                     */
	/************************************************************************/
	_tree = new ChristmasTree();
	// trunk tecture
	LoadTexture("1142.jpg",_tree->trunk_texture_id);
	LoadTexture("1142-normal.jpg",_tree->trunk_texture_normal_id);
	LoadTexture("1142-bump.jpg",_tree->trunk_texture_height_id);
	//trunk shader
	_tree->trunk_shader_programID = LoadShaderFromFile("TrunkVertexShader.glsl","TrunkFragShader.glsl");
	glUseProgram(_tree->trunk_shader_programID);
	int loc = glGetUniformLocation(_tree->trunk_shader_programID,"ColorTexture");
	if(loc!=-1)
		glUniform1i(loc,0);
	else
		cout<<"uniform error"<<endl;
	loc = glGetUniformLocation(_tree->trunk_shader_programID,"NormalMapTexture");
	if(loc!=-1)
		glUniform1i(loc,1);
	else
		cout<<"uniform error"<<endl;
	loc = glGetUniformLocation(_tree->trunk_shader_programID,"heightMapTexture");
	if(loc!=-1)
		glUniform1i(loc,2);
	else
		cout<<"uniform error"<<endl;
	loc = glGetUniformLocation(_tree->trunk_shader_programID,"applyTexture");
	if(loc!=-1)
		glUniform1i(loc,true);
	else
		cout<<"uniform error"<<endl;
	loc = glGetUniformLocation(_tree->trunk_shader_programID,"applyNormalMap");
	if(loc!=-1)
		glUniform1i(loc,true);
	else
		cout<<"uniform error"<<endl;
	loc = glGetUniformLocation(_tree->trunk_shader_programID,"applyParallaxMap");
	if(loc!=-1)
		glUniform1i(loc,true);
	else
		cout<<"uniform error"<<endl;
	glUseProgram(0);
	//////////////////////////////////////////////////////////////////////////
	//leaf texture
	LoadTexture("leaf_texture.tga",_tree->leaf_texture_id);
	LoadTexture("leaf_nor_texture.tga",_tree->leaf_nor_texture_id);
	//leaf leaf
	_tree->leaf_shader_programID = LoadShaderFromFile("LeafVertexShader2.glsl","LeafFragShader2.glsl");
// 	_tree->trunk_shader_programID = _tree_trunk_shader_programID;
// 	_tree->leaf_shader_programID = _tree_leaf_shader_programID;
	glUseProgram(_tree->leaf_shader_programID);
	loc = glGetUniformLocation(_tree->leaf_shader_programID,"ColorTexture");
	if(loc!=-1)
		glUniform1i(loc,0);
	else
		cout<<"uniform error"<<endl;
	loc = glGetUniformLocation(_tree->leaf_shader_programID,"NormalMapTexture");
	if(loc!=-1)
		glUniform1i(loc,1);
	else
		cout<<"uniform error"<<endl;

	loc = glGetUniformLocation(_tree->leaf_shader_programID, "applyTexture");
	if(loc!=-1)
		glUniform1i(loc,true);
	else
		cout<<"uniform error"<<endl;
	
	loc = glGetUniformLocation(_tree->leaf_shader_programID, "applyNormalMap");
	if(loc!=-1)
		glUniform1i(loc,true);
	else
		cout<<"uniform error"<<endl;
	
	glUseProgram(0);


	_tree->Initialize();

	/************************************************************************/
	/* glass ball                                                                     */
	/************************************************************************/
// 	_ball = new Ball();
// 	_ball->setEnableTransparency(true);
// 	_ball->setRenderTexture(false);
// 	_ball->setRenderMaterials(false);
// 	_ball->setColorApalha(0.1);
// 	modelController->AssemblyTransparencyPartSphere(_ball,1.0,40,40,modelController->_textures[0]);

	/************************************************************************/
	/* water pool                                                                     */
	/************************************************************************/
// 	_pool = new Pool();
// 	_pool->setRenderTexture(false);
// 	_pool->setRenderMaterials(false);
// 	_pool->setEnableTransparency(true);
// 	_pool->setColorApalha(0.5);
// 	modelController->AssemblyModelFromFile(_pool,"pool.mxy",modelController->_textures[0]);
// 	_pool->setEnableTransparency(false);

	//////////////////////////////////////////////////////////////////////////

	/************************************************************************/
	/* flash                                                                     */
	/************************************************************************/
/*	flashLight = new FlashLighting();*/

}

void ChristmasWindow::InitialiseCamera(){
	_cameraAngle = 30.0;
	_cameraPositionZ = -5.0;
	_cameraRotation = 0.0;
	_cameraHerical = 0.0;
}

void ChristmasWindow::InitialiseParicles(){
// 	_smoke.Initialize();
// 
// 	_snowflake.setTexture(modelController->_textures[4]);
// 	_snowflake.setHeight(2.7);
// 	_snowflake.setRaius(2.2);
// 	_snowflake.Initialize();
// 
// 	_fire.Initialize();
}

/**
void ChristmasWindow::InitialiseShader(){

	CheckShaderEnvironment();
	//init cube shader
	if(GenerateShaderProgram(_cubeShaderProgramID,"studyvertexshader1.glsl","studyfragshader1.glsl")){
		printf("generate ok\n");
//		glBindAttribLocation(_cubeShaderProgramID,0, "MCVertex");
// 		glBindAttribLocation(_cubeShaderProgramID,1, "VertexColor");
// 		glBindAttribLocation(_cubeShaderProgramID,2, "Testfloat0");
// 		glBindAttribLocation(_cubeShaderProgramID,3, "Testfloat1");
// 		glBindAttribLocation(_cubeShaderProgramID,4, "Testfloat2");
		
		
// 		int k = glGetAttribLocation(_cubeShaderProgramID,"Testfloat2");
// 		k = 0;
		
		
	}else{
		printf("generate failed!\n");
	}
	//BallVertexShader.glsl BallFragShader.glsl
	if(GenerateShaderProgram(_ballProgramID,"BallVertexShader.glsl","BallFragShader.glsl")){
		printf("Ball shader ok\n");
	}else{
		printf("Ball Shader fail\n");
	}

	if(GenerateShaderProgram(_TreeProgramID,"LeafVertexShader.glsl","LeafFragShader.glsl")){
		printf("leaf shader ok\n");
		glUseProgram( _TreeProgramID);
		glUniform1i( glGetUniformLocation( _TreeProgramID, "normalTex"), 0);
		glUniform1i( glGetUniformLocation( _TreeProgramID, "baseTex"), 1);
		glUseProgram( 0);
	}else{
		printf("leaf Shader fail\n");
	}


}
*/

void ChristmasWindow::LoadShaders(){
	CheckShaderEnvironment();
	//_tree_trunk_shader_programID = LoadShaderFromFile("phongvertexshader.glsl","phongfragmentshader.glsl");
	//_tree_leaf_shader_programID = LoadShaderFromFile("LeafVertexShader.glsl","LeafFragShader.glsl");



// 	_tree_trunk_shader_programID = LoadShaderFromFile("basic_vertex.glsl","basic_fragment.glsl");
// 	glUseProgram( _tree_trunk_shader_programID);
// 	glUniform1i( glGetUniformLocation( _tree_trunk_shader_programID, "normalTex"), 0);
// 	glUniform1i( glGetUniformLocation( _tree_trunk_shader_programID, "baseTex"), 1);
	
}
/**
bool ChristmasWindow::GenerateShaderProgram(GLuint &programID, char* vPath, char* fPath){
	programID = glCreateProgram();
	GLuint vID;
	GLuint fID;
	try
	{
		vID = GenerateShaderObject(vPath, GL_VERTEX_SHADER);
		fID = GenerateShaderObject(fPath, GL_FRAGMENT_SHADER);

		glAttachShader(programID, vID);
		glAttachShader(programID, fID);

// 		glBindAttribLocation(_cubeShaderProgramID,0, "VertexPosition");
// 		glBindAttribLocation(_cubeShaderProgramID,1, "VertexColor");
// 		glBindAttribLocation(_cubeShaderProgramID,2, "Testfloat0");
// 		glBindAttribLocation(_cubeShaderProgramID,3, "Testfloat1");
// 		glBindAttribLocation(_cubeShaderProgramID,4, "Testfloat2")
//		glBindFragDataLocation(programID,0,"FragColor");

		glLinkProgram(programID);
		
		
		GLint maxLength, nAttribs;
		glGetProgramiv(programID, GL_ACTIVE_ATTRIBUTES, &nAttribs);
		glGetProgramiv(programID, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLength);

		GLchar* name = (GLchar*)malloc(maxLength);

		GLint written, size, location;
		GLenum type;
		printf(" Index | Name\n");
		printf("----------------------------\n");
		for(int i = 0; i<nAttribs; i++){
			glGetActiveAttrib( programID, i, maxLength, &written, &size, &type, name);
			location = glGetAttribLocation(programID, name);
		}
		free(name);
	}
	catch(exception& e)
	{
		cerr << e.what() << endl;

		return false;
	}

	return true;
}
*/
/**
GLuint ChristmasWindow::GenerateShaderObject(std::string filename, GLenum shaderType){
	// Attempt to load filename
	ifstream file;
	file.open(filename, ios::in);
	if (!file)
	{
		cerr << "Error loading " << filename << " - file not found" << endl;
		throw exception("Error loading shader");
	}

	stringstream srcBuilder;
	while (!file.eof())
	{
		unsigned char in = file.get();
		srcBuilder << in;
	}
	file.close();
	string shaderSrc = srcBuilder.str();
	// Remove EOF char
	shaderSrc = shaderSrc.substr(0, shaderSrc.size()-1);

	file.close();

	
	GLuint id = glCreateShader(shaderType);
	if (id == 0)
	{
		cerr << "Could not create shader object" << endl;
		throw exception("Could not create shader object");
	}

	// Assign source
	GLint len[1];
	len[0] = shaderSrc.size();
	GLchar** src = new GLchar*[1];
	src[0] = new GLchar[len[0]];
	for (int i = 0; i < len[0]; i++) src[0][i] = shaderSrc[i];
	glShaderSource(id, 1, (const GLchar**) src, len);

	// Compile shader
	glCompileShader(id);

	//verify
	GLint result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if(GL_FALSE == result){
		printf(" shader compilaion failed!\n ");
		GLint logLen;
		glGetShaderiv(id,GL_INFO_LOG_LENGTH, &logLen);
		if(logLen>0){

			char* log = (char*)malloc(logLen);
			GLsizei written;
			glGetShaderInfoLog(id,logLen,&written,log);

			printf("rewrite shader log: \n%s",log);
			free(log);
		}
	}else{
		printf("shader compilation right\n");
	}

	return id;
}

*/




void ChristmasWindow::LoadCamera(){
	// clear window first: it might take a moment before image loads
	glClear(GL_COLOR_BUFFER_BIT);
	SwapBuffers();
	// turns vsync off so the frame rate is not limited
	wglSwapIntervalEXT(0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0f,(GLfloat)Width()/(GLfloat)Height(),0.01f,100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glShadeModel(GL_SMOOTH);
	glViewport(0,0, Width(), Height());
}
void ChristmasWindow::LoadBasicOpenGLParame(){
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	// track material ambient and diffuse from surface color, call it before glEnable(GL_COLOR_MATERIAL)
	//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	// remove back faces
	glEnable(GL_CULL_FACE);
}
void ChristmasWindow::CheckMultitextureSupport(){
	//1
	// does this driver support multitexture?
	_bHaveMultitex = glex::Supports( "GL_ARB_multitexture" );
	if (!_bHaveMultitex) {
		// warn the user if multitexture not supported
		cout<<"GL_ARB_multitexture NOT found"<<endl;
	}

	// if it supports multitexture, turn it on
	_bMultitex = _bHaveMultitex;
}

void ChristmasWindow::CheckShaderEnvironment(){
	const GLubyte *render = glGetString(GL_RENDER);
	const GLubyte *vender = glGetString(GL_VENDOR);
	const GLubyte *version = glGetString(GL_VERSION);
	const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);
	printf("GL Vendor    : %s\n", vender);
	printf("GL Renderer  : %s\n", render);
	printf("GL Version (string)  : %s\n", version);
	printf("GL Version (integer) : %d.%d\n", major, minor);
	printf("GLSL Version : %s\n", glslVersion);  
}

GLuint ChristmasWindow::LoadShaderFromFile(const char* vPath,const char* fPath){
	GLuint programID;
	programID = glCreateProgram();
	GLuint vID;
	GLuint fID;
	try
	{
		vID = GenerateShaderObject(vPath, GL_VERTEX_SHADER);
		fID = GenerateShaderObject(fPath, GL_FRAGMENT_SHADER);

		glAttachShader(programID, vID);
		glAttachShader(programID, fID);

		glLinkProgram(programID);

		/************************************************************************/
		/* list shader active attributes                                                                     */
		/************************************************************************/
		GLint maxLength, nAttribs;
		glGetProgramiv(programID, GL_ACTIVE_ATTRIBUTES, &nAttribs);
		glGetProgramiv(programID, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLength);
		
		GLchar* name = (GLchar*)malloc(maxLength);

		GLint written, size, location;
		GLenum type;
		printf(" Index | Name\n");
		printf("----------------------------\n");
		for(int i = 0; i<nAttribs; i++){
			glGetActiveAttrib( programID, i, maxLength, &written, &size, &type, name);
			location = glGetAttribLocation(programID, name);
		}
		free(name);
	}
	catch(exception& e)
	{
		cerr << e.what() << endl;
	}

	return programID;
}
GLuint ChristmasWindow::GenerateShaderObject(std::string filename, GLenum shaderType){
	// Attempt to load filename
	ifstream file;
	file.open(filename, ios::in);
	if (!file)
	{
		cerr << "Error loading " << filename << " - file not found" << endl;
		throw exception("Error loading shader");
	}

	stringstream srcBuilder;
	while (!file.eof())
	{
		unsigned char in = file.get();
		srcBuilder << in;
	}
	file.close();
	string shaderSrc = srcBuilder.str();
	// Remove EOF char
	shaderSrc = shaderSrc.substr(0, shaderSrc.size()-1);

	file.close();


	GLuint id = glCreateShader(shaderType);
	if (id == 0)
	{
		cerr << "Could not create shader object" << endl;
		throw exception("Could not create shader object");
	}

	// Assign source
	GLint len[1];
	len[0] = shaderSrc.size();
	GLchar** src = new GLchar*[1];
	src[0] = new GLchar[len[0]];
	for (int i = 0; i < len[0]; i++) src[0][i] = shaderSrc[i];
	glShaderSource(id, 1, (const GLchar**) src, len);

	// Compile shader
	glCompileShader(id);

	//verify
	GLint result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if(GL_FALSE == result){
		printf(" shader compilaion failed!\n ");
		GLint logLen;
		glGetShaderiv(id,GL_INFO_LOG_LENGTH, &logLen);
		if(logLen>0){

			char* log = (char*)malloc(logLen);
			GLsizei written;
			glGetShaderInfoLog(id,logLen,&written,log);

			printf("rewrite shader log: \n%s",log);
			free(log);
		}
	}else{
		printf("shader compilation right\n");
	}

	return id;
}

/************************************************************************/
/* load texture                                                                     */
/************************************************************************/
void ChristmasWindow::LoadTexture(std::string fileName, GLuint &textureID)
{
	Image image;
	image.Load(fileName.c_str());
	glGenTextures(1, &textureID);

	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	image.gluBuild2DMipmaps();
	image.Free();
}
