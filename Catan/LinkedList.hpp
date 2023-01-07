#pragma once
#include "Component.hpp"
#include "Node.hpp"

class LinkedList {
private:
  Node *head;

public:
  LinkedList();
  void add(Component *);
  void delete_node(Node *);
  void printImage();
  void to_string();
  bool isEmpty() { return (this->head == NULL); }
};
