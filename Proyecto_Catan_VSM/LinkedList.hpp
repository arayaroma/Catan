#pragma once
#include "Component.hpp"
#include "Land.hpp"
#include "Node.hpp"
#include <iostream>
#include <string>

class LinkedList {
private:
  Node *head;

public:
  LinkedList();
  void add(Component *);
  void delete_node(Node *);

  void to_string();
  bool isEmpty() { return (this->head == NULL); }
};
