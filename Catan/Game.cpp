#include "Game.hpp"
using std::pair;

Game::Game() {
    townsList = new list<Town*>();
    players = new list<Player*>();
    citiesList = new list<City*>();
    roadsList = new list<Road*>();
    landsList = new list<Land*>();
    loadMaps();
}

void Game::loadMaps() {
  loadProgressPaths();
  loadTilesPaths();
}

void Game::loadSpecialCards() {
  imagePaths.insert(pair<string,string>(
      "biggestPath", "Images/extraCards/biggestPathCard.png"));
  imagePaths.insert(pair<string,string>(
      "biggestArmyPath", "Images/extraCards/biggestArmyCard.png"));
}
void Game::loadProgressPaths() {
  imagePaths.insert(
      pair<string,string>("knightPath", "Images/knightCards/knightCard"));

  imagePaths.insert(pair<string,string>("progressPath",
                                         "Images/progressCards/progressCard"));

  imagePaths.insert(pair<string,string>(
      "victoryPointsPath", "Images/victoryPointsCards/victoryPointCard"));
}

void Game::loadTilesPaths() {
  imagePaths.insert(
      pair<string,string>("grassPath", "Images/tiles/Grass.jpg"));
  imagePaths.insert(
      pair<string,string>("brickPath", "Images/tiles/Brick.jpg"));
  imagePaths.insert(
      pair<string,string>("fieldPath", "Images/tiles/Field.jpg"));

  imagePaths.insert(
      pair<string,string>("mountainPath", "Images/tiles/Mountain.jpg"));

  imagePaths.insert(
      pair<string,string>("forestPath", "Images/tiles/Forest.jpg"));

  imagePaths.insert(
      pair<string,string>("dessertPath", "Images/tiles/Dessert.jpg"));
}

void Game::loadLands() {
  loadTilesPaths();
  int i;
  int landId = 1;
  for (i = 0; i < 4; i++) {
    if (i < 1) {
      landsList->push_front(
          new Land( imagePaths.at("dessertPath"), 0, 0, landId));
      landId++;
    }
    if (i < 3) {
      landsList->push_front(
          new Land( imagePaths.at("mountainPath"), 0, 0, landId));
      landId++;
      landsList->push_front(new Land(imagePaths.at("fieldPath"), 0, 0, landId));
      landId++;
    }
    landsList->push_front(new Land( imagePaths.at("grassPath"), 0, 0, landId));
    landId++;
    landsList->push_front(new Land( imagePaths.at("forestPath"), 0, 0, landId));
    landId++;
    landsList->push_front(new Land( imagePaths.at("brickPath"), 0, 0, landId));
    landId++;
  }
}

void Game::loadStacks() {}

void Game::makeSpecialCard() {
  specialCard = new Progress( imagePaths.at("biggestPath"));
  specialCard = new Progress( imagePaths.at("biggestArmyPath"));
}

void Game::makeMaterialCard() {
  int i, numberOfCards = 19;
  for (i = 0; i < numberOfCards; i++) {
    woodCards->push(new Wood());
    woolCards->push(new Wool());
    wheatCards->push(new Wheat());
    clayCards->push(new Clay());
    mineralCards->push(new Mineral());
  }
}

void Game::makeDevelopCard() {
  std::string knightPath, progressPath, victoryPointsPath;
  int i, num = 1, numberOfCards = 4;
  for (i = 0; i < numberOfCards; i++) {
    string stringNumber(std::to_string(num));

    if (i < 2) {
      progressCards->push(new Progress(progressPath));
      knightCards->push(new Knight(knightPath));
      victoryPointCards->push(new VictoryPoints(victoryPointsPath));
    }

    num++;
    // Poner png
    knightPath = imagePaths.at("knightPath") + stringNumber;
    progressPath = imagePaths.at("progressPath") + stringNumber;
    victoryPointsPath = imagePaths.at("victoryPointsPath") + stringNumber;
  }
}

void Game::makeFigures() {
  int i = 0;
  for (i = 0; i < 60; i++) {
    if (i < 16)
      citiesList->push_front(new City());
    if (i < 20)
      townsList->push_front(new Town());
    roadsList->push_front(new Road());
  }
}

void Game::makeGraph() {
  int vertexId = 1;
  int vertexJump = 4;
  Town *town = new Town();

  // SE CREAN LOS VERTICES
  for (vertexId = 1; vertexId < 55; vertexId++) {
    Vertex *vertex = new Vertex(vertexId, "", town);
    graph.insertVertex(vertex);
  }

  // SE CREAN CONEXIONES ENTRE VERTICES CON ARISTAS
  for (vertexId = 1; vertexId < 4; vertexId++) {
    graph.insertEdge(vertexId, vertexJump + vertexId);
    graph.insertEdge(vertexId, vertexId + vertexJump - 1);
  }
  for (vertexId = 4; vertexId < 8; vertexId++) {
    graph.insertEdge(vertexId, vertexId + vertexJump);
  }
  for (vertexId = 8; vertexId < 12; vertexId++) {
    graph.insertEdge(vertexId, vertexId + vertexJump);
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
  vertexJump++; ////==6
  for (vertexId = 22; vertexId < 28; vertexId++) {
    graph.insertEdge(vertexId, vertexId + vertexJump);
  }
  vertexJump--; ////==5
  for (vertexId = 28; vertexId < 34; vertexId++) {
    if (vertexId == 28) {
      graph.insertEdge(vertexId, vertexId + vertexJump + 1);
    } else if (vertexId == 33) {
      graph.insertEdge(vertexId, vertexId + vertexJump);
    } else {
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
    } else if (vertexId == 43) {
      graph.insertEdge(vertexId, vertexId + vertexJump - 1);
    } else {
      graph.insertEdge(vertexId, vertexId + vertexJump);
      graph.insertEdge(vertexId, vertexId + vertexJump - 1);
    }
  }
  for (vertexId = 44; vertexId < 48; vertexId++) {
    graph.insertEdge(vertexId, vertexId + vertexJump - 1);
  }
  vertexJump--; ////==3
  for (vertexId = 48; vertexId < 52; vertexId++) {
    if (vertexId == 48) {
      graph.insertEdge(vertexId, vertexId + vertexJump);
    } else if (vertexId == 52) {
      graph.insertEdge(vertexId, vertexId + vertexJump);
    } else {
      graph.insertEdge(vertexId, vertexId + vertexJump);
      graph.insertEdge(vertexId, vertexId + vertexJump - 1);
    }
  }
  // graph.showListAdjacency();
}
void Game::makeVertexOwners() {}

void Game::assignTownsToLand() {
  int contLands = 1, idVertex = 1, endVertex = 10, sumId = 3;
  landIterator = landsList->begin();
  while (contLands < 4) {
    assignTowns(*landIterator, idVertex, endVertex, sumId);
    idVertex++, endVertex++,contLands++,landIterator++;
  }
  sumId++, contLands = 1,idVertex = 8, endVertex = 19;
  while (contLands < 5) {
    assignTowns(*landIterator, idVertex, endVertex, sumId);
    idVertex++, endVertex++,contLands++ , landIterator++;
  }

  sumId++, contLands = 1,idVertex = 17, endVertex = 30;
  while (contLands < 6) {
    assignTownsMiddleRow(*landIterator, idVertex, endVertex, sumId);
    idVertex++, endVertex++,contLands++, landIterator++;
  }
  contLands = 1,idVertex = 29, endVertex = 41;
  while (contLands < 5) {
    assignTownsLastRows(*landIterator, idVertex, endVertex, sumId);
    idVertex++, endVertex++,contLands++, landIterator++;
  }
  sumId = 4,contLands = 1,idVertex = 40, endVertex = 50;
  while (contLands < 4) {
    assignTownsLastRows(*landIterator, idVertex, endVertex, sumId);
    idVertex++, endVertex++,contLands++, landIterator++;
  }
}
void Game::assignTowns(Land *temp, int idVertex, int endVertex, int sumId) {
  int conditional = 0, firstVertex = idVertex;
  Town *town = new Town();
  for (idVertex = firstVertex; idVertex < endVertex; idVertex += sumId + 1) {
    if (conditional < 2) {
      temp->townsList.push_front(new Vertex(idVertex, "", town));//aca se cae
      temp->townsList.push_front(new Vertex(idVertex + sumId, "", town));
      conditional++;
    } else {
      temp->townsList.push_front(new Vertex(idVertex, "", town));
      temp->townsList.push_front(new Vertex(idVertex + sumId + 1, "", town));
    }
  }
}
void Game::assignTownsMiddleRow(Land *temp, int idVertex, int endVertex,int sumId) {
  int firstVertex = idVertex;
  Town *town = new Town();
  for (idVertex = firstVertex; idVertex < endVertex; idVertex += sumId + 1) {
    temp->townsList.push_front(new Vertex(idVertex, "", town));
    temp->townsList.push_front(new Vertex(idVertex + sumId, "", town));
  }
  // Show List
}

void Game::assignTownsLastRows(Land *temp, int idVertex, int endVertex,int sumId) {
  int conditional = 0,firstVertex = idVertex;
  Town *town = new Town();
  for (idVertex = firstVertex; idVertex < endVertex; idVertex += sumId + 1) {
    if (conditional == 0) {
      temp->townsList.push_front(new Vertex(idVertex, "", town));
      temp->townsList.push_front(new Vertex(idVertex + sumId, "", town));
      conditional++;
    } else {
      temp->townsList.push_front(new Vertex(idVertex, "", town));
      temp->townsList.push_front(new Vertex(idVertex + sumId - 1, "", town));
      conditional++;
    }
  }
  // Show List
}