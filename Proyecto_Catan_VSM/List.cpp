#include "List.h"
template<typename T>
List<T>::List(){}

template<typename T>
void List<T>::add(T& newLand) { // Inserta al final de la lista
    aux = new Node<T>(newLand);
    if (isEmpty()) {
        head = aux;
        end = aux;
    }
    else {
        end->setNext(aux);
        aux->setPrevious(end);
        end = aux;
    }
}

template<typename T>
bool List<T>::deleteNode(T& Node) {
    if (!isEmpty()) {
        // buscar el nodo
        aux = head;
        while (aux != NULL && aux != Node)
            aux = aux->getNext();
        if (aux != NULL) { // si encontró el nodo
            if (aux != head)
                aux->getPrevious()->setNext(aux->getNext());
            else
                head = aux->getNext();
            if (aux != end)
                aux->getNext()->setPrevious(
                    aux->getPrevious()); // conecta el siguiente con el anterior
            else
                end = aux->getPrevious();
            delete aux;
            return true;
        }
        else
            return false;
    }
    return false;
}
template<typename T>
void List<T>::print() {
     aux = head;
    while (aux != NULL) {
        aux->getInfo()->toString();
        aux = aux->getNext();
    }
}

template<typename T>
bool List<T>::isEmpty() { return (head == NULL); }
