#include "LinkedList.h"

LinkedList::LinkedList() {
	this->head = NULL;
}

void LinkedList::add(Land* value) {
	Node* node = new Node();
	node->data = value;
	node->next = head;
	head = node;
	std::cout << "Se agrego!" << std::endl;
}

void LinkedList::delete_node(Node* node_before) {
	Node* temp = new Node();
	temp = node_before->next = temp->next;
	delete temp;
}

void LinkedList::to_string() {
	Node* temp = head;
	while (temp != NULL) {
		temp->data->toString();
		temp = temp->next;
	}
}