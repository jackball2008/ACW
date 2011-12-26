#include "ChristmasWindow.h"

#define SEASONLENGTH 3*30*24*60*60


#define DRAWREFLECTION



ChristmasWindow::ChristmasWindow(void) :
	_sunRunCycleAngleInc(30)
{
	SetSize(512,512);
	SetDepthBits(24);
	SetTitle("Christmas Gift From Xiaoyu Ma email: maxiaoyuzdz@gmail.com");

	//stencilbuffer
/*	_loadStencilBuffer = true;*/
	_drawSpotLights = false;
	//multitexture support check
	_bMultitex = _bHaveMultitex = false;
	_sunRunCycleAngle = 0.0f;
	_currentSeason = Spring;
	_timerCounter = 0;
	_timeSpeedFactor = 1;

	pauseCounter = 0;
}




void ChristmasWindow::OnCreate()
{
	GLWindowEx::OnCreate();

	//CreateFBO();

	CheckMultitextureSupport();
	//////////////////////////////////////////////////////////////////////////
	InitialiseCamera();
	LoadCamera();
	//////////////////////////////////////////////////////////////////////////
	LoadBasicOpenGLParame();
	//////////////////////////////////////////////////////////////////////////
	InitialiseLights();
	//////////////////////////////////////////////////////////////////////////
	CheckShaderEnvironment();
	//////////////////////////////////////////////////////////////////////////
	LoadModels();
	
	//////////////////////////////////////////////////////////////////////////
	InitialiseParicles();

	win_status = winterbegin;
	
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
	/* update every shader first                                                                     */
	/************************************************************************/
	
	//update seat shader
	glUseProgram(_seatSurface->shaderProgramID);
	int loc = glGetUniformLocation(_seatSurface->shaderProgramID,"size");
	if(loc!=-1)
		glUniform1f(loc,_seatSurface->snowVal);
	else
		cout<<"uniform error"<<endl;
	glUseProgram(0);
	//update houseroof shader
	glUseProgram(_houseRoof->shaderProgramID);
	loc = glGetUniformLocation(_houseRoof->shaderProgramID,"size");
	if(loc!=-1)
		glUniform1f(loc,_seatSurface->snowVal);//same like seat
	else
		cout<<"uniform error"<<endl;
	glUseProgram(0);
	/************************************************************************/
	/* updat                                                                     */
	/************************************************************************/
	/************************************************************************/
	/* update particles                                                                     */
	/************************************************************************/
	glUseProgram(_snowflake->shaderProgramID);
	//
	loc = glGetUniformLocation(_snowflake->shaderProgramID,"ColorTexture");
	if(loc>-1)
		glUniform1i(loc,0);
	else
		cout<<"uniform error"<<endl;
	loc = glGetUniformLocation(_snowflake->shaderProgramID,"cameraPos");
	if(loc>-1)
		glUniform4fv(loc,1,camera_org);
	else
		cout<<"uniform error"<<endl;

	glUseProgram(0);

	glUseProgram(_fire->shaderProgramID);
	loc = glGetUniformLocation(_fire->shaderProgramID,"cameraPos");
	if(loc>-1)
		glUniform4fv(loc,1,camera_org);
	else
		cout<<"uniform error"<<endl;

	glUseProgram(0);

	/************************************************************************/
	/* update ball                                                                     */
	/************************************************************************/

	glUseProgram(_ball->shaderProgramID);
	loc = glGetUniformLocation(_ball->shaderProgramID,"cameraPos");
	if(loc>-1)
		glUniform4fv(loc,1,camera_org);
	else
		cout<<"uniform error"<<endl;
	glUseProgram(0);

// 	glUseProgram(_tree->leaf_shader_programID);
// 	loc = glGetUniformLocation(_tree->leaf_shader_programID,"cameraPos");
// 	if(loc>-1)
// 		glUniform4fv(loc,1,camera_org);
// 	else
// 		cout<<"uniform error"<<endl;
// 	glUseProgram(0);

 	_snowflake->Update(tempDelataTime);
	_fire->Update(tempDelataTime);
	_smoke->Update(tempDelataTime);
	//////////////////////////////////////////////////////////////////////////
// 	_smoke.Update(tempDelataTime);
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
			//**************************************
			//_currentSeason = Winter;
			//**************************************

			//start flash
			_lightingBolt->Start();
			if(Pause(20)){
				_lightingBolt->Stop();
				_tree->TreeState = FIREING;
			}
		}
		if( FIREING == _tree->TreeState){
			
			//cout<<"fire"<<endl;
			_tree->TreeState = TREEDOWNING;
			_fire->Start();
		}
		if(FIREEND == _tree->TreeState){

		}

		if(TREEDOWNEND == _tree->TreeState){
			_fire->Stop();
			_currentSeason = Winter;
		}

	}
	
	if(Winter == _currentSeason ){
		
		

		if(winterbegin == win_status){
			_smoke->Start();//the house start to emit smoke
			_snowflake->Start();
			_seatSurface->snowVal -= 0.01;
			if(_seatSurface->snowVal < 0.19){
				_seatSurface->snowVal = 0.19;
				win_status = winterlast;
			}
		}

		if(winterlast == win_status){
			if(Pause(5000))
				win_status = winterend;
		}
		if(winterend == win_status){
			_seatSurface->snowVal += 0.01;
			if(_seatSurface->snowVal>50)
			{
				_seatSurface->snowVal = 51;

				win_status = happynewyear;
			}
		}
		if(happynewyear == win_status){
			_smoke->Stop();
			_snowflake->Stop();
			_tree->reset();
			_tree->TreeState = START;
			_currentSeason = Spring;
			win_status = winterbegin;
		}
		

		
// 		if( TREEDOWNEND == _tree->TreeState){
// 			/*_currentSeason = Winter;*/
// 			
// 			_tree->reset();
// 			_tree->TreeState = START;
// 			_currentSeason = Spring;
// 
// 		}

		
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
// 	glPushMatrix();
// 		glTranslatef(pool_pos_x,pool_pos_y,pool_pos_z);
// 		glRotatef(-270,1,0,0);
// 		glScalef(pool_scal_x,pool_scal_y,pool_scal_z);
// 		_pool->Draw();
		_pool->rotaterangle=-270;
		_pool->Draw();
/*	glPopMatrix();*/
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

	
	glCullFace(GL_FRONT);

	//_tree->Draw();
	_tree->DrawReflection();

	glCullFace(GL_BACK);
	glPopMatrix();
	
	



	
}

void ChristmasWindow::OnDisplay()
{
	

	
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glPushMatrix();
		glTranslatef(0.0f, 0.0f,_cameraPositionZ);
		glRotatef(_cameraAngle, 1.0,0.0,0.0);
		glRotatef(_cameraRotation, 0.0, 1.0, 0.0);
		
		

		glGetFloatv(GL_MODELVIEW_MATRIX,mdl);
		CalculateCameraWorldPosition();
		//put here because the camera pos is the newest
		this->OnUpdate();

		

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
			glRotatef(-4*_sunRunCycleAngle, 0.0, 0.0, 1.0);
			_sunLight.setPosition(Vector4f(5.0,5.0,0.0,1.0));
			glTranslatef(5.0,5.0,0.0);
			_sunMaterial.apply();
			_sunSphere.draw();
		glPopMatrix();

		
		/************************************************************************/
		/* draw smoke                                                                     */
		/************************************************************************/
		glPushMatrix();
			glTranslatef(-1.24f,1.06,0.15);
			_smoke->Draw();
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
 				_snowflake->Draw();
// 			}
		glPopMatrix();


		glPushMatrix();
			glTranslatef(0.6f,0.2f,-0.2f);
			_fire->Draw();
			//glRotatef(20,0,0,1);
			
// 			if(_fire.working){
// 				_fire.Draw();
// 			}
		glPopMatrix();
		
		glPushMatrix();
		glScalef(1,4,1);
		glTranslatef(0.3f,0.0f,-0.2f);
		_lightingBolt->Draw();
		glPopMatrix();

		glPushMatrix();
		
		glTranslatef(0.0f,-0.5f,0.0f);
		glRotatef(-90.0f,1.0,0.0,0.0);
		_seatBody->Draw();
		glPopMatrix();
		/*glPushMatrix();*/
			//glRotatef(-90.0f,1.0,0.0,0.0);
			_seatSurface->Draw();
		/*glPopMatrix();*/

		glPushMatrix();
			glTranslatef(-1.0,0.28,0.0f);
			glScalef(0.25,0.25,0.25);
			glRotatef(-90,1.0,0.0,0.0);
			_houseBody->Draw();
			_houseRoof->Draw();
			_houseChemry->Draw();
/*			_house->Draw();*/
		glPopMatrix();

		//glUseProgram(_TreeProgramID);
		//glPushMatrix();
// 			glTranslatef(tree_pos_x,tree_pos_y,tree_pos_z);
// 			glScalef(tree_scal_x,tree_scal_y,tree_scal_z);
			
			_tree->Draw();
		//glPopMatrix();
		//glUseProgram(0);


		// 		glUseProgram(_shaderProgramID);
		// 		glUseProgram(0);	
/*#ifdef DRAWREFLECTION*/
		/************************************************************************/
		/* draw reflection                                                                     */
		/************************************************************************/
		glDepthMask(GL_FALSE);
// 		if (_loadStencilBuffer)
// 		{
// 			LoadStencil();
// 		}
		LoadStencil();
		DrawReflection();

		glDisable(GL_STENCIL_TEST);
		glDepthMask(GL_TRUE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glFrontFace(GL_CW);
// 		glPushMatrix();
// 			glTranslatef(pool_pos_x,pool_pos_y,pool_pos_z);
// 			glRotatef(-90,1,0,0);
// 			glScalef(pool_scal_x,pool_scal_y,pool_scal_z);
			_pool->rotaterangle=-90;
			_pool->Draw();
/*		glPopMatrix();*/
		glFrontFace(GL_CCW);
		glDisable(GL_BLEND);
/*#endif*/
		

		glDisable(GL_STENCIL_TEST);
		glDepthMask(GL_TRUE);
		
		//I don't know why is here
		glEnable(GL_BLEND);

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
// 		glPushMatrix();
// 			glTranslatef(pool_pos_x,pool_pos_y,pool_pos_z);
// 			glRotatef(-90,1,0,0);
// 			glScalef(pool_scal_x,pool_scal_y,pool_scal_z);
// 			_pool->Draw();
			_pool->rotaterangle=-90;
			_pool->Draw();
/*		glPopMatrix();*/
		

		glDisable(GL_BLEND);
		
		
		/************************************************************************/
		/* last draw the ball                                                                     */
		/************************************************************************/
		glUseProgram(0);
		glPushMatrix();
			glTranslatef(0.0f, 2.1f, 0.0f);
			glScalef(3,3,3);
			_ball->Draw();
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
	//char c = tolower(key);

	switch(key){
	
	case 187:
		_timeSpeedFactor = _timeSpeedFactor * 2.0;
		cout<<"Decrease Speed +"<<endl;
		break;
	case 189:
		_timeSpeedFactor = _timeSpeedFactor * 0.5;
		cout<<"Increase Speed -"<<endl;
		break;
	}
	switch( tolower(key) ) {
	case '&': 
		_cameraAngle += 5.0;
		break;
	case '(':
		_cameraAngle -= 5.0;
		break;
// 		case 'a': 
// 			_cameraAngle += 5.0;
// 			break;
// 		case 'z':
// 			_cameraAngle -= 5.0;
// 			break;
		case 'c': 
			_cameraHerical += 5.0;
			break;
		case 'x':
			_cameraHerical -= 5.0;
			break;
		
		
		case 's':
			_drawSpotLights = !_drawSpotLights;
			break;
		case 'u':
			_smoke->working = !_smoke->working;
/*			_smoke.working = !_smoke.working;*/
			break;
		case 'y':
			_snowflake->working = !_snowflake->working;
			break;
		case 't':
			_fire->working = !_fire->working;
			break;
		case 'q':
			_seatSurface->snowVal = _seatSurface->snowVal + 0.1;
			/*			_fire.working = !_fire.working;*/
			cout<<"snow v = "<<_seatSurface->snowVal<<endl;
			break;
		case 'w':
			_seatSurface->snowVal = _seatSurface->snowVal - 0.1;
			/*			_fire.working = !_fire.working;*/
			cout<<"snow v = "<<_seatSurface->snowVal<<endl;
			break;
		case 'm':
			_tree->ChangeRenderType();
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

	_spotlightGreen.create(2,Color::black(),Color::red());
	_spotlightGreen.setSpot(30.0,100.0f);

	_spotlightBlue.create(3,Color::black(),Color::red());//
	_spotlightBlue.setSpot(30.0,100.0f);

	_spotlightWhite.create(4,Color::black(),Color::red());
	_spotlightWhite.setSpot(30.0,100.0f);

	// turn the global ambient off by setting it to zero
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Color::black().rgba());

	_sunLight.apply();

	_spotlightRed.apply();
	_spotlightGreen.apply();
	_spotlightBlue.apply();
	_spotlightWhite.apply();

	_sunSphere.create(0.1f, 10, 10, false);
	_sunMaterial.create(Color::black(), Color::black(), Color(1.0,1.0,1.0,0.7));

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	
}


void ChristmasWindow::LoadModels(){
	

	/************************************************************************/
	/* lighting nolt                                                                     */
	/************************************************************************/
	_lightingBolt = new LightingBolt();
	LoadTexture("redflash.jpg",_lightingBolt->textureID);
	_lightingBolt->shaderProgramID = LoadShaderFromFile("LightingBoltVertex.glsl","LightingBoltFrag.glsl");
	/************************************************************************/
	/* seat  surface                                                           */
	/************************************************************************/
 	_seatSurface = new Seat();
	_seatSurface->rotaterangle = -90.0f;
	_seatSurface->rotatex = 1.0f;
	_seatSurface->Initialize("ground.mxy");
	LoadTexture("seat_tex.tga",_seatSurface->seat_texture_ID);
	//LoadTexture("blank_tex_s.tga",_seatSurface->permTextureID);
	_seatSurface->shaderProgramID = LoadShaderFromFile("SeatVertexShader.glsl","SeatFragShader.glsl");

	glUseProgram(_seatSurface->shaderProgramID);
	int loc = glGetUniformLocation(_seatSurface->shaderProgramID,"permTexture");
	if(loc>-1)
		glUniform1i(loc,1);
	else
		cout<<"uniform error"<<endl;
	loc = glGetUniformLocation(_seatSurface->shaderProgramID,"size");
	if(loc>-1)
		glUniform1f(loc,_seatSurface->snowVal);
	else
		cout<<"uniform error"<<endl;

	
	loc = glGetUniformLocation(_seatSurface->shaderProgramID,"ColorTexture");
	if(loc!=-1)
		glUniform1i(loc,0);
	else
		cout<<"uniform error"<<endl;
	glUseProgram(0);

	/************************************************************************/
	/* water pool                                                                     */
	/************************************************************************/
	_pool = new Pool();
	_pool->translatex = 0.55;
	_pool->translatey = -0.06;
	_pool->translatez = 0.53;
	_pool->scalex = 0.58;
	_pool->scaley = 0.58;
	_pool->scalez = 0.58;
	_pool->Initialize("pool.mxy");
	for(int i = 0; i < _pool->numberOfVertices;i++){
		_pool->_vertices[i].colour[A_POS] = 0.5;
	}
	_pool->shaderProgramID = LoadShaderFromFile("PoolVertexShader.glsl","PoolFragShader.glsl");

	_seatBody = new SeatBody();
	_seatBody->Initialize("seatbody.mxy");//wood.jpg
	LoadTexture("wood.jpg",_seatBody->textureID);

	// 	_pool->setRenderTexture(false);
	// 	_pool->setRenderMaterials(false);
	// 	_pool->setEnableTransparency(true);
	// 	_pool->setColorApalha(0.5);
	// 	modelController->AssemblyModelFromFile(_pool,"pool.mxy",modelController->_textures[0]);
	// 	_pool->setEnableTransparency(false);
	/************************************************************************/
	/* house body                                                                     */
	/************************************************************************/
	_houseBody = new HouseBody();
	_houseBody->Initialize("house2body.mxy");//brickbump.jpg ColorTexture
	LoadTexture("brickbump.jpg",_houseBody->housebody_texture_id);
	_houseBody->shaderProgramID = LoadShaderFromFile("HouseBodyVertexShader.glsl","HouseBodyFragShader.glsl");
	glUseProgram(_houseBody->shaderProgramID);
	loc = glGetUniformLocation(_houseBody->shaderProgramID,"ColorTexture");
	if(loc!=-1)
		glUniform1i(loc,0);
	else
		cout<<"uniform error"<<endl;
	glUseProgram(0);
	//////////////////////////////////////////////////////////////////////////
	//roof
	_houseRoof = new HouseRoof();
	_houseRoof->Initialize("house2roof.mxy");
	_houseRoof->shaderProgramID = LoadShaderFromFile("HouseRoofVertexShader.glsl","HouseRoofFragShader.glsl");
	LoadTexture("roof.jpg",_houseRoof->roof_texture_id);
	glUseProgram(_houseRoof->shaderProgramID);
	loc = glGetUniformLocation(_houseRoof->shaderProgramID,"permTexture");
	if(loc>-1)
		glUniform1i(loc,1);
	else
		cout<<"uniform error"<<endl;
	loc = glGetUniformLocation(_houseRoof->shaderProgramID,"size");
	if(loc>-1)
		glUniform1f(loc,_houseRoof->snowVal);
	else
		cout<<"uniform error"<<endl;
	loc = glGetUniformLocation(_houseRoof->shaderProgramID,"ColorTexture");
	if(loc!=-1)
		glUniform1i(loc,0);
	else
		cout<<"uniform error"<<endl;
	glUseProgram(0);
	
	
	//////////////////////////////////////////////////////////////////////////
	_houseChemry = new HouseChemry();
	_houseChemry->Initialize("house2chemry.mxy");
	LoadTexture("brickbump.jpg",_houseChemry->housechemry_texture_id);
	_houseChemry->shaderProgramID = LoadShaderFromFile("HouseChemryVShader.glsl","HouseChemryFShader.glsl");
	glUseProgram(_houseChemry->shaderProgramID);
	loc = glGetUniformLocation(_houseChemry->shaderProgramID,"ColorTexture");
	if(loc!=-1)
		glUniform1i(loc,0);
	else
		cout<<"uniform error"<<endl;
	glUseProgram(0);
	/************************************************************************/
	/* tree                                                                     */
	/************************************************************************/
	_tree = new ChristmasTree();
	_tree->translatex = 0.6;
	_tree->translatey = 0.0;
	_tree->translatez = -0.2;
	_tree->scalex = 0.2;
	_tree->scaley = 0.2;
	_tree->scalez = 0.2;
	
	LoadTexture("trunk_slide_tex.tga",_tree->trunk_texture_id);
	LoadTexture("trunk_slide_nor.tga",_tree->trunk_texture_normal_id);
	LoadTexture("trunk_slide_hei.tga",_tree->trunk_texture_height_id);

	//trunk shader
	_tree->trunk_shader_programID = LoadShaderFromFile("TrunkVertexShader.glsl","TrunkFragShader.glsl");
	glUseProgram(_tree->trunk_shader_programID);
	loc = glGetUniformLocation(_tree->trunk_shader_programID,"ColorTexture");
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
	//_tree->leaf_shader_programID = LoadShaderFromFile("LeafVShader.glsl","LeafFShader.glsl");
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
	_ball = new Ball();
	_ball->Initialize();
	_ball->shaderProgramID = LoadShaderFromFile("BallVShader.glsl","BallFShader.glsl");
	
// 	_ball = new Ball();
// 	_ball->setEnableTransparency(true);
// 	_ball->setRenderTexture(false);
// 	_ball->setRenderMaterials(false);
// 	_ball->setColorApalha(0.1);
// 	modelController->AssemblyTransparencyPartSphere(_ball,1.0,40,40,modelController->_textures[0]);


}

void ChristmasWindow::InitialiseCamera(){
	_cameraPos[0] = 0;
	_cameraPos[1] = 0;
	_cameraPos[2] = 5;
	_cameraPos[3] = 1;

	//
	_cameraAngle = 30.0;
	_cameraPositionZ = 0.0;
	_cameraRotation = 0.0;
	_cameraHerical = 0.0;

	/**
	_cameraWorldPos[0] = 0;
	_cameraWorldPos[1] = 0;
	_cameraWorldPos[2] = 0;
	_cameraWorldPos[3] = 1;
	*/
}

void ChristmasWindow::InitialiseParicles(){
	_snowflake = new SnowParticleSys();
	_snowflake->height = 2.7;
	_snowflake->radius = 2.2;
	_snowflake->Initialize();
	LoadTexture("SnowFlake1.tga",_snowflake->snow_texture0_id);

	_snowflake->shaderProgramID = LoadShaderFromFile("SnowVertexShader.glsl","SnowFragShader.glsl");
	glUseProgram(_snowflake->shaderProgramID);
	int loc = glGetUniformLocation(_snowflake->shaderProgramID,"ColorTexture");
	if(loc>-1)
		glUniform1i(loc,0);
	else
		cout<<"uniform error"<<endl;
	glUseProgram(0);


	_fire = new FireParticles();
	_fire->Initialize();
	//fire_texture0_id fire.jpg
	LoadTexture("fire.jpg",_fire->textureID);
	_fire->shaderProgramID = LoadShaderFromFile("FireParticlesVertexShader.glsl","FireParticlesFragShader.glsl");
	glUseProgram(_fire->shaderProgramID);
	loc = glGetUniformLocation(_fire->shaderProgramID,"ColorTexture");
	if(loc>-1)
		glUniform1i(loc,0);
	else
		cout<<"uniform error"<<endl;
	glUseProgram(0);

	//////////////////////////////////////////////////////////////////////////
	_smoke = new SmokeParticles();
	_smoke->Initialize();
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
/**
void ChristmasWindow::LoadShaders(){
	
	//_tree_trunk_shader_programID = LoadShaderFromFile("phongvertexshader.glsl","phongfragmentshader.glsl");
	//_tree_leaf_shader_programID = LoadShaderFromFile("LeafVertexShader.glsl","LeafFragShader.glsl");



// 	_tree_trunk_shader_programID = LoadShaderFromFile("basic_vertex.glsl","basic_fragment.glsl");
// 	glUseProgram( _tree_trunk_shader_programID);
// 	glUniform1i( glGetUniformLocation( _tree_trunk_shader_programID, "normalTex"), 0);
// 	glUniform1i( glGetUniformLocation( _tree_trunk_shader_programID, "baseTex"), 1);
	
}
**
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
	
	gluLookAt(_cameraPos[0],_cameraPos[1],_cameraPos[2],0.0,0.0,0.0,0.0,1.0,0.0);
	
	glViewport(0,0, Width(), Height());
}
void ChristmasWindow::LoadBasicOpenGLParame(){
	glEnable(GL_DEPTH_TEST);
	
	//glEnable(GL_TEXTURE_2D);
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
/************************************************************************/
/* camera world position                                                                     */
/************************************************************************/
void ChristmasWindow::CalculateCameraWorldPosition(){

	camera_org[0] = -(mdl[0]*mdl[12] + mdl[1]*mdl[13] + mdl[2]*mdl[14]);
	camera_org[1] = -(mdl[4]*mdl[12] + mdl[5]*mdl[13] + mdl[6]*mdl[14]);
	camera_org[2] = -(mdl[8]*mdl[12] + mdl[9]*mdl[13] + mdl[10]*mdl[14]);
	camera_org[3] = 1.0f;
// 	float modelview[16];
// 	GLfloat _cameraPos[4];
// 	GLfloat _cameraWorldPos[4];
	/**
	_cameraWorldPos[0] = modelview[0] * _cameraPos[0] + 
							modelview[1] * _cameraPos[1] + 
							modelview[2] * _cameraPos[2] +
							modelview[3] * _cameraPos[3];

	_cameraWorldPos[1] = modelview[4] * _cameraPos[0] + 
		modelview[5] * _cameraPos[1] + 
		modelview[6] * _cameraPos[2] +
		modelview[7] * _cameraPos[3];

	_cameraWorldPos[2] = modelview[8] * _cameraPos[0] + 
		modelview[9] * _cameraPos[1] + 
		modelview[10] * _cameraPos[2] +
		modelview[11] * _cameraPos[3];
	_cameraWorldPos[3] = modelview[12] * _cameraPos[0] + 
		modelview[13] * _cameraPos[1] + 
		modelview[14] * _cameraPos[2] +
		modelview[15] * _cameraPos[3];

	_cameraWorldPos[0] = float(_cameraWorldPos[0]/_cameraWorldPos[3]);
	_cameraWorldPos[1] = float(_cameraWorldPos[1]/_cameraWorldPos[3]);
	_cameraWorldPos[2] = float(_cameraWorldPos[2]/_cameraWorldPos[3]);
	_cameraWorldPos[3] = float(_cameraWorldPos[3]/_cameraWorldPos[3]);
	*/



}

void ChristmasWindow::CreateFBO(){
	/************************************************************************/
	/* fbo                                                                     */
	/************************************************************************/
	glGenFramebuffers(1,&fboID);
	glBindFramebuffer(GL_FRAMEBUFFER,fboID);
	glGenTextures(1,&_textureID);
	glBindTexture(GL_TEXTURE_2D,_textureID);
	glTexImage2D(GL_TEXTURE_2D,
		0,
		GL_RGBA16F,
		512,512,
		0,
		GL_RGBA,
		GL_HALF_FLOAT,
		0);

	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER,
		GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MAG_FILTER,
		GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D,0);

	glFramebufferTexture2D(
		GL_FRAMEBUFFER,
		GL_COLOR_ATTACHMENT0,
		GL_TEXTURE_2D,
		_textureID,
		0);
	glGenRenderbuffers(1,&_depthID);
	glBindRenderbuffer(GL_RENDERBUFFER,_depthID);
	glRenderbufferStorage(
		GL_RENDERBUFFER,
		GL_DEPTH_COMPONENT24,
		512,512);
	glFramebufferRenderbuffer(
		GL_FRAMEBUFFER,
		GL_DEPTH_ATTACHMENT,
		GL_RENDERBUFFER,
		_depthID);
	glBindFramebuffer(GL_FRAMEBUFFER,0);

}

void ChristmasWindow::DisplayFBO(){
	glBindFramebuffer(GL_FRAMEBUFFER,fboID);
	glClear(GL_COLOR_BUFFER_BIT| (512? GL_DEPTH_BUFFER_BIT:0));


}