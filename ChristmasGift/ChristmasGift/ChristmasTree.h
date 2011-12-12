#pragma once
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include "DisplayObjectModel.h"
#include "mxyVector.h"
typedef mxy::vec3<float> vec3f;
typedef mxy::vec4<float> vec4f;

/*#define  PI float(3.1415926535897932384626433832795)*/

using std::vector;

enum treestatus {START,GROWING,STOPGROWING,SYNCLIVE,LEAFGROWING,LEAFGROWEND,LEAFCOLORBROWN,LEAFCOLORBROWNEND,LEAFDOWN,LEAFDOWNEND,FIREING,FIREEND,TREEDOWNING,TREEDOWNEND};

#define SHOWTRUNKTEXTURE
#ifdef SHOWTRUNKTEXTURE
#define VERTEXSIZEPERINTRUNK 8
#else
#define VERTEXSIZEPERINTRUNK 6
#endif

#define VERTEXSIZEPERINLEAF	8

#define MAXHEIGHT 16
#define MAXSEGMENTS 16
#define MAXNUMSEGMENTSNOBRANCHES 5
#define XZ_WAVEINBRANCHGENERATION 2.0f * 3.1415927f + randfFromF1To1()
#define BRANCHANGLE 0.6f
#define LEAFSCALEFACTOR 6.0f

class ChristmasTree :
	public DisplayObjectModel
{

private:
	/************************************************************************/
	/* store all trunk data in one vbo, the problem is that we should update all data duting the whole process                                                                     */
	/************************************************************************/
	vector<float>	_trunkVertices;
	vector<GLuint>	_trunkIndices;
	GLuint			_trunkVBO;
	/************************************************************************/
	/* the same as trunk, same questions                                                                     */
	/************************************************************************/
	vector<float>	_leafVertices;
	vector<GLuint>	_leafIndices;
	GLuint _leafVBO;
	//leaf grow
	vector<vec3f>	_leafRootStore;
	vector<vec3f>	_dirStore;
	vector<float>	_sizeStore;
	vector<vec3f>	_leaf_pos_offsetStore;

 	vector<float>	_temp_leafVertices;
	
	
	//
	/************************************************************************/
	/*                   generation parameters
	 *                   
	 * numSegments :    number of segments high the tree is (each segment has a trunk component and a set of branches  
	 * _height :		height
	 * _radius :		radius
	 * _branchSides:	number of sides on the trunk and branches
	 * _branchesPerSegment : number of branches in each segment
	 * _globalIterationCount : number of iteration
	 * _branchIterationDecay : rate change when new iteration
	/************************************************************************/
	int		_num_of_Segments;
	float	_height;
	float	_radius;
	int		_branchSides;
	int		_branchesPerSegment;
	int		_globalIterationCount;
	float	_branchIterationDecay;
	// static constants
// 	static const int trunkVertexSize;
// 	static const int leafVertexSize;
	/************************************************************************/
	/* standard data, store the grow condition 
	/************************************************************************/
	float	_standard_height;
	int		_standard_numSegments; 
	float	_standard_radius;
	int		_standard_branchSides; 
	int		_standard_branchesPerSegment;
	int		_standard_branchIterationCounts;
	float	_standard_IterationDecay;
	/************************************************************************/
	/* min segment for no grow branches                                                                     */
	/************************************************************************/
	int		_number_of_segment_no_branches;
	/************************************************************************/
	/*      used for control grow speed                                                                */
	/************************************************************************/
	float	_grow_increase_fator;
	/************************************************************************/
	/* time record                                                                   
	 * used for control grow
	/************************************************************************/
	float	_temp_timerrecord;
	/************************************************************************/
	/* initialize temp dec factor                                                                     */
	/************************************************************************/
	float	_initialize_dec;
	/************************************************************************/
	/* control render choice                                                                     */
	/************************************************************************/
	int		VBO_BUILD_OR_FLUSH_FLAG;
	
	void	setTreeParameter();
	/************************************************************************/
	/*set the parameter when beginning                                                                      */
	/************************************************************************/
	void	generateTreeSeed();
	/************************************************************************/
	/* generate growing data in each frame during the growing process                                                                 */
	/************************************************************************/
	void	updateTreeGrowingData();
	/************************************************************************/
	/* growing method                                                                     */
	/************************************************************************/
	void	makeTreeGrowing();
	/************************************************************************/
	/*            generate data for each segments trunk                              */
	/************************************************************************/
	void	generateVertexAndNormalizeForPerSegments(vec3f& top, vec3f& bottom, float& radius,float& _radius);
	/************************************************************************/
	/* control build or update vbo                                                                     */
	/************************************************************************/
	void	buildAndFlushVBO();
	/************************************************************************/
	/* control the gowth of                                                                     */
	/************************************************************************/
	void	makeLeafGrowing(vec3f dir, vec3f root, float size, int gen);
	/************************************************************************/
	/* draw trunk                                                                     */
	/************************************************************************/
	void	drawTrunks();
	/************************************************************************/
	/* draw leaf                                                                     */
	/************************************************************************/
	void	drawLeaf();
	/************************************************************************/
	/* setter for private variable                                                                     */
	/************************************************************************/
	void	setTrunkCutCount( int s) { _standard_numSegments = _num_of_Segments = s; }
	void	setHeight( float h) { _standard_height = _height = h; }
	void	setRadius( float r) { _standard_radius = _radius = r; }
	void	setNumPerBranchSides( int n) { _standard_branchSides = _branchSides = n;} 
	void	setBranchesPerSegment( int n) { _standard_branchesPerSegment = _branchesPerSegment =n;}
	void	setBranchIterationCount( int gen) { _standard_branchIterationCounts = _globalIterationCount = gen; }
	void	setBranchIterationDecay( float r) { _standard_IterationDecay = _branchIterationDecay = r; }
	void	setMinNoBranches( int n ){ _number_of_segment_no_branches = n; };

	/************************************************************************/
	/* random tools                                                                     */
	/************************************************************************/
	float	randfPosFrom0To1();
	float	randfFromF1To1();
	float	rand2fFromF1To0To1();
	
	void	downUpdateTreeGrowing();
	/************************************************************************/
	/* flash trunk vbo                                                                     */
	/************************************************************************/
	void	flushTrunkVBO();
	void	flushLeafVBO();
	//leaf grow method
	bool	showLeaf;
	float	leafSize;
	void	smallAllLeaf();
	bool	growLeaf;

	void	leafDownMethod();
	bool	leafDwonFinished;

	void	leafColorBrown();
	vec4f	leafColor;
	bool	leafColorBrownFinished;
public:
	ChristmasTree(void);
	~ChristmasTree(void);
	/************************************************************************/
	/* texture                                                                     */
	/************************************************************************/
	GLuint	trunk_texture_id;
	GLuint	leaf_texture_id;
	GLuint	leaf_nor_texture_id;
	/************************************************************************/
	/* status control                                                                     */
	/************************************************************************/
	treestatus	TreeState;
	bool		_canRandom;
	
	/************************************************************************/
	/* implement the interface method of IDisplayObject                                                                     */
	/************************************************************************/
	void Initialize();
	void Draw();
	void Update(const float& t);
	
	/************************************************************************/
	/* personal functions                                                                     */
	/************************************************************************/
	void	reset();
	
	

	

	
	
};

