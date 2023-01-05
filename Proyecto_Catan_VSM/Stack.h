#pragma once
#include <iostream>
#include "CardNode.h"
#include "Card.h"

class Stack{
private:
	Component* data;
	CardNode* aux;
	CardNode* head;
	CardNode* end;
public:
	void push(Component*);
	Component* pop();
	Component* top();
	bool isEmpty();
	void print();
};

