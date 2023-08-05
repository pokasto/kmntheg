#ifndef BinaryTree_h
#define BinaryTree_h
#include "Node.hpp"
#include "Stack.hpp"
class BinaryTree
{
private:
	Node* root;
	int heightVal;
	int sum;
	int height();
	int height(Node* node);
	void calculateHeight();
	int calcSum(Node* node);
	void deleteTree(Node* node);
public:
	BinaryTree();
	BinaryTree(Stack* stack);
	void insert(int value);
	void calculateSum();
	int getHeight();
	int getSum();
	void print();
	void print(Node* node);
	~BinaryTree();
};
#endif

