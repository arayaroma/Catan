#include "Graph.hpp"
using namespace std;
Graph::Graph() {
	firstVertex = nullptr;
	this->size = 0;
}

bool Graph::isEmpty() {
	return size == 0;
}

Vertex* Graph::getVertex(int id) {
	Vertex* auxVertex = firstVertex;
	while (auxVertex != nullptr) {
		if (auxVertex->idVertex == id)
			return auxVertex;
		auxVertex = auxVertex->next;
	}
	return nullptr;
}

int Graph::getIdVertex(Vertex* auxVertex) {
	return auxVertex->idVertex;
}
void Graph::vertexXY() {
	Vertex* auxVertex = firstVertex;
	while (auxVertex != nullptr) {
		cout << auxVertex->town->getPosX() << " " << auxVertex->town->getPosY() << endl;
		auxVertex = auxVertex->next;
	}
}

void Graph::insertVertex(Vertex* newVertex) {
	if (getVertex(newVertex->idVertex) == nullptr) {
		if (isEmpty()) {
			firstVertex = newVertex;
			firstVertex->next = nullptr;
		}
		else {
			Vertex* auxVertex = firstVertex;
			while (auxVertex->next != nullptr) {
				auxVertex = auxVertex->next;
			}
			auxVertex->next = newVertex;
		}
		size++;
	}
	
}

void Graph::insertOwnerHexagon(int id, int vecOwners[]) {
	Vertex* vertex = getVertex(id);
	if (vertex != nullptr){
		for (int i = 0; i < 3; i++) {
			vertex->ownerHexagon[i] = vecOwners[i];
		}
	}
}

void  Graph::insertEdge(int origin, int destiny){
	Vertex* originVertex = getVertex(origin);
	Vertex* destinyVertex = getVertex(destiny);

	if (originVertex == nullptr)
		cout << " El Vertex origen no existe " << endl;

	if (destinyVertex == nullptr)
		cout << " El Vertex destino no existe " << endl;

	if (originVertex != nullptr && destinyVertex != nullptr){
		Edge* newEdge = new  Edge(destinyVertex);

		if (originVertex->firstEdge == nullptr) {
			originVertex->firstEdge = newEdge;
		}
		else {
			Edge* auxEdge = originVertex->firstEdge;
			while (auxEdge->next != nullptr) {
				auxEdge = auxEdge->next;
			}
			auxEdge->next = newEdge;

		}
	}
}

void Graph::showListAdjacency() {
	Vertex* auxVertex = firstVertex;
	while (auxVertex != nullptr){
		Edge* auxEdge = auxVertex->firstEdge;
		cout << auxVertex->idVertex << " = ";
		while (auxEdge != nullptr){
			cout << auxVertex->idVertex << "->" << auxEdge->destinyVertex->idVertex << ",";
			auxEdge = auxEdge->next;
		}
		cout << endl;
		auxVertex = auxVertex->next;
	}
}
