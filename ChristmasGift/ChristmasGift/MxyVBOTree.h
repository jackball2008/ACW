#pragma once

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "DisplayObjectModel.h"
#include "mxyVector.h"

typedef mxy::vec3<float> vec3f;

#define  PI float(3.1415926535897932384626433832795)

using std::vector;

class MxyVBOTree :
	public DisplayObjectModel
{

private:

	//generation parameters
	int _numSegments; //number of segments high the tree is (each segment has a trunk component and a set of branches
	float _height;	//height
	float _radius;  //radius
	int _branchSides; //number of sides on the trunk and branches
	int _branchesPerSegment; //number of branches in a segment
	int _globalIterationCount; //how many times a branch will branch, when it grows from the base of the tree
	float _branchIterationDecay; // rate per-segment that the branchiness decays

	/************************************************************************/
	/* count for calculate segment of trunk                                                                     */
	/************************************************************************/
	int _segment_count;

public:
	MxyVBOTree(void);
	~MxyVBOTree(void);

	/************************************************************************/
	/* variable                                                                     */
	/************************************************************************/
	
	

	/************************************************************************/
	/* main method                                                                     */
	/************************************************************************/
	void Initialize();

	void Update(const float& t);
	
	void Draw();

	/************************************************************************/
	/* store trunk and branch                                                                     */
	/************************************************************************/
	vector<DisplayObjectModel> _trunkVertexAll;
	
	
	
	DisplayObjectModel* allmodel;
	
	vector<vec3f> testar;
	GLuint _vboids;
	GLuint _indexVboId;
	int _numberOfVertices;
	int _numberOfIndices;
	/************************************************************************/
	/* store leaf                                                                     */
	/************************************************************************/
	
	

	/************************************************************************/
	/* build tree                                                                     */
	/************************************************************************/
	void buildTree();

	void buildTrunk();

	/************************************************************************/
	/* void build branch                                                                     */
	/************************************************************************/
	void buildBranch();


	/************************************************************************/
	/* test                                                                     */
	/************************************************************************/
	void test();

};

