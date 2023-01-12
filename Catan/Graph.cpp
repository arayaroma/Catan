#include "Graph.h"
using namespace std;
Graph::Graph() {
	firstVertex = NULL;
	int size = 0;
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
void  Graph::insertVertex(Vertex* newVertex)
{
	if (getVertex(newVertex->idVertex) == NULL)
	{
		if(isEmpty())
			firstVertex = newVertex;
		
		Vertex* auxVertex = firstVertex;
		while (auxVertex->next != NULL)
				auxVertex = auxVertex->next;

		auxVertex->next = firstVertex;

		size++;
	}
	else {
		cout << " Ese Vertex ya existe en el Graph " << endl;
	}
		
}

void  Graph::insertEdge(Vertex* originVertex, Vertex* destinyVertex)
{
	getVertex(originVertex->idVertex);
	getVertex(destinyVertex->idVertex);

	if(originVertex == NULL)
		cout << " El Vertex origen no existe " << endl;

	if(destinyVertex == NULL)
		cout << " El Vertex destino no existe " << endl;

	if (originVertex != NULL && destinyVertex != NULL)
	{
		Edge* newEdge = new  Edge(destinyVertex);

		if(originVertex->firstEdge == NULL)
			originVertex->firstEdge = newEdge;
		
		Edge* auxEdge = originVertex->firstEdge;
		while (auxEdge->next != NULL){
			auxEdge = auxEdge->next;
			auxEdge->next = newEdge;
		}
	}
}
