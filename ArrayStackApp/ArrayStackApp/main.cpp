#include <iostream>
#include "ArrayStack.h"

using namespace std;

int main()
{

	ArrayStack stack(37);
	ArrayStack reverseStack(37);
	int stackData = 0;

	for (int i = 0; i < 37; i++)
	{
		stack.push(i * i);
	}

	cout << "Original Stack: " << endl;
	while (!stack.isEmpty())
	{
		stackData = stack.pop();
		reverseStack.push(stackData);
		cout << stackData << endl;
	}

	cout << "Reverse Stack: " << endl;

	while (!reverseStack.isEmpty())
	{
		stackData = reverseStack.pop();
		stack.push(stackData);
		cout << stackData << endl;
	}

	cout << "Original Stack: " << endl;
	while (!stack.isEmpty())
	{
		stackData = stack.pop();
		reverseStack.push(stackData);
		cout << stackData << endl;
	}
	return 0;
}