#pragma once
#include "Node.hpp"
#include <iostream>

template <typename T> class LinkedList {
public:
  Node<T> *head;

public:
  LinkedList() { this->head = nullptr; }

  void add(T data) {
    Node<T> *temp = new Node<T>();
    temp->setData(data);
    temp->setNext(head);
    head = temp;
  }

  void delete_node(Node<T> *nodeBefore) {
    Node<T> *temp = new Node<T>();
    temp = nodeBefore->getNext() = temp->getNext();
    delete temp;
  }

  bool isEmpty() { return (this->head == nullptr); }

  void printImage() {}

  void toString() {
    Node<T> *temp = head;
    while (temp != nullptr) {
      temp->getData()->toString();
      temp = temp->getNext();
    }
  }
};
