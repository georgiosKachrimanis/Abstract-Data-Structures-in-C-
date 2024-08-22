#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;

class Queue
{
private:

public:
	virtual void enqueue(int newEntry) = 0;
	virtual int dequeue() = 0;
	virtual int peekFront() const = 0;
	virtual bool isEmpty() const = 0;
	virtual void makeEmpty() = 0;
};

#endif // !QUEUE_H

