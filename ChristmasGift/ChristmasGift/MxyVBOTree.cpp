#include "MxyVBOTree.h"


//static utils
//[0-1]
static float randPos(){
	return float(rand())/float(RAND_MAX);
}
//[-1,1]
static float randf(){
	return randPos() * 2.0f - 1.0f;
}
//[-1,0,1]
static float rand2f(){
	float val = randf();
	return (val > 0.0f) ? val*val: -(val*val);
}

MxyVBOTree::MxyVBOTree(void):_numSegments(40),_height(16.0f),_radius(6.0),_branchSides(6),_branchesPerSegment(3),_globalIterationCount(5),_branchIterationDecay(1.0/7.0),_segment_count(0)
{
	

}


MxyVBOTree::~MxyVBOTree(void)
{

}

void MxyVBOTree::Initialize(){
	
}

void MxyVBOTree::Update(const float& t){

}

void MxyVBOTree::Draw()
{
	/*allmodel->Draw();*/
	glBindBuffer(GL_ARRAY_BUFFER, _vboids);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexVboId);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
	/*glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));*/
	glNormalPointer(GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(20));
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(32));

	glDrawElements(GL_TRIANGLES, _numberOfIndices, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}
/************************************************************************/
/* build tree                                                                     */
/************************************************************************/
void MxyVBOTree::buildTree(){

}


void MxyVBOTree::buildTrunk(){
	
	vec3f segmentBottomCenterPos;
	Vertex (*_vertices);
	GLuint *_indices;
	float radius = _radius;
	float h = _height / float(_numSegments);
	vec3f segmentTopCenterPos = segmentBottomCenterPos + vec3f( 0.0f, h, 0.0f);
	GLuint baseIndex =0;

	_vertices = new Vertex[_branchSides * 2];
	/*std::cout<<"set"<<_branchSides * 2<<std::endl;*/

	for ( int i = 0; i < _branchSides; i++){
		float x = sinf( float(i)/float(_branchSides) * 2.0f * 3.1415927f);
		float z = cosf( float(i)/float(_branchSides) * 2.0f * 3.1415927f);

		vec3f currentSideDir( x, 0.0f, z);
		vec3f highvertex = segmentTopCenterPos + currentSideDir * (radius - _radius/float(_numSegments - 2)) * 0.05f;
		vec3f lowvertex = segmentBottomCenterPos + currentSideDir * radius * 0.05f;

		testar.push_back(highvertex);
		testar.push_back(lowvertex);

		//low
		_vertices[i].position[X_POS] = lowvertex.x;
		_vertices[i].position[Y_POS] = lowvertex.y;
		_vertices[i].position[Z_POS] = lowvertex.z;

		_vertices[i].normal[X_POS] = currentSideDir.x;
		_vertices[i].normal[Y_POS] = currentSideDir.y;
		_vertices[i].normal[Z_POS] = currentSideDir.z;

		_vertices[i].colour[R_POS] = 0.5;
		_vertices[i].colour[G_POS] = 0.0;
		_vertices[i].colour[B_POS] = 0.5;
		_vertices[i].colour[A_POS] = 1.0;

		_vertices[i].texture[U_POS] = 0.0;
		_vertices[i].texture[V_POS] = 0.0;

		//high
		_vertices[i+1].position[X_POS] = highvertex.x;
		_vertices[i+1].position[Y_POS] = highvertex.y;
		_vertices[i+1].position[Z_POS] = highvertex.z;

		_vertices[i+1].normal[X_POS] = currentSideDir.x;
		_vertices[i+1].normal[Y_POS] = currentSideDir.y;
		_vertices[i+1].normal[Z_POS] = currentSideDir.z;

		_vertices[i+1].colour[R_POS] = 0.5;
		_vertices[i+1].colour[G_POS] = 0.0;
		_vertices[i+1].colour[B_POS] = 0.5;
		_vertices[i+1].colour[A_POS] = 1.0;

		_vertices[i+1].texture[U_POS] = 0.0;
		_vertices[i+1].texture[V_POS] = 0.0;


	}

	/*std::cout<<testar.size()<<std::endl;*/
	_indices = new GLuint[_branchSides * 6]; 
	/*vector<GLuint> _trunkIndices;*/
	//generate index
	for (int jj = 0; jj < _branchSides; jj++) {
		_indices[jj] = ( baseIndex + jj * 2);
		_indices[jj+1] = ( baseIndex + jj * 2 + 1);
		_indices[jj+2] = ( baseIndex + (jj * 2 + 2) % (_branchSides * 2));
		_indices[jj+3] = ( baseIndex + (jj * 2 + 2) % (_branchSides * 2));
		_indices[jj+4] = ( baseIndex + jj * 2 + 1);
		_indices[jj+5] = ( baseIndex + (jj * 2 + 3) % (_branchSides * 2));
		
	}
 	
	_numberOfVertices = _branchSides * 2;
	_numberOfIndices =  _branchSides * 6;

	glGenBuffers(1, &_vboids);
	glBindBuffer(GL_ARRAY_BUFFER_ARB, _vboids);

	glBufferData(GL_ARRAY_BUFFER_ARB, sizeof(Vertex)*_numberOfVertices, 0, GL_STATIC_DRAW_ARB);
	glBufferSubData(GL_ARRAY_BUFFER_ARB, 0, sizeof(Vertex)*_numberOfVertices, _vertices);

	glGenBuffers(1, &_indexVboId); // Generate buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexVboId); 
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _numberOfIndices * sizeof(GLuint), _indices, GL_STATIC_DRAW);
	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, sizeof(GLuint)*_numberOfIndices, _indices);

	glBindBufferARB(GL_ARRAY_BUFFER_ARB, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

/************************************************************************/
/* void build branch                                                                     */
/************************************************************************/
void MxyVBOTree::buildBranch(){

}
/************************************************************************/
/* test                                                                     */
/************************************************************************/

void MxyVBOTree::test(){

}