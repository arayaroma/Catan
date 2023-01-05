#pragma once
#include <iostream>
#include <string>
#include "Land.h"
#include "Component.h"
class Node {
private:
public:
	Land* data;
	Node* next;

	Node();
	Node(Land*);

	Node* get_next();
	void set_next(Node*);

	Land* get_data();
	void set_data(Land*);
};

