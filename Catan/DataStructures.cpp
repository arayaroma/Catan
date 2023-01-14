#include "DataStructures.hpp"
using namespace std;

DataStructures::DataStructures() {
  lands = LinkedList<Land>();
  townFigures = LinkedList<Town>();
  cityFigures = LinkedList<City>();
  roadFigures = LinkedList<Road>();
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
  for (i = 0; i < 4; i++) {
    if (i < 1)
      lands.add(Land("Dessert", um_Paths.at("dessertPath"), 0, 0));
    if (i < 3) {
      lands.add(Land("Mountain", um_Paths.at("mountainPath"), 0, 0));
      lands.add(Land("Field", um_Paths.at("fieldPath"), 0, 0));
    }
    lands.add(Land("Grass", um_Paths.at("grassPath"), 0, 0));
    lands.add(Land("Forest", um_Paths.at("forestPath"), 0, 0));
    lands.add(Land("Brick", um_Paths.at("brickPath"), 0, 0));
  }
}

void DataStructures::loadStacks() {}

void DataStructures::makeSpecialCard() {
  specialCard[0] = new Progress("SpecialCard", um_Paths.at("biggestPath"));
  specialCard[1] = new Progress("SpecialCard", um_Paths.at("biggestArmyPath"));
}

void DataStructures::makeMaterialCard() {
  int i, numberOfCards = 19;
  for (i = 0; i < numberOfCards; i++) {
    woodCards->push(Wood());
    woolCards->push(Wool());
    wheatCards->push(Wheat());
    clayCards->push(Clay());
    mineralCards->push(Mineral());
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
      progressCards->push(Progress(progressPath));
    knightCards->push(Knight(knightPath));
    victoryPointCards->push(VictoryPoints(victoryPointsPath));

    num++;
  }
}

void DataStructures::makeFigures() {
  int i = 0;
  for (i = 0; i < 60; i++) {
    if (i < 16)
      cityFigures.add(City("City", "12", 0, 0));
    if (i < 20)
      townFigures.add(Town("Town", "Images/puebloX.png", 0, 0));

    roadFigures.add(Road("Road", "12", 0, 0));
  }
}
void DataStructures::makeGraph() {
    int vertexId=1;
    int vertexJump = 4;
    Town* town = new Town("Town", "Images/puebloX.png", 0, 0);
    /// <summary>
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
    /*
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

    }*/
    graph.showListAdjacency();
}
void DataStructures::makeVertexOwners() {

}