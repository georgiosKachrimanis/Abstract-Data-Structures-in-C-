#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "Queue.h"

using namespace std;

class ArrayQueue : public Queue
{
	private:
		int* mArray;
		const int MAX_SIZE;
		int front;
		int back;
		int numElements;
	public:
		ArrayQueue(int s = 26) : MAX_SIZE(s)
		{
			front = 0;
			back = 0;
			mArray = new int[MAX_SIZE];
			numElements = 0;
		}
		virtual ~ArrayQueue()
		{
			delete[] mArray;
		}

		void enqueue(int newEntry)
		{
			if (numElements > MAX_SIZE - 1)
			{
				cout << "The queue is full. No more items can be added! " << endl;
			}
			else
			{
				mArray[back] = newEntry;
				back = (back + 1) % MAX_SIZE;
				numElements++;
			}
		}

		int dequeue()
		{
			int data = 0;
			if (!isEmpty())
			{
				data = mArray[front];
				front= (front + 1) % MAX_SIZE;
				numElements--;
			}
			else
			{
				cout << "The queue is empty!" << endl;
			}
			return data;

		}

		int peekFront() const
		{
			int data = 0;
			if (!isEmpty())
			{
				data = mArray[front];
			}
			else
			{
				cout << "The queue is empty!" << endl;
			}
			return data;
		}

		bool isEmpty() const
		{
			return numElements == 0;
		}

		void makeEmpty()
		{
			front = 0;
			back = 0;
			numElements = 0;
		}
};

#endif // !ARRAYQUEUE_H

