#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "Queue.h"

using namespace std;

// ---------------------------------- Node --------------------------------- //
class Node
{
public:
	Node(int data, Node* next, Node* previous)
	{
		this->data = data;
		this->next = next;
		this->previous = previous;
	}

	int getData() const
	{
		return data;
	}

	Node* getNext() const
	{
		return next;
	}

	Node* getPrevious() const
	{
		return previous;
	}

	void setData(int data)
	{
		this->data = data;
	}

	void setNext(Node* next)
	{
		this->next = next;
	}

	void setPrevious(Node* previous)
	{
		this->previous = previous;
	}

private:
	int data;
	Node* next;
	Node* previous;
};


// ------------------------------ Linked Queue --------------------------------//
class LinkedQueue : public Queue
{
private:
	Node* front;
	Node* back;
public:
	LinkedQueue()
	{
		front = nullptr;
		back = nullptr;
	}

	virtual ~LinkedQueue()
	{
		makeEmpty();
	}

	void enqueue(int newEntry)
	{
		Node* newNode = new Node(newEntry, back, nullptr);

		if (isEmpty()) 
		{
			front = newNode;
		}
		else
		{
			back->setPrevious(newNode);
		}
		
		back = newNode;

	}

	int dequeue()
	{
		int data = 0;

		if (isEmpty())
		{
			cout << "Error: The Queue is empty! " << endl;
		}
		else
		{
			Node* temp = front;
			data = front->getData();
			front = front->getPrevious();

			delete temp;

			if (front == nullptr)
			{
				back = nullptr;
			}
			else
			{
				front->setNext(nullptr);
			}
		}

		return data;
	}

	int peekFront() const
	{
		int data = 0;
		if (isEmpty())
		{
			cout << "Error: You can not peek on an empty queue!" << endl;
		}
		else
		{
			data = front->getData();
		}
		return data;
	}

	bool isEmpty() const
	{
		return front == nullptr && front == back;
	}

	void makeEmpty()
	{
		while(!isEmpty())
		{
			dequeue();
		}
	}
};

#endif // !LINKEDQUEUE_H
