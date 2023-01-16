#pragma once
#include "Node.hpp"
#include <iostream>

template <typename T> class LinkedList {
public:
  Node<T> *head;
  Node<T>* headTowns;
public:
    LinkedList() { this->head = nullptr; this->headTowns = nullptr; }

  void add(T* data) {
    Node<T> *temp = new Node<T>();
    Node<T>* tempAux = new Node<T>();
    temp->setData(data);
    temp->next = NULL;
    if (head != nullptr) {
        tempAux = head;
        while (tempAux->getNext() != nullptr) {
            tempAux = tempAux->getNext();
        }
        tempAux->next = temp;
    }
    else {
        head = temp;
    }
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
  void printIdVertex() {

      int id = 0;
      Node<T>* temp = head;
      while (temp != nullptr) {
          id = temp->getData();
          std::cout << id << std::endl;
          temp = temp->getNext();
      }
  }
  void print() {
      Node<T>* temp = head;
      std::cout << "holaqqqq" << std::endl;
      while (temp != nullptr) {
          std::cout << "hola" << std::endl;
          std::cout<<temp->getData()<< std::endl;
          temp = temp->getNext();
      }
  }
  int size() {
      int size=0;
      Node<T>* temp = head;
      while (temp != NULL) {
          size++;
          temp = temp->getNext();
      }
      std::cout << "SIZE: ";
      return size;
  }
};
