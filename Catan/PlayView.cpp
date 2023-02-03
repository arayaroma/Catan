#include "PlayView.hpp"

PlayView::PlayView() {
  landsList = new list<Land *>();
  vertexesList = new list<Vertex *>();
}

PlayView::PlayView(list<Player *> *players) { game.players = players; }

void PlayView::createLabelNumTurn() {
  titleTurn = new Label("Turno:  ", sf::Color(0, 0, 255, 128), font,
                        sf::Text::Bold, 20, 400.f, 2.f);
  labelNumTurn = new Label(std::to_string(numTurn), sf::Color(0, 0, 255, 128),
                           font, sf::Text::Bold, 20, 500.f, 2.f);
  infoFisrtTurn = new Label(
      "Primera Vuelta, por favor elija 2 poblados y pase de turno",
      sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 250.f, 17.f);
  labelNumDice = new Label(std::to_string(numDice), sf::Color(0, 0, 255, 128),
                           font, sf::Text::Bold, 20, 1150.f, 570.f);
}
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

void PlayView::createButtons() {

  p = Button("Turn", {0, 0}, 16, sf::Color::Green, sf::Color::White);

  turn = Button("Turn", {120, 35}, 16, sf::Color::Green, sf::Color::White);
  trade = Button("Trade", {120, 35}, 16, sf::Color::Green, sf::Color::White);
  buy = Button("Buy", {120, 35}, 16, sf::Color::Green, sf::Color::White);
  dice = Button("Dice", {120, 35}, 16, sf::Color::Green, sf::Color::White);

  p.setFont(font);
  p.setPosition({0, 0}, 3);

  turn.setFont(font);
  turn.setPosition({985, 600}, 3);

  trade.setFont(font);
  trade.setPosition({20, 600}, 3);

  buy.setFont(font);
  buy.setPosition({150, 600}, 3);

  dice.setFont(font);
  dice.setPosition({1120, 600}, 3);

  loadRegisterButtons(p);
  loadRegisterButtons(turn);
  loadRegisterButtons(trade);
  loadRegisterButtons(buy);
  loadRegisterButtons(dice);
}

void PlayView::loadRegisterButtons(Button &button) {
  if (button.isMouseOver(view)) {
    button.setBackgroundColor(sf::Color::White);
  } else {
    button.setBackgroundColor(sf::Color::Blue);
  }
  button.drawTo(view);
}
void PlayView::drawLabelNumTurn() {
  createLabelNumTurn();
  view.draw(titleTurn->getTextInstance());
  view.draw(labelNumTurn->getTextInstance());
  view.draw(labelNumDice->getTextInstance());
  if (isFirstTurn) {
    view.draw(infoFisrtTurn->getTextInstance());
  }
}
void PlayView::drawLabels() {
  createLabels();
  view.draw(materialCard->getTextInstance());
  view.draw(developCard->getTextInstance());
  view.draw(pricingTable->getTextInstance());
  view.draw(turns->getTextInstance());
  view.draw(cards->getTextInstance());
}
void PlayView::makeThreePlayers() {
  player1 = new Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128),
                      font, sf::Text::Bold, 20, 1100.f, 120.f);
  playerIterator++;
  player2 = new Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128),
                      font, sf::Text::Bold, 20, 1100.f, 180.f);
  playerIterator++;
  player3 = new Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128),
                      font, sf::Text::Bold, 20, 1100.f, 240.f);
}
void PlayView::makeFourPlayers() {
  player4 = new Label((*playerIterator)->getName(), sf::Color(0, 0, 255, 128),
                      font, sf::Text::Bold, 20, 1100.f, 300.f);
}
void PlayView::createLabelNamePlayers() {
  playerIterator = game.players->begin();
  if (playerIterator != game.players->end()) {
    if (game.players->size() == 3) {
      makeThreePlayers();
    }
    if (game.players->size() == 4) {
      makeThreePlayers();
      playerIterator++;
      makeFourPlayers();
    }
  }
}

void PlayView::drawLabelNamePlayers() {
  createLabelNamePlayers();
  if (game.players->size() == 3) {
    view.draw(player1->getTextInstance());
    view.draw(player2->getTextInstance());
    view.draw(player3->getTextInstance());
  } else {
    view.draw(player1->getTextInstance());
    view.draw(player2->getTextInstance());
    view.draw(player3->getTextInstance());
    view.draw(player4->getTextInstance());
  }
}

void PlayView::printPlayerCard() {
  printImages("Images/playerCard/clayCard.png", 360, 640);
  printImages("Images/playerCard/mineralCard.png", 400, 640);
  printImages("Images/playerCard/wheatCard.png", 440, 640);
  printImages("Images/playerCard/woodCard.png", 480, 640);
  printImages("Images/playerCard/woolCard.png", 520, 640);
}

void PlayView::createLabelCardPlayer() {
  clayCard = new Label(std::to_string((*game.playerIterator)->clayCard->size()),
                       sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20,
                       375.f, 620.f);
  mineralPlayerCard = new Label(
      std::to_string((*game.playerIterator)->mineralCard->size()),
      sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 415.f, 620.f);
  wheatPlayerCard = new Label(
      std::to_string((*game.playerIterator)->wheatlCard->size()),
      sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 455.f, 620.f);
  woodPlayerCard = new Label(
      std::to_string((*game.playerIterator)->woodCard->size()),
      sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 495.f, 620.f);
  woolPlayerCard = new Label(
      std::to_string((*game.playerIterator)->woolCard->size()),
      sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20, 535.f, 620.f);
}

void PlayView::drawLabelCardPlayer() {
  createLabelCardPlayer();
  view.draw(clayCard->getTextInstance());
  view.draw(mineralPlayerCard->getTextInstance());
  view.draw(wheatPlayerCard->getTextInstance());
  view.draw(woodPlayerCard->getTextInstance());
  view.draw(woolPlayerCard->getTextInstance());
}

void PlayView::createLabelFigurePlayer() {
  townPlayer = new Label(std::to_string((*game.playerIterator)->towns->size()),
                         sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20,
                         600.f, 620.f);
  cityPlayer = new Label(std::to_string((*game.playerIterator)->citys->size()),
                         sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20,
                         640.f, 620.f);
  roadPlayer = new Label(std::to_string((*game.playerIterator)->roads->size()),
                         sf::Color(0, 0, 255, 128), font, sf::Text::Bold, 20,
                         680.f, 620.f);
}

void PlayView::drawLabelFigurePlayer() {
  createLabelFigurePlayer();
  view.draw(townPlayer->getTextInstance());
  view.draw(cityPlayer->getTextInstance());
  view.draw(roadPlayer->getTextInstance());
}

void PlayView::printPlayerFigure() {
  cityIterator = (*game.playerIterator)->citys->begin();
  townIterator = (*game.playerIterator)->towns->begin();
  if (townIterator != (*game.playerIterator)->towns->end())
    printImages((*townIterator)->getImagePath(), 590, 650);

  if (cityIterator != (*game.playerIterator)->citys->end())
    printImages((*cityIterator)->getImagePath(), 630, 650);
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
  view.draw(playerRectangle);
}

void PlayView::loadCardsRectangle() {
  cardsRectangle = playerRectangle;
  cardsRectangle.setPosition(350, 600);
  cardsRectangle.setSize({600, 100});
  view.draw(cardsRectangle);
}

void PlayView::loadGameButtons() {
  loadPlayersRectangle();
  loadCardsRectangle();
}

void PlayView::loadView() {
  view.create(sf::VideoMode(1280, 720), "Play");
  image.loadFromFile("Images/catan_1280x720.jpg");
  sprite.setTexture(image);
  font.loadFromFile("mononoki.ttf");
  view.setFramerateLimit(120);
}

void PlayView::drawView() {
  view.clear();
  view.draw(sprite);
  loadGameButtons();
  drawLabels();
  printBoard();
  printTownsTest();
  printMaterialCard();
  drawLabelNamePlayers();
  drawLabelNumTurn();
  printPlayerCard();
  drawLabelCardPlayer();
  drawLabelFigurePlayer();
  printPlayerFigure();
  createButtons();
  view.display();
}
void PlayView::traverseLands(double x, double y) {
  it = landsList->begin();
  while (it != landsList->end()) {
    searhTown(x, y, it);
    it++;
  }
}
void PlayView::initializeIteratorTownList() {
  townIterator = (*game.playerIterator)->towns->begin();
}
void PlayView::setIsClickedToVertexGraph(list<Vertex *>::iterator it) {
  game.graph.getVertex((*it)->getVertexId())->setIsClicked(true);
}
void PlayView::printTownPlayer(list<Vertex *>::iterator vIterator, int x,
                               int y) {
  if ((*game.playerIterator)->towns->size() > 0) {
    if ((*game.playerIterator)->getTownFirstTurn() < 2) {
      initializeIteratorTownList();
      setIsClickedToVertexGraph(vIterator);
      if (townIterator != (*game.playerIterator)->towns->end())
        printImages((*townIterator)->getImagePath(),
                    (*vIterator)->getTown()->getPosX(),
                    (*vIterator)->getTown()->getPosY());
      setOwnerToVertexGraph(game.graph.getVertex((*vIterator)->getVertexId()));
      deleteTowntoPlayer();
      (*game.playerIterator)->setTownFirstTurn(1);
      if ((*game.playerIterator)->getTownFirstTurn() == 2) {
        receiveFirstMaterialCard();
      }
      view.display();
    }
  }
  (*game.playerIterator)->setFirstTurnFinished(true);
}
void PlayView::searhTown(double x, double y, list<Land *>::iterator it) {
  list<Vertex *>::iterator vIterator;
  vIterator = (*it)->getTownsList()->begin();
  while (vIterator != (*it)->getTownsList()->end()) {
    if (isTownClicked(vIterator, x, y)) {
      printTownPlayer(vIterator, (int)x, (int)y);
    }
    vIterator++;
  }
}
void PlayView::receiveFirstCard(list<Land *>::iterator it) {
  list<Vertex *>::iterator vIterator;
  vIterator = (*it)->getTownsList()->begin();
  while (vIterator != (*it)->getTownsList()->end()) {
    if (game.graph.getVertex((*vIterator)->getVertexId())->getOwner() !=
        nullptr) {
      if (game.graph.getVertex((*vIterator)->getVertexId())
              ->getOwner()
              ->getName() == (*game.playerIterator)->getName()) {
        if ((*it)->getTypeLand() == "Mountain")
          (*game.playerIterator)->mineralCard->push_back(new Mineral());
        if ((*it)->getTypeLand() == "Brick")
          (*game.playerIterator)->clayCard->push_back(new Clay());
        if ((*it)->getTypeLand() == "Forest")
          (*game.playerIterator)->woodCard->push_back(new Wood());
        if ((*it)->getTypeLand() == "Grass")
          (*game.playerIterator)->woolCard->push_back(new Wool());
        if ((*it)->getTypeLand() == "Field")
          (*game.playerIterator)->wheatlCard->push_back(new Wheat());
      }
    }
    vIterator++;
  }
}
void PlayView::receiveFirstMaterialCard() {
  list<Land *>::iterator it;
  it = landsList->begin();
  while (it != landsList->end()) {
    receiveFirstCard(it);
    it++;
  }
}
void PlayView::firstTurn() {
  playerIterator = game.players->begin();
  while (playerIterator != game.players->end()) {
    if ((*playerIterator)->getFirstTurnFinished()) {
      isFirstTurn = false;
    } else {
      isFirstTurn = true;
    }

    playerIterator++;
  }
}
void PlayView::deleteTowntoPlayer() {
  if (townIterator != (*game.playerIterator)->towns->end())
    (*game.playerIterator)->towns->pop_back(); // poner alerta aca
}

void PlayView::setOwnerToVertexGraph(Vertex *vertex) {
  game.graph.getVertex(vertex->getVertexId())->setOwner((*game.playerIterator));
}

bool PlayView::isTownClicked(list<Vertex *>::iterator vertexIterator, double x,
                             double y) {
  return (x > (*vertexIterator)->getTown()->getPosX() &&
          x < (*vertexIterator)->getTown()->getPosX() + 30 &&
          y > (*vertexIterator)->getTown()->getPosY() &&
          y < (*vertexIterator)->getTown()->getPosY() + 30);
}

void PlayView::goView() {
  game.playerIterator = game.players->begin();
  game.loadLands();
  game.assignTownsToLand();
  game.makeGraph();
  landsList = game.getLandsList();
  loadView();
  drawView();
  start = true;
  view.draw(sprite);
  while (view.isOpen()) {
    sf::Event eventTest;
    srand((unsigned)time(nullptr));
    view.setFramerateLimit(120);
    while (view.pollEvent(eventTest)) {
      showCoordinates(eventTest);
      switch (eventTest.type) {
      case sf::Event::Closed:
        view.close();
        break;
      }
      break;
    }
    view.waitEvent(eventTest);
    if (eventTest.MouseButtonPressed &&
        eventTest.mouseButton.button == sf::Mouse::Left) {
      if (isFirstTurn) {
        traverseLands(sf::Mouse::getPosition(view).x,
                      sf::Mouse::getPosition(view).y);
      } else {
        isDiceButtonClicked(sf::Mouse::getPosition(view).x,
                            sf::Mouse::getPosition(view).y);
      }
      isTurnButtonClicked(sf::Mouse::getPosition(view).x,
                          sf::Mouse::getPosition(view).y);
    }
    drawView();
  }
}
void PlayView::isDiceButtonClicked(int x, int y) {
  if (dice.isMouseOver(view)) {
    if (!isDiceSpin) {
      numDice = 1 + rand() % 19;
      receiveMaterialCard(numDice);
      isDiceSpin = true;
    }
  }
}
void PlayView::receiveCard(list<Land *>::iterator it) {
  list<Vertex *>::iterator vIterator;
  vIterator = (*it)->getTownsList()->begin();
  playerIterator = game.players->begin();
  while (playerIterator != game.players->end()) {
    while (vIterator != (*it)->getTownsList()->end()) {
      if (game.graph.getVertex((*vIterator)->getVertexId())->getOwner() !=
          nullptr) {
        if (game.graph.getVertex((*vIterator)->getVertexId())
                ->getOwner()
                ->getName() == (*playerIterator)->getName()) {
          if ((*it)->getTypeLand() == "Mountain")
            (*playerIterator)->mineralCard->push_back(new Mineral());
          if ((*it)->getTypeLand() == "Brick")
            (*playerIterator)->clayCard->push_back(new Clay());
          if ((*it)->getTypeLand() == "Forest")
            (*playerIterator)->woodCard->push_back(new Wood());
          if ((*it)->getTypeLand() == "Grass")
            (*playerIterator)->woolCard->push_back(new Wool());
          if ((*it)->getTypeLand() == "Field")
            (*playerIterator)->wheatlCard->push_back(new Wheat());
        }
      }
      vIterator++;
    }
    vIterator = (*it)->getTownsList()->begin();
    playerIterator++;
  }
}
void PlayView::receiveMaterialCard(int idLand) {
  list<Land *>::iterator it;
  it = landsList->begin();
  while (it != landsList->end()) {
    if ((*it)->getLandId() == idLand) {
      receiveCard(it);
      break;
    }
    it++;
  }
}
void PlayView::isTurnButtonClicked(int x, int y) {
  if (turn.isMouseOver(view)) {
    if (game.playerIterator != game.players->end()) {
      game.playerIterator++;
      numTurn++;
      isDiceSpin = false;
    }
    if (game.playerIterator == game.players->end()) {
      game.playerIterator = game.players->begin();
      firstTurn();
      numTurn = 1;
    }
  }
}

void PlayView::setTurn(int numberPlayers) {
  log(turnNumber);
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

void PlayView::printImages(string imagePath, double posX, double posY) {
  sf::Texture path;
  path.loadFromFile(imagePath);
  sf::Sprite tempSprite(path);
  tempSprite.setPosition(static_cast<float>(posX), static_cast<float>(posY));
  view.draw(tempSprite);
}

void PlayView::initializeLandsList() {
  isPrintedFalse();
  it = landsList->begin();
}

void PlayView::isPrintedFalse() {
  Vertex *auxVertex = game.graph.firstVertex;
  while (auxVertex != nullptr) {
    auxVertex->setIsPrinted(false);
    auxVertex = auxVertex->next;
  }
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

void PlayView::setTempImagePath(string image) { this->tempImagePath = image; }
bool PlayView::isLandsListTraversal() const { return (it != landsList->end()); }
void PlayView::iterateLand() { it++; }
void PlayView::iterateLand2() { it2++; }

bool PlayView::isLastIteration(double number) const {
  return (number == lastIterationNumber);
}

void PlayView::lastIterationBehaviour(double number) {
  if (isLastIteration(number))
    lastIteration = true;
  else
    lastIteration = false;
}

void PlayView::setPosXYtoLand(double posX, double posY,
                              list<Land *>::iterator auxIt) {
  (*auxIt)->setPosX(posX);
  (*auxIt)->setPosY(posY);
}

void PlayView::setAndTraverse(double posX, double posY,
                              list<Land *>::iterator auxIt) {
  setTempImagePath((*auxIt)->getImagePath());
  setPosXYtoLand(posX, posY, auxIt);
  printImages(tempImagePath, posX, posY);
}

void PlayView::setAndTraverseTest(double posX, double posY,
                                  list<Land *>::iterator auxIt) {
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

void PlayView::traverseFirstAndLastRow(double posX, double topHeight,
                                       double botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(posX, topHeight, it);
    iterateLand();

    setAndTraverse(posX, botHeight, it2);
    iterateLand2();
  }
}

void PlayView::traverseSecondAndNextToLastRow(double posX, double topHeight,
                                              double botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(posX, topHeight, it);
    iterateLand();

    setAndTraverse(posX, botHeight, it2);
    iterateLand2();
  }
}

void PlayView::traverseMiddleRow(double posX, double topHeight,
                                 double botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(posX, topHeight, it2);
    iterateLand2();
  }
}

void PlayView::traverseFirstAndLastRowTest(double posX, double topHeight,
                                           double botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverseTest(posX, topHeight, it);
    iterateLand();

    setAndTraverseTest(posX, botHeight, it2);
    iterateLand2();
  }
}

void PlayView::traverseSecondAndNextToLastRowTest(double posX, double topHeight,
                                                  double botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverseTest(posX, topHeight, it);
    iterateLand();

    setAndTraverseTest(posX, botHeight, it2);
    iterateLand2();
  }
}

void PlayView::traverseMiddleRowTest(double posX, double topHeight,
                                     double botHeight) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverseTest(posX, topHeight, it2);
    iterateLand2();
  }
}

void PlayView::C_Traversal(double posX, double posY,
                           list<Land *>::iterator auxIt) {
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
  double relativePositionX =
      posX + landsRadius + (landsRadius * cos(getFormula(iterationNumber)));
  double relativePositionY =
      posY + landsRadius + (landsRadius * sin(getFormula(iterationNumber)));

  if (!getIsVertexGraphClicked(itX)) {
    if (!getIsVertexGraphPrinted(itX)) {
      game.graph.getVertex((*itX)->getVertexId())->setIsPrinted(true);
      printTowns(relativePositionX, relativePositionY);
      setPosXYtoVertex(itX, relativePositionX, relativePositionY);
      setPosXYtoVertexesGraph((*itX)->getVertexId(), relativePositionX,
                              relativePositionY);
    }
  } else if (!getIsVertexGraphPrinted(itX)) {
    game.graph.getVertex((*itX)->getVertexId())->setIsPrinted(true);
    townIterator =
        game.graph.getVertex((*itX)->getVertexId())
            ->getOwner()
            ->towns->begin(); //(*game.playerIterator)->towns->begin();
    if (townIterator !=
        game.graph.getVertex((*itX)->getVertexId())->getOwner()->towns->end())
      printImages((*townIterator)->getImagePath(), relativePositionX,
                  relativePositionY);
  }
}

bool PlayView::getIsVertexGraphClicked(list<Vertex *>::iterator it) {
  if (!game.graph.getVertex((*it)->getVertexId())->getIsClicked())
    return false;
  return true;
}

bool PlayView::getIsVertexGraphPrinted(list<Vertex *>::iterator it) {
  if (!game.graph.getVertex((*it)->getVertexId())->getIsPrint())
    return false;
  return true;
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
    log("mouse x: " << event.mouseButton.x);
    log("mouse y: " << event.mouseButton.y);
  }
}