#ifndef LIST_STACK_H
#define LIST_STACK_H

#include "LinkedList.h"

using namespace std;

class ListStack : LinkedList
{
private:
	LinkedList linkedListStack;
public:
	ListStack()
	{
	}

	virtual ~ListStack()
	{
		linkedListStack.makeEmpty();
	}

	void push(int newEntry)
	{
		linkedListStack.add(newEntry);
	}
	
	int pop()
	{
		int data = 0;
		if (!isEmpty()) 
		{
			data = linkedListStack.remove(0);
		}
		else
		{
			cout << "Error: The stack is empty!" << endl;
		}
		
		return data;
	}

	int peek()
	{
		int data = 0;

		if (!isEmpty())
		{
			data = pop();
			push(data);
		}
		else
		{
			cout << "Error: The stack is empty!" << endl;
		}

		return data;
	}

	bool isEmpty() const
	{
		return linkedListStack.isEmpty();
	}

	void makeEmpty()
	{
		linkedListStack.makeEmpty();
	}
};
#endif // !LIST_STACK_H

