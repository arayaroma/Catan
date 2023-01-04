#pragma once
#include "CardNode.h"
#include "Card.h"
class Stack
{
private:
	CardNode* aux;
	CardNode* head;
	CardNode* end;
public:
	void push(CardNode* n);
	Card* pop();
	Card* top();
	bool isEmpty();
	void print();
};

