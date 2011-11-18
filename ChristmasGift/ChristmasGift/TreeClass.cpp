#include "TreeClass.h"
// #include <time.h>
// #include <stdlib.h>
// #include <stdio.h>
// 
// #include <iostream> 
// 
// using namespace std;


TreeClass::TreeClass(void)
{
	//root = NULL;

	countofbranch = 0;


	rootStopGrowing = false;

	tempheight = 0;


	tree2.Create(0.1,0.1,1,root_slices,root_stacks);


	gin = 2;
}


TreeClass::~TreeClass(void)
{
}

void TreeClass::Initialize(){
	root = new TreeNode();
	root->Left = NULL;
	root->Right = NULL;
	root->Father = NULL;
	root->Data.Create(root_topr,root_bottomr,root_height,root_slices,root_stacks);
	root->_maxheight = ROOTMAXTREEHEIGHT;
	root->stopgrowing = false;
	root->Data._moveheight = 0;
	root->id = 0;
	root->Data._rx = 0;
	root->Data._rz = 0;

	if(countofbranch == 0){
		root->isleaf = true;
		root->isroot = true;
		root->hasbranch = false;
	}
}

void TreeClass::Update(const float& t){

// 	if(!rootStopGrowing)
// 		GoThoughTree(root,0.99);
}

void TreeClass::Draw(){

/*	GoThoughTreeDraw(root);*/
	Recursion(2);

}

//great work
void TreeClass::GrowTree(const float& height_inc_percent, const float& tr_inc_percent, const float& br_inc_percent){

	//_treedata.UpdateData(height_inc_percent,tr_inc_percent,br_inc_percent);

}

int TreeClass::RangedRand( int range_min, int range_max)
{
	int u = (double)rand() / (RAND_MAX + 1) * (range_max - range_min)
		+ range_min;
	return u;
}

