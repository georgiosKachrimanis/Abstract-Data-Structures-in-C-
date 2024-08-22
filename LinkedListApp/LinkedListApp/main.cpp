#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{

	LinkedList myList;
	int data;

	for (int i = 0; i < 13; i++)
	{
		myList.add(i * i + i*i*i);
	}

	myList.printList();

	myList.set(5555, 8);
	myList.set(1, 0);
	myList.set(1, 12);

	cout << endl << endl;
	myList.add(111111, 13);
	myList.printList();



	cout << endl << endl;

	cout << myList.remove(5) << endl;

	cout << endl << endl;
	myList.printList();

	myList.add(111111, 13);
	myList.printList();

	cout << myList.find(111111) << endl;
	cout << boolalpha << myList.contains(5555);

	return 0;
}