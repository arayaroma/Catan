#include "LinkedList.h"

LinkedList::LinkedList() {
	this->head = NULL;
}

void LinkedList::add(Land data) {
	Node* node = new Node(data);
	node->set_next(head);
	head = node;
	std::cout << "Se agrego!" << std::endl;
}

void LinkedList::delete_node(Node* node_before) {
	Node* temp = new Node();
	temp = node_before->next = temp->next;
	delete temp;
}

void LinkedList::to_string() {
	Node* temp = this->head;
	while (temp->next != NULL) {
		temp->get_data().toString();
		temp = temp->next;
	}
}