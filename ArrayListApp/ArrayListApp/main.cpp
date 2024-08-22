#include <iostream>
#include "ArrayList.h"

using namespace std;

int main()
{
	ArrayList myList(30);

	for (int i = 0; i < 25; i++)
	{
		myList.add(i * 7);
	}

	myList.printList();
	cout << endl << endl;

	cout << "List size: " << myList.size() << endl;

	cout << endl << endl;
	myList.add(12, 25);
	myList.printList();
	cout << "New list size: " << myList.size() << endl;
	cout << endl << endl;


	return 0;
}