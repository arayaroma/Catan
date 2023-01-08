#pragma once
#include "Component.hpp"

class Node {
private:
public:
  Component *data;
  Node *next;

  Node();
  Node(Component *);

  Node *getNext();
  void setNext(Node *);

  Component *getData();
  void setData(Component *);
};
