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
    int x = 10;//primera,segunda,tercera
    int x1 = 10;//ultima y penultima columna de hexagonos
    Node* temp = head;
            x1 += 295;
            for (int q = 450; q <= 600; q += 75) {
                temp->get_data()->printHexagon(q, x);
                temp = temp->next;
                temp->get_data()->printHexagon(q,x1);
                temp = temp->next;
            }
            x += 75;
            x1 = 230;
            for (int w = 425; w <= 675; w += 75) {
                temp->get_data()->printHexagon(w, x);
                temp = temp->next;
                temp->get_data()->printHexagon(w, x1);
                temp = temp->next;
            }
            x += 75;
            for (int d = 400; d <= 700; d += 75) {
                temp->get_data()->printHexagon(d, x);
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