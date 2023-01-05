#pragma once
#include <iostream>
#include <string>
#include "Land.h"

class Node {
private:
	
	Land data;

public:
	Node* next;

	Node();
	Node(Land);

	Node* get_next();
	void set_next(Node*);

	Land get_data();
	void set_data(Land);
};

