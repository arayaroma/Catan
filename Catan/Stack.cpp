#include "Stack.hpp"

Stack::Stack() {

  this->aux = NULL;
  this->data = NULL;
  this->end = NULL;
  this->head = NULL;
}
void Stack::push(Component *card) { // inserta el nodo al inicio de la lista
  Node *aux1 = new Node(card);
  if (isEmpty()) {
    head = aux1;
    end = aux1;
    std::cout << "Agregado";
  } else {

    aux1->setNext(head);
    head = aux1;
  }
}

Component *Stack::pop() { // extrae el nodo del inicio. LIFO: Last In, First Out
                          // (Ultimo en entrar, primero en salir)
  Node *aux1 = head;
  if (!isEmpty()) {
    head = head->getNext();
    aux1->setNext(NULL);
  }
  return aux1->getData();
}

Component *Stack::top() {
  if (!isEmpty())
    return head->getData();
  return NULL;
}

void Stack::print() {

  Node *aux1 = head;

  while (aux1 != NULL) {
    aux1->getData()->toString();
    aux1 = aux1->getNext();
  }
}

bool Stack::isEmpty() { return (head == NULL); }