#include "BinaryTree.hpp"
#include<iostream>
BinaryTree::BinaryTree()
{
	this->root = nullptr;
	this->heightVal = -1;
	this->sum = -1;
}
BinaryTree::BinaryTree(Stack* stack)
{
	this->root = nullptr;
	this->heightVal = -1;
	this->sum = -1;
	while (!stack->isEmpty())
	{
		this->insert(stack->pop());
	}
	calculateHeight();
}

void BinaryTree::insert(int value)
{
	Node* itr = root;
	if (itr== nullptr)
	{
		root = new Node(value);
		return;
	}
	bool found = false;
	while (!found)
	{
		if (itr->getValue() == value)return;
		if (itr->getValue() > value)
		{
			if (itr->getLeft() != nullptr)
			{
				itr= itr->getLeft();
			}
			else {
				itr->setLeft(new Node(value));
				found = true;
			}
		}
		else {
			if (itr->getRight() != nullptr)
			{
				itr = itr->getRight();
			}
			else {
				itr->setRight(new Node(value));
				found = true;
			}
		}
	}
}
int BinaryTree::height()
{
	return height(this->root);
}
int BinaryTree::height(Node* node)
{
	if (node == nullptr)
		return -1;
	return 1 + std::max(height(node->getLeft()), height(node->getRight()));
}

void BinaryTree::calculateHeight()
{
	this->heightVal = height();
}
void BinaryTree::calculateSum()
{
	this->sum = calcSum(this->root);
}
int BinaryTree::calcSum(Node* node)
{
	if (node == nullptr)
		return 0;
	return (node->getValue() + calcSum(node->getLeft()) + calcSum(node->getRight()));
}
int BinaryTree::getHeight()
{
	return this->heightVal;
}
int BinaryTree::getSum()
{
	return this->sum;
}
void BinaryTree::print()
{
	print(this->root);
}
void BinaryTree :: print(Node* node)
{
	if (node == nullptr)return;
	print(node->getLeft());
	print(node->getRight());
	std::cout << char(node->getValue());
}

void BinaryTree::deleteTree(Node* node)
{
	if (node)
	{
		deleteTree(node->getLeft());
		deleteTree(node->getRight());
		delete node;
	}
}
BinaryTree::~BinaryTree()
{	
	deleteTree(root);
}