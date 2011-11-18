#include <iostream>

using namespace std;

template<class T>
struct BTNode
{
	T data;
	BTNode <T> * Lchild,*Rchild;
	BTNode(T nodeValue = T(),BTNode<T>* leftNode = NULL,BTNode<T>* rightNode = NULL )
		:data(nodeValue),Lchild(leftNode),Rchild(rightNode){}       //可选择参数的默认构造函数
};

template <class T>
void createBinTree(BTNode<T> * &root )
{
	BTNode<T>* p = root;
	BTNode<T>* k;
	T nodeValue ;
	cin>>nodeValue;
	if(nodeValue==-1)
	{
		root=NULL;
	}
	else
	{
		root=new BTNode<T>();
		root->data = nodeValue;
		createBinTree(root->Lchild);
		createBinTree(root->Rchild);
	}
}