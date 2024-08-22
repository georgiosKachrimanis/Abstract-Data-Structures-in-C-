#ifndef NODE_H
#define NODE_H

class Node
{
	public:
		Node(int data, Node* next)
		{
			this->data = data;
			this->next = next;
		}

		void setData(int Data)
		{
			this->data = data;
		}
		void setNext(Node* next)
		{
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

	private:
		int data;
		Node* next;
};
#endif // !NODE_H

