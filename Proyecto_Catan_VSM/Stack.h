#pragma once
#include "Node.h"
#include "Card.h"
template<typename T>
class Stack
{
private:
	Node<T>* aux;
	Node<T>* head;
	Node<T>* end;
public:
	void push(T& newData);
	T& pop();
	T& top();
	bool isEmpty();
	void print();
};

