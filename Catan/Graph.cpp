#include "Graph.h"
using namespace std;
Graph::Graph() {
	firstVertex = NULL;
	this->size = 0;
}
bool Graph::isEmpty() {
	return size == 0;
}
Vertex* Graph::getVertex(int id) {
	Vertex* auxVertex = firstVertex;
	while (auxVertex != NULL) {
		if (auxVertex->idVertex == id)
			return auxVertex;
		auxVertex = auxVertex->next;
	}
	return NULL;
}
int Graph::getIdVertex(Vertex* auxVertex) {
	return auxVertex->idVertex;
}
void Graph::vertexXY() {
	Vertex* auxVertex = firstVertex;
	while (auxVertex != NULL) {
		cout<<auxVertex->town->getPosX() << " " << auxVertex->town->getPosY() << endl;
		auxVertex = auxVertex->next;
	}
}
void  Graph::insertVertex(Vertex* newVertex)
{
	if (getVertex(newVertex->idVertex) == NULL)
	{
		if (isEmpty()) {
			firstVertex = newVertex;
			firstVertex->next = NULL;
		}
		else {
			Vertex* auxVertex = firstVertex;
			while (auxVertex->next != NULL) {
				auxVertex = auxVertex->next;
			}
			auxVertex->next = newVertex;
		}
		size++;
	}
	else {
		cout << " Ese Vertex ya existe en el Graph " << endl;
	}
		
}
void Graph::insertOwnerHexagon(int id, int vecOwners[]) {
	Vertex* vertex = getVertex(id);
	if (vertex != NULL)
	{
		for (int i = 0; i < 3; i++) {
			vertex->ownerHexagon[i] = vecOwners[i];
		}
	}
}
void  Graph::insertEdge(int origin, int destiny)
{
	Vertex* originVertex = getVertex(origin);
	Vertex* destinyVertex = getVertex(destiny);

	if(originVertex == NULL)
		cout << " El Vertex origen no existe " << endl;

	if(destinyVertex == NULL)
		cout << " El Vertex destino no existe " << endl;

	if (originVertex != NULL && destinyVertex != NULL)
	{
		Edge* newEdge = new  Edge(destinyVertex);

		if (originVertex->firstEdge == NULL) {
			originVertex->firstEdge = newEdge;
		}
		else {
			Edge* auxEdge = originVertex->firstEdge;
			while (auxEdge->next != NULL) {
				auxEdge = auxEdge->next;
			}
			auxEdge->next = newEdge;
			
		}
	}
}
void Graph::showListAdjacency(){
	Vertex* auxVertex = firstVertex;
	while (auxVertex != NULL)
	{
		Edge* auxEdge = auxVertex->firstEdge;
		cout << auxVertex->idVertex << " = ";
		while (auxEdge != NULL)
		{
			cout << auxVertex->idVertex << "->"<< auxEdge->destinyVertex->idVertex << ",";
			auxEdge = auxEdge->next;
		}
		cout << endl;
		auxVertex = auxVertex->next;
	}
}
