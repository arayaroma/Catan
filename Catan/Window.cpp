#include "Window.hpp"

Button btnStart;
Button btnClose;

int cont = 0;
bool var = false;

void Window::goTitleView() {
  sf::RenderWindow titleWindow(sf::VideoMode(1280, 720), "Main Menu");
  sf::Texture titleImage;
  titleImage.loadFromFile("Images/inicio.jpg");
  sf::Sprite titleSprite(titleImage);
  font.loadFromFile("mononoki.ttf");
  Label *title = new Label("Catan", sf::Color::Black, font, sf::Text::Bold, 100,
                           500.f, 50.f);
  Label *play = new Label("Jugar", sf::Color::Black, font, sf::Text::Bold, 100,
                          500.f, 250.f);
  Label *about = new Label("Acerca", sf::Color::Black, font, sf::Text::Bold,
                           100, 500.f, 450.f);
  titleWindow.draw(titleSprite);
  titleWindow.draw(title->getTextInstance());
  titleWindow.draw(play->getTextInstance());
  titleWindow.draw(about->getTextInstance());
  titleWindow.display();

  while (titleWindow.isOpen()) {
    sf::Event event;
    while (titleWindow.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        titleWindow.close();
        break;

      case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left) {
          showCoordinates(titleWindow);
          // Pantalla Juego
          if (event.mouseButton.x > 485 && event.mouseButton.y > 265 &&
              event.mouseButton.x < 805 && event.mouseButton.y < 355) {
            titleWindow.close();
            goPlayView();
          }
          // pantalla de acerca de
          if (event.mouseButton.x > 485 && event.mouseButton.y > 460 &&
              event.mouseButton.x < 850 && event.mouseButton.y < 560) {
            titleWindow.close();
            goAboutView();
          }
        }
        break;

      default:
        if (goBack(titleWindow))
          titleWindow.close();
        break;
      }
    }
  }
}

void Window::goAboutView() {
  sf::RenderWindow aboutWindow(sf::VideoMode(1280, 720), "About");
  sf::Texture aboutImage;
  aboutImage.loadFromFile("Images/acercaDe.jpg");
  sf::Sprite aboutSprite(aboutImage);
  font.loadFromFile("mononoki.ttf");
  Label *back =
      new Label("<---", sf::Color::Black, font, sf::Text::Bold, 18, 20.f, 20.f);

  aboutWindow.draw(aboutSprite);
  aboutWindow.draw(back->getTextInstance());
  aboutWindow.display();

  while (aboutWindow.isOpen()) {
    sf::Event event;
    while (aboutWindow.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        aboutWindow.close();
        break;

      case sf::Event::MouseButtonPressed:
        if (event.mouseButton.button == sf::Mouse::Left)
          showCoordinates(aboutWindow);
        break;

      case sf::Event::KeyPressed:
        if (goBack(aboutWindow)) {
          aboutWindow.close();
          goTitleView();
        }
        break;
      default:
        if (goBack(aboutWindow))
          aboutWindow.close();
        break;
      }
    }
  }
}

void Window::goPlayView() {
  sf::RenderWindow playWindow(sf::VideoMode(1280, 720), "Play");
  sf::Texture playImage;
  playImage.loadFromFile("Images/catan_1280x720.jpg");
  sf::Sprite playSprite(playImage);
  bool start = true;
  // playWindow.draw(playSprite);
  // loadStartButtons(playWindow);
  // var = true;
  // playWindow.display();
  playWindow.setFramerateLimit(120);

  while (playWindow.isOpen()) {
    sf::Event event;
    playWindow.clear();
    while (playWindow.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        playWindow.close();
      }

      // playWindow.waitEvent(event);

      if (event.MouseButtonPressed &&
          event.mouseButton.button == sf::Mouse::Left) {
        // showCoordinates(playWindow);
        if (sf::Mouse::getPosition(playWindow).x > 1080 &&
            sf::Mouse::getPosition(playWindow).y > 0 &&
            sf::Mouse::getPosition(playWindow).x < 1175 &&
            sf::Mouse::getPosition(playWindow).y < 40) {
          playWindow.clear();
          playWindow.draw(playSprite);
        }
        if (sf::Mouse::getPosition(playWindow).x > 1200 &&
            sf::Mouse::getPosition(playWindow).y > 0 &&
            sf::Mouse::getPosition(playWindow).x < 1270 &&
            sf::Mouse::getPosition(playWindow).y < 40) {
          setTurn(4);
        }
      }
    }
    playWindow.draw(playSprite);
    loadGameButtons(playWindow);
    printBoard(playWindow);
    printMaterialCard(playWindow);
    // printTown(playWindow);
    loadStartButtons(playWindow);
    playWindow.display();
  }
}

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
  std::cout << "x: " << sf::Mouse::getPosition(window).x << std::endl;
  std::cout << "y: " << sf::Mouse::getPosition(window).y << std::endl;
}

void Window::printImages(sf::RenderWindow &window, string imagePath, int posX,
                         int posY) {
  // string imagePath = imagePath;
  sf::Texture path;
  path.loadFromFile(imagePath);
  sf::Sprite sprite(path);
  sprite.setPosition(static_cast<float>(posX), static_cast<float>(posY));
  window.draw(sprite);
}

void Window::loadStartButtons(sf::RenderWindow &playWindow) {
  sf::RectangleShape start;
  sf::RectangleShape close;
  btnStart.createButton(playWindow, "Iniciar", start, {1080, 0},
                        sf::Color::Green, {95, 40}, {1085, 5});
  btnClose.createButton(playWindow, "Cerrar", close, {1185, 0}, sf::Color::Red,
                        {90, 40}, {1190, 5});
}

void Window::loadGameButtons(sf::RenderWindow &playWindow) {
  Prueba.createButton(playWindow, "", prueba, {0, 0}, sf::Color::Blue, {0, 0},
                      {0, 0});

  sf::RectangleShape playerRectangle;
  sf::RectangleShape cardsRectangle;
  turn.setPosition(1020, 100);
  turn.setOutlineColor(sf::Color::Black);
  turn.setSize({220, 90});
  turn.setFillColor(sf::Color(255, 255, 255, 128));
  playWindow.draw(turn);

  playerRectangle.setPosition(1020, 100);
  playerRectangle.setOutlineColor(sf::Color::Black);
  playerRectangle.setSize({220, 400});
  playerRectangle.setFillColor(sf::Color(255, 255, 255, 128));
  playWindow.draw(playerRectangle);
  cardsRectangle = playerRectangle;
  cardsRectangle.setPosition(350, 600);
  cardsRectangle.setSize({600, 100});
  playWindow.draw(cardsRectangle);
  // x y                                     x+  y+      pos Label
  btnTrade.createButton(playWindow, "Comerciar", trade, {25, 650},
                        sf::Color(0, 0, 255, 110), {125, 40}, {30, 650});
  btnBuy.createButton(playWindow, "Comprar", buy, {170, 650},
                      sf::Color(0, 0, 255, 110), {130, 40}, {185, 650});
  btnTurns.createButton(playWindow, "Turno", Turnos, {1170, 590},
                        sf::Color(0, 0, 255, 110), {90, 40}, {1175, 590});
  btnClose.createButton(playWindow, "Cerrar", close2, {1170, 650},
                        sf::Color(0, 0, 255, 110), {90, 40}, {1175, 650});
  btnOpcional1.createButton(playWindow, "opcional1", opcional1, {1000, 590},
                            sf::Color(0, 0, 255, 110), {130, 40}, {1010, 590});
  btnOpcional2.createButton(playWindow, "opcional2", opcional2, {1000, 650},
                            sf::Color(0, 0, 255, 110), {130, 40}, {1010, 650});
}

// Agregado recientemente -> Separar en clases los metodos de Window
void Window::setTempImagePath(string image) { this->tempImagePath = image; }

bool Window::isLandsListTraversal() const { return (it != landsList->end()); }

void Window::iterateLand() { it++; }

bool Window::isLastIteration(int number) const {
  return (number == lastIterationNumber);
}

void Window::lastIterationBehaviour(int number) {
    if (isLastIteration(number)) {
        lastIteration = true;
    }
    else {
        lastIteration = false;
    }
 
}

void Window::setPosXYtoLand(double posX, double posY) {
  (*it)->setPosX(posX);
  (*it)->setPosY(posY);
}

void Window::setAndTraverse(sf::RenderWindow &window, int posX, int posY) {
  setTempImagePath((*it)->getImagePath());
  setPosXYtoLand(posX, posY);
  Window::getInstance().printImages(window, tempImagePath, posX, posY);
  C_Traversal(window, posX, posY);
}
void Window::initializeLandsList() {
  game.loadLands();
  game.assignTownsToLand();
  landsList = game.getLandsList();
  it = landsList->begin();
}
void Window::initializeGraph() {
    game.makeGraph();
    game.assignTownsToLand();
}
void Window::initializeVertexesList() {
  vertexesList = (*it)->getTownsList();
  vertexIterator = vertexesList.begin();
}

bool Window::isVertexesListTraversal() const {
  return (vertexIterator != vertexesList.end());
}

void Window::iterateVertex() { vertexIterator++; }

bool Window::isTwoLastVertex() const {
  return (vertexIterationNumber == 3 || vertexIterationNumber == 5);
}

void Window::traverseFirstAndLastRow(int posX, int topHeight, int botHeight,
                                     sf::RenderWindow &window) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(window, posX, topHeight);
    iterateLand();

    setAndTraverse(window, posX, botHeight);
    iterateLand();
  }
}

void Window::traverseSecondAndNextToLastRow(int posX, int topHeight,
                                            int botHeight,
                                            sf::RenderWindow &window) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(window, posX, topHeight);
    iterateLand();

    setAndTraverse(window, posX, botHeight);
    iterateLand();
  }
}

void Window::traverseMiddleRow(int posX, int topHeight, int botHeight,
                               sf::RenderWindow &window) {
  if (isLandsListTraversal()) {
    lastIterationBehaviour(posX);

    setAndTraverse(window, posX, topHeight);
    iterateLand();
  }
}

void Window::C_Traversal(sf::RenderWindow &window, int posX, int posY) {
  vertexIterationNumber = 1;
  initializeVertexesList();

  for (vertexIterationNumber; vertexIterationNumber < 7;
       vertexIterationNumber++) {
    if (isVertexesListTraversal()) {
      if (!isTwoLastVertex()) {
            loadHexagonNodes(window, vertexIterator, posX, posY,
                vertexIterationNumber);
            iterateVertex();
      }

      if (isTwoLastVertex() && !lastIteration) {
          setHexagonCoordinates(vertexIterator, posX, posY,
              vertexIterationNumber);
          iterateVertex();
      }
      if (lastIteration) {
        loadHexagonNodes(window, vertexIterator, posX, posY,
                         vertexIterationNumber);
        iterateVertex();
      }
    }
  }
}
void Window::printBoard(sf::RenderWindow &window) {
  int top_height = 30, bot_height = 30, cycle_cord_x = 0, i = 1;
  initializeLandsList();
  initializeGraph();
  bot_height += 330;
  for (cycle_cord_x = 530; cycle_cord_x <= 680; cycle_cord_x += 75) {
    traverseFirstAndLastRow(cycle_cord_x, top_height, bot_height, window);
  }
  lastIteration = false;
  top_height += 80;
  bot_height = 270;
  lastIterationNumber = 755;
  for (cycle_cord_x = 505; cycle_cord_x <= 755; cycle_cord_x += 75) {

    traverseSecondAndNextToLastRow(cycle_cord_x, top_height, bot_height,
                                   window);
  }
  lastIteration = false;
  top_height += 80;
  lastIterationNumber = 760;
  for (cycle_cord_x = 460; cycle_cord_x <= 760; cycle_cord_x += 75) {
    traverseMiddleRow(cycle_cord_x, top_height, bot_height, window);
  }
}

void Window::loadHexagonNodes(sf::RenderWindow &window,
                              list<Vertex *>::iterator it, double posX,
                              double posY, int iterationNumber) {
  if (iterationNumber < 4) {
    double relativePositionX = posX - 10 + landsRadius +
                               (landsRadius * cos(getFormula(iterationNumber)));
    double relativePositionY = posY - 20 + landsRadius +
                               (landsRadius * sin(getFormula(iterationNumber)));
    printTowns(window, relativePositionX, relativePositionY - 3);
    setPosXYtoVertex(it,  relativePositionX,  relativePositionY);
    setPosXYtoVertexesGraph((*it)->getVertexId(), relativePositionX, relativePositionY);
  } else {
    double relativePositionX = posX - 10 + landsRadius +
                               (landsRadius * cos(getFormula(iterationNumber)));
    double relativePositionY = posY - 20 + landsRadius +
                               (landsRadius * sin(getFormula(iterationNumber)));
    printTowns(window, relativePositionX, relativePositionY + 15);
    setPosXYtoVertex(it, relativePositionX, relativePositionY);
    setPosXYtoVertexesGraph((*it)->getVertexId(), relativePositionX, relativePositionY);
  }
}

void Window::setHexagonCoordinates(list<Vertex *>::iterator vertexIterator,
                                   double posX, double posY,
                                   int iterationNumber) {
  double relativePositionX = posX - 10 + landsRadius +
                             (landsRadius * cos(getFormula(iterationNumber)));
  double relativePositionY = posY - 20 + landsRadius +
                             (landsRadius * sin(getFormula(iterationNumber)));
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

void Window::printMaterialCard(sf::RenderWindow &window) {
  Label *materialCard =
      new Label("Cartas de Materiales", sf::Color(0, 0, 255, 128), font,
                sf::Text::Bold, 20, 5.f, 230.f);
  Label *pricingTable = new Label("Tabla de precios", sf::Color(0, 0, 255, 128),
                                  font, sf::Text::Bold, 20, 5.f, 0.f);
  Label *turns = new Label("Jugadores", sf::Color(0, 0, 255, 128), font,
                           sf::Text::Bold, 20, 1050.f, 60.f);
  Label *cards = new Label("Cartas", sf::Color(0, 0, 255, 128), font,
                           sf::Text::Bold, 20, 565.f, 575.f);

  printImages(window, "Images/resourcesCards/clayCard.png", 0, 255);
  printImages(window, "Images/resourcesCards/mineralCard.png", 70, 255);
  printImages(window, "Images/resourcesCards/wheatCard.png", 140, 255);
  printImages(window, "Images/resourcesCards/woodCard.png", 210, 255);
  printImages(window, "Images/resourcesCards/woolCard.png", 280, 255);
  printImages(window, "Images/extraCards/progressCardBackwards.png", 0, 385);
  printImages(window, "Images/extraCards/pricingTable.jpeg", 0, 25);
  window.draw(materialCard->getTextInstance());
  window.draw(pricingTable->getTextInstance());
  window.draw(turns->getTextInstance());
  window.draw(cards->getTextInstance());
}

void Window::printTowns(sf::RenderWindow &window, double x, double y) {
  string tempImagePath = "Images/puebloX.png";
  Window::getInstance().printImages(window, tempImagePath, static_cast<int>(x),
                                    static_cast<int>(y));
}
void Window::setPosXYtoVertex(list<Vertex*>::iterator vertexIterator, double x, double y) {
    (*vertexIterator)->town->setPosX(x);
    (*vertexIterator)->town->setPosY(y);
}
void Window::setPosXYtoVertexesGraph(int idVertex, double x, double y) {
    game.graph.getVertex(idVertex)->getTown()->setPosX(x);
    game.graph.getVertex(idVertex)->getTown()->setPosY(y);
}