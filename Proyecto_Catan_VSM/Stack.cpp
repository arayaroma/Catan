#include "Stack.hpp"

Stack::Stack() {

    this->aux = NULL; 
    this->data = NULL; 
    this->end = NULL; 
    this->head = NULL; 
}
void Stack::push(Component *card) { // inserta el nodo al inicio de la lista
 Node* aux1 = new Node(card);
  if (isEmpty()) {
    head = aux1;
    end = aux1;
    std::cout << "Agregado";
  }
  else {

      aux1->set_next(head);
      head = aux1;
  }

}

Component *Stack::pop() { // extrae el nodo del inicio. LIFO: Last In, First Out
                          // (Ultimo en entrar, primero en salir)
 Node* aux1 = head;
  if (!isEmpty()) {
    head = head->get_next();
    aux1->set_next(NULL);
  }
  return aux1->get_data();
}

Component *Stack::top() {
  if (!isEmpty())
    return head->get_data();
  return NULL;
}

void Stack::print() {
  
  Node* aux1 = head;
  
  while (aux1 != NULL) {
      aux1->get_data()->toString();
      aux1 = aux1->get_next();
   
  }
}

bool Stack::isEmpty() { return (head == NULL); }