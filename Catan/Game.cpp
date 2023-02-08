#include "Game.hpp"
#include <algorithm>
using std::pair;

Game::Game() {
  townsList = new list<Town *>();
  players = new list<Player *>();
  citiesList = new list<City *>();
  roadsList = new list<Road *>();
  landsList = new list<Land *>();
  endUrl = ".png";
  loadMaps();
}

void Game::setGraph(Graph graph) { this->graph = graph; }
Graph Game::getGraph() const { return this->graph; }

void Game::setImagePaths(unordered_map<string, string> imagePaths) {
  this->imagePaths = imagePaths;
}

unordered_map<string, string> Game::getImagePaths() const {
  return this->imagePaths;
}

void Game::setPlayersList(list<Player *> *playersList) {
  this->players = playersList;
}

list<Player *> *Game::getPlayersList() const { return this->players; }

void Game::setTownsList(list<Town *> *townsList) {
  this->townsList = townsList;
}

list<Town *> *Game::getTownsList() const { return this->townsList; }

void Game::setCitiesList(list<City *> *citiesList) {
  this->citiesList = citiesList;
}

list<City *> *Game::getCitiesList() const { return this->citiesList; }

void Game::setRoadsList(list<Road *> *roadsList) {
  this->roadsList = roadsList;
}

list<Road *> *Game::getRoadsList() const { return this->roadsList; }

void Game::setLandsList(list<Land *> *landsList) {
  this->landsList = landsList;
}

list<Land *> *Game::getLandsList() const { return this->landsList; }

void Game::setVertexesList(list<Vertex *> *vertexesList) {
  this->vertexesList = vertexesList;
}

list<Vertex *> *Game::getVertexesList() const { return this->vertexesList; }

void Game::setKnightCards(list<Knight *> *knightCards) {
  this->knightCards = knightCards;
}

list<Knight *> *Game::getKnightCards() const { return this->knightCards; }

void Game::setProgressCards(list<Progress *> *progressCards) {
  this->progressCards = progressCards;
}

list<Progress *> *Game::getProgressCards() const { return this->progressCards; }

void Game::setVictoryPointsCards(list<VictoryPoints *> *victoryPointCards) {
  this->victoryPointCards = victoryPointCards;
}

list<VictoryPoints *> *Game::getVictoryPointsCards() const {
  return this->victoryPointCards;
}

void Game::setClayCards(stack<Clay *> *clayCards) {
  this->clayCards = clayCards;
}

stack<Clay *> *Game::getClayCards() const { return this->clayCards; }

void Game::setMineralCards(stack<Mineral *> *mineralCards) {
  this->mineralCards = mineralCards;
}

stack<Mineral *> *Game::getMineralCards() const { return this->mineralCards; }

void Game::setWheatCards(stack<Wheat *> *wheatCards) {
  this->wheatCards = wheatCards;
}

stack<Wheat *> *Game::getWheatCards() const { return this->wheatCards; }

void Game::setWoodCards(stack<Wood *> *woodCards) {
  this->woodCards = woodCards;
}

stack<Wood *> *Game::getWoodCards() const { return this->woodCards; }

void Game::setWoolCards(stack<Wool *> *woolCards) {
  this->woolCards = woolCards;
}

stack<Wool *> *Game::getWoolCards() const { return this->woolCards; }

void Game::setLandNumbers(vector<int> landsNumbers) {
  this->landsNumbers = landsNumbers;
}

vector<int> Game::getLandNumbers() const { return this->landsNumbers; }

void Game::loadMaps() {
  loadProgressPaths();
  loadTilesPaths();
}

void Game::loadSpecialCards() {
  imagePaths.insert(pair<string, string>(
      "biggestPath", "Images/extraCards/biggestPathCard.png"));
  imagePaths.insert(pair<string, string>(
      "biggestArmyPath", "Images/extraCards/biggestArmyCard.png"));
}

void Game::loadProgressPaths() {
  imagePaths.insert(
      pair<string, string>("knightPath", "Images/knightCards/mini_knightCard"));

  imagePaths.insert(pair<string, string>(
      "progressPath", "Images/progressCards/mini_progressCard"));

  imagePaths.insert(pair<string, string>(
      "victoryPointsPath", "Images/victoryPointsCards/mini_victoryPointCard"));
}

void Game::loadTilesPaths() {
  imagePaths.insert(
      pair<string, string>("grassPath", "Images/tiles/Grass.png"));
  imagePaths.insert(
      pair<string, string>("brickPath", "Images/tiles/Brick.png"));
  imagePaths.insert(
      pair<string, string>("fieldPath", "Images/tiles/Field.png"));

  imagePaths.insert(
      pair<string, string>("mountainPath", "Images/tiles/Mountain.png"));

  imagePaths.insert(
      pair<string, string>("forestPath", "Images/tiles/Forest.png"));

  imagePaths.insert(
      pair<string, string>("dessertPath", "Images/tiles/Dessert.png"));
}

void Game::loadLandsNumbers() {
  landsNumbers = {2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12};
}

void Game::randomizeLandsNumbers() {
  int i, j;
  for (i = 0; i < landsNumbers.size() - 1; i++) {
    j = i + rand() % (landsNumbers.size() - i);
    std::swap(landsNumbers[i], landsNumbers[j]);
  }
}

void Game::shuffleLandList() {
  int i, j;
  for (i = 0; i < landsList->size() - 1; i++) {
    j = i + rand() % (landsList->size() - i);
    std::swap(landsList[i], landsList[j]);
  }
}

vector<int> Game::getLandsNumbersRandomized() {
  loadLandsNumbers();
  randomizeLandsNumbers();
  return landsNumbers;
}

void Game::printLandsNumbers(vector<int> const &landsNumbers) {
  for (auto &number : landsNumbers)
    std::cout << number << " ";
}

void Game::setNumbersToLands(list<Land *> *landsList) {
  landsNumbers = getLandsNumbersRandomized();

  list<Land *>::iterator landsIterator;
  landsIterator = landsList->begin();

  vector<int>::iterator landsNumbersIterator;
  landsNumbersIterator = landsNumbers.begin();

  if (!isNumbersLandsSet) {
    while (landsIterator != landsList->end()) {
      while (landsNumbersIterator != landsNumbers.end()) {
        if ((*landsIterator)->getTypeLand() != "Dessert") {
          (*landsIterator)->setDiceNumber((*landsNumbersIterator));
          landsNumbersIterator++;
        }
        landsIterator++;
      }
    }
  }
  isNumbersLandsSet = true;
}

void Game::printDiceNumbersInLands() {
  list<Land *>::iterator landsIterator;
  landsIterator = landsList->begin();
  while (landIterator != landsList->end()) {
    std::cout << (*landIterator)->getDiceNumber() << std::endl;
    landIterator++;
  }
}

void Game::loadLands() {
  loadTilesPaths();
  int i;
  int landId = 1;
  for (i = 0; i < 4; i++) {
    if (i < 1) {
      landsList->push_back(
          new Land("Dessert", imagePaths.at("dessertPath"), 0, 0, landId));
      landId++;
    }
    if (i < 3) {
      landsList->push_back(
          new Land("Mountain", imagePaths.at("mountainPath"), 0, 0, landId));
      landId++;
      landsList->push_back(
          new Land("Field", imagePaths.at("fieldPath"), 0, 0, landId));
      landId++;
    }
    landsList->push_back(
        new Land("Grass", imagePaths.at("grassPath"), 0, 0, landId));
    landId++;
    landsList->push_back(
        new Land("Forest", imagePaths.at("forestPath"), 0, 0, landId));
    landId++;
    landsList->push_back(
        new Land("Brick", imagePaths.at("brickPath"), 0, 0, landId));
    landId++;
  }
  // landsList = shuffleLandList();
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
  endUrl = ".png";
  int i, num = 1, numberOfCards = 5;
  for (int x = 0; x < 3; x++) {
    for (i = 0; i < numberOfCards; i++) {
      string stringNumber(std::to_string(num));
      knightPath = imagePaths.at("knightPath") + stringNumber + endUrl;

      if (i < 3 && x < 2) {
        progressPath = imagePaths.at("progressPath") + stringNumber + endUrl;
        progressCards->push_back(new Progress(num, progressPath));
      }
      if (x == 0) {
        victoryPointsPath =
            imagePaths.at("victoryPointsPath") + stringNumber + endUrl;
        victoryPointCards->push_back(new VictoryPoints(victoryPointsPath));
      }
      knightCards->push_back(new Knight(knightPath));

      num++;
      // Poner png
    }
    num = 1;
  }
}

void Game::makeFigures() {
  int i;
  for (i = 0; i < 60; i++) {
    if (i < 16)
      citiesList->push_back(new City(""));
    if (i < 20)
      townsList->push_back(new Town(""));
    roadsList->push_back(new Road(""));
  }
}

void Game::createGraphVertex() {
  for (vertexId = 1; vertexId < 55; vertexId++) {
    Vertex *vertex = new Vertex(vertexId, "", new Town(), false);
    graph.insertVertex(vertex);
  }
}

void Game::makeGraph() {
  vertexId = 1;
  vertexJump = 4;

  // SE CREAN LOS VERTICES
  for (vertexId = 1; vertexId < 55; vertexId++) {
    Vertex *vertex = new Vertex(vertexId, "", new Town(), false);
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
}

void Game::assignTownsToLand() {
  int contLands = 1, idVertex = 1, endVertex = 10, sumId = 3;
  landIterator = landsList->begin();
  while (contLands < 4) {
    assignTowns(*landIterator, idVertex, endVertex, sumId);
    idVertex++, endVertex++, contLands++, landIterator++;
  }
  sumId++, contLands = 1, idVertex = 8, endVertex = 19;

  while (contLands < 5) {
    assignTowns(*landIterator, idVertex, endVertex, sumId);
    idVertex++, endVertex++, contLands++, landIterator++;
  }
  sumId++, contLands = 1, idVertex = 17, endVertex = 30;

  while (contLands < 6) {
    assignTownsMiddleRow(*landIterator, idVertex, endVertex, sumId);
    idVertex++, endVertex++, contLands++, landIterator++;
  }
  sumId = 5, contLands = 1, idVertex = 29, endVertex = 41;

  while (contLands < 5) {
    assignTownsLastRows(*landIterator, idVertex, endVertex, sumId);
    idVertex++, endVertex++, contLands++, landIterator++;
  }
  sumId = 4, contLands = 1, idVertex = 40, endVertex = 50;

  while (contLands < 4) {
    assignTownsLastRows(*landIterator, idVertex, endVertex, sumId);
    idVertex++, endVertex++, contLands++, landIterator++;
  }
}

void Game::assignTowns(Land *temp, int idVertex, int endVertex, int sumId) {
  int conditional = 0;
  for (idVertex; idVertex < endVertex; idVertex += sumId + 1) {
    if (conditional < 2) {
        temp->townsList->push_back(
          new Vertex(idVertex, "", new Town(), false)); // aca se cae
        temp->townsList->push_back(
          new Vertex(idVertex + sumId, "", new Town(), false));
      conditional++;
    } else {
        temp->townsList->push_back(new Vertex(idVertex, "", new Town(), false));
        temp->townsList->push_back(
          new Vertex(idVertex + sumId + 1, "", new Town(), false));
    }
  }
}

void Game::assignTownsMiddleRow(Land *temp, int idVertex, int endVertex,
                                int sumId) {

  for (idVertex; idVertex < endVertex; idVertex += sumId + 1) {
    temp->townsList->push_back(new Vertex(idVertex, "", new Town(), false));
    temp->townsList->push_back(
        new Vertex(idVertex + sumId, "", new Town(), false));
  }
}

void Game::assignTownsLastRows(Land *temp, int idVertex, int endVertex,
                               int sumId) {
  int cycleNumber = 0;
  const int secondCycle = 1;
  int iterationSumSpecialCase = sumId + 1; // 5 + 1 == 6

  for (idVertex; idVertex < endVertex; idVertex += iterationSumSpecialCase) {
    if (cycleNumber >= secondCycle) {
      temp->townsList->push_back(new Vertex(idVertex, "", new Town(), false));
      temp->townsList->push_back(
          new Vertex(idVertex + sumId - 1, "", new Town(), false));
      iterationSumSpecialCase--;
    } else {
      temp->townsList->push_back(new Vertex(idVertex, "", new Town(), false));
      temp->townsList->push_back(
          new Vertex(idVertex + sumId, "", new Town(), false));
    }
    cycleNumber++;
  }
}

void Game::printLand(list<Land *> *landsList) {
  landIterator = landsList->begin();
  while (landIterator != landsList->end()) {
    std::cout << "Type: " << (*landIterator)->getType() << " landId "
              << (*landIterator)->getLandId()
              << " posX: " << (*landIterator)->getPosX()
              << " posY: " << (*landIterator)->getPosY() << std::endl;
    landIterator++;
  }
}

void Game::printVertex(list<Vertex *> *vertexList) {
  list<Vertex *>::iterator vertexIterator;
  vertexIterator = vertexList->begin();
  while (vertexIterator != vertexList->end()) {
    std::cout << "vertexId: " << (*vertexIterator)->getVertexId()
              << " posX: " << (*vertexIterator)->getTown()->getPosX()
              << " posY: " << (*vertexIterator)->getTown()->getPosY()
              << std::endl;
    vertexIterator++;
  }
}

void Game::makePlayer() {
  int numPlayer = 0;
  playerIterator = players->begin();
  while (playerIterator != players->end()) {
    loadFiguresToPlayer((*playerIterator), numPlayer);
    playerIterator++;
    numPlayer++;
  }
}

void Game::loadFiguresToPlayer(Player *player, int numPlayer) {
  int iterator;
  for (iterator = 0; iterator < 16; iterator++) {
    loadRoades(player);
    if (iterator < 5)
      loadCities(player);
    if (iterator < 6)
      loadTowns(player);
  }
}

void Game::loadRoades(Player *player) {
  if (player->getColor() == "RED")
    player->roads->push_back(new Road("Images/Figures/RoadRed.png"));
  if (player->getColor() == "BLUE")
    player->roads->push_back(new Road("Images/Figures/RoadBlue.png"));
  if (player->getColor() == "GREEN")
    player->roads->push_back(new Road("Images/Figures/RoadGreen.png"));
  if (player->getColor() == "YELLOW")
    player->roads->push_back(new Road("Images/Figures/RoadYellow.png"));
}

void Game::loadCities(Player *player) {
  if (player->getColor() == "RED")
    player->citys->push_back(new City("Images/Figures/CityRed.png"));
  if (player->getColor() == "BLUE")
    player->citys->push_back(new City("Images/Figures/CityBlue.png"));
  if (player->getColor() == "GREEN")
    player->citys->push_back(new City("Images/Figures/CityGreen.png"));
  if (player->getColor() == "YELLOW")
    player->citys->push_back(new City("Images/Figures/CityYellow.png"));
}

void Game::loadTowns(Player *player) {
  if (player->getColor() == "RED")
    player->towns->push_back(new Town("Images/Figures/TownRed.png"));
  if (player->getColor() == "BLUE")
    player->towns->push_back(new Town("Images/Figures/TownBlue.png"));
  if (player->getColor() == "GREEN")
    player->towns->push_back(new Town("Images/Figures/TownGreen.png"));
  if (player->getColor() == "YELLOW")
    player->towns->push_back(new Town("Images/Figures/TownYellow.png"));
}
