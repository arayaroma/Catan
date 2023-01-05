#pragma once
#include <iostream>
#include "Card.h"

class CardNode{
private:
	Card data;
	CardNode* next;
public:
	CardNode();
	CardNode(Card);

	void set_data(Card);
	Card get_data();

	void set_next(CardNode*);
	CardNode* get_next();
};

