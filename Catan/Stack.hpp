#pragma once
#include "Node.hpp"
#include <iostream>

class Stack {
private:
  Component *data;
  Node *aux;
  Node *head;
  Node *end;

public:
  Stack();
  void push(Component *);
  Component *pop();
  Component *top();

  bool isEmpty();
  void print();
};
