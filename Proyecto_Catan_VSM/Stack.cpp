#include "Stack.h"
#include <cstddef>

template<typename T>
void Stack<T>::push(T& newData) {//inserta el nodo al inicio de la lista
	aux = new Node<T>(newData);
	if (isEmpty()) {
		head = aux;
		end = aux;
	}
	else {
		aux->setNext(head);
		head->setPrevious(aux);
		head = aux;
	}
}

template<typename T>
T& Stack<T>::pop() {//extrae el nodo del inicio. LIFO: Last In, First Out (Ultimo en entrar, primero en salir)
	 aux = head;
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

template<typename T>
T& Stack<T>::top() {
	if (!isEmpty())
		return head->getInfo();
	return NULL;
}

template<typename T>
void Stack<T>::print() {
	aux = head;
	while (aux != NULL) {
		aux->getInfo()->toString();
		aux = aux->getNext();
	}
}

template<typename T>
bool Stack<T>::isEmpty() { return (head == NULL); }