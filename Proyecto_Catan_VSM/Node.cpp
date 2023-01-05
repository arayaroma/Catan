#include "Node.h"

Node::Node() { this->data = NULL; this->next = NULL; }

Node::Node(Land* data) {
	this->data = data;
	this->next = NULL;
}

void Node::set_data(Land* data) { this->data = data; }
Land* Node::get_data() { return this->data; }

void Node::set_next(Node* next) { this->next = next; }
Node* Node::get_next() { return this->next; }
