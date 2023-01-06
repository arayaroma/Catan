#include "LinkedList.hpp"

LinkedList::LinkedList() { this->head = NULL; }

void LinkedList::add(Component *value) {
  Node *node = new Node();
  node->data = value;
  node->next = head;
  head = node;
}

void LinkedList::delete_node(Node *node_before) {
  Node *temp = new Node();
  temp = node_before->next = temp->next;
  delete temp;
}

void LinkedList::to_string() {
  Node *temp = head;
  while (temp != NULL) {
    temp->get_data()->to_string();
    temp = temp->next;
  }
}