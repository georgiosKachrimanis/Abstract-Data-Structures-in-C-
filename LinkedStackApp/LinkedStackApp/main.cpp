#include <iostream>
#include "LinkedStack.h"

using namespace std;
void printStack(LinkedStack& stack);

int main()
{
	LinkedStack stack;


	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	
	cout << stack.peek() << endl;
	printStack(stack);
	cout << endl << endl;
	printStack(stack);

	return 0;
}

void printStack(LinkedStack& stack)
{
	LinkedStack tempStack;
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