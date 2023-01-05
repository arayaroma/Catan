#include "LinkedList.h"

LinkedList::LinkedList() {
	this->head = NULL;
}

void LinkedList::add(Node* data) {
	data->set_next(head);
	head = data;
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
		if (temp->get_data()->getTypeClass() == "Land") {
			std::cout << "DENtro" << std::endl;
			Land* land = new Land(temp->get_data());
			land->toString();
		}
		temp = temp->next;
	}
}