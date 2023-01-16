#pragma once
#include "Figures.hpp"
#include "Materials.hpp"
#include "ProgressCards.hpp"
#include "Vertex.hpp"
template <typename T> class Node {

public:
  T* data;
  Node *next;
  Node* headerTown;

public:
  Node() {
    this->data = nullptr;
    this->next = nullptr;
    this->headerTown = nullptr;
  }

  Node(T* data) {
    this->data = data;
    this->next = nullptr;
    this->headerTown = nullptr;
  }

  void setNext(Node *next) { this->next = next; }
  Node *getNext() const { return this->next; }

  void setHeaderTown(Node* header) { this->headerTown = header; }
  Node* getHeaderTown() const { return this->headerTown; }

  void setData(T* data) { this->data = data; }
  T* getData()  { return this->data; }
};

template class Node<VictoryPoints>;
template class Node<Knight>;
template class Node<Progress>;

template class Node<Clay>;
template class Node<Mineral>;
template class Node<Wheat>;
template class Node<Wood>;
template class Node<Wool>;

template class Node<City>;
template class Node<Town>;
template class Node<Road>;
template class Node<Vertex>;