#include "DataStructures.hpp"
using namespace std;

DataStructures::DataStructures() {
  lands = LinkedList<Land>();
  townFigures = LinkedList<Town>();
  cityFigures = LinkedList<City>();
  roadFigures = LinkedList<Road>();
   towns = LinkedList<int>();
}

void DataStructures::loadMaps() {
  loadProgressPaths();
  loadTilesPaths();
}

void DataStructures::loadSpecialCards() {
  um_Paths.insert(pair<const char *, const char *>(
      "biggestPath", "Images/extraCards/biggestPathCard.png"));
  um_Paths.insert(pair<const char *, const char *>(
      "biggestArmyPath", "Images/extraCards/biggestArmyCard.png"));
}

void DataStructures::loadProgressPaths() {
  um_Paths.insert(pair<const char *, const char *>(
      "knightPath", "Images/knightCards/knightCard"));

  um_Paths.insert(pair<const char *, const char *>(
      "progressPath", "Images/progressCards/progressCard"));

  um_Paths.insert(pair<const char *, const char *>(
      "victoryPointsPath", "Images/victoryPointsCards/victoryPointCard"));
}

void DataStructures::loadTilesPaths() {
  um_Paths.insert(
      pair<const char *, const char *>("grassPath", "Images/tiles/Grass.jpg"));
  um_Paths.insert(
      pair<const char *, const char *>("brickPath", "Images/tiles/Brick.jpg"));
  um_Paths.insert(
      pair<const char *, const char *>("fieldPath", "Images/tiles/Field.jpg"));

  um_Paths.insert(pair<const char *, const char *>(
      "mountainPath", "Images/tiles/Mountain.jpg"));
  um_Paths.insert(pair<const char *, const char *>("forestPath",
                                                   "Images/tiles/Forest.jpg"));
  um_Paths.insert(pair<const char *, const char *>("dessertPath",
                                                   "Images/tiles/Dessert.jpg"));
}

void DataStructures::loadLands() {
  loadTilesPaths();
  int i;
  int idLand = 1;
  for (i = 0; i < 4; i++) {
     if (i < 1) {
       lands.add(new Land("Dessert", um_Paths.at("dessertPath"), 0, 0, idLand));
       idLand++;
     }
    if (i < 3) {
      lands.add(new Land("Mountain", um_Paths.at("mountainPath"), 0, 0, idLand));
      idLand++;
      lands.add(new Land("Field", um_Paths.at("fieldPath"), 0, 0, idLand));
      idLand++;
    }
    lands.add(new Land("Grass", um_Paths.at("grassPath"), 0, 0, idLand));
    idLand++;
    lands.add(new Land("Forest", um_Paths.at("forestPath"), 0, 0, idLand));
    idLand++;
    lands.add(new Land("Brick", um_Paths.at("brickPath"), 0, 0, idLand));
    idLand++;
  }
  //lands.toString();
}

void DataStructures::loadStacks() {}

void DataStructures::makeSpecialCard() {
  specialCard[0] = new Progress("SpecialCard", um_Paths.at("biggestPath"));
  specialCard[1] = new Progress("SpecialCard", um_Paths.at("biggestArmyPath"));
}

void DataStructures::makeMaterialCard() {
  int i, numberOfCards = 19;
  for (i = 0; i < numberOfCards; i++) {
    woodCards->push(new Wood());
    woolCards->push(new Wool());
    wheatCards->push(new Wheat());
    clayCards->push(new Clay());
    mineralCards->push(new Mineral());
  }
}

void DataStructures::makeDevelopCard() {
  std::string knightPath, progressPath, victoryPointsPath;
  int i, num = 1, numberOfCards = 4;
  for (i = 0; i < numberOfCards; i++) {
    std::string stringNumber(std::to_string(num));

    // Poner .png
    knightPath = um_Paths.at("knightPath") + stringNumber;
    progressPath = um_Paths.at("progressPath") + stringNumber;
    victoryPointsPath = um_Paths.at("victoryPointsPath") + stringNumber;

    if (i < 2)
      progressCards->push(new Progress(progressPath));
    knightCards->push(new Knight(knightPath));
    victoryPointCards->push(new VictoryPoints(victoryPointsPath));

    num++;
  }
}

void DataStructures::makeFigures() {
  int i = 0;
  for (i = 0; i < 60; i++) {
    if (i < 16)
      cityFigures.add(new City("City", "12", 0, 0));
    if (i < 20)
      townFigures.add(new Town("Town", "Images/puebloX.png", 0, 0));

    roadFigures.add(new Road("Road", "12", 0, 0));
  }
}
void DataStructures::makeGraph() {
    int vertexId=1;
    int vertexJump = 4;
    Town* town = new Town("Town", "Images/puebloX.png", 0, 0);
    // <summary>
    /// SE CREAN LOS VERTICES
    /// </summary>
    for (vertexId = 1; vertexId < 55; vertexId++) {
        Vertex* vertex = new Vertex(vertexId, "", town);
        graph.insertVertex(vertex);
    }
    /// <summary>
    /// SE CREAN CONEXIONES ENTRE VERTICES CON ARISTAS
    /// </summary>
    /// 
    
    for (vertexId = 1; vertexId < 4; vertexId++) {
        graph.insertEdge(vertexId,vertexJump + vertexId);
        graph.insertEdge(vertexId, vertexId + vertexJump -1);
    }
    for (vertexId = 4; vertexId < 8; vertexId++) {
        graph.insertEdge(vertexId, vertexId + vertexJump);
    }
    for (vertexId = 8; vertexId < 12; vertexId++) {
        graph.insertEdge(vertexId, vertexId + vertexJump );
        graph.insertEdge(vertexId, vertexId + vertexJump + 1);
    }
    vertexJump++; ////==5
    for (vertexId = 12; vertexId < 17; vertexId++) {
        graph.insertEdge(vertexId, vertexId + vertexJump);
    }
    for (vertexId = 17; vertexId < 22; vertexId++) {
        graph.insertEdge(vertexId, vertexId + vertexJump);
        graph.insertEdge(vertexId, vertexId + vertexJump + 1);
    }
    vertexJump++;////==6
    for (vertexId = 22; vertexId < 28; vertexId++) {
        graph.insertEdge(vertexId, vertexId + vertexJump);
    }
    vertexJump--;////==5
    for (vertexId = 28; vertexId < 34; vertexId++) {
        if (vertexId == 28) {
            graph.insertEdge(vertexId, vertexId + vertexJump+1);
        }
        else if (vertexId == 33) {
            graph.insertEdge(vertexId, vertexId + vertexJump);
        }
        else {
            graph.insertEdge(vertexId, vertexId + vertexJump);
            graph.insertEdge(vertexId, vertexId + vertexJump - 1);
        }
    }
    for (vertexId = 34; vertexId < 39; vertexId++) {
        graph.insertEdge(vertexId, vertexId + vertexJump);
    }
    for (vertexId = 39; vertexId < 44; vertexId++) {
        if (vertexId == 39) {
            graph.insertEdge(vertexId, vertexId + vertexJump);
        }
        else if (vertexId == 43) {
            graph.insertEdge(vertexId, vertexId + vertexJump-1);
        }
        else {
            graph.insertEdge(vertexId, vertexId + vertexJump);
            graph.insertEdge(vertexId, vertexId + vertexJump - 1);
        }
    }
    for (vertexId = 44; vertexId < 48; vertexId++) {
        graph.insertEdge(vertexId, vertexId + vertexJump-1);
    }
    vertexJump--;////==3
    for (vertexId = 48; vertexId < 52; vertexId++) {
        if (vertexId == 48) {
            graph.insertEdge(vertexId, vertexId + vertexJump );
        }
        else if (vertexId == 52) {
            graph.insertEdge(vertexId, vertexId + vertexJump);
        }
        else {
            graph.insertEdge(vertexId, vertexId + vertexJump);
            graph.insertEdge(vertexId, vertexId + vertexJump - 1);
        }

    }
    //graph.showListAdjacency();
}


void DataStructures::assignTownsToLand() {
    Node<Land>* temp = lands.head;
    int contLands = 1;
    int idVertex = 1, endVertex = 10, sumId = 3;
    while (contLands <4) {
        assignTowns(temp, idVertex, endVertex, sumId);
        temp = temp->getNext();
        idVertex++, endVertex++;
        contLands++;
    }
    sumId++,contLands = 1;
    idVertex = 8, endVertex = 19;
    while (contLands < 5) {
        assignTowns(temp, idVertex, endVertex, sumId);
        temp = temp->getNext();
        idVertex++, endVertex++;
        contLands++;
    }
    
    sumId++, contLands = 1;
    idVertex = 17, endVertex = 30;
    while (contLands < 6) {
        assignTownsMiddleRow(temp, idVertex, endVertex, sumId);
        temp = temp->getNext();
        idVertex++, endVertex++;
        contLands++;
    }
    contLands = 1; idVertex = 29, endVertex = 41;
    while (contLands < 5) {
        assignTownsLastRows(temp, idVertex, endVertex, sumId );
        temp = temp->getNext();
        idVertex++, endVertex++;
        contLands++;
    }
    sumId=4;
    contLands = 1; idVertex = 40, endVertex = 50;
    while (contLands < 4) {
        assignTownsLastRows(temp, idVertex,  endVertex, sumId );
        temp = temp->getNext();
        idVertex++,  endVertex++;
        contLands++;
    }
}
void DataStructures::assignTowns(Node<Land>* temp, int idVertex, int endVertex, int sumId) {
    int conditional = 0;
    int firstVertex = idVertex;
    Town* town = new Town("Town", "Images/puebloX.png", 0, 0);
    for (idVertex = firstVertex; idVertex < endVertex; idVertex += sumId+1) {
        if (conditional != 2) {
            temp->getData()->towns.add(new Vertex(idVertex, "", town));
            temp->getData()->towns.add(new Vertex(idVertex + sumId, "", town));
            conditional++;
        }
        else {
            temp->getData()->towns.add(new Vertex(idVertex, "", town));
            temp->getData()->towns.add(new Vertex(idVertex + sumId + 1, "", town));
        }
    }
    temp->getData()->towns.toString();
    cout << endl;
}
void DataStructures::assignTownsMiddleRow(Node<Land>* temp, int idVertex, int endVertex, int sumId) {
    int firstVertex = idVertex;
    Town* town = new Town("Town", "Images/puebloX.png", 0, 0);
    for (idVertex = firstVertex; idVertex < endVertex; idVertex += sumId+1) {
        temp->getData()->towns.add(new Vertex(idVertex, "", town));
        temp->getData()->towns.add(new Vertex(idVertex + sumId, "", town));
    }
    temp->getData()->towns.toString();
    cout << endl;
}
void DataStructures::assignTownsLastRows(Node<Land>* temp, int idVertex, int endVertex, int sumId) {
    int conditional = 0;
    int firstVertex = idVertex;
    Town* town = new Town("Town", "Images/puebloX.png", 0, 0);
    for (idVertex = firstVertex; idVertex < endVertex; idVertex += sumId+1) {
        if (conditional == 0) {
            temp->getData()->towns.add(new Vertex(idVertex, "", town));
            temp->getData()->towns.add(new Vertex(idVertex + sumId , "", town));
        }
        else {
            temp->getData()->towns.add(new Vertex(idVertex, "", town));
            temp->getData()->towns.add(new Vertex(idVertex + sumId-1, "", town));
            conditional++;
        }
    }
    temp->getData()->towns.toString();
    cout << endl;
}