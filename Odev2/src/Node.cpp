#include "Node.hpp"

Node::Node(int value)
{
	this->value = value;
	this->right = nullptr;
	this->left = nullptr;
}
void Node::setLeft(Node* left)
{
	this->left = left;
}
void Node::setRight(Node* right)
{
	this->right = right;
}

Node* Node::getLeft()
{
	return this->left;
}
Node* Node::getRight()
{
	return this->right;
}
int Node::getValue()
{
	return this->value;
}