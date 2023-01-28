#include "Graph.hpp"
using namespace std;
Graph::Graph() {
  firstVertex = nullptr;
  this->size = NULL;
}

bool Graph::isEmpty() { return size == NULL; }

Vertex *Graph::getVertex(int id) {
  Vertex *auxVertex = firstVertex;
  while (auxVertex != nullptr) {
    if (auxVertex->getVertexId() == id) {
      return auxVertex;
    }
    auxVertex = auxVertex->next;
  }
  return nullptr;
}

int Graph::getVertexId(Vertex *auxVertex) { return auxVertex->getVertexId(); }

void Graph::vertexXY() {
  Vertex *auxVertex = firstVertex;
  while (auxVertex != nullptr) {
    cout << auxVertex->town->getPosX() << " " << auxVertex->town->getPosY()
         << endl;
    auxVertex = auxVertex->next;
  }
}

void Graph::insertVertex(Vertex *newVertex) {
  if (getVertex(newVertex->getVertexId()) == nullptr) {
    if (isEmpty()) {
      firstVertex = newVertex;
      firstVertex->next = nullptr;
    } else {
      Vertex *auxVertex = firstVertex;
      while (auxVertex->next != nullptr) {
        auxVertex = auxVertex->next;
      }
      auxVertex->next = newVertex;
    }
    size++;
  }
}



void Graph::insertEdge(int origin, int destiny) {
  Vertex *originVertex = getVertex(origin);
  Vertex *destinyVertex = getVertex(destiny);

  if (originVertex != nullptr && destinyVertex != nullptr) {
    Edge *newEdge = new Edge(destinyVertex);

    if (originVertex->firstEdge == nullptr) {
      originVertex->firstEdge = newEdge;
    } else {
      Edge *auxEdge = originVertex->firstEdge;
      while (auxEdge->next != nullptr) {
        auxEdge = auxEdge->next;
      }
      auxEdge->next = newEdge;
    }
  }
}

void Graph::showAdjacencyList() {
  Vertex *auxVertex = firstVertex;
  while (auxVertex != nullptr) {
    Edge *auxEdge = auxVertex->firstEdge;
    cout << auxVertex->getVertexId() << " PosX: " << auxVertex->getTown()->getPosX()
         << " PosY: " << auxVertex->getTown()->getPosY() << " = ";
    while (auxEdge != nullptr) {
      cout << auxVertex->getVertexId() << "->"
           << auxEdge->destinyVertex->getVertexId() << ",";
      auxEdge = auxEdge->next;
    }
    cout << endl;
    auxVertex = auxVertex->next;
  }
}

