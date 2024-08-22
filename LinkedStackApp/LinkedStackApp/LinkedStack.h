#ifndef LINKED_STAKC_H
#define LINKED_STACK_H

#include "Stack.h"
#include <iostream>

// ---------------------------- NODE ----------------------------- //

class Node
{
public:
	Node(int data, Node* next)
	{
		this->data = data;
		this->next = next;
	}

	int getData() const
	{
		return data;
	}

	Node* getNext() const
	{
		return next;
	}

	void setData(int data)
	{
		this->data = data;
	}

	void setNext(Node* next)
	{
		this->next = next;
	}

private:
	int data;
	Node* next;
};

// ---------------------- Linked Stack --------------------------- //

class LinkedStack : public Stack
{
	public:
		LinkedStack()
		{
			top = nullptr;
		}

		virtual ~LinkedStack()
		{
			makeEmpty();
		}

		void push(int newEntry)
		{
			Node* newNode = new Node(newEntry, top);
			top = newNode;
		}

		int pop()
		{
			int data = 0;

			if (isEmpty())
			{
				cout << "Error: The Stack is empty!" << endl;
			}
			else
			{
				Node* temp = top;
				data = temp->getData();
				top = temp->getNext();
				delete temp;
				
				
			}
			return data;
		}

		int peek() const
		{
			int data = 0;

			if (isEmpty())
			{
				cout << "Error: The Stack is empty!" << endl;
			}
			else
			{
				data = top->getData();
			}
			return data;
		}

		bool isEmpty() const
		{
			return top == nullptr;
		}

		void makeEmpty()
		{
			Node* temp = top;
			while (top != nullptr)
			{
				temp = top;
				top = top->getNext();
				delete temp;

			}
		}

	private:
		Node* top;

};


#endif // !LINKED_STAKC_H

