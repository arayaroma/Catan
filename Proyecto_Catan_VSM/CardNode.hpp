#pragma once
#include <iostream>
#include "Card.hpp"
#include "Component.hpp"

class CardNode{
private:
	Component* data;
	CardNode* next;

public:
	CardNode();
	CardNode(Component*);

	void set_data(Component*);
	Component* get_data();

	void set_next(CardNode*);
	CardNode* get_next();
};

