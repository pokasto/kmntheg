#ifndef Stack_h
#define Stack_h
class Stack
{
private:
	int size;
	int capacity;
	int *arr;
	void expand();
public:
	Stack();
	void push(int value);
	int pop();
	int peek();
	bool isEmpty();
	~Stack();
};
#endif

