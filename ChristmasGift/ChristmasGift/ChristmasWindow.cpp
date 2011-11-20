#include "ChristmasWindow.h"


#define USECASTSHADOW1
#define DRAWREFLECTION
#define ALLOWSEATCULLFACE1

const Vector4f _PS = Vector4f(1.0f,0.0f,0.0f,0.0f);
const Vector4f _PT = Vector4f(0.0f,1.0f,0.0f,0.0f);
const Vector4f _PR = Vector4f(0.0f,0.0f,1.0f,0.0f);
const Vector4f _PQ = Vector4f(0.0f,0.0f,0.0f,1.0f);

/*(0.64,1.0,0.51*/
const float pool_pos_x = 0.55;
const float pool_pos_y = 0.94;
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
const float tree_pos_y = 1.0;
const float tree_pos_z = -0.2;
const float tree_scal_x = 0.2;
const float tree_scal_y = 0.2;
const float tree_scal_z = 0.2;


ChristmasWindow::ChristmasWindow(void) :_loadStencilBuffer(true),_drawSpotLights(false),_bMultitex(false) ,_bHaveMultitex(false) ,_angleInc(30),_currentSeason(Spring),_timerCounter(0),_timeDecFactor(1),_seasonCounter(0)
{
	SetSize(512,512);
	SetDepthBits(24);
	SetTitle("Christmas Gift From Xiaoyu Ma");
	
	_switch = false;

// 	_cameraPositionVec3f.x = 0;
// 	_cameraPositionVec3f.y = 0;
// 	_cameraPositionVec3f.z = _cameraPosition;

}




void ChristmasWindow::initialiseLights(){
	/************************************************************************/
	/* initialize lighting                                                                     */
	/************************************************************************/
	_sunPos.Assign(0.0,0.0,5.0,1.0);
	_sun.create(0, Color(0.2f,0.2f,0.2f,1.0f), Color(0.7f,0.7f,0.7f,1.0f),_sunPos);
	
	/*_sun.setPosition(Vector4f(0.0,0.0,5.0,1.0));*/
	

	_spotlightRed.create(1,Color::black(),Color(1.0f,0.0f,0.0f,1.0f));
	_spotlightRed.setSpot(30.0,100.0f);

	_spotlightGreen.create(2,Color::black(),Color(0.0f,1.0f,0.0f,1.0f));
	_spotlightGreen.setSpot(30.0,100.0f);

	_spotlightBlue.create(3,Color::black(),Color(0.0f,0.0f,1.0f,1.0f));
	_spotlightBlue.setSpot(30.0,100.0f);

	_spotlightWhite.create(4,Color::black(),Color(1.0f,1.0f,0.0f,1.0f));
	_spotlightWhite.setSpot(30.0,100.0f);

	// turn the global ambient off by setting it to zero
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Color::black().rgba());

	_sun.apply();

	_spotlightRed.apply();
 	_spotlightGreen.apply();
	_spotlightBlue.apply();
	_spotlightWhite.apply();

	
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
	initialiseLights();
	//////////////////////////////////////////////////////////////////////////
	
	/************************************************************************/
	/* test for modelcontroller       test passed                           */
	/************************************************************************/
	/*ModelController* */modelController = ModelController::GetInstance();
	/************************************************************************/
	/* load texture together                                                */
	/************************************************************************/
	//GLuint* _textures;
	modelController->LoadTexture();
#ifdef USECASTSHADOW
	glActiveTextureARB(GL_TEXTURE0_ARB);
#endif
	//////////////////////////////////////////////////////////////////////////
	/************************************************************************/
	/* use mutil textue, purpose for shadow                                 */
	/************************************************************************/	
	_planepos.Assign(0.0f,3.3f,0.0f,1.0f);
	
	/************************************************************************/
	/* start to create model in this scene                                   */
	/************************************************************************/
	_house = new DisplayObjectModel();
	_house->setRenderTexture(true);
	_house->setRenderMaterials(false);
	modelController->AssemblyModelFromFile(_house,"House2.mxy",modelController->_textures[0]);

	/************************************************************************/
	/* seat                                                                     */
	/************************************************************************/
	_seat = new DisplayObjectModel();
	_seat->setRenderTexture(true);
	_seat->setRenderMaterials(false);
	modelController->AssemblyModelFromFile(_seat,"ground.mxy",modelController->_textures[2]);
	
	/************************************************************************/
	/* tree                                                                     */
	/************************************************************************/
 	_tree = new ChristmasTree();
 	_tree->setTreeParameter();
 	_tree->Initialize();

	/************************************************************************/
	/* glass ball                                                                     */
	/************************************************************************/
	_ball = new DisplayObjectModel();
// 	Materials _ballMaterials;
// 	_ballMaterials.create(Color::black(), Color(1.0,0.0,0.0,0.0));
// 	bool _ballRenderTextures = false;
// 	bool _ballRenderMaterials = true;
// 	bool _ballEnableTransparency = true;
	/*_ball->setMaterials(_ballMaterials);*/
	_ball->setEnableTransparency(true);
	_ball->setRenderTexture(false);
	_ball->setRenderMaterials(false);
	_ball->setColorApalha(0.1);
	modelController->AssemblyTransparencyPartSphere(_ball,1.0,40,40,modelController->_textures[0]);

	/************************************************************************/
	/* water pool                                                                     */
	/************************************************************************/
	_pool = new DisplayObjectModel();
// 	bool _poolRenterTextures = false;
// 	bool _poolRenderMaterials = false;
// 	bool _poolEnableTransparency = true;
	_pool->setRenderTexture(false);
	_pool->setRenderMaterials(false);
	_pool->setEnableTransparency(true);
	_pool->setColorApalha(0.5);
	modelController->AssemblyModelFromFile(_pool,"pool.mxy",modelController->_textures[0]);
	_pool->setEnableTransparency(false);
	
	//////////////////////////////////////////////////////////////////////////
	_cameraAngle = 30.0;
	_cameraPosition = -5.0;
	_cameraRotation = 0.0;
	_cameraHerical = 0.0;
	
	//////////////////////////////////////////////////////////////////////////
#ifdef USECASTSHADOW
	initShadow();
#endif

	loadShaders();
	_green.create(Color::black(), Color::green());

	/************************************************************************/
	/* particles                                                                     */
	/************************************************************************/
// 	pp.setTexture(modelController->_textures[4]);
// 	pp.Initialize();
	pp1.working = true;
	pp1.Initialize();

	/*testtexid = modelController->_textures[4];*/
}
const vec3f _startup(0,1,0);
void ChristmasWindow::TestMethod()
{
	float matrix[16];

	vec3f campos(0,0,_cameraPosition);
	vec3f veceye(0,0,-_cameraPosition);

	//test
	/*vec3f test(10,10,10);*/

	vec3f vectoreye = -campos;

	
	vec3f look = mxy::normalize(vectoreye);

	vec3f tempup(0,1,0);

	vec3f right = mxy::normalize(cross(look,tempup));
	vec3f rightup = mxy::normalize(cross(right,look));

// 	vec3f right = mxy::normalize(cross( canpos, _startup));
// 	vec3f up = normalize( cross( right, canpos));
// 	vec3f look = normalize( cross( up, right));

	glPushMatrix();

	/*glGetFloatv(GL_MODELVIEW_MATRIX , matrix);*/

// 	matrix[0] = matrix[10] = matrix[15] = 1.0f;
// 	matrix[1] = matrix[2] = matrix[8] = matrix[9] = 0.0f;
// 	matrix[0] = right.x; matrix[1] =rightup.x; matrix[2] = look.x; matrix[3] = 0;
// 	matrix[4] = right.y; matrix[5] =rightup.y; matrix[6] = look.y; matrix[7] = 1;
// 	matrix[8] = right.z; matrix[9] =rightup.z; matrix[10] = look.z; matrix[11] = 0;
// 	matrix[12] = 0; matrix[13] =0; matrix[14] = 0; matrix[15] = 1;

	matrix[0] = right.x;	matrix[1] =right.y;		matrix[2] = right.z;		matrix[3] = 0;

	matrix[4] = rightup.x;	matrix[5] =rightup.y;	matrix[6] = rightup.z;		matrix[7] = 0;

	matrix[8] = look.x;		matrix[9] =look.y;		matrix[10] = look.z;		matrix[11] = 0;

	matrix[12] = 0;			matrix[13] =1;			matrix[14] = 0;				matrix[15] = 1;


	/*glLoadMatrixf(matrix);*/
// 	glDisable(GL_CULL_FACE);
// 	glPointSize(10.0);
// 	glBegin(GL_TRIANGLES);//GL_POINT,GL_TRIANGLES
// 	glColor3f(1,1,1);
// 	glNormal3f(0.0f,0.0f,1.0f);
// 	glVertex3f(-1.0f,1.0f,0.0f);
// 	glVertex3f(1.0f,1.0f,0.0f);
// 	glVertex3f(0.0f,2.0f,0.0f);
// 
// 	glEnd();
// 	glEnable(GL_CULL_FACE);


	/**
	float quadratic[] = { 1.0f, 0.0f, 0.01f };
	
	glPointParameterfvARB( GL_POINT_DISTANCE_ATTENUATION_ARB, quadratic );
	glPointParameterfARB( GL_POINT_FADE_THRESHOLD_SIZE_ARB, 60.0f );
	glPointParameterfARB( GL_POINT_SIZE_MIN_ARB, 13.0f );
	glPointParameterfARB( GL_POINT_SIZE_MAX_ARB, 100.0f );

	glTexEnvf( GL_POINT_SPRITE_ARB, GL_COORD_REPLACE_ARB, GL_TRUE );

	glEnable( GL_POINT_SPRITE_ARB );
	/*glPointParameterf(GL_POINT_DISTANCE_ATTENUATION_ARB, 0.1);*/
	/*glEnable(GL_POINT_SPRITE);*/
	/**
	glPointSize(30.0);
	glBegin(GL_POINT);
	glColor3f(1,1,1);
	glVertex3f(0, 3,0);

	glEnd();
	glDisable( GL_POINT_SPRITE_ARB );
	*/
// 	bool m_PointARBEnable;
// 	bool m_PointNVEnable;
// 	PFNGLPOINTPARAMETERFARBPROC  glPointParameterfARB  ;
// 	PFNGLPOINTPARAMETERFVARBPROC glPointParameterfvARB ;
// 	void CheckForExtension(void);
// 
// 	char *ext = (char*)glGetString(GL_EXTENSIONS);
// 	if(strstr(ext, "GL_ARB_point_parameters") != NULL){
// 		glPointParameterfARB  = (PFNGLPOINTPARAMETERFEXTPROC)wglGetProcAddress("glPointParameterfARB");
// 		glPointParameterfvARB = (PFNGLPOINTPARAMETERFVEXTPROC)wglGetProcAddress("glPointParameterfvARB");
// 		if( !glPointParameterfARB || !glPointParameterfvARB )
// 		{
// 			/*LOGFILE<<"One or more GL_EXT_point_parameters functions were not found"<<std::endl;*/
// 			m_PointARBEnable=false;
// 		}
// 		m_PointARBEnable=true;
// 	}


// 	glBindTexture(GL_TEXTURE_2D,testtexid);
// 	glEnable(GL_POINT_SPRITE);
// 	glTexEnvi(GL_POINT_SPRITE,GL_COORD_REPLACE,GL_TRUE);
// 	
// 	glPointSize(30.0);
// 	glBegin(GL_POINT);
// 	glColor3f(1,0,0);
// 	glVertex3f(0, 3,0);
// 
// 	glEnd();
// 	
	float quadratic[] =  { 10.0f, 0.0f, 0.01f };
	glPointParameterfv( GL_POINT_DISTANCE_ATTENUATION, quadratic );
	float maxSize = 0.0f;
	glGetFloatv( GL_POINT_SIZE_MAX, &maxSize  );
	glPointSize( /*maxSize*/ 2 );
	glPointParameterf( GL_POINT_SIZE_MAX, maxSize );
	glPointParameterf( GL_POINT_SIZE_MIN, 0.5f );
	glTexEnvf( GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE );
	
	glEnable( GL_POINT_SPRITE );
	glBegin( GL_POINTS );
	{
		glColor4f(1,0,1,1.0f);
		glVertex3f(2,1,0);
	}
	glEnd();
	glDisable( GL_POINT_SPRITE );


	glPopMatrix();

}
/************************************************************************/
/* test for particles                                                                     */
/************************************************************************/

/************************************************************************/
/* load shaders                                                                     */
/************************************************************************/
void ChristmasWindow::loadShaders(){
	_shaderProgramID = glCreateProgram();

	GLuint vertexShaderID;
	GLuint fragmentShaderID;

	try
	{
		vertexShaderID = generateShaderObject("phongvertexshader.txt", GL_VERTEX_SHADER);
		fragmentShaderID = generateShaderObject("phongfragmentshader.txt", GL_FRAGMENT_SHADER);

		glAttachShader(_shaderProgramID, vertexShaderID);
		glAttachShader(_shaderProgramID, fragmentShaderID);

		glLinkProgram(_shaderProgramID);

	}
	catch(exception& e)
	{
		cerr << e.what() << endl;
	}
}
GLuint ChristmasWindow::generateShaderObject(std::string filename, GLenum shaderType){
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

	return id;
}
/************************************************************************/
/* initialize shadow                                                                     */
/************************************************************************/
void ChristmasWindow::initShadow(){
	glGenTextures(1,&_shadow);
	glActiveTextureARB(GL_TEXTURE1_ARB);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _shadow);
	glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, 0, 0, 512, 512, 0);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// enter texture stack
	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();
	glTranslatef(0.5f, 0.5f, 0.0f);
	glScalef(0.5f, 0.5f, 1.0f);
	gluPerspective(60.0f, 1.0f, 0.01f, 10.0f);
	glPushMatrix();
	// leave texture stack
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);
	glEnable(GL_TEXTURE_GEN_R);
	glEnable(GL_TEXTURE_GEN_Q);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glDisable(GL_TEXTURE_2D);

}
/************************************************************************/
/* update shadow                                                                     */
/************************************************************************/
void ChristmasWindow::updateShadow(){
	glActiveTextureARB(GL_TEXTURE1_ARB);
	glViewport(0,0,512,512);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f,1.0f, 0.01f, 10.0f);
	glMatrixMode(GL_MODELVIEW);

	glDisable(GL_LIGHTING);
	glColor3f(0.5f,0.5f,0.5f);//gray
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
		gluLookAt(_sun[0], _sun[1], _sun[2], _planepos[0], _planepos[1], _planepos[2], 0.0f, 1.0f, 0.0f); 
		glTranslatef(_planepos[0],_planepos[1],_planepos[2]);
		
		glDisable(GL_CULL_FACE);
		
		_house->Draw();

		glEnable(GL_CULL_FACE);

	glPopMatrix();

	glBindTexture(GL_TEXTURE_2D, _shadow);
	glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, 512, 512);

	// start lights again
	glEnable(GL_LIGHTING);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	OnResize(Width(),Height());
}
/************************************************************************/
/* update function                                                                     */
/************************************************************************/
void ChristmasWindow::OnUpdate(){
	float deltaTime = (float)App::GetDeltaTime();
	_timerCounter = _timerCounter + deltaTime;
	_seasonCounter++;
	if(_timerCounter>= SEASONLENGTH*_timeDecFactor){
		_tree->Update(deltaTime);
		_timerCounter = 0;
	}
	if(Spring == _tree->_currentSeason){
		_currentSeason = Spring;
	}
	if(Summer == _tree->_currentSeason){
		_currentSeason = Summer;
	}

	if(Autumn == _tree->_currentSeason){
		_currentSeason = Autumn;
	}

	if(Winter == _tree->_currentSeason){
		_currentSeason = Winter;
	}

#ifdef USECASTSHADOW
	updateShadow();
#endif
	
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
		glTranslatef(0.0f, 0.0f,_cameraPosition);
		glRotatef(_cameraAngle, 1.0,0.0,0.0);
		glRotatef(_cameraRotation, 0.0, 1.0, 0.0);

		

		glPushMatrix();
			glTranslatef(0,4,0);
			
			pp1.Draw();
			
		glPopMatrix();

// 		glPushMatrix();
// 			_green.apply();
// 			glTranslatef(0.0f, 1.0f, 0.0f);
// 			/*tree();*/
// 		glPopMatrix();


#ifdef	USECASTSHADOW 

		glActiveTextureARB(GL_TEXTURE1_ARB);
		glBindTexture(GL_TEXTURE_2D, _shadow);
		glTexGenfv(GL_S, GL_EYE_PLANE, _PS.xyzw());
		glTexGenfv(GL_T, GL_EYE_PLANE, _PT.xyzw());
		glTexGenfv(GL_R, GL_EYE_PLANE, _PR.xyzw());
		glTexGenfv(GL_Q, GL_EYE_PLANE, _PQ.xyzw());
		glEnable(GL_TEXTURE_2D);

		glMatrixMode(GL_TEXTURE);
		glPopMatrix();
		glPushMatrix();
		gluLookAt(_sun[0], _sun[1], _sun[2], _planepos[0], _planepos[1], _planepos[2], 0.0f, 1.0f, 0.0f); 
		glMatrixMode(GL_MODELVIEW);
		glActiveTextureARB(GL_TEXTURE0_ARB);
		glEnable(GL_TEXTURE_2D);

#endif

		glPushMatrix();
			if(_drawSpotLights){
				
				_spotlightRed.apply();
				_spotlightGreen.apply();
				_spotlightBlue.apply();
				_spotlightWhite.apply();
				drawSporLights();
			}
			else{
				glDisable(GL_LIGHT1);
				glDisable(GL_LIGHT2);
				glDisable(GL_LIGHT3);
				glDisable(GL_LIGHT4);
			}
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0,1,0.0);
			glRotatef(-90.0f,1.0,0.0,0.0);
			_seat->Draw();
		glPopMatrix();

		
		glPushMatrix();
			glScalef(0.25,0.25,0.25);
			glTranslatef(-4.0,5.0,0.0f);
			glRotatef(-90,1.0,0.0,0.0);
			_house->Draw();
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
		glPushMatrix();
		glTranslatef(tree_pos_x,tree_pos_y,tree_pos_z);
		glScalef(tree_scal_x,tree_scal_y,tree_scal_z);
		_tree->Draw();
		glPopMatrix();
		

		

		

		/************************************************************************/
		/* last draw the ball                                                                     */
		/************************************************************************/
		
		glPushMatrix();
		glTranslatef(0.0f, 3.29f, 0.0f);
		glScalef(3,3,3);
		/*_ball->Draw();*/
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
		default:
			break;
	}
}
void ChristmasWindow::OnMouseMove(int x, int y) {
	static int temp_x, temp_y;
	if(_leftDown) {
		_cameraPosition += (y-temp_y)*0.05f;
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








void ChristmasWindow::drawSporLights(){
	_spotlightRed.setPosition(Vector4f(0,8,0,1.0f));
	_spotlightRed.setDirection(Vector4f(1.0f,-4.0f,0.0f, 0.0f));
	_spotlightGreen.setPosition(Vector4f(0,8,0,1.0f));
	_spotlightGreen.setDirection(Vector4f(-1.0f,-4.0f,0.0f, 0.0f));
	_spotlightBlue.setPosition(Vector4f(0,8,0,1.0f));
	_spotlightBlue.setDirection(Vector4f(0.0f,-4.0f,1.0f, 0.0f));
	_spotlightWhite.setPosition(Vector4f(0,8,0,1.0f));
	_spotlightWhite.setDirection(Vector4f(0.0f,-4.0f,-1.0f, 0.0f));

}