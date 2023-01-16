#pragma once
#include "Materials.hpp"
#include "Node.hpp"
#include "ProgressCards.hpp"
#include <iostream>

template <typename T> class Stack {

public:
  Node<T> *head;
  Node<T> *end;

public:
  Stack() {
    this->head = nullptr;
    this->end = nullptr;
  }
  void push(T* data) {
    Node<T> *temp = new Node<T>(data);
    if (isEmpty()) {
      this->head = temp;
      this->end = temp;
      std::cout << "Agregado";
    }
    temp->setNext(head);
    head = temp;
  }
  T* pop() {
    Node<T> *temp = this->head;
    if (!isEmpty()) {
      head = head->getNext();
      temp->setNext(nullptr);
    }
    return temp->getData();
  }

  T* top() {
    if (isEmpty())
      return NULL;
    return this->head->getData();
  }

  bool isEmpty() { return (head == nullptr); }

  void print() {
    Node<T> *temp = head;
    while (temp != NULL) {
      temp->getData()->toString();
      temp = temp->getNext();
    }
  }
};
template class Stack<VictoryPoints>;
template class Stack<Knight>;
template class Stack<Progress>;
template class Stack<Clay>;
template class Stack<Mineral>;
template class Stack<Wheat>;
template class Stack<Wood>;
template class Stack<Wool>;
