#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

class Stack
{
	public:

	private:
		virtual void push(int newEntry) = 0;
		virtual int pop() = 0;
		virtual int peek() = 0;
		virtual bool isEmpty() const = 0;
		virtual void makeEmpty() = 0;

};

#endif // !STACK_H

