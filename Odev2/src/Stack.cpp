#include "Stack.hpp"

Stack::Stack()
{
	this->capacity = 10;
	this->size = 0;
	this->arr = new int[capacity];
}

void Stack::push(int value)
{
	if (size == capacity)
		expand();
	arr[size] = value;
	size++;
}

void Stack::expand()
{
	this->capacity *= 2;
	int* tmp = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = arr[i];
	}
	delete[] arr;
	arr = tmp;
}

int Stack::pop()
{
	if (size == 0)
	{
		return -1;
	}
	size--;
	return arr[size];
}

int Stack::peek()
{
	return arr[size-1];
}
bool Stack::isEmpty()
{
	return size == 0;
}
Stack::~Stack()
{
	delete []arr;
}