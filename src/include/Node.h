#pragma once
class Node
{
	protected:
		Node* next;
		Node* previous;
	public:
		Node();	
		~Node();
		void setNext(Node* s);
		Node* getNext();
		void setPrevious(Node* a);
		Node* getPrevious();
};
