#pragma once
#include "Node.hpp"
#include <iostream>

template <typename T> class LinkedList {
public:
  Node<T> *head;

public:
  LinkedList() { this->head = nullptr; }

  void add(T data) {
    Node<T> *node = new Node<T>();
    node->data = data;
    node->next = head;
    head = node;
  }

  void delete_node(Node<T> *node_before) {
    Node<T> *temp = new Node<T>();
    temp = node_before->next = temp->next;
    delete temp;
  }

  bool isEmpty() { return (this->head == nullptr); }

  void printImage() {}

  void toString() {
    Node<T> *temp = head;
    while (temp != nullptr) {
      temp->getData()->toString();
      temp = temp->next;
    }
  }
};
