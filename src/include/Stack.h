#pragma once
#include "Node.h"
#include "Card.h"

class Stack  {
public:
	void push(Node* n);
	Card* pop();
	Card* top();
};