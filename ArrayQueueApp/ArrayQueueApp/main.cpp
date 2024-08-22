#include <iostream>
#include "ArrayQueue.h"

using namespace std;

int main()
{
	ArrayQueue queue;

	for (int i = 0; i <= 26; i++)
	{
		queue.enqueue(i*i*i);
	}

	cout << "Peek ;) " << queue.peekFront() << endl << endl;
	

	cout << "Dequeue ;) " << endl << endl;

	while (!queue.isEmpty())
	{
		cout << queue.dequeue() << endl;
	}

	cout << "Trying to dequeue from empty queue: " << queue.dequeue() << endl;

	for (int i = 0; i <= 40; i++)
	{
		cout << "Just added in the queue: " << (i * 20) << endl;
		queue.enqueue(i * 10); 
			if (i % 3 == 0)
			{
				cout << "Just dequeued " << queue.dequeue() << endl;
 			}

	}
	
	queue.enqueue(9999);
	queue.enqueue(99);

	return 0;
}