#ifndef BinaryTreeList_h 
#define BinaryTreeList_h
#include "BinaryTree.hpp"
class BinaryTreeList
{
private:
	int size;
	int capacity;
	BinaryTree** binaryTrees;
	void expand();
public:
	BinaryTreeList();
	void add(BinaryTree* tree);
	void print();
	BinaryTree* compare(BinaryTree *first,BinaryTree *second);
	~BinaryTreeList();
};
#endif

