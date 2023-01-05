#pragma once
#include <iostream>
#include "CardNode.h"
#include "Card.h"

class Stack{
private:
	Card data;
	CardNode* aux;
	CardNode* head;
	CardNode* end;
public:
	void push(Card);
	Card pop();
	Card top();
	bool isEmpty();
	void print();
};

