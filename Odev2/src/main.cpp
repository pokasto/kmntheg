#include <iostream>
#include<fstream>
#include<sstream>
#include "BinaryTreeList.hpp"
int main()
{
	std::ifstream Oku("Sayilar.txt");
	std::string line;
	BinaryTreeList* treeList = new BinaryTreeList();
	Stack* stack = new Stack();
	while (getline(Oku, line))
	{
		std::istringstream iss(line);
		std::string strnum;
		BinaryTree* currLineTree = nullptr;
		BinaryTree* newTree = nullptr;
		while (getline(iss, strnum, ' ')) {
			int number = std::stoi(strnum);
			if (!stack->isEmpty()) {
				if ((stack->peek() < number && number % 2 == 0))
				{
					newTree = new BinaryTree(stack);
					if (currLineTree != nullptr)
					{
						currLineTree=treeList->compare(currLineTree, newTree);
					}
					else {
						currLineTree = newTree;
					}
				}
			}
			stack->push(number);
		}
		newTree = new BinaryTree(stack);
		currLineTree = treeList->compare(currLineTree, newTree);
		treeList->add(currLineTree);
	}
	treeList->print();
	delete treeList;
	delete stack;
}