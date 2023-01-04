#pragma once
#include "Node.h"
#include <string>
template<typename T>
class List  {
private:
	Node<T>* aux;
	Node<T>* head;
	Node<T>* end;
public:
	List();
	void add(T& newLandNode);
	bool deleteNode(T& LandNode);
	bool isEmpty();
	void print();
};


