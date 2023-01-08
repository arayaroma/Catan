#include "Node.hpp"

Node::Node() {
  this->data = NULL;
  this->next = NULL;
}

Node::Node(Component *data) {
  this->data = data;
  this->next = NULL;
}

void Node::setData(Component *data) { this->data = data; }
Component *Node::getData() { return this->data; }

void Node::setNext(Node *next) { this->next = next; }
Node *Node::getNext() { return this->next; }
