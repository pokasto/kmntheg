#include "BinaryTreeList.hpp"
#include <iostream>
#include <windows.h>
BinaryTreeList::BinaryTreeList()
{
	this->size = 0;
	this->capacity = 10;
	this->binaryTrees = new BinaryTree*[capacity];
}

void BinaryTreeList::add(BinaryTree* binaryTree)
{
	if (size == capacity)
	{
		expand();
	}
	binaryTrees[size] = binaryTree;
	size++;
}

void BinaryTreeList::expand()
{

	this->capacity *= 2;
	BinaryTree** tmp = new BinaryTree*[capacity];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = binaryTrees[i];
	}
	delete[] binaryTrees;
	binaryTrees = tmp;
}
void BinaryTreeList::print()
{
	for (int i = 0; i < size; i++)
	{
		binaryTrees[i]->print();
		std::cout << '\n';
		Sleep(10);
	}
}

BinaryTree* BinaryTreeList::compare(BinaryTree *first,BinaryTree *second)
{
	if (first == nullptr)return second;
	if (second == nullptr)return first;
	if (first->getHeight() < second->getHeight())
	{
		delete first;
		first = second;
	}
	else if (first->getHeight() == second->getHeight())
	{
		if(first->getSum()==-1)
		first->calculateSum();
		if(second->getSum()==-1)
		second->calculateSum();
		if (first->getSum() < second->getSum())
		{
			delete first;
			first = second;
		}
		else {
			delete second;
		}
	}
	else {
		delete second;
	}
	return first;
}
BinaryTreeList::~BinaryTreeList()
{
	for (int i = 0; i < size; i++)
	{
		delete binaryTrees[i];
	}
	delete []binaryTrees;
}