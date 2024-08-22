#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "list.h"

using namespace std;
// ------------------------ Node Class ----------------------//
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

//--------------------------Linked List Class ----------------//
class LinkedList : public List
{
	public:
		LinkedList()
		{
			mNumElements = 0;
			mHead = nullptr;
		}

		virtual ~LinkedList()
		{
			makeEmpty();
		}

		void add(int newEntry)
		{
			Node* newNode = new Node(newEntry, mHead);
			mHead = newNode;
			
			mNumElements++;
		}

		void add(int newEntry, int position)
		{
			Node* newNode = new Node(newEntry, mHead);

			if (position >= mNumElements + 1 || position < 0)
			{
				cout << "Error: The position for the new entry is out of range!" << endl;
				return;
			}

			if (position == 0)
			{
				newNode->setNext(mHead);
				mHead = newNode;
			}
			else
			{
				Node* nodeBefore = mHead;
				Node* nodeAfter;

				// The reason we are doing this is because we do not have an index of the nodes in the list, so we must traverse all the linked nodes untli we find the node we need...
				for (int i = 0; i < position - 1; i++)
				{
					nodeBefore = nodeBefore->getNext();
				}

				nodeAfter = nodeBefore->getNext();
				newNode->setNext(nodeAfter);
				nodeBefore->setNext(newNode);
			}
			mNumElements++;

		}

		void set(int newEntry, int position)
		{
			
			Node* walker = mHead;
						
			if (position < 0 || position >= mNumElements)
			{
				cout << "Error: The position for the entry is out of range!" << endl;
				return;
			}

			for (int i = 0; i < position; i++)
			{
				walker = walker->getNext();
			}
			
			walker->setData(newEntry);
		}


		bool contains(int entry) const
		{

			return find(entry) != -1;
		}

		int find(int entry) const
		{
			int foundIndex = -1;

			int indexCounter = 0;
			Node* walker = mHead;

			while (walker != nullptr)
			{
				if (walker->getData() == entry)
				{
					foundIndex = indexCounter;
				}

				indexCounter++;
				walker = walker->getNext();
			}

			return foundIndex;
		}

		int remove(int position)
		{
			Node* walker = mHead;

			if (position >= mNumElements + 1 || position < 0)
			{
				cout << "Error: The position for the new entry is out of range!" << endl;
				return -1;
			}

			int returnData = 0;
			if (position == 0)
			{
				Node* temp = mHead;
				returnData = temp->getData();
				mHead = temp->getNext(); // mHead = mHead->getNext();
				delete temp;
			}
			else
			{
				Node* nodeBefore = mHead;
				Node* nodeToRemove;
				Node* nodeAfter;

				// The reason we are doing this is because we do not have an index of the nodes in the list, so we must traverse all the linked nodes untli we find the node we need...
				for (int i = 0; i < position - 1; i++)
				{
					nodeBefore = nodeBefore->getNext();
				}

				nodeToRemove = nodeBefore->getNext();
				returnData = nodeToRemove->getData();
				
				nodeAfter = nodeToRemove->getNext();
				nodeBefore->setNext(nodeAfter);
				delete nodeToRemove;
			}

			mNumElements--;
			
			return returnData;
		}

		void makeEmpty()
		{
			Node* temp;
			while (mHead != nullptr)
			{
				temp = mHead;
				mHead = mHead->getNext();
				delete temp;
			}

			mNumElements = 0;
		}

		int size() const 
		{
			return mNumElements;
		}

		bool isEmpty() const
		{
			return mNumElements == 0;
		}

		void printList() const
		{
			Node* walker = mHead;

			while (walker != nullptr)
			{
				cout << walker->getData() << endl;
				walker = walker->getNext();
			}
		}


	private:
		Node* mHead;
		int mNumElements;
};

#endif // !LINKED_LIST_H

