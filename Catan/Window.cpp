#include "Window.hpp"

int cont = 0;
bool var = false;

void Window::setTurn(int numberPlayers) {
  std::cout << turnNumber << std::endl;

  if (turnNumber == numberPlayers) {
    turnNumber = 0;
    i = 100;
    drawTurn(turnNumber, i);
  } else {

    drawTurn(turnNumber, i);
    i = i + 45;
    turnNumber++;
  }
}

void Window::drawTurn(int turns, int posiI) {}

bool Window::goBack(sf::RenderWindow &window) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return true;
  return false;
}

void Window::showCoordinates(sf::RenderWindow &window) {
  log("x: " << sf::Mouse::getPosition(window).x);
  log("y: " << sf::Mouse::getPosition(window).y);
}

// Renombrar -> playWindow
void Window::printImages(string imagePath, int posX, int posY) {
  sf::Texture path;
  path.loadFromFile(imagePath);
  sf::Sprite sprite(path);
  sprite.setPosition(static_cast<float>(posX), static_cast<float>(posY));
  playWindow.draw(sprite);
}

// Agregado recientemente -> Separar en clases los metodos de Window
void Window::setTempImagePath(string image) { this->tempImagePath = image; }

bool Window::isLandsListTraversal() const { return (it != landsList->end()); }

void Window::iterateLand() { it++; }
void Window::iterateLand2() { it2++; }

bool Window::isLastIteration(int number) const {
  return (number == lastIterationNumber);
}

void Window::lastIterationBehaviour(int number) {
  if (isLastIteration(number)) {
    lastIteration = true;
  } else {
    lastIteration = false;
  }
}

void Window::setPosXYtoLand(double posX, double posY,
                            list<Land *>::iterator auxIt) {
  (*auxIt)->setPosX(posX);
  (*auxIt)->setPosY(posY);
}

void Window::setAndTraverse(int posX, int posY, list<Land *>::iterator auxIt) {
  setTempImagePath((*auxIt)->getImagePath());
  setPosXYtoLand(posX, posY, auxIt);
  Window::getInstance().printImages(tempImagePath, posX, posY);
  C_Traversal(posX, posY, auxIt);
}

void Window::initializeLandsList() {
  game.loadLands();
  game.assignTownsToLand();
  game.makeGraph();
  landsList = game.getLandsList();
  it = landsList->begin();
}

void Window::initializeVertexesList(list<Land *>::iterator auxIt) {
  vertexesList = (*auxIt)->getTownsList();
  vertexIterator = vertexesList->begin();
}

bool Window::isVertexesListTraversal() const {
  return (vertexIterator != vertexesList->end());
}

void Window::iterateVertex() { vertexIterator++; }

bool Window::isTwoLastVertex() const {
  return (vertexIterationNumber == 3 || vertexIterationNumber == 5);
}

void Window::traverseFirstAndLastRow(int posX, int topHeight, int botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(posX, topHeight, it);
    iterateLand();

    setAndTraverse(posX, botHeight, it2);
    iterateLand2();
  }
}

void Window::traverseSecondAndNextToLastRow(int posX, int topHeight,
                                            int botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(posX, topHeight, it);
    iterateLand();

    setAndTraverse(posX, botHeight, it2);
    iterateLand2();
  }
}

void Window::traverseMiddleRow(int posX, int topHeight, int botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(posX, topHeight, it2);
    iterateLand2();
  }
}

void Window::C_Traversal(int posX, int posY, list<Land *>::iterator auxIt) {
  vertexIterationNumber = 1;
  initializeVertexesList(auxIt);

  for (vertexIterationNumber; vertexIterationNumber < 7;
       vertexIterationNumber++) {
    if (isVertexesListTraversal()) {
      loadHexagonNodes(vertexIterator, posX, posY, vertexIterationNumber);
      iterateVertex();
    }
  }
}

double Window::getFormula(int vertexId) {
  if (vertexId == 1)
    return firstAngle;
  if (vertexId == 2)
    return secondAngle;
  if (vertexId == 3)
    return thirdAngle;
  if (vertexId == 4)
    return fourthAngle;
  if (vertexId == 5)
    return fifthAngle;
  if (vertexId == 6)
    return sexthAngle;
  return 0;
}

void Window::printTowns(double x, double y) {
  string tempImagePath = "Images/puebloX.png";
  Window::getInstance().printImages(tempImagePath, static_cast<int>(x),
                                    static_cast<int>(y));
}
void Window::setPosXYtoVertex(list<Vertex *>::iterator vertexIterator, double x,
                              double y) {
  (*vertexIterator)->town->setPosX(x);
  (*vertexIterator)->town->setPosY(y);
}

void Window::loadHexagonNodes(list<Vertex *>::iterator itX, double posX,
                              double posY, int iterationNumber) {
  double relativePositionX = posX - 10 + landsRadius +
                             (landsRadius * cos(getFormula(iterationNumber)));
  double relativePositionY = posY - 20 + landsRadius +
                             (landsRadius * sin(getFormula(iterationNumber)));
  if (iterationNumber < 4) {
    printTowns(relativePositionX, relativePositionY - 3);
    setPosXYtoVertex(itX, relativePositionX, relativePositionY);
    setPosXYtoVertexesGraph((*itX)->getVertexId(), relativePositionX,
                            relativePositionY);
  } else {
    printTowns(relativePositionX, relativePositionY + 15);
    setPosXYtoVertex(itX, relativePositionX, relativePositionY);
    setPosXYtoVertexesGraph((*itX)->getVertexId(), relativePositionX,
                            relativePositionY);
  }
}

void Window::setPosXYtoVertexesGraph(int vertexId, double posX, double posY) {
  game.graph.getVertex(vertexId)->getTown()->setPosX(posX);
  game.graph.getVertex(vertexId)->getTown()->setPosY(posY);
}

//////////////////////// CARGAR /////////////////////////

///////////////////////// IMPRIMIR //////////////////////
void Window::consolePrintLandAndVertex() {
  game.printLand(landsList);
  it = landsList->begin();
  while (it != landsList->end()) {
    log("landId: " << (*it)->getLandId());
    game.printVertex((*it)->getTownsList());
    it++;
  }
}
