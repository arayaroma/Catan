#include "Stack.hpp"

void Stack::push(Component *card) { // inserta el nodo al inicio de la lista
  aux = new CardNode(card);
  if (isEmpty()) {
    head = aux;
    end = aux;
  }
  aux->set_next(head);
  head = aux;
}

Component *Stack::pop() { // extrae el nodo del inicio. LIFO: Last In, First Out
                          // (Ultimo en entrar, primero en salir)
  aux = head;
  if (!isEmpty()) {
    head = head->get_next();
    aux->set_next(NULL);
  }
  return aux->get_data();
}

Component *Stack::top() {
  if (!isEmpty())
    return head->get_data();
  return head->get_data();
}

void Stack::print() {
  aux = head;
  while (aux != NULL) {
    // aux->get_data()->toString();
    aux = aux->get_next();
  }
}

bool Stack::isEmpty() { return (head == NULL); }