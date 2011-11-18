#pragma once
#include "DisplayObjectModel.h"
#include "TreeElement.h"
#include <queue>
#include <vector>

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include <iostream> 

using namespace std;

using std::vector;

#define _DEBUG1

#define ROOTMAXTREEHEIGHT 0.5
#define MINTREEHEIGHT 0.8

#define DECREASEFACTOR 0.5



struct TreeNode{

	TreeNode* Left;
	TreeNode* Right;
	TreeNode* Father;

	TreeElement Data;

	bool isroot;
	bool isleaf;
	bool hasbranch;

	bool stopgrowing;

	int id;

	GLfloat _maxheight;


};



const float basic_topr_inc = 0.05;
const float basic_bottom_inc = 0.05;
const float basic_height_inc = 0.5;

const float root_topr = 0.01;
const float root_bottomr = 0.015;
const float root_height = 0.1;
const float root_slices = 10;
const float root_stacks = 5;


class TreeClass :
	public DisplayObjectModel
{
public:
	TreeClass(void);
	~TreeClass(void);
	/************************************************************************/
	/* DisplayModel Method                                                                     */
	/************************************************************************/
	void Update(const float& t);

	void Draw();

	void Initialize();
	
	//////////////////////////////////////////////////////////////////////////

	void GrowTree(const float& height_inc_percent, const float& tr_inc_percent, const float& br_inc_percent);

	//generate random num
	int RangedRand( int range_min, int range_max);


	//bsp method
	
	int countofbranch;


	bool rootStopGrowing;

	float tempheight;
	


	TreeNode* root;


	//for update tree
	//grow, born
	void GoThoughTree(TreeNode* nood,float p){
		
		OperateTreeBrances(nood, p);
		//for bother
		if(nood->Right != NULL)
			GoThoughTree(nood->Right, p);//brother
		if(nood->Left != NULL)
			GoThoughTree(nood->Left, p*DECREASEFACTOR);//children
	}

	void OperateTreeBrances(TreeNode* nood,float p){

		if(nood->Data._h < nood->_maxheight)
			nood->Data.UpdateData(basic_height_inc,basic_topr_inc,basic_bottom_inc);
		else{
			nood->stopgrowing = true;
#ifdef _DEBUG
			if(nood->id ==2)
				cout<<""<<endl;
#endif
			if(!nood->hasbranch){
				nood->Left = GenerateBranch(nood,p);

				cout<<"new branch"<<endl;
				cout<<"root id "<<nood->id<<endl;
				TreeNode* p = nood->Left;
				cout<<"chilren id "<<p->id<<endl;
				while(p->Right != NULL){
					p = p->Right;
					cout<<"chilren id "<<p->id<<endl;
					
				}
				cout<<"================="<<endl;
			}

		}


	}


	TreeNode* GenerateBranch(TreeNode* root,float p){
		srand((unsigned) time(NULL));
		int nob = RangedRand(2,5);
		root->hasbranch = true;
		root->isleaf = false;
		TreeNode* firstp;

		TreeNode* tempp;
		tempp = NULL;

#ifdef _DEBUG
		nob = 1;
#endif
		for(int i = 0; i< 2; i++){
			countofbranch++;
			//generate node
			TreeNode* np = new TreeNode();

			//tempp = np;

			np->id = countofbranch;

			np->Left = NULL;
			np->Right = NULL;
			np->Father = root;

			

			np->isleaf = true;
			np->hasbranch = false;
			np->isroot = false;
			np->_maxheight = root->Data._h;
			np->stopgrowing = false;

			

			//generate data
			np->Data.Create(root_topr,root_bottomr,0.05,root_slices,root_stacks);
			//generate rx, rz
			srand((unsigned) time(NULL));
			np->Data._rx = (GLfloat)RangedRand(15,85);
			srand((unsigned) time(NULL));
			np->Data._rz = (GLfloat)RangedRand(15,85);

#ifdef _DEBUG
			np->Data._rx = 30*countofbranch;
			np->Data._rz = 30*countofbranch;
#endif

			//set y move variable = root .h
			np->Data._moveheight = root->Data._h;
			
			if(i == 0){
				//first
				firstp = np;
				tempp = np;
			}
			else{
				tempp->Right = np;
				tempp = np;
			}

		}


		return firstp;
	}

	void GoThoughTreeDraw(TreeNode* nood){

		
		glPushMatrix();
 		glTranslatef(0,nood->Data._moveheight,0);
 		glRotatef(nood->Data._rx,1.0,0,0);
 		glRotatef(nood->Data._rz,0,0,1);

		
		DrawBraches(nood->Data);
		
		

		if(nood->Right != NULL){
// 			glPushMatrix();
// 			glRotatef(nood->Data._rx,1,0,0);
// 			glRotatef(nood->Data._rz,0,0,1);
			GoThoughTreeDraw(nood->Right);
/*			glPopMatrix();*/
		}

		
			
		if(nood->Left != NULL){
// 			glPushMatrix();
// 			glTranslatef(0,nood->Data._moveheight,0);
			GoThoughTreeDraw(nood->Left);
/*			glPopMatrix();*/
		}

		
		glPopMatrix();

		
	}
	void DrawBraches(TreeElement &branch){
		branch.Draw();
	}

	TreeElement tree2;
	
	int gin;

	void Recursion(short iter){
		if(iter == 0){
			
		}
		else{

			//draw body

			TreeElement tree;
			
			tree.Create(0.1,0.1,1,root_slices,root_stacks);
			tree.Draw();


			glPushMatrix();
			
			glTranslatef(0,tree._h,0);
			glRotatef(45,1,0,0);
			Recursion(iter-1);
			glPopMatrix();
			 

			//turn right, right subtree
			glPushMatrix();
			
			glTranslatef(0,tree._h,0);
			glRotatef(-45,1,0,0);
			Recursion(iter-1);
			glPopMatrix();
			//

		}
		
	}

	


	
};

