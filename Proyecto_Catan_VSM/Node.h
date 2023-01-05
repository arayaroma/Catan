#pragma once
#include <iostream>
#include <string>
#include "Land.h"
#include "Component.h"
class Node {
private:
public:
	Component* data;
	Node* next;

	Node();
	Node(Component*);

	Node* get_next();
	void set_next(Node*);

	Component* get_data();
	void set_data(Component*);
};

