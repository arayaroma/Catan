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

void LinkedList::printImage() {
    int x = 345;//primera,segunda,tercera
    int x1 = 345;//ultima y penultima columna de hexagonos
    Node* temp = head;
            x1 += 180;
            for (int q = 100; q <= 200; q += 50) {
                temp->get_data()->printHexagon(x, q);
                temp = temp->next;
                temp->get_data()->printHexagon(x1, q);
                temp = temp->next;
            }
            x += 45;
            x1 = 480;
            for (int w = 75; w <= 225; w += 50) {
                temp->get_data()->printHexagon(x, w);
                temp = temp->next;
                temp->get_data()->printHexagon(x1, w);
                temp = temp->next;
            }
            x += 45;
            for (int d = 50; d <= 250; d += 50) {
                temp->get_data()->printHexagon(x, d);
               temp = temp->next;
            }
    
}

void LinkedList::to_string() {
  Node *temp = head;
  while (temp != NULL) {
    temp->get_data()->toString();
    temp = temp->next;
  }
}