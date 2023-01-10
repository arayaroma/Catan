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

  bool isEmpty();
  void printImage();
  void printTown();
  void toString();
};
