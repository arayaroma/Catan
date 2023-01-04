#include "Node.h"
template<typename T> Node<T>::Node(){}
template<typename T> Node<T>::Node(T& info) { this.info = info; }
 template<typename T> void Node<T>::setNext(T& nextNode) { next = nextNode; }
 template<typename T> T Node<T>::getNext() { return next; }
 template<typename T> void Node<T>::setPrevious(T& previousNode) { previous = previousNode; }
 template<typename T> T  Node<T>::getPrevious() { return previous; }
 template<typename T> void Node<T>::setInfo(T& info) { info = info; }
 template<typename T> T Node<T>::getInfo() { return info; }
