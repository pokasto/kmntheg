#ifndef Node_h
#define Node_h

class Node
{
private:
	Node* right;
	Node* left;
	int value;

public:
	Node(int value);
	void setRight(Node* right);
	void setLeft(Node* left);
	Node* getRight();
	Node* getLeft();
	int getValue();
};
#endif

