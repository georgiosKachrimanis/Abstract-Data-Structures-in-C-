#include <iostream>
#include "ListStack.h"

using namespace std;
void printStack(ListStack& stack);

int main()
{
	ListStack stack;
	
	for (int i = 100; i < 1250; i += 50) 
	{
		stack.push(i);
	}
	printStack(stack);

	stack.push(10000);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	
	printStack(stack);

	cout << stack.peek() << endl;
	
	return 0;
}

void printStack(ListStack& stack)
{
	ListStack tempStack;
	int tempData;

	while (!stack.isEmpty())
	{
		tempData = stack.pop();
		tempStack.push(tempData);
		cout << tempData << endl;
	}

	while (!tempStack.isEmpty())
	{
		tempData = tempStack.pop();
		stack.push(tempData);
	}
}