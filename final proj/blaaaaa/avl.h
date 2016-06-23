// Chad S Funckes
// CSCI 2421 AVL Tree class
/*
Purpose:  avl.h contains a fully templated AVL tree implementation with the following information:
CLASS: NODE and AVL defined

Node Class:
	Contains a value item, a int value for the height in the tree and Left and Right Pointers

AVL Class:
	Creates a blanaced AVL tree of Node Class items.  Where the value is templated to be whatever.
	Many functions are overloaded, calling private member functions with the same name.  This is 
	so that the user can easily use them, without a big parameter list, or access to the private MBR data 
	being required.

	Constructors:
	AVL(); 
		Post: Initialize pointers ROOT and EMPTY, no duplicates allowed by default.
	AVL(bool allow);
		Post: Initialize pointers, allow inserting duplicates.
	~AVL();
		Post: Recursive deletion of the tree.

	Accessors:
		Node<T>* Search(T val)
			PRE: T val, is a complete item of the type being used by AVL...for example, must be a complete class, if T is a class
			Post: A pointer to the found item in the tree.
		T Max(), T Min()
			Post: returns a copy of the item at value, that is the smallest or largest in the tree
			Comment: // Originally thought I would use this for complete searching, but didn't so I just left it there.
		PrintInOrderTraversal(ostream &outputstream)
			PRE: Requires an output stream be specified, this is so you can output to a screen or a file, or whatever easily.
			POST: The values in the tree, in order from smallest to largest.
	Mutators:
		void Insert(T val)
			PRE: Insert takes a fully constructed item of type T if T is a class.
			Post: Item T is copied into the tree, in order and the tree is then balanced.
		void Delete(T val)
			PRE: Delete needs a fully constructede item of type T for reference.
			Post: The item that matches T, however defined by == operator is removed from the tree and
					the tree is blanced.
		void Copy(AVL<T>& lside, AVL<T>& rside)
			PRE: Two AVL trees with lside being the item being copied and rside being the tree that will be the duplicated
			POST: rside is a copy of lside
		void ClearTree()
			POST: Everything in the tree is deleted and tree is ready to be filled again.
	Value Symantics:
			This class requires classes have:
				Equality Operator ==
				Less than Operator <
				Less than Equal Operator <= (for duplicates)
				(greater than is assumed (if not less than) and overloaded operators not needed)
*/
#ifndef AVLTREE_FINAL
#define AVLTREE_FINAL
#include<iostream>
using namespace std;

template<class T>
class Node
{
public:
	T value;
	int h; // The depth of the node in the tree
	Node *left, *right;
};

template<class T>
class AVL
{
public:
	// Constructors/destructor
	AVL() { Init(); AllowDup = false; } // Initialize pointers when constructor is called, no duplicates by default.
	AVL(bool allow) {Init(); AllowDup = allow; } // Initialize pointers, allow to specify duplicates (this only effects Insert func)
	~AVL() { DeallocMemory(Root); } // When the destructor is called, it invokes recursive deletion of the tree.
	// Accessors
	Node<T>* Search(T val) { return Search(Root, val); } // Search func so user only has to type the value and not care about the root
	T Max() {	// The Max value from AVL is the rightmost node in the tree
			Node<T> *N = Root;
			while (N->right != EMPTY) N = N->right;
			return N->value;
		}
	T Min() { // The Min value from AVL is in the leftmost node of the tree
			Node<T> *N = Root;
			while (N->left != EMPTY) N = N->left;
			return N->value;
		}
	void PrintInOrderTraversal(ostream &outputstream)
		{
			PrintInOrderTraversal(outputstream, Root);
		}
	//Mutators	
	void Insert(T val) { Root = Insert(Root, val); } // Insert func, so user only has to use value and not care about root pointer
	void Delete(T val) { Root = Delete(Root, val); } // Ditto ^^
	void Copy(AVL<T>& lside, AVL<T>& rside);
	void ClearTree() { DeallocMemory(Root); Root = EMPTY; }
	
protected:					// Protected so that derived classes, like roloAVL can get access to the privates...
	Node <T> *Root, *EMPTY; // *Root is the root, *EMPTY is an empty reference ( to tell is the next node empty(without checking left,right nulls) 
							//and prvention of hanging right,left pointers during deletions ).  At the end of every leaf will be a pointers(not copies) to the roots EMPTY
	bool AllowDup;			// Bool value for insert to check if item exists
	void Init();			// Sets up all the values.
	Node<T>* Search(Node<T> *N, T val);
	void DeallocMemory(Node<T> *N);
	Node<T>* Insert(Node<T> *N, T val);
	Node<T>* Delete(Node<T> *N, T val);
	void GetHeight(Node<T> *N); // Updadets the depth of the node N in the tree
	Node<T>* RotateLeft(Node<T> *N); // The Rotate left operation, for balancing the tre
	Node<T>* RotateRight(Node<T> *N);
	Node<T>* Balance(Node<T> *N);// Balance the nodes in the way that no two subtrees of a node have their maximum depth with a difference bigger than 1
	int Max(int a, int b);
	void CopyTree(AVL<T>&, AVL<T>&, Node<T>* N);
	void PrintInOrderTraversal(ostream &outputstream, Node<T> *N)
		{
			if (N == EMPTY) return;
			PrintInOrderTraversal(outputstream, N->left);
			outputstream << N->value << " ";
			PrintInOrderTraversal(outputstream, N->right);
		}
};
#include "avl.template"
#endif