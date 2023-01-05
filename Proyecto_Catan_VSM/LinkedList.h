#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include "Component.h"
#include "Land.h"

class LinkedList  {
private:
	Node* head;
public:
	LinkedList();
	void add(Component* data);
	void delete_node(Node*);

	void to_string();
	bool isEmpty(){ return (head == NULL); }
};


