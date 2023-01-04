#include "Stack.h"
#include <cstddef>
void Stack::push(CardNode* n) {//inserta el nodo al inicio de la lista
	if (isEmpty()) {
		head = n;
		end = n;
	}
	else {
		n->setNext(head);
		head->setPrevious(n);
		head = n;
	}
}

Card* Stack::pop() {//extrae el nodo del inicio. LIFO: Last In, First Out (Ultimo en entrar, primero en salir)
	CardNode* aux = head;
	if (!isEmpty()) {
		head = head->getNext();
		if (head != NULL)
			head->setPrevious(NULL);
		aux->setNext(NULL);
	}
	else
		return NULL;
	return aux->getInfo();
}

Card* Stack::top() {
	if (!isEmpty())
		return head->getInfo();
	return NULL;
}
void Stack::print() {
	CardNode* aux = head;
	while (aux != NULL) {
		aux->getInfo()->toString();
		aux = aux->getNext();
	}
}
bool Stack::isEmpty() { return (head == NULL); }