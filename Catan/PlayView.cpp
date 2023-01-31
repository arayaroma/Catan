#include "PlayView.hpp"

void PlayView::createLabels() {
  materialCard = new Label("Cartas de Materiales", sf::Color(0, 0, 255, 128),
                           font, sf::Text::Bold, 20, 5.f, 230.f);
  developCard = new Label("Cartas de Desarrollo", sf::Color(0, 0, 255, 128),
                           font, sf::Text::Bold, 20, 5.f, 360.f);
  pricingTable = new Label("Tabla de precios", sf::Color(0, 0, 255, 128), font,
                           sf::Text::Bold, 20, 5.f, 0.f);
  turns = new Label("Jugadores", sf::Color(0, 0, 255, 128), font,
                    sf::Text::Bold, 20, 1070.f, 60.f);
  cards = new Label("Componentes", sf::Color(0, 0, 255, 128), font,
                    sf::Text::Bold, 20, 565.f, 575.f);
}

void PlayView::drawLabels() {
  createLabels();
  playView.draw(materialCard->getTextInstance());
  playView.draw(developCard->getTextInstance());
  playView.draw(pricingTable->getTextInstance());
  playView.draw(turns->getTextInstance());
  playView.draw(cards->getTextInstance());
}

void PlayView::createLabelNamePlayers() {
    player1 = new Label("Jesus", sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 1100.f, 120.f);
    player2 = new Label("Daniel", sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 1100.f, 180.f);
    player3 = new Label("Dilan", sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 1100.f, 240.f);
    player4 = new Label("Profe", sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 1100.f, 300.f);
}
void PlayView::drawLabelNamePlayers() {
    createLabelNamePlayers();
    playView.draw(player1->getTextInstance());
    playView.draw(player2->getTextInstance());
    playView.draw(player3->getTextInstance());
    playView.draw(player4->getTextInstance());
}
void PlayView::printPlayerCard() {
    printImages("Images/playerCard/clayCard.png", 360, 640);
    printImages("Images/playerCard/mineralCard.png", 400, 640);
    printImages("Images/playerCard/wheatCard.png", 440, 640);
    printImages("Images/playerCard/woodCard.png", 480, 640);
    printImages("Images/playerCard/woolCard.png", 520, 640);
}
void PlayView::createLabelCardPlayer() {
    clayCard = new Label("0", sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 375.f, 620.f);
    mineralPlayerCard = new Label("0", sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 415.f, 620.f);
    wheatPlayerCard = new Label("0", sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 455.f, 620.f);
    woodPlayerCard = new Label("0", sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 495.f, 620.f);
    woolPlayerCard = new Label("0", sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 535.f, 620.f);

}
void PlayView::drawLabelCardPlayer() {
    createLabelCardPlayer();
    playView.draw(clayCard->getTextInstance());
    playView.draw(mineralPlayerCard->getTextInstance());
    playView.draw(wheatPlayerCard->getTextInstance());
    playView.draw(woodPlayerCard->getTextInstance());
    playView.draw(woolPlayerCard->getTextInstance());
}
void PlayView::createLabelFigurePlayer() {
    townPlayer = new Label("0", sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 600.f, 620.f);
    cityPlayer = new Label("0", sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 640.f, 620.f);
    roadPlayer = new Label("0", sf::Color(0, 0, 255, 128),
        font, sf::Text::Bold, 20, 680.f, 620.f);
}
void PlayView::drawLabelFigurePlayer() {
    createLabelFigurePlayer();
    playView.draw(townPlayer->getTextInstance());
    playView.draw(cityPlayer->getTextInstance());
    playView.draw(roadPlayer->getTextInstance());
}
void PlayView::printPlayerFigure() {
    printImages("Images/Figures/TownBlue.png", 590, 650);
    printImages("Images/Figures/CityBlue.png", 630, 650);
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
  printTownsTest();
  printMaterialCard();
  printPlayerCard();
  drawLabelNamePlayers();
  drawLabelCardPlayer();
  drawLabelFigurePlayer();
  printPlayerFigure();
  playView.display();
}

void PlayView::goPlayView() {
  loadPlayView();
  drawPlayView();
  start = true;
  while (playView.isOpen()) {
    while (playView.pollEvent(event)) {
      showCoordinates(event);
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
  }
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
  double top_height = 40, bot_height = 40, cycle_cord_x = 0, i = 1;
  initializeLandsList();
  bot_height += 280;
  it2 = landsList->begin();
  std::advance(it2, 16);
  for (cycle_cord_x = 530; cycle_cord_x <= 700; cycle_cord_x += 85) {
    traverseFirstAndLastRow(cycle_cord_x, top_height, bot_height);
  }
  lastIteration = false;
  top_height += 70;
  bot_height = 250;
  lastIterationNumber = 755;
  it2 = landsList->begin();
  std::advance(it2, 12);
  for (cycle_cord_x = 487.5; cycle_cord_x <= 757.5; cycle_cord_x += 85) {
    traverseSecondAndNextToLastRow(cycle_cord_x, top_height, bot_height);
  }
  lastIteration = false;
  top_height += 70;
  lastIterationNumber = 760;
  it2 = landsList->begin();
  std::advance(it2, 7);
  for (cycle_cord_x = 445; cycle_cord_x <= 785; cycle_cord_x += 85) {
    traverseMiddleRow(cycle_cord_x, top_height, bot_height);
  }
}
void PlayView::printTownsTest() {
    double top_height = 40, bot_height = 40, cycle_cord_x = 0, i = 1;
    initializeLandsList();
    bot_height += 280;
    it2 = landsList->begin();
    std::advance(it2, 16);
    for (cycle_cord_x = 530; cycle_cord_x <= 700; cycle_cord_x += 85) {
        traverseFirstAndLastRowTest(cycle_cord_x, top_height, bot_height);
    }
    lastIteration = false;
    top_height += 70;
    bot_height = 250;
    lastIterationNumber = 755;
    it2 = landsList->begin();
    std::advance(it2, 12);
    for (cycle_cord_x = 487.5; cycle_cord_x <= 757.5; cycle_cord_x += 85) {
        traverseSecondAndNextToLastRowTest(cycle_cord_x, top_height, bot_height);
    }
    lastIteration = false;
    top_height += 70;
    lastIterationNumber = 760;
    it2 = landsList->begin();
    std::advance(it2, 7);
    for (cycle_cord_x = 445; cycle_cord_x <= 785; cycle_cord_x += 85) {
        traverseMiddleRowTest(cycle_cord_x, top_height, bot_height);
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
 
}
void PlayView::setAndTraverseTest(int posX, int posY, list<Land*>::iterator auxIt) {
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

void PlayView::traverseFirstAndLastRowTest(int posX, int topHeight, int botHeight) {
    if (isLandsListTraversal()) {
        lastIterationBehaviour(posX);

        setAndTraverseTest(posX, topHeight, it);
        iterateLand();

        setAndTraverseTest(posX, botHeight, it2);
        iterateLand2();
    }
}

void PlayView::traverseSecondAndNextToLastRowTest(int posX, int topHeight,
    int botHeight) {
    if (isLandsListTraversal()) {
        lastIterationBehaviour(posX);

        setAndTraverseTest(posX, topHeight, it);
        iterateLand();

        setAndTraverseTest(posX, botHeight, it2);
        iterateLand2();
    }
}

void PlayView::traverseMiddleRowTest(int posX, int topHeight, int botHeight) {
    if (isLandsListTraversal()) {
        lastIterationBehaviour(posX);

        setAndTraverseTest(posX, topHeight, it2);
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
  string tempImagePath = "Images/Town.png";
  printImages(tempImagePath, static_cast<int>(x), static_cast<int>(y));
}

void PlayView::setPosXYtoVertex(list<Vertex *>::iterator vertexIterator,
                                double x, double y) {
  (*vertexIterator)->town->setPosX(x);
  (*vertexIterator)->town->setPosY(y);
}

void PlayView::loadHexagonNodes(list<Vertex *>::iterator itX, double posX,
                                double posY, int iterationNumber) {
  double relativePositionX = posX   + landsRadius +
                             (landsRadius * cos(getFormula(iterationNumber)));
  double relativePositionY = posY  + landsRadius +
                             (landsRadius * sin(getFormula(iterationNumber)));
  if (!game.graph.getVertex((*itX)->getVertexId())->getIsPrint()) {
      game.graph.getVertex((*itX)->getVertexId())->setIsPrinted(true);
      printTowns(relativePositionX, relativePositionY);
      setPosXYtoVertex(itX, relativePositionX, relativePositionY);
      setPosXYtoVertexesGraph((*itX)->getVertexId(), relativePositionX,
          relativePositionY);
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

void PlayView::showCoordinates(sf::Event event) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
        }
}