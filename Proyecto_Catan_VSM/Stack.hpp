#pragma once
#include "Card.hpp"
#include "CardNode.hpp"
#include <iostream>

class Stack {
private:
  Component *data;
  CardNode *aux;
  CardNode *head;
  CardNode *end;

public:
  void push(Component *);
  Component *pop();
  Component *top();

  bool isEmpty();
  void print();
};
