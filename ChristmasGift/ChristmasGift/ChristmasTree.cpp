#include "ChristmasTree.h"

#define TIMERCOUNT 0.4
#define NOGROWRADOM
#define NOGROWENDRADOM1
/*#define ENDSYNCBETWEENTRUNKANDLEAF*/
#define USESEGMENTGROWCHANGE

/************************************************************************/
/* static utils                                                                     */
/************************************************************************/
// Random floating [0-1]
static float randfPos1() {	return float(rand()) /float(RAND_MAX);}
// Random floating [-1 - 1]
static float randf1() {return randfPos1() * 2.0f - 1.0f;}
//  Random floating [-1 ,0 , 1]
static float rand2f1() {
	float val = randf1();
	return (val >0.0f) ? val*val : -(val*val);
}
/************************************************************************/
/* unstatic version, for good control, but no effeicient                                                                     */
/************************************************************************/
float ChristmasTree::randfPosFrom0To1() {
	if(_canRandom)
		return float(rand()) /float(RAND_MAX);
	else
		return 0.5;
}
//[-1 - 1]
float ChristmasTree::randfFromF1To1() {
	if(_canRandom)
		return randfPosFrom0To1() * 2.0f - 1.0f;
	else
		return 0;
}
//[-1 ,0, 1]
float ChristmasTree::rand2fFromF1To0To1() {
	if(_canRandom){
		float val = randfFromF1To1();
		return (val >0.0f) ? val*val : -(val*val);
	}
	else
		return 0;
}

ChristmasTree::ChristmasTree(void)
{
	_canRandom = false;
	showLeaf = false;
	growLeaf = false;
	leafSize = 0.05;

	_temp_timerrecord = 0;
	VBO_BUILD_OR_FLUSH_FLAG = 0;

	leafDwonFinished = false;
}

void ChristmasTree::reset(){
	_temp_timerrecord = 0;
	_grow_increase_fator = 0.01;
	VBO_BUILD_OR_FLUSH_FLAG = 0;

	setTreeParameter();
	showLeaf = false;
	leafDwonFinished = false;
	growLeaf = false;
	leafSize = 0.05;
	/************************************************************************/
	/* for leaf grow                                                                     */
	/************************************************************************/
	_leafRootStore.clear();
	_leaf_pos_offsetStore.clear();
// 	_leafScaleStore.clear();
// 	_leafPosStore.clear();
	_dirStore.clear();
	_sizeStore.clear();
	/************************************************************************/
	/* end                                                                  */
	/************************************************************************/
	/************************************************************************/
	/* leaf color                                                                     */
	/************************************************************************/
	leafColor = vec4f( 0.0f, 0.7f, 0.0f, 1.0f);
	leafColorBrownFinished = false;
	/************************************************************************/
	/* tree die                                                                     */
	/************************************************************************/
	isTreeDead = false;

	generateTreeSeed();
	Update(0);
}


ChristmasTree::~ChristmasTree(void)
{

}

void ChristmasTree::Initialize(){	
	reset();

}
void ChristmasTree::Draw(){
	




	drawTrunks();
	if(showLeaf)
		drawLeaf();
}

//update data for all this tree
void ChristmasTree::Update(const float& t){
	_temp_timerrecord = _temp_timerrecord + t;
	/************************************************************************/
	/* control the grow timer                                                                     */
	/************************************************************************/
	if(_temp_timerrecord >= TIMERCOUNT ){
		_temp_timerrecord = 0;
		if( GROWING ==  TreeState || STOPGROWING == TreeState)
			updateTreeGrowingData();
		if(TREEDOWNING == TreeState)
			treeDie();
	}



	if( GROWING ==  TreeState){
#ifdef NOGROWRADOM
		_canRandom = false;
#else
		_canRandom = true;
#endif
		_trunkVertices.clear();
		_trunkIndices.clear();
		_leafVertices.clear();
		_leafIndices.clear();
		makeTreeGrowing();
	}
	if(STOPGROWING == TreeState){
		_trunkVertices.clear();
		_trunkIndices.clear();
		_leafVertices.clear();
		_leafIndices.clear();
#ifdef NOGROWENDRADOM
		_canRandom = false;
#else
		_canRandom = true;
#endif
		//last grow
		growLeaf = true;
		makeTreeGrowing();

		TreeState = SYNCLIVE;
	}
	if(SYNCLIVE == TreeState){
		//small all leaf
		smallAllLeaf();
	}
	if(LEAFGROWING == TreeState){
		//update leaf

		//std::cout<<"ww"<<std::endl;
		showLeaf = true;
		/************************************************************************/
		/* do leaf growing operation                                                                     */
		/************************************************************************/
		leafSize = leafSize + 0.001;
		smallAllLeaf();

		if(leafSize>=1){
			TreeState = LEAFGROWEND;
		}
		
	}
	if(LEAFGROWEND == TreeState){
		//std::cout<<"ww"<<std::endl;
	}

	if(LEAFCOLORBROWN == TreeState){
		leafColorBrown();
		if(leafColorBrownFinished)
			TreeState = LEAFCOLORBROWNEND;
	}
	if(LEAFCOLORBROWNEND == TreeState){

		TreeState = LEAFDOWN;
	}

	if( LEAFDOWN == TreeState){
		
		leafDownMethod();

		if(leafDwonFinished)
		{
			TreeState = LEAFDOWNEND; 
			showLeaf = false;//great
		}
			
	}

	if( LEAFDOWNEND == TreeState){
		//std::cout<<"ww"<<std::endl;

		/*TreeState = TREEDOWNING;*/
	}

	if(FIREING == TreeState){


		//do fire change

		TreeState = FIREEND;
	}

	if(FIREEND == TreeState){

	}

	if( TREEDOWNING == TreeState){
		//std::cout<<"ww"<<std::endl;
		_canRandom = false;
		_trunkVertices.clear();
		_trunkIndices.clear();
		_leafVertices.clear();
		_leafIndices.clear();
		makeTreeGrowing();
		
	}

	if( TREEDOWNEND == TreeState){
		//std::cout<<"end"<<std::endl;
	}
	
	
}
/************************************************************************/
/* set initialize data                                                                     */
/************************************************************************/
void ChristmasTree::setTreeParameter(){
	setTrunkCutCount(8);
	setHeight(14);
	setRadius(6.0);
	setNumPerBranchSides(10); 
	setBranchesPerSegment(6);
	setBranchIterationCount(5);
	setBranchIterationDecay(1.0/7.0);
	setMinNoBranches(1);
	TreeState = GROWING;
}
/************************************************************************/
/*use paraments to generate a seed = small tree                                                                      */
/************************************************************************/
void ChristmasTree::generateTreeSeed(){
	_height = 2;
	_num_of_Segments = 2;
}

/************************************************************************/
/* grow                                                                     */
/************************************************************************/
void ChristmasTree::updateTreeGrowingData(){
	_height = _height+1;
	_num_of_Segments = _num_of_Segments + 1;
	_number_of_segment_no_branches = _number_of_segment_no_branches + 1;
	if(_number_of_segment_no_branches>= MAXNUMSEGMENTSNOBRANCHES) _number_of_segment_no_branches = MAXNUMSEGMENTSNOBRANCHES;
	if(_height >= MAXHEIGHT) _height = MAXHEIGHT;
	if(_num_of_Segments >= MAXSEGMENTS) _num_of_Segments = MAXSEGMENTS;

	if( _height == MAXHEIGHT && _num_of_Segments == MAXSEGMENTS && SYNCLIVE != TreeState){
		TreeState = STOPGROWING;
	}
}
void ChristmasTree::treeDie(){

// 	_height = 2;
// 	_num_of_Segments = 2;
	//_number_of_segment_no_branches =1
	_height = _height-1;
	_num_of_Segments = _num_of_Segments - 1;
	if(_num_of_Segments <= _number_of_segment_no_branches)
		_number_of_segment_no_branches = _num_of_Segments - 1;
	//if(_number_of_segment_no_branches<= 1) _number_of_segment_no_branches = 1;
	if(_height <= 2) _height = 2;
	if(_num_of_Segments <= 2) _num_of_Segments = 2;

	if( _height == 2 && _num_of_Segments == 2 && _number_of_segment_no_branches == 1 && TREEDOWNEND != TreeState){
		TreeState = TREEDOWNEND;
	}
}
/************************************************************************/
/*               generate data for each segments trunk                            */
/************************************************************************/
void ChristmasTree::generateVertexAndNormalizeForPerSegments(vec3f& top, vec3f& bottom, float& radius,float& _radius){
	GLuint baseIndex = (GLuint)_trunkVertices.size() / VERTEXSIZEPERINTRUNK;
	//generate each vertex position for every trunk segment
	//default value = 6

	int textureIndex = 0;
 
	for ( int jj = 0; jj < _branchSides; jj++){
		float x = sinf( float(jj)/float(_branchSides) * 2.0f * 3.1415927f);
		float z = cosf( float(jj)/float(_branchSides) * 2.0f * 3.1415927f);

		//here control up angle
		vec3f currentSideDir( x, 0.0f, z);

		vec3f highvertex = top + currentSideDir * radius * 0.05f;
		vec3f lowvertex = bottom + currentSideDir * radius * 0.05f;

		//store line
		//low pos
		_trunkVertices.push_back( lowvertex.x);
		_trunkVertices.push_back( lowvertex.y);
		_trunkVertices.push_back( lowvertex.z);
		//nor
		_trunkVertices.push_back( currentSideDir.x);
		_trunkVertices.push_back( currentSideDir.y);
		_trunkVertices.push_back( currentSideDir.z);
		//tex
#ifdef SHOWTRUNKTEXTURE

		if(textureIndex<2)
		{
			_trunkVertices.push_back(0.0);
			_trunkVertices.push_back(0.0);
		}else{
			_trunkVertices.push_back(1.0);
			_trunkVertices.push_back(1.0);
		}
		textureIndex++;
#endif
		//high pos
		_trunkVertices.push_back( highvertex.x);
		_trunkVertices.push_back( highvertex.y);
		_trunkVertices.push_back( highvertex.z);
		//nor
		_trunkVertices.push_back( currentSideDir.x);
		_trunkVertices.push_back( currentSideDir.y);
		_trunkVertices.push_back( currentSideDir.z);
#ifdef SHOWTRUNKTEXTURE
		if(textureIndex<2)
		{
			_trunkVertices.push_back(1.0);
			_trunkVertices.push_back(0.0);
		}else{
			_trunkVertices.push_back(0.0);
			_trunkVertices.push_back(1.0);
		}
		textureIndex++;
		if(textureIndex>3){
			textureIndex = 0;
		}
#endif
	}
	//index
	int k = _trunkVertices.size();
	for (int jj = 0; jj < _branchSides; jj++) {
		_trunkIndices.push_back( baseIndex + jj * 2);
		_trunkIndices.push_back( baseIndex + jj * 2 + 1);
		_trunkIndices.push_back( baseIndex + (jj * 2 + 2) % (_branchSides * 2));
		_trunkIndices.push_back( baseIndex + (jj * 2 + 2) % (_branchSides * 2));
		_trunkIndices.push_back( baseIndex + jj * 2 + 1);
		_trunkIndices.push_back( baseIndex + (jj * 2 + 3) % (_branchSides * 2));

	}
}
/************************************************************************/
/* real calculate data after get data                                                                     */
/************************************************************************/
void ChristmasTree::makeTreeGrowing(){
	vec3f segmentBottomCenterPos;
	float radius = _radius;
	
	/************************************************************************/
	/* logic
	 * per segment include its branches
	 * each branch iterate branch until finish
	 * first generate the trunk without branches
	 * second generate the trunk with branches
	/************************************************************************/
	for(int i = 0; i<_number_of_segment_no_branches;i++){
		float h = _height / float(_num_of_Segments);
#ifndef USESEGMENTGROWCHANGE

		vec3f segmentTopCenterPos = segmentBottomCenterPos + vec3f( 0.0f, h, 0.0f);
#else
		vec3f segmentTopCenterPos = segmentBottomCenterPos + vec3f( 0.0f, _height / float(_num_of_Segments), 0.0f);
#endif
		generateVertexAndNormalizeForPerSegments(segmentTopCenterPos,segmentBottomCenterPos,radius,_radius);
		// update values for the next iteration
		segmentBottomCenterPos = segmentTopCenterPos;
		radius -= _radius/float(_num_of_Segments - 1);
	}

	for (int ii = _number_of_segment_no_branches; ii < _num_of_Segments; ii++) {
		//calculate the center pos
		float h = _height / float(_num_of_Segments);
		/************************************************************************/
		/* now have top and bottom  
		 * (0,0,0) (0,h,0)
		/************************************************************************/
#ifndef USESEGMENTGROWCHANGE
		vec3f segmentTopCenterPos = segmentBottomCenterPos + vec3f( 0.0f, h, 0.0f);
#else
		vec3f segmentTopCenterPos = segmentBottomCenterPos + vec3f( 0.0f, _height / float(_num_of_Segments), 0.0f);
#endif
		generateVertexAndNormalizeForPerSegments(segmentTopCenterPos,segmentBottomCenterPos,radius,_radius);

		//create the individual branches
		for ( int jj = 0; jj < _branchesPerSegment; jj++){
			float x = sinf( float(jj)/float(_branchesPerSegment) * XZ_WAVEINBRANCHGENERATION);
			float z = cosf( float(jj)/float(_branchesPerSegment) * XZ_WAVEINBRANCHGENERATION);
			// direction of growth
			vec3f dir( x,BRANCHANGLE, z);
			vec3f dirchangevextor( rand2fFromF1To0To1(), randfPosFrom0To1() + 0.25f * (ii/float(_num_of_Segments - 1)), rand2fFromF1To0To1());
			float val = randfPosFrom0To1();
			vec3f segmentchangevextor( 0.0f, val*val, 0.0f);
			//grow the fractal branch
			//dir, root, radius, iterationcount
			makeLeafGrowing( dir + dirchangevextor * 0.1f, segmentBottomCenterPos + segmentchangevextor, radius/2.25f, int(_globalIterationCount - ii * _branchIterationDecay + 0.5f));
		}

		// update values for the next iteration
		segmentBottomCenterPos = segmentTopCenterPos;
		radius -= _radius/float(_num_of_Segments - 1);
	}
	/************************************************************************/
	/* store or flush vbo data                                                                     */
	/************************************************************************/
	buildAndFlushVBO();
}


void ChristmasTree::makeLeafGrowing(vec3f dir, vec3f root, float size, int iterationcount){
	vec3f up( 0.0f, 1.0f, 0.0f);
	//cross a¡Áb=(aybz-azby)i+(azbx-axbz)j+(axby-aybx)k
	// x y z / squrt(x*x+y*y+z*z) = unit 
	// out used for out unit
	vec3f out = mxy::normalize(cross( dir, up));
	//up unit dir
	up = normalize( cross( out, dir));
	//born pos
	vec3f pos = root + dir * size;

	if (iterationcount > 0){
		//save the current position in the vertex list
		GLuint baseIdx = (GLuint)_trunkVertices.size() / VERTEXSIZEPERINTRUNK;

		int textureIndex = 0;

		// create the vertices for this segment of the branch
		for (int ii = 0; ii < _branchSides; ii++){
			float x = sinf( float(ii)/float(_branchSides) * 2.0f * 3.1415927f); 
			float y = cosf( float(ii)/float(_branchSides) * 2.0f * 3.1415927f);

			vec3f dir = normalize( x * out + y * up);
			vec3f lowvertex = root + dir * size * 0.035f;
			vec3f highvertex = pos + dir * size * 0.015f;// root + dir * size

			//vertex position
			_trunkVertices.push_back( lowvertex.x);
			_trunkVertices.push_back( lowvertex.y);
			_trunkVertices.push_back( lowvertex.z);
			//vertex normalize
			_trunkVertices.push_back( dir.x);
			_trunkVertices.push_back( dir.y);
			_trunkVertices.push_back( dir.z);

#ifdef SHOWTRUNKTEXTURE

			if(textureIndex<2)
			{
				_trunkVertices.push_back(0.0);
				_trunkVertices.push_back(0.0);
			}else{
				_trunkVertices.push_back(1.0);
				_trunkVertices.push_back(1.0);
			}
			textureIndex++;
#endif
			
			_trunkVertices.push_back( highvertex.x);
			_trunkVertices.push_back( highvertex.y);
			_trunkVertices.push_back( highvertex.z);

			_trunkVertices.push_back( dir.x);
			_trunkVertices.push_back( dir.y);
			_trunkVertices.push_back( dir.z);

#ifdef SHOWTRUNKTEXTURE
			if(textureIndex<2)
			{
				_trunkVertices.push_back(1.0);
				_trunkVertices.push_back(0.0);
			}else{
				_trunkVertices.push_back(0.0);
				_trunkVertices.push_back(1.0);
			}
			textureIndex++;
			if(textureIndex>3){
				textureIndex = 0;
			}
#endif
		}


		// add the indices for this portion of the branch
		for (int i = 0; i < _branchSides; i++) {
			_trunkIndices.push_back( baseIdx + i * 2);
			_trunkIndices.push_back( baseIdx + i * 2 + 1);
			_trunkIndices.push_back( baseIdx + (i * 2 + 2) % (_branchSides * 2));
			_trunkIndices.push_back( baseIdx + (i * 2 + 2) % (_branchSides * 2));
			_trunkIndices.push_back( baseIdx + i * 2 + 1);
			_trunkIndices.push_back( baseIdx + (i * 2 + 3) % (_branchSides * 2));
		}

		float dirFactor = 1.0f;

		//this makes the fronds stick up a bit more
		if (iterationcount == 1)
			dirFactor = 0.7f;
		// Compute random factors used to control how far out the next iteration
		float nextVal1 = 1.0f - powf( randfPosFrom0To1(), 4.0f);
		float nextVal2 = 1.0f - powf( randfPosFrom0To1(), 4.0f);
		float nextVal3 = 1.0f - powf( randfPosFrom0To1(), 4.0f);
		// continue to grow the branch
		//left
		makeLeafGrowing( mxy::normalize( dir * dirFactor + 0.9f*out + 0.30f *up),  pos, size * 0.5f * nextVal1, iterationcount-1);
		//right
		makeLeafGrowing( mxy::normalize( dir * dirFactor + -0.9f*out + 0.22f *up), pos, size * 0.5f * nextVal2, iterationcount-1);
		//up if I like , I can generate more
		//makeLeafGrowing( mxy::normalize( dir * dirFactor + 0.2f *up),pos, size * 0.6f * outVal3, iterationcount-1);

	}
	else{
		
		// save the current vertex position
		GLuint leafIndex = (GLuint)_leafVertices.size() / VERTEXSIZEPERINLEAF;
		// scale up the size for the leaf
		size *= LEAFSCALEFACTOR;
		// give it a range
		if ( size > 1.75f)
			size = 1.75f;
		if ( size < 0.5f)
			size = 0.5f;

		//root = vec3f(0,0,0);

		pos = root + dir * size; // scale by length
		float scale =  size * 0.5f; // width scale is 1/2 length scale, because it is +/-

		// compute vectors needed to generate vertex and normalize
		vec3f pos_offset = normalize( out * randf1() + up * randf1() * 0.5f);
		vec3f nor = normalize( cross( dir, pos_offset));
		vec3f vtx;

		if(growLeaf){
			_leafRootStore.push_back(root);
			_leaf_pos_offsetStore.push_back(pos_offset);
// 			_leafScaleStore.push_back(scale);
// 			_leafPosStore.push_back(pos);
			_dirStore.push_back(dir);
			_sizeStore.push_back(size);
		}

		// Compute the 4 vertices of the frond geometry and store them, along with
		// normal, texcoord, and tangents
		vtx = root - pos_offset * scale;
		//vtx = vec3f(0,0,0);
		//pos
		for (int ii = 0; ii < 3; ii++) _leafVertices.push_back( vtx[ii]);
		for (int ii = 0; ii < 3; ii++) _leafVertices.push_back( nor[ii]);
		//texture
		_leafVertices.push_back( 0.0f);
		_leafVertices.push_back( 0.0f);


		vtx = root + pos_offset * scale;
		for (int ii = 0; ii < 3; ii++) _leafVertices.push_back( vtx[ii]);
		for (int ii = 0; ii < 3; ii++) _leafVertices.push_back( nor[ii]);
		_leafVertices.push_back( 1.0f);
		_leafVertices.push_back( 0.0f);

		vtx = pos + pos_offset * scale;
		//vtx = vec3f(1,1,0);
		for (int ii = 0; ii < 3; ii++) _leafVertices.push_back( vtx[ii]);
		for (int ii = 0; ii < 3; ii++) _leafVertices.push_back( nor[ii]);
		_leafVertices.push_back( 1.0f);
		_leafVertices.push_back( 1.0f);

		vtx = pos - pos_offset * scale;
		//vtx = vec3f(0,1,0);
		for (int ii = 0; ii < 3; ii++) _leafVertices.push_back( vtx[ii]);
		for (int ii = 0; ii < 3; ii++) _leafVertices.push_back( nor[ii]);
		_leafVertices.push_back( 0.0f);
		_leafVertices.push_back( 1.0f);

		// add the indices for this frond to the index list
		_leafIndices.push_back( leafIndex + 0);
		_leafIndices.push_back( leafIndex + 1);
		_leafIndices.push_back( leafIndex + 2);
		_leafIndices.push_back( leafIndex + 0);
		_leafIndices.push_back( leafIndex + 2);
		_leafIndices.push_back( leafIndex + 3);


		
	}
}


void ChristmasTree::buildAndFlushVBO(){
	if(VBO_BUILD_OR_FLUSH_FLAG == 0){
		VBO_BUILD_OR_FLUSH_FLAG++;
		//leaf vbo
		glGenBuffers( 1, &_leafVBO);
		glBindBuffer( GL_ARRAY_BUFFER, _leafVBO);
		glBufferData( GL_ARRAY_BUFFER, _leafVertices.size() * sizeof(float), &_leafVertices[0], GL_DYNAMIC_DRAW);

		//trunk vbo
		glGenBuffers( 1, &_trunkVBO);
		glBindBuffer( GL_ARRAY_BUFFER, _trunkVBO);
		glBufferData( GL_ARRAY_BUFFER, _trunkVertices.size() * sizeof(float), &_trunkVertices[0], GL_DYNAMIC_DRAW);

	}else{	
		//leaf
		//if(growLeaf)
		flushLeafVBO();
		//trunk
		flushTrunkVBO();
	}
}
/************************************************************************/
/* draw trunk                                                                     */
/************************************************************************/
void ChristmasTree::drawTrunks(){
	glUseProgram(trunk_shader_programID);
// 	float brown[] = { 0.5f, 0.5f, 0.0f, 1.0f};
// 	glColor3f( 0.5f, 0.5f, 0.0f);
	glEnable(GL_LIGHTING);
	/************************************************************************/
	/* texture                                                                     */
	/************************************************************************/
	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D); 
	glBindTexture(GL_TEXTURE_2D, trunk_texture_id); 
	/************************************************************************/
	/* normal                                                                     */
	/************************************************************************/
	glActiveTexture(GL_TEXTURE1);
	glEnable(GL_TEXTURE_2D); 
	glBindTexture(GL_TEXTURE_2D, trunk_texture_normal_id); 
	/************************************************************************/
	/* height                                                                     */
	/************************************************************************/
	glActiveTexture(GL_TEXTURE2);
	glEnable(GL_TEXTURE_2D); 
	glBindTexture(GL_TEXTURE_2D, trunk_texture_height_id); 

	//bind vbo
	glBindBuffer( GL_ARRAY_BUFFER, _trunkVBO);

	//set texture coordinate
	//texture
	glClientActiveTexture(GL_TEXTURE0);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer( 2, GL_FLOAT, sizeof(float)*VERTEXSIZEPERINLEAF, (float*)(0) + 6);
	//normal
	glClientActiveTexture(GL_TEXTURE1);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer( 2, GL_FLOAT, sizeof(float)*VERTEXSIZEPERINLEAF, (float*)(0) + 6);
	//height
	glClientActiveTexture(GL_TEXTURE2);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer( 2, GL_FLOAT, sizeof(float)*VERTEXSIZEPERINLEAF, (float*)(0) + 6);

	glVertexPointer( 3, GL_FLOAT, sizeof(float)*VERTEXSIZEPERINTRUNK, 0);
	glNormalPointer( GL_FLOAT, sizeof(float)*VERTEXSIZEPERINTRUNK, (float*)(0) + 3);
	
	
	glEnableClientState( GL_VERTEX_ARRAY);
	glEnableClientState( GL_NORMAL_ARRAY);
	

	glDrawElements( GL_TRIANGLES, (GLsizei)_trunkIndices.size(), GL_UNSIGNED_INT, &_trunkIndices[0]);
	//GL_LINE_LOOP
	//GL_LINE_STRIP
	//GL_TRIANGLES
	glDisable(GL_LIGHTING);

	glClientActiveTexture(GL_TEXTURE0);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glClientActiveTexture(GL_TEXTURE1);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glClientActiveTexture(GL_TEXTURE2);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);


	glActiveTexture(GL_TEXTURE0);
	glDisable(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE1);
	glDisable(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE2);
	glDisable(GL_TEXTURE_2D);

	glDisableClientState( GL_VERTEX_ARRAY);
	glDisableClientState( GL_NORMAL_ARRAY);


	glBindBuffer( GL_ARRAY_BUFFER, 0);

	glUseProgram(0);
}
/************************************************************************/
/* draw leaf                                                                     */
/************************************************************************/
void ChristmasTree::drawLeaf(){
	float green[] = { leafColor.x, leafColor.y, leafColor.z, leafColor.w};

// 	float modelview[16];
// 	glGetFloatv(GL_MODELVIEW, modelview);
// 	glGetFloatv(GL_NORMAL_ARRAY,modelview);

	glEnable(GL_LIGHTING);
	glUseProgram(leaf_shader_programID);
	




	glColor3f(leafColor.x, leafColor.y, leafColor.z);
	glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, green);
	glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 32.0f);


	glActiveTexture(GL_TEXTURE0);
	glEnable(GL_TEXTURE_2D); 
	glBindTexture(GL_TEXTURE_2D, leaf_texture_id); 
	
	glActiveTexture(GL_TEXTURE1);
	glEnable(GL_TEXTURE_2D); 
	glBindTexture(GL_TEXTURE_2D, leaf_nor_texture_id); 
	

 	glBindBuffer( GL_ARRAY_BUFFER, _leafVBO);

	glClientActiveTexture(GL_TEXTURE0);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer( 2, GL_FLOAT, sizeof(float)*VERTEXSIZEPERINLEAF, (float*)(0) + 6);

	glClientActiveTexture(GL_TEXTURE1);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glTexCoordPointer( 2, GL_FLOAT, sizeof(float)*VERTEXSIZEPERINLEAF, (float*)(0) + 6);

	glVertexPointer( 3, GL_FLOAT, sizeof(float)*VERTEXSIZEPERINLEAF, 0);
	glNormalPointer( GL_FLOAT, sizeof(float)*VERTEXSIZEPERINLEAF, (float*)(0) + 3);
	//glTexCoordPointer( 2, GL_FLOAT, sizeof(float)*VERTEXSIZEPERINLEAF, (float*)(0) + 6);//pos nor uv*/

	
	//glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState( GL_VERTEX_ARRAY);
	glEnableClientState( GL_NORMAL_ARRAY);


	glDrawElements( GL_TRIANGLES, (GLsizei)_leafIndices.size(), GL_UNSIGNED_INT, &_leafIndices[0]);

	glDisable(GL_LIGHTING);

	glClientActiveTexture(GL_TEXTURE0);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glClientActiveTexture(GL_TEXTURE1);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	glActiveTexture(GL_TEXTURE0);
	glDisable(GL_TEXTURE_2D);
	glActiveTexture(GL_TEXTURE1);
	glDisable(GL_TEXTURE_2D);


	glDisableClientState( GL_VERTEX_ARRAY);
	glDisableClientState( GL_NORMAL_ARRAY);
	//glDisable(GL_TEXTURE_2D);
 	glBindBuffer( GL_ARRAY_BUFFER, 0);
	glUseProgram(0);
}

void ChristmasTree::flushTrunkVBO(){
	glBindBuffer( GL_ARRAY_BUFFER, _trunkVBO);
	glBufferData( GL_ARRAY_BUFFER, _trunkVertices.size() * sizeof(float), NULL, GL_DYNAMIC_DRAW);
	glBufferData( GL_ARRAY_BUFFER, _trunkVertices.size() * sizeof(float), &_trunkVertices[0], GL_DYNAMIC_DRAW);
}
void ChristmasTree::flushLeafVBO(){
	glBindBuffer( GL_ARRAY_BUFFER, _leafVBO);
	glBufferData( GL_ARRAY_BUFFER, _leafVertices.size() * sizeof(float), NULL, GL_DYNAMIC_DRAW);
	glBufferData( GL_ARRAY_BUFFER, _leafVertices.size() * sizeof(float), &_leafVertices[0], GL_DYNAMIC_DRAW);
}
void ChristmasTree::smallAllLeaf(){

	for(int i=0;i<_leafRootStore.size();i++){
		vec3f pos = _leafRootStore[i] + _dirStore[i] * _sizeStore[i] * leafSize;
		float scale =  _sizeStore[i] * 0.5f * leafSize;
		vec3f vtx;
		

		vec3f nor = normalize( cross( _dirStore[i], _leaf_pos_offsetStore[i]));

		vtx = _leafRootStore[i] - _leaf_pos_offsetStore[i]* scale;
		for (int ii = 0; ii < 3; ii++) _temp_leafVertices.push_back( vtx[ii]);
		for (int ii = 0; ii < 3; ii++) _temp_leafVertices.push_back( nor[ii]);
		_temp_leafVertices.push_back( 0.0f);
		_temp_leafVertices.push_back( 0.0f);


		vtx = _leafRootStore[i] + _leaf_pos_offsetStore[i]* scale;
		for (int ii = 0; ii < 3; ii++) _temp_leafVertices.push_back( vtx[ii]);
		for (int ii = 0; ii < 3; ii++) _temp_leafVertices.push_back( nor[ii]);
		_temp_leafVertices.push_back( 1.0f);
		_temp_leafVertices.push_back( 0.0f);

		vtx = pos  + _leaf_pos_offsetStore[i] * scale;
		for (int ii = 0; ii < 3; ii++) _temp_leafVertices.push_back( vtx[ii]);
		for (int ii = 0; ii < 3; ii++) _temp_leafVertices.push_back( nor[ii]);
		_temp_leafVertices.push_back( 1.0f);
		_temp_leafVertices.push_back( 1.0f);

		vtx = pos  - _leaf_pos_offsetStore[i] * scale;
		for (int ii = 0; ii < 3; ii++) _temp_leafVertices.push_back( vtx[ii]);
		for (int ii = 0; ii < 3; ii++) _temp_leafVertices.push_back( nor[ii]);
		_temp_leafVertices.push_back( 0.0f);
		_temp_leafVertices.push_back( 1.0f);

		
	}
	
	for(int i=0;i<_leafVertices.size();i++){
		_leafVertices[i] = _temp_leafVertices[i];
	}
	

	_temp_leafVertices.clear();
	flushLeafVBO();
}

void ChristmasTree::leafDownMethod(){
	for(int i=0;i<_leafVertices.size();i++){
		//p1
		i++;
		float y = _leafVertices[i];
		float k = randf1();
		if(y>0){
			if(k>0)
			_leafVertices[i] = y-0.01;
		}
		i=i+6;
	}

	flushLeafVBO();

	leafDwonFinished =  true;

	for(int i=0;i<_leafVertices.size();i++){
		i++;
		float y = _leafVertices[i];
		if(y>0)
			leafDwonFinished = false;
		i=i+6;
	}

}

void ChristmasTree::leafColorBrown(){
	if(leafColor.x <= 0.5)
		leafColor.x = leafColor.x + 0.0001;
	if(leafColor.y >= 0.5)
		leafColor.y = leafColor.y - 0.00005;

	if(leafColor.x >= 0.5 && leafColor.y<=0.5)
		leafColorBrownFinished = true;
}