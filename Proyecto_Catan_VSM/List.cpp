#include "List.h"

void List::add(LandNode* newLand) { // Inserta al final de la lista
    if (isEmpty()) {
        head = newLand;
        end = newLand;
    }
    else {
        end->setNext(newLand);
        newLand->setPrevious(end);
        end = newLand;
    }
}

bool List::deleteNode(LandNode* Node) {
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
void List::print() {
    LandNode* aux = head;
    while (aux != NULL) {
        aux->getInfo()->toString();
        aux = aux->getNext();
    }
}
bool List::isEmpty() { return (head == NULL); }
