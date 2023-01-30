#include "PlayView.hpp"

void PlayView::createLabels() {
  materialCard = new Label("Cartas de Materiales", sf::Color(0, 0, 255, 128),
                           font, sf::Text::Bold, 20, 5.f, 230.f);
  pricingTable = new Label("Tabla de precios", sf::Color(0, 0, 255, 128), font,
                           sf::Text::Bold, 20, 5.f, 0.f);
  turns = new Label("Jugadores", sf::Color(0, 0, 255, 128), font,
                    sf::Text::Bold, 20, 1050.f, 60.f);
  cards = new Label("Componentes", sf::Color(0, 0, 255, 128), font,
                    sf::Text::Bold, 20, 565.f, 575.f);
}

void PlayView::drawLabels() {
  createLabels();
  playView.draw(materialCard->getTextInstance());
  playView.draw(pricingTable->getTextInstance());
  playView.draw(turns->getTextInstance());
  playView.draw(cards->getTextInstance());
}

void PlayView::printMaterialCard() {
  printImages("Images/resourcesCards/clayCard.png", 0, 255);
  printImages("Images/resourcesCards/mineralCard.png", 70, 255);
  printImages("Images/resourcesCards/wheatCard.png", 140, 255);
  printImages("Images/resourcesCards/woodCard.png", 210, 255);
  printImages("Images/resourcesCards/woolCard.png", 280, 255);
  printImages("Images/extraCards/progressCardBackwards.png", 0, 385);
  printImages("Images/extraCards/pricingTable.jpeg", 0, 25);
  drawLabels();
}

void PlayView::loadPlayersRectangle() {
  playerRectangle.setPosition(1020, 100);
  playerRectangle.setOutlineColor(sf::Color::White);
  playerRectangle.setSize({220, 400});
  playerRectangle.setFillColor(sf::Color(255, 255, 255, 128));
  playView.draw(playerRectangle);
}

void PlayView::loadCardsRectangle() {
  cardsRectangle = playerRectangle;
  cardsRectangle.setPosition(350, 600);
  cardsRectangle.setSize({600, 100});
  playView.draw(cardsRectangle);
}

void PlayView::loadGameButtons() {
  loadPlayersRectangle();
  loadCardsRectangle();
}

void PlayView::loadPlayView() {
  playView.create(sf::VideoMode(1280, 720), "Play");
  playImage.loadFromFile("Images/catan_1280x720.jpg");
  playSprite.setTexture(playImage);
  font.loadFromFile("mononoki.ttf");
  playView.setFramerateLimit(120);
}

void PlayView::drawPlayView() {
  playView.clear();
  playView.draw(playSprite);
  loadGameButtons();
  drawLabels();
  printBoard();
  playView.display();
}

void PlayView::goPlayView() {
  loadPlayView();
  drawPlayView();
  start = true;
  while (playView.isOpen()) {
    while (playView.pollEvent(event)) {
      playView.waitEvent(event);
      switch (event.type) {
      case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left) {
        }
        break;
      case sf::Event::Closed:
        playView.close();
        break;
      }
    }
    // playView.clear();
    // playView.draw(playSprite);
    // loadGameButtons();
    // drawLabels();
    // printMaterialCard();
    // printBoard();
    //  loadStartButtons(playWindow);
    // loadGameButtons();
    // playView.display();
  }
  // consolePrintLandAndVertex();
  // log("Grafo");
  // game.graph.showAdjacencyList();
}

void PlayView::setTurn(int numberPlayers) {
  std::cout << turnNumber << std::endl;
  int i = 0;
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

void PlayView::drawTurn(int turns, int posiI) {}

void PlayView::printImages(string imagePath, int posX, int posY) {
  sf::Texture path;
  path.loadFromFile(imagePath);
  sf::Sprite tempSprite(path);
  tempSprite.setPosition(static_cast<float>(posX), static_cast<float>(posY));
  playView.draw(tempSprite);
}

// Ver que pex con Game -> Window
void PlayView::initializeLandsList() {
  game.loadLands();
  game.assignTownsToLand();
  game.makeGraph();
  landsList = game.getLandsList();
  it = landsList->begin();
}

void PlayView::printBoard() {
  int top_height = 30, bot_height = 30, cycle_cord_x = 0, i = 1;
  initializeLandsList();
  bot_height += 330;
  it2 = landsList->begin();
  std::advance(it2, 16);
  for (cycle_cord_x = 530; cycle_cord_x <= 680; cycle_cord_x += 75) {
    traverseFirstAndLastRow(cycle_cord_x, top_height, bot_height);
  }
  lastIteration = false;
  top_height += 80;
  bot_height = 270;
  lastIterationNumber = 755;
  it2 = landsList->begin();
  std::advance(it2, 12);
  for (cycle_cord_x = 505; cycle_cord_x <= 755; cycle_cord_x += 75) {
    traverseSecondAndNextToLastRow(cycle_cord_x, top_height, bot_height);
  }
  lastIteration = false;
  top_height += 80;
  lastIterationNumber = 760;
  it2 = landsList->begin();
  std::advance(it2, 7);
  for (cycle_cord_x = 460; cycle_cord_x <= 760; cycle_cord_x += 75) {
    traverseMiddleRow(cycle_cord_x, top_height, bot_height);
  }
}

// Agregado recientemente -> Separar en clases los metodos de Window
void PlayView::setTempImagePath(string image) { this->tempImagePath = image; }

bool PlayView::isLandsListTraversal() const { return (it != landsList->end()); }

void PlayView::iterateLand() { it++; }
void PlayView::iterateLand2() { it2++; }

bool PlayView::isLastIteration(int number) const {
  return (number == lastIterationNumber);
}

void PlayView::lastIterationBehaviour(int number) {
  if (isLastIteration(number)) {
    lastIteration = true;
  } else {
    lastIteration = false;
  }
}

void PlayView::setPosXYtoLand(double posX, double posY,
                              list<Land *>::iterator auxIt) {
  (*auxIt)->setPosX(posX);
  (*auxIt)->setPosY(posY);
}

void PlayView::setAndTraverse(int posX, int posY,
                              list<Land *>::iterator auxIt) {
  setTempImagePath((*auxIt)->getImagePath());
  setPosXYtoLand(posX, posY, auxIt);
  printImages(tempImagePath, posX, posY);
  C_Traversal(posX, posY, auxIt);
}

void PlayView::initializeVertexesList(list<Land *>::iterator auxIt) {
  vertexesList = (*auxIt)->getTownsList();
  vertexIterator = vertexesList->begin();
}

bool PlayView::isVertexesListTraversal() const {
  return (vertexIterator != vertexesList->end());
}

void PlayView::iterateVertex() { vertexIterator++; }

bool PlayView::isTwoLastVertex() const {
  return (vertexIterationNumber == 3 || vertexIterationNumber == 5);
}

void PlayView::traverseFirstAndLastRow(int posX, int topHeight, int botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(posX, topHeight, it);
    iterateLand();

    setAndTraverse(posX, botHeight, it2);
    iterateLand2();
  }
}

void PlayView::traverseSecondAndNextToLastRow(int posX, int topHeight,
                                              int botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(posX, topHeight, it);
    iterateLand();

    setAndTraverse(posX, botHeight, it2);
    iterateLand2();
  }
}

void PlayView::traverseMiddleRow(int posX, int topHeight, int botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(posX, topHeight, it2);
    iterateLand2();
  }
}

void PlayView::C_Traversal(int posX, int posY, list<Land *>::iterator auxIt) {
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

double PlayView::getFormula(int vertexId) const {
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

void PlayView::printTowns(double x, double y) {
  string tempImagePath = "Images/puebloX.png";
  printImages(tempImagePath, static_cast<int>(x), static_cast<int>(y));
}

void PlayView::setPosXYtoVertex(list<Vertex *>::iterator vertexIterator,
                                double x, double y) {
  (*vertexIterator)->town->setPosX(x);
  (*vertexIterator)->town->setPosY(y);
}

void PlayView::loadHexagonNodes(list<Vertex *>::iterator itX, double posX,
                                double posY, int iterationNumber) {
  double relativePositionX = posX - 10 + landsRadius +
                             (landsRadius * cos(getFormula(iterationNumber)));
  double relativePositionY = posY - 20 + landsRadius +
                             (landsRadius * sin(getFormula(iterationNumber)));
  if (game.graph.getVertex((*itX)->getVertexId())->getIsPrint() == false) {
      game.graph.getVertex((*itX)->getVertexId())->setIsPrinted(true);
      if (iterationNumber < 4) {
          printTowns(relativePositionX, relativePositionY - 3);
          setPosXYtoVertex(itX, relativePositionX, relativePositionY);
          setPosXYtoVertexesGraph((*itX)->getVertexId(), relativePositionX,
              relativePositionY);
      }
      else {
          printTowns(relativePositionX, relativePositionY + 15);
          setPosXYtoVertex(itX, relativePositionX, relativePositionY);
          setPosXYtoVertexesGraph((*itX)->getVertexId(), relativePositionX,
              relativePositionY);
          
      }
  }
}
void PlayView::isPrinted(int vertexId) {
    game.graph.getVertex(vertexId)->setIsPrinted(true);
}
void PlayView::setPosXYtoVertexesGraph(int vertexId, double posX, double posY) {
  game.graph.getVertex(vertexId)->getTown()->setPosX(posX);
  game.graph.getVertex(vertexId)->getTown()->setPosY(posY);
}

void PlayView::consolePrintLandAndVertex() {
  game.printLand(landsList);
  it = landsList->begin();
  while (it != landsList->end()) {
    log("landId: " << (*it)->getLandId());
    game.printVertex((*it)->getTownsList());
    it++;
  }
}