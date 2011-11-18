#include "ChristmasTree.h"

#define TIMERCOUNT 0.4
#define NOGROWRADOM
#define NOGROWENDRADOM
#define ENDSYNCBETWEENTRUNKANDLEAF
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

ChristmasTree::ChristmasTree(void):FLUSHTRUNKVBOCOUNT(0),FLUSHLEAFVBOCOUNT(0),FLUSH_TRUNK_OR_LEAF_FLAG(false),_temp_timerrecord(0),_initialize_dec(0.1),_grow_increase_fator(0.01),VBO_BUILD_OR_FLUSH_FLAG(0)//,_clearvbodata(false) //:_numSegments(40),_height(16.0f),_radius(6.0),_branchSides(6),_branchesPerSegment(3),_branchGenerations(5),_branchGenerationDecayRate(1.0/7.0)
{
	_canRandom = false;
}


ChristmasTree::~ChristmasTree(void)
{

}

void ChristmasTree::Initialize(){	
	generateTreeSeed();
	Update(0);
}
void ChristmasTree::Draw(){
	drawTrunks();
	drawLeaf();
}

//update data for all this tree
void ChristmasTree::Update(const float& t){
	_temp_timerrecord = _temp_timerrecord + t;
	/************************************************************************/
	/* control the grow timer                                                                     */
	/************************************************************************/
	if(_temp_timerrecord >= TIMERCOUNT){
		_temp_timerrecord = 0;
		updateTreeGrowing();
	}
	if( GROWING ==  _TreeState){
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
	if(STOPGROWING == _TreeState){
		_trunkVertices.clear();
		_trunkIndices.clear();
		_leafVertices.clear();
		_leafIndices.clear();
#ifdef NOGROWENDRADOM
		_canRandom = false;
#else
		_canRandom = true;
#endif
		makeTreeGrowing();
		_TreeState = SYNCLIVE;
	}
	if(SYNCLIVE == _TreeState){
#ifdef ENDSYNCBETWEENTRUNKANDLEAF

#endif
		_currentSeason = Summer;		
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
	_TreeState = GROWING;
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
void ChristmasTree::updateTreeGrowing(){
	_height = _height+1;
	_num_of_Segments = _num_of_Segments + 1;
	_number_of_segment_no_branches = _number_of_segment_no_branches + 1;
	if(_number_of_segment_no_branches>= MAXNUMSEGMENTSNOBRANCHES) _number_of_segment_no_branches = MAXNUMSEGMENTSNOBRANCHES;
	if(_height >= MAXHEIGHT) _height = MAXHEIGHT;
	if(_num_of_Segments >= MAXSEGMENTS) _num_of_Segments = MAXSEGMENTS;

	if( _height == MAXHEIGHT && _num_of_Segments == MAXSEGMENTS && SYNCLIVE != _TreeState){
		_TreeState = STOPGROWING;
	}
}
/************************************************************************/
/*               generate data for each segments trunk                            */
/************************************************************************/
void ChristmasTree::generateVertexAndNormalizeForPerSegments(vec3f& top, vec3f& bottom, float& radius,float& _radius){
	GLuint baseIndex = (GLuint)_trunkVertices.size() / VERTEXSIZEPERINTRUNK;
	//generate each vertex position for every trunk segment
	//default value = 6
 
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
		//high pos
		_trunkVertices.push_back( highvertex.x);
		_trunkVertices.push_back( highvertex.y);
		_trunkVertices.push_back( highvertex.z);
		//nor
		_trunkVertices.push_back( currentSideDir.x);
		_trunkVertices.push_back( currentSideDir.y);
		_trunkVertices.push_back( currentSideDir.z);
	}
	//index
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

		// Compute random factors used to control how far out the next iteration
		float nextVal1 = 1.0f - powf( randfPosFrom0To1(), 4.0f);
		float nextVal2 = 1.0f - powf( randfPosFrom0To1(), 4.0f);
		float nextVal3 = 1.0f - powf( randfPosFrom0To1(), 4.0f);

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
			
			_trunkVertices.push_back( highvertex.x);
			_trunkVertices.push_back( highvertex.y);
			_trunkVertices.push_back( highvertex.z);

			_trunkVertices.push_back( dir.x);
			_trunkVertices.push_back( dir.y);
			_trunkVertices.push_back( dir.z);
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
		// Compute the 4 vertices of the frond geometry and store them, along with
		// normal, texcoord, and tangents
		vtx = root - pos_offset * scale;
		//vtx = vec3f(0,0,0);
		//pos
		for (int i = 0; i < 3; i++) _leafVertices.push_back( vtx[i]);
		//nor
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
		if(FLUSH_TRUNK_OR_LEAF_FLAG){
			glBufferData( GL_ARRAY_BUFFER, _leafVertices.size() * sizeof(float), NULL, GL_DYNAMIC_DRAW);
			glBindBuffer( GL_ARRAY_BUFFER, _leafVBO);
			glBufferData( GL_ARRAY_BUFFER, _leafVertices.size() * sizeof(float), &_leafVertices[0], GL_DYNAMIC_DRAW);
		}else{
			//trunk
			glBufferData( GL_ARRAY_BUFFER, _trunkVertices.size() * sizeof(float), NULL, GL_DYNAMIC_DRAW);
			glBindBuffer( GL_ARRAY_BUFFER, _trunkVBO);
			glBufferData( GL_ARRAY_BUFFER, _trunkVertices.size() * sizeof(float), &_trunkVertices[0], GL_DYNAMIC_DRAW);
		}
		FLUSH_TRUNK_OR_LEAF_FLAG = !FLUSH_TRUNK_OR_LEAF_FLAG;


	}
}
/************************************************************************/
/* draw trunk                                                                     */
/************************************************************************/
void ChristmasTree::drawTrunks(){
	float brown[] = { 0.5f, 0.5f, 0.0f, 1.0f};
	glColor3f( 0.5f, 0.5f, 0.0f);
	glBindBuffer( GL_ARRAY_BUFFER, _trunkVBO);

	glEnable(GL_LIGHTING);
	glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, brown);
	glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 32.0f);
	
	glVertexPointer( 3, GL_FLOAT, sizeof(float)*VERTEXSIZEPERINTRUNK, 0);
	glNormalPointer( GL_FLOAT, sizeof(float)*VERTEXSIZEPERINTRUNK, (float*)(0) + 3);
	
	glEnableClientState( GL_VERTEX_ARRAY);
	glEnableClientState( GL_NORMAL_ARRAY);

	glDrawElements( GL_TRIANGLES, (GLsizei)_trunkIndices.size(), GL_UNSIGNED_INT, &_trunkIndices[0]);


	glDisableClientState( GL_VERTEX_ARRAY);
	glDisableClientState( GL_NORMAL_ARRAY);

	glBindBuffer( GL_ARRAY_BUFFER, 0);

	glDisable(GL_LIGHTING);
}
/************************************************************************/
/* draw leaf                                                                     */
/************************************************************************/
void ChristmasTree::drawLeaf(){
	float green[] = { 0.0f, 0.7f, 0.0f, 1.0f};

	glEnable(GL_LIGHTING);
	glColor3f( 0.0f, 0.7f, 0.0f);
	glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, green);
	glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 32.0f);

	glBindBuffer( GL_ARRAY_BUFFER, _leafVBO);
	 
	
	glVertexPointer( 3, GL_FLOAT, sizeof(float)*VERTEXSIZEPERINLEAF, 0);
	glNormalPointer( GL_FLOAT, sizeof(float)*VERTEXSIZEPERINLEAF, (float*)(0) + 3);
	glTexCoordPointer( 2, GL_FLOAT, sizeof(float)*VERTEXSIZEPERINLEAF, (float*)(0) + 6);//pos nor uv*/

	glClientActiveTexture( GL_TEXTURE0);
	glEnableClientState(GL_TEXTURE0);

	glEnableClientState( GL_TEXTURE_COORD_ARRAY);
	glEnableClientState( GL_VERTEX_ARRAY);
	glEnableClientState( GL_NORMAL_ARRAY);

	glDrawElements( GL_TRIANGLES, (GLsizei)_leafIndices.size(), GL_UNSIGNED_INT, &_leafIndices[0]);

	glDisable(GL_LIGHTING);

	glDisableClientState( GL_VERTEX_ARRAY);
	glDisableClientState( GL_NORMAL_ARRAY);

	

	glClientActiveTexture( GL_TEXTURE0);
	glDisableClientState( GL_TEXTURE_COORD_ARRAY);

	glBindBuffer( GL_ARRAY_BUFFER, 0);
}