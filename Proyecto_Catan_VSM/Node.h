#pragma once

template<typename T> class Node
{
private:
	
	T info;
	Node* next;
	Node* previous;
public:
	Node<T>();
	Node<T>(T&);
	void setNext(T&  nextNode);
	T getNext();
	void setPrevious(T&  previousNode);
	T getPrevious();
	void setInfo(T& info);
	T getInfo();
};

