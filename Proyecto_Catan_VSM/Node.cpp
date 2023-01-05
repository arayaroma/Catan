#include "Node.h"

Node::Node(){}

Node::Node(Component* data) {
	this->data = data;
	this->next = NULL;
}

void Node::set_data(Component* data) { this->data = data; }
Component* Node::get_data() { return this->data; }

void Node::set_next(Node* next) { this->next = next; }
Node* Node::get_next() { return this->next; }
