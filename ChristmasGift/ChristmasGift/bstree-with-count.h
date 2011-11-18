//////////////////////////////////////////////////////////////////////
//
// bstree-with-count.h   --   Binary search tree with counting
//
//////////////////////////////////////////////////////////////////////

#include<iostream>
#include<string>

template<class T> struct BTNode {
	T value;
	BTNode<T> * parent;
	BTNode<T> * rchild;
	BTNode<T> * lchild;
	int count;

	BTNode() : parent(NULL), lchild(NULL), rchild(NULL), count(1) {}; 
	~BTNode() {  }
	inline bool has_parent() const { return parent != NULL; }
	inline bool has_lchild() const { return lchild != NULL; }
	inline bool has_rchild() const { return rchild != NULL; }

	inline bool is_lchild() const {
		if( parent == NULL ) return false;
		else 
			return parent->lchild == this;
	}

	inline bool is_rchild() const {
		if( parent == NULL ) return false;
		else 
			return parent->rchild == this;
	}

	inline bool is_leaf() { return lchild == NULL && rchild == NULL; }

};


/// ******************** Binary Tree Type ************************
template<class T> class BTree {
public:
	typedef  T                            value_type;
	typedef  BTNode<T>                    node_type;
	typedef  BTNode<T>*                   node_ptr_type; 

protected:
	BTNode<T> * root_ptr;

public:
	BTree(): root_ptr(NULL) {}; 
	~BTree(){ delete_tree(root_ptr); }

	//copy constructor and operator= required !

	void insert( const T& key ){ 
		if ( root_ptr )
			insert_node( root_ptr, key ); 
		else{ //the tree is empty, create a node
			root_ptr = (node_ptr_type) new BTNode<T>();
			root_ptr->value = key;
		}
	}
	BTNode<T>* root() { return root_ptr; }

	void print_postorder(  node_ptr_type  );
	void print_preorder( node_ptr_type  );
	void print_inorder( node_ptr_type );

	bool lookup( const T& key ){ return lookup( root_ptr, key); } 
	bool lookup( node_ptr_type, const T& ); 
	int  get_count( node_ptr_type, const T& ); 
	int  get_count( const T& key ){ return get_count( root_ptr, key); } 
};

template<class T>
void BTree<T>::print_postorder( BTNode<T>* current ) {
	if( current ) {
		if( current->has_lchild() ) print_postorder( current->lchild );
		if( current->has_rchild() ) print_postorder( current->rchild );
		cout << current->value << " ";
	}
	else cout << "empty tree\n";
}

template<class T>
void BTree<T>::print_preorder( BTNode<T>* current ) {
	if( current ) {
		cout << current->value << " ";
		if( current->has_lchild() ) print_preorder( current->lchild );
		if( current->has_rchild() ) print_preorder( current->rchild );
	}
	else cout << "empty tree\n";
}

template<class T>
void BTree<T>::print_inorder( BTNode<T>* current ) {
	if( current ) {
		if( current->has_lchild() ) print_inorder( current->lchild );
		cout << current->value << " ";
		if( current->has_rchild() ) print_inorder( current->rchild );
	}
	else cout << "empty tree\n";
}

// insertion into BST 
template<class T>
void insert_node( BTNode<T>* current, const T& key ){

	if( ! current ) { cout << "ERROR: empty node!\n"; return; }
	if( current->value == key ) {
		current->count++;
		return;
	}
	if ( key < current->value ){ //must go left 
		if( current->has_lchild() )
			insert_node( current->lchild, key );
		else {
			BTNode<T>* new_node = (BTNode<T>*) new BTNode<T>();
			current->lchild = new_node;
			new_node->value = key;
			new_node->parent = current;
		}
	}
	else{ //must go right
		if( current->has_rchild() )
			insert_node( current->rchild, key );
		else {
			BTNode<T>* new_node = (BTNode<T>*) new BTNode<T>();
			current->rchild = new_node;
			new_node->value = key;
			new_node->parent = current;
		}
	}
}

// recursive postorder tree deletion
template<class T> 
void delete_tree( BTNode<T>* ptr ){
	if( ptr ){ 
		if( ptr->lchild ) delete_tree( ptr->lchild );
		if( ptr->rchild ) delete_tree( ptr->rchild );
		delete ptr;
	}
}  

//lookup 
template<class T>
bool BTree<T>::lookup( BTNode<T>* current, const T& key ){
	if( current == NULL ) return false;
	if( current->value == key ) return true;
	else 
		if( key < current->value ) lookup( current->lchild, key );
		else lookup( current->rchild, key );
}

//lookup with count 
template<class T>
int BTree<T>::get_count( BTNode<T>* current, const T& key ){
	if( current == NULL ) return 0;
	cout << ".";
	if( current->value == key ) {
		cout << endl;
		return current->count;
	} 
	else 
		if( key < current->value ) return get_count( current->lchild, key );
		else return get_count( current->rchild, key );
}