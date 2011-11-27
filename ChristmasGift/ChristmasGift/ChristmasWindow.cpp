#include "ChristmasWindow.h"

#define SEASONLENGTH 3*30*24*60*60


#define DRAWREFLECTION
#define ALLOWSEATCULLFACE1

#define DRAWSEAT1


// const Vector4f _PS = Vector4f(1.0f,0.0f,0.0f,0.0f);
// const Vector4f _PT = Vector4f(0.0f,1.0f,0.0f,0.0f);
// const Vector4f _PR = Vector4f(0.0f,0.0f,1.0f,0.0f);
// const Vector4f _PQ = Vector4f(0.0f,0.0f,0.0f,1.0f);

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


ChristmasWindow::ChristmasWindow(void) :_treeangleInc(10),_loadStencilBuffer(true),_drawSpotLights(false),_bMultitex(false) ,_bHaveMultitex(false) ,_angleInc(30),_currentSeason(Spring),_timerCounter(0),_timeDecFactor(1)/*,_seasonCounter(0)*/
{
	SetSize(512,512);
	SetDepthBits(24);
	SetTitle("Christmas Gift From Xiaoyu Ma");
	_angle = 0.0f;

	_treeCrash = false;
	_treeangle = 0.0;
	stayCounter = 0;
}




void ChristmasWindow::OnCreate()
{
	GLWindowEx::OnCreate();

	// does this driver support multitexture?
	_bHaveMultitex = glex::Supports( "GL_ARB_multitexture" );
	if (!_bHaveMultitex) {
		// warn the user if multitexture not supported
		cout<<"GL_ARB_multitexture NOT found"<<endl;
	}

	// if it supports multitexture, turn it on
	_bMultitex = _bHaveMultitex;

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
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	// track material ambient and diffuse from surface color, call it before glEnable(GL_COLOR_MATERIAL)
	//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
	// remove back faces
	glEnable(GL_CULL_FACE);
	//////////////////////////////////////////////////////////////////////////
	InitialiseLights();
	//////////////////////////////////////////////////////////////////////////
	InitialiseShader();
	//////////////////////////////////////////////////////////////////////////
	InitialiseModels();
	//////////////////////////////////////////////////////////////////////////
	InitialiseCamera();
	//////////////////////////////////////////////////////////////////////////
	InitialiseParicles();
	

	/*_green.create(Color::black(), Color::green());*/


}






/************************************************************************/
/* update function                                                                     */
/************************************************************************/
bool ChristmasWindow::keepStatyIn(int a){
	stayCounter++;
	if(stayCounter >= a){
		stayCounter = 0;
		return true;
	}
	else{
		return false;
	}
}
void ChristmasWindow::OnUpdate(){
	float deltaTime = (float)App::GetDeltaTime();
	_timerCounter = _timerCounter + deltaTime;
	
	

	/************************************************************************/
	/* update particles                                                                     */
	/************************************************************************/
	_smoke.Update(deltaTime);
	_snowflake.Update(deltaTime);
	_fire.Update(deltaTime);

	/************************************************************************/
	/* update light spirce rotate angle                                                                     */
	/************************************************************************/
	_angle += _angleInc * deltaTime;
	if(_angle > 360.0f) 
		_angle -=360.0f;
	/************************************************************************/
	/* tree angle                                                                     */
	/************************************************************************/
	if(_treeCrash){
		_treeangle += _treeangleInc * deltaTime;
		if(_treeangle > 90){
			_treeangle = 0;
			_treeCrash = false;
			/*_tree->currentSeason = Winter;*/
			_tree->TreeState = TREEDOWNEND;
		}
	}
	if(_timerCounter>= SEASONLENGTH*_timeDecFactor){
		_tree->Update(deltaTime);
		_timerCounter = 0;
	}
	if(Spring == _currentSeason ){
		if(START == _tree->TreeState){
			_tree->TreeState = GROWING;
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
			//cout<<"lging"<<endl;
		}
		if( LEAFGROWEND == _tree->TreeState ){
 			_currentSeason = Autumn;

		}

	}
	
	if( Autumn == _currentSeason){
		if(LEAFGROWEND == _tree->TreeState){
			_tree->TreeState = LEAFDOWN;
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
			_treeCrash = true;
		}
		if( TREEDOWNEND == _tree->TreeState){
			/*_currentSeason = Winter;*/
			
			_tree->reset();
			_tree->TreeState = START;
			_currentSeason = Spring;

		}

		
	}
	

	/**
	if(Spring == _tree->currentSeason){
		_currentSeason = Spring;
	}
	if(Summer == _tree->currentSeason){
		_currentSeason = Summer;
	}

	if(Autumn == _tree->currentSeason){
		_currentSeason = Autumn;
		_treeCrash = true;
		//flash lighting
		//fire on the tree
		//down leaf
	}

	if(Winter == _tree->currentSeason){
		_currentSeason = Winter;
		_tree->currentSeason = Spring;
		_tree->TreeState = GROWING;
		_tree->reset();
	}
	*/
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
		_pool->Draw();
		
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
	glRotatef(_treeangle,0,0,1);
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
		TestMethod();
		glPopMatrix();

		glPushMatrix();
			glRotatef(-4*_angle, 0.0, 1.0, 0.0);
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
			if(_smoke.working){
				_smoke.Draw();
			}
			
		glPopMatrix();

		/************************************************************************/
		/* draw snoke                                                                     */
		/************************************************************************/
		glPushMatrix();
		glTranslatef(0,0.1,0);
			if(_snowflake.working){
				_snowflake.setCameraPos(0.0f, 0.0f,_cameraPositionZ);
				_snowflake.Draw();
			}
		glPopMatrix();


		glPushMatrix();
			glTranslatef(0.0f,1.06f,0.0f);
			if(_fire.working){
				_fire.Draw();
			}
		glPopMatrix();
		
#ifdef DRAWSEAT

		glPushMatrix();
			glRotatef(-90.0f,1.0,0.0,0.0);
			_seat->Draw();
		glPopMatrix();

#endif
		glPushMatrix();
			glTranslatef(-1.0,0.28,0.0f);
			glScalef(0.25,0.25,0.25);
			glRotatef(-90,1.0,0.0,0.0);
			_house->Draw();
		glPopMatrix();

		glPushMatrix();
			glTranslatef(tree_pos_x,tree_pos_y,tree_pos_z);
			glScalef(tree_scal_x,tree_scal_y,tree_scal_z);
			glRotatef(_treeangle,0,0,1);
			_tree->Draw();
		glPopMatrix();



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
			_pool->Draw();
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
			_pool->Draw();
		glPopMatrix();
#ifdef DRAWREFLECTION
		glDisable(GL_BLEND);
#endif
		
		/************************************************************************/
		/* last draw the ball                                                                     */
		/************************************************************************/
		
		glPushMatrix();
			glTranslatef(0.0f, 2.3f, 0.0f);
			glScalef(3,3,3);
			_ball->Draw();
		glPopMatrix();

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
			_timeDecFactor = _timeDecFactor * 0.1;
			cout<<"Increase Speed +"<<endl;
			break;
		case 'o':
			_timeDecFactor = _timeDecFactor * 10.0;
			cout<<"Decrease Speed -"<<endl;
			break;
		
		case 'l':
			_drawSpotLights = !_drawSpotLights;
			break;
		case 'u':
			_smoke.working = !_smoke.working;
			break;
		case 'y':
			_snowflake.working = !_snowflake.working;
			break;
		case 't':
			_fire.working = !_fire.working;
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

	_spotlightBlue.create(3,Color::black(),Color::blue());
	_spotlightBlue.setSpot(30.0,100.0f);

	_spotlightWhite.create(4,Color::black(),Color::white());
	_spotlightWhite.setSpot(30.0,100.0f);

	// turn the global ambient off by setting it to zero
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Color::black().rgba());

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
	modelController->LoadTexture();

	/************************************************************************/
	/* test                                                                     */
	/************************************************************************/
	_testObject = new TestCube();
	_testObject->setEnableShaderProgram(true);
	_testObject->setShaderProgramID(_cubeShaderProgramID);
	modelController->AssemblyModelFromFile2(_testObject,"cube.mxy",modelController->_textures[0]);
	/************************************************************************/
	/* start to create model in this scene                                   */
	/************************************************************************/
	_house = new House();
	_house->setRenderTexture(true);
	_house->setRenderMaterials(false);
	modelController->AssemblyModelFromFile(_house,"House2.mxy",modelController->_textures[0]);

	
	/************************************************************************/
	/* seat                                                                     */
	/************************************************************************/
#ifdef DRAWSEAT

	_seat = new Seat();
	_seat->setRenderTexture(true);
	_seat->setRenderMaterials(false);
	modelController->AssemblyModelFromFile(_seat,"ground.mxy",modelController->_textures[2]);
#endif
	/************************************************************************/
	/* tree                                                                     */
	/************************************************************************/
	_tree = new ChristmasTree();
	/*_tree->setTreeParameter();*/
	_tree->Initialize();


	/************************************************************************/
	/* glass ball                                                                     */
	/************************************************************************/
	_ball = new Ball();
	_ball->setEnableTransparency(true);
	_ball->setRenderTexture(false);
	_ball->setRenderMaterials(false);
	_ball->setColorApalha(0.1);
	
	modelController->AssemblyTransparencyPartSphere(_ball,1.0,40,40,modelController->_textures[0]);

	/************************************************************************/
	/* water pool                                                                     */
	/************************************************************************/
	_pool = new Pool();
	_pool->setRenderTexture(false);
	_pool->setRenderMaterials(false);
	_pool->setEnableTransparency(true);
	_pool->setColorApalha(0.5);
	modelController->AssemblyModelFromFile(_pool,"pool.mxy",modelController->_textures[0]);
	_pool->setEnableTransparency(false);

	//////////////////////////////////////////////////////////////////////////
}

void ChristmasWindow::InitialiseCamera(){
	_cameraAngle = 30.0;
	_cameraPositionZ = -5.0;
	_cameraRotation = 0.0;
	_cameraHerical = 0.0;
}

void ChristmasWindow::InitialiseParicles(){
	_smoke.Initialize();

	_snowflake.setTexture(modelController->_textures[4]);
	_snowflake.setHeight(2.7);
	_snowflake.setRaius(2.2);
	_snowflake.Initialize();

	_fire.Initialize();
}


void ChristmasWindow::InitialiseShader(){

	CheckShaderEnvironment();
	//init cube shader
	if(GenerateShaderProgram(_cubeShaderProgramID,"studyvertexshader1.glsl","studyfragshader1.glsl")){
		printf("generate ok\n");
/*		glBindAttribLocation(_cubeShaderProgramID,0, "MCVertex");*/
// 		glBindAttribLocation(_cubeShaderProgramID,1, "VertexColor");
// 		glBindAttribLocation(_cubeShaderProgramID,2, "Testfloat0");
// 		glBindAttribLocation(_cubeShaderProgramID,3, "Testfloat1");
// 		glBindAttribLocation(_cubeShaderProgramID,4, "Testfloat2");
		
		
// 		int k = glGetAttribLocation(_cubeShaderProgramID,"Testfloat2");
// 		k = 0;
		
		
	}else{
		printf("generate failed!\n");
	}




}
/************************************************************************/
/* load shaders                                                                     */
/************************************************************************/
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
void ChristmasWindow::LoadShaders(){
	_cubeShaderProgramID = glCreateProgram();

	GLuint vertexShaderID;
	GLuint fragmentShaderID;

	try
	{
		vertexShaderID = GenerateShaderObject("testvertexshader.vert", GL_VERTEX_SHADER);
		fragmentShaderID = GenerateShaderObject("testfragshader.frag", GL_FRAGMENT_SHADER);

// 		glAttachShader(_cubeShaderProgramID, vertexShaderID);
// 		glAttachShader(_cubeShaderProgramID, fragmentShaderID);

		glLinkProgram(_cubeShaderProgramID);

	}
	catch(exception& e)
	{
		cerr << e.what() << endl;
	}
}

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
// 		glBindAttribLocation(_cubeShaderProgramID,4, "Testfloat2");
		/*glBindFragDataLocation(programID,0,"FragColor");*/

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

		return false;
	}

	return true;
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

	////////////////////////
	// Try to build shader

	// Create shader object
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
/* initialize shadow                                                                     */
/************************************************************************/
void ChristmasWindow::InitialiseShadow(){
	

}
/************************************************************************/
/* update shadow                                                                     */
/************************************************************************/
void ChristmasWindow::UpdateShadow(){
	
}


/*const vec3f _startup(0,1,0);*/
void ChristmasWindow::TestMethod()
{

	glTranslatef(0.0,2.0,0.0);
	if(_testObject->useShader){
		//_testObject->Draw();
	}else{
		//_testObject->Draw();
	}


	/**
	float matrix[16];

	vec3f campos(0,0,_cameraPositionZ);

	vec3f vectoreye = -campos;
	vec3f tempup(0,1,0);

	vec3f look = mxy::normalize(vectoreye);
	vec3f right = mxy::normalize(cross(look,tempup));
	vec3f rightup = mxy::normalize(cross(right,look));

	glPushMatrix();

	glGetFloatv(GL_MODELVIEW_MATRIX , matrix);

	matrix[0] = right.x;	matrix[1] =right.y;		matrix[2] = right.z;		matrix[3] = 0;

	matrix[4] = rightup.x;	matrix[5] =rightup.y;	matrix[6] = rightup.z;		matrix[7] = 0;

	matrix[8] = look.x;		matrix[9] =look.y;		matrix[10] = look.z;		matrix[11] = 0;

	//matrix[12] = -vectoreye.x;			matrix[13] = -vectoreye.y+1;			matrix[14] = -vectoreye.z;				matrix[15] = 1;


	glLoadMatrixf(matrix);
	glDisable(GL_CULL_FACE);
	glPointSize(10.0);
	glBegin(GL_TRIANGLES);//GL_POINT,GL_TRIANGLES
	glColor3f(0,1,0);
	glNormal3f(0.0f,0.0f,1.0f);
	glVertex3f(-1.0f,1.0f,0.0f);
	glVertex3f(1.0f,1.0f,0.0f);
	glVertex3f(0.0f,2.0f,0.0f);

	glEnd();
	glEnable(GL_CULL_FACE);


	float matrix2[16];
	glGetFloatv(GL_MODELVIEW_MATRIX,&matrix2[0]);

	glPopMatrix();
	*/



}
