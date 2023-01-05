#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include "Component.h"
class LinkedList  {
private:
	Node* head;

public:
	LinkedList();
	void add(Node* data);
	void delete_node(Node*);

	void to_string();
	bool isEmpty(){ return (head == NULL); }
};

