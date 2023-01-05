#pragma once
#include "Node.h"
#include <iostream>
#include <string>

class LinkedList  {
private:
	Node* head;

public:
	LinkedList();
	void add(Land data);
	void delete_node(Node*);

	void to_string();
	bool isEmpty(){ return (head == NULL); }
};


