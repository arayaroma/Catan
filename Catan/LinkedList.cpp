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

bool LinkedList::isEmpty() { return (this->head == NULL); }

void LinkedList::printImage() {
  int top_height = 10; // primera,segunda,tercera
  int bot_height = 10; // ultima y penultima columna de hexagonos
  int cycle_cord_x = 0;
  Node *temp = head;

  bot_height += 295;
  for (cycle_cord_x = 470; cycle_cord_x <= 620; cycle_cord_x += 75) {
    temp->getData()->printHexagon(cycle_cord_x, top_height);
    temp = temp->next;
    temp->getData()->printHexagon(cycle_cord_x, bot_height);
    temp = temp->next;
  }

  top_height += 75;
  bot_height = 230;
  for (cycle_cord_x = 435; cycle_cord_x <= 695; cycle_cord_x += 75) {
    temp->getData()->printHexagon(cycle_cord_x, top_height);
    temp = temp->next;
    temp->getData()->printHexagon(cycle_cord_x, bot_height);
    temp = temp->next;
  }

  top_height += 75;
  for (cycle_cord_x = 400; cycle_cord_x <= 700; cycle_cord_x += 75) {
    temp->getData()->printHexagon(cycle_cord_x, top_height);
    temp = temp->next;
  }
}

void LinkedList::toString() {
  Node *temp = head;
  while (temp != NULL) {
    temp->getData()->toString();
    temp = temp->next;
  }
}