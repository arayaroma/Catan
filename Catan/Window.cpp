#include "Window.hpp"

Button btnStart;
Button btnClose;

int cont = 0;
bool var = false;

void Window::goTitleView() {
  titleWindow.create(sf::VideoMode(1280, 720), "Main Menu");
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
                    showCoordinates(titleWindow, event);
                    // Pantalla Juego
                    if (event.mouseButton.x > 485 && event.mouseButton.y > 265 &&
                        event.mouseButton.x < 805 && event.mouseButton.y < 355) {
                        titleWindow.close();
                        // goPlayView(); 
                        goRegisterView();
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
  aboutWindow.create(sf::VideoMode(1280, 720), "About");
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
          showCoordinates(aboutWindow, event);
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

void  Window::goRegisterView() {
    registerView.create(sf::VideoMode(1280, 720), "Register");
    registerView.setKeyRepeatEnabled(true);
    sf::ConvexShape register;
    sf::Texture registerImage;
    registerImage.loadFromFile("Images/catan_1280x720.jpg");
    sf::Sprite registerSprite(registerImage);
    font.loadFromFile("mononoki.ttf");
    registerView.setFramerateLimit(120);
    TextBox name1 = TextBox(15, sf::Color::Black, false, { 345,240 }, { 180, 40 }, sf::Color::White);
    name1.serFont(font);
    name1.setPosition({ 365,250 });
    TextBox name2 = TextBox(15, sf::Color::Black, false, { 345,300 }, { 180, 40 }, sf::Color::White);
    name2.serFont(font);
    name2.setPosition({ 365,310 });
    TextBox name3 = TextBox(15, sf::Color::Black, false, { 345,360 }, { 180, 40 }, sf::Color::White);
    name3.serFont(font);
    name3.setPosition({ 365,370 });
    TextBox name4 = TextBox(15, sf::Color::Black, false, { 345,420 }, { 180, 40 }, sf::Color::White);
    name4.serFont(font);
    name4.setPosition({ 365,430 });

    Button btnPlay("Jugar", { 150,60 }, 20, sf::Color::Blue, sf::Color::Black);
    btnPlay.setPosition({ 1000,320 });
    btnPlay.setFont(font);
    Button btn3Players("3 Jugadores", { 200,60 }, 20, sf::Color::Green, sf::Color::Black);
    btn3Players.setPosition2({ 100,280 });
    btn3Players.setFont(font);
    Button btn4Players("4 Jugadores", { 200,60 }, 20, sf::Color::Green, sf::Color::Black);
    btn4Players.setPosition2({ 100,350 });
    btn4Players.setFont(font);
    while (registerView.isOpen())
    {
        sf::Event event;

        while (registerView.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:
                registerView.close();
             
            case sf::Event::TextEntered:
                if (name1.isMouseOver(registerView)) {
                    name1.typeOn(event);
                }
                else if (name2.isMouseOver(registerView)) {

                    name2.typeOn(event);
                }
                else if (name3.isMouseOver(registerView)) {

                    name3.typeOn(event);
                }
                else if (name4.isMouseOver(registerView)) {
                    name4.typeOn(event);
                }
                break;

            case sf::Event::KeyPressed:
                if (goBack(registerView)) {
                    registerView.close();
                    goTitleView();
                }
            case sf::Event::MouseButtonPressed:
                showCoordinates(registerView, event);
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (btnPlay.isMouseOver(registerView)) {
                       
                        goPlayView();
                        registerView.close();
                    }
                    else if (btn3Players.isMouseOver(registerView)) {

                        Player3 = true;
                    }
                    else if (btn4Players.isMouseOver(registerView)) {

                        Player4 = true;
                    }
                }
                break; 
            }
        }
        registerView.clear();
        registerView.draw(registerSprite);
        registerButton(registerView);
        loadRegisterButtons(registerView, btnPlay, btn3Players, btn4Players);
        btnPlay.drawTo(registerView);
        btn3Players.drawTo(registerView);
        btn4Players.drawTo(registerView);
        loadTextFields(registerView, name1, name2, name3, name4);
        registerView.display();
    }
}

void Window::loadTextFields(sf::RenderWindow& registerView, TextBox& name1, TextBox& name2, TextBox& name3, TextBox& name4) {

    if (Player3 == true) {
        if (name1.isMouseOver(registerView)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                name1.setSelected(true);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::End)) {
                name1.setSelected(false);
            }
        }
        else if (name2.isMouseOver(registerView)) {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                name2.setSelected(true);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::End)) {
                name2.setSelected(false);
            }
        }
        else if (name3.isMouseOver(registerView)) {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                name3.setSelected(true);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::End)) {
                name3.setSelected(false);
            }
        }
        else if (name4.isMouseOver(registerView)) {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                name4.setSelected(true);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::End)) {
                name4.setSelected(false);
            }
        }
    }

    if (Player3 == true) {
        name1.drawTo(registerView);
        name2.drawTo(registerView);
        name3.drawTo(registerView);
    }if (Player4 == true) {
        name4.drawTo(registerView);
    }

}

void Window::loadRegisterButtons(sf::RenderWindow& registerView, Button& btnPlay, Button& btn3Players, Button& btn4Players) {

    if (btnPlay.isMouseOver(registerView)) {
        btnPlay.setBackColor(sf::Color::White);
    }
    else {
        btnPlay.setBackColor(sf::Color::Blue);
    }
    if (btn3Players.isMouseOver(registerView)) {
        btn3Players.setBackColor(sf::Color::White);
    }
    else {
        btn3Players.setBackColor(sf::Color::Green);
    }
    if (btn4Players.isMouseOver(registerView)) {
        btn4Players.setBackColor(sf::Color::White);
    }
    else {
        btn4Players.setBackColor(sf::Color::Green);
    }
}

void Window::registerButton(sf::RenderWindow &window) {
    Label* title = new Label("Registro de Usuarios", sf::Color::Black, font, sf::Text::Bold, 30, 480.f, 50.f);
    Label* name = new Label("Nombre", sf::Color::Black, font, sf::Text::Bold, 20, 405.f, 200.f);
    Label* type = new Label("Tipo de jugador", sf::Color::Black, font, sf::Text::Bold, 20, 545.f, 200.f);
    Label* color = new Label("Color", sf::Color::Black, font, sf::Text::Bold, 20, 800.f, 200.f);
    
    window.draw(title->getTextInstance());
    window.draw(type->getTextInstance());
    window.draw(name->getTextInstance());
    window.draw(color->getTextInstance());
}

void Window::showCoordinates(sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {

        if (event.mouseButton.button == sf::Mouse::Right)
        {
            std::cout << "the right button was pressed" << std::endl;
            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
        }
    }
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            std::cout << "the Left button was pressed" << std::endl;
            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
        }
    }
}

void Window::goPlayView() {
  playWindow.create(sf::VideoMode(1280, 720), "Play");
  playWindow.setFramerateLimit(120);
  sf::Texture playImage;
  playImage.loadFromFile("Images/catan_1280x720.jpg");
  sf::Sprite playSprite(playImage);
  bool start = true;
  while (playWindow.isOpen()) {
    sf::Event event;
    while (playWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            playWindow.close();
        }
         playWindow.waitEvent(event);
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
    playWindow.clear();
    playWindow.draw(playSprite);
    loadGameButtons(playWindow);
    printMaterialCard(playWindow);
    printBoard();
   
    loadStartButtons(playWindow);
    loadGameButtons(playWindow);
    playWindow.display();
  }
 // consolePrintLandAndVertex();
 // log("Grafo");
 // game.graph.showAdjacencyList();
}

void Window::loadStartButtons(sf::RenderWindow &playWindow) {
 
    Button p("p", { 0,0 }, 20, sf::Color::Green, sf::Color::Black);
    p.setPosition3({ 0,50 });
  
    Button btnIni("Iniciar", { 100,40 }, 20, sf::Color::Green, sf::Color::Black);
    btnIni.setPosition3({ 1040,0 });
  
    Button btnClose("Cerrar", { 100,40 }, 20, sf::Color::Red, sf::Color::Black);
    btnClose.setPosition2({ 1145,0 });

    Button btnTurn("Turno", { 100,40 }, 20, sf::Color::Red, sf::Color::Black);
    btnTurn.setPosition2({ 980,600 });

    Button btnTrade("Comerciar", { 160,40 }, 20, sf::Color::Red, sf::Color::Black);
    btnTrade.setPosition2({ 30,625 });

    Button btnBuy("Comprar", { 130,40 }, 20, sf::Color::Red, sf::Color::Black);
    btnBuy.setPosition2({ 200,625 });

    btnClose.setFont(font);
    p.setFont(font);
    btnIni.setFont(font);
    btnTurn.setFont(font);
    btnTrade.setFont(font);
    btnBuy.setFont(font);

    if (btnIni.isMouseOver(playWindow)) {

        btnIni.setBackColor(sf::Color::Blue);
    }
    else {
        btnIni.setBackColor(sf::Color::Green);
    }
    if (btnClose.isMouseOver(playWindow)) {

        btnClose.setBackColor(sf::Color::Blue);
    }
    else {
        btnClose.setBackColor(sf::Color::Red);
    }
    if (btnTurn.isMouseOver(playWindow)) {

        btnTurn.setBackColor(sf::Color::Blue);
    }
    else {
        btnTurn.setBackColor(sf::Color::Magenta);
    }
    if (btnTrade.isMouseOver(playWindow)) {

        btnTrade.setBackColor(sf::Color::Blue);
    }
    else {
        btnTrade.setBackColor(sf::Color::Magenta);
    }
    if (btnBuy.isMouseOver(playWindow)) {

        btnBuy.setBackColor(sf::Color::Blue);
    }
    else {
        btnBuy.setBackColor(sf::Color::Magenta);
    }

    p.drawTo(playWindow);
    btnIni.drawTo(playWindow);
    btnClose.drawTo(playWindow);
    btnTurn.drawTo(playWindow);
    btnTrade.drawTo(playWindow);
    btnBuy.drawTo(playWindow);
}

void Window::setTurn(int numberPlayers) {
    std::cout << turnNumber << std::endl;

    if (turnNumber == numberPlayers) {
        turnNumber = 0;
        i = 100;
        drawTurn(turnNumber, i);
    }
    else {

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

/*void Window::loadStartButtons(sf::RenderWindow& playWindow) {
  sf::RectangleShape start;
  sf::RectangleShape close;
  //btnStart.createButton(playWindow, "Iniciar", start, {1080, 0},
                        //sf::Color::Green, {95, 40}, {1085, 5});
  //btnClose.createButton(playWindow, "Cerrar", close, {1185, 0}, sf::Color::Red,
                        //{90, 40}, {1190, 5});
}*/

void Window::loadGameButtons(sf::RenderWindow &playWindow) {
   
  sf::RectangleShape playerRectangle;
  sf::RectangleShape cardsRectangle;
  playerRectangle.setPosition(1020, 100);
  playerRectangle.setOutlineColor(sf::Color::White);
  playerRectangle.setSize({220, 400});
  playerRectangle.setFillColor(sf::Color(255, 255, 255, 128));
  playWindow.draw(playerRectangle);
  cardsRectangle = playerRectangle;
  cardsRectangle.setPosition(350, 600);
  cardsRectangle.setSize({600, 100});
  playWindow.draw(cardsRectangle);
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

void Window::printBoard() {
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
  Label *cards = new Label("Componentes", sf::Color(0, 0, 255, 128), font,
                           sf::Text::Bold, 20, 565.f, 575.f);

  printImages("Images/resourcesCards/clayCard.png", 0, 255);
  printImages("Images/resourcesCards/mineralCard.png", 70, 255);
  printImages("Images/resourcesCards/wheatCard.png", 140, 255);
  printImages("Images/resourcesCards/woodCard.png", 210, 255);
  printImages("Images/resourcesCards/woolCard.png", 280, 255);
  printImages("Images/extraCards/progressCardBackwards.png", 0, 385);
  printImages("Images/extraCards/pricingTable.jpeg", 0, 25);

  window.draw(materialCard->getTextInstance());
  window.draw(pricingTable->getTextInstance());
  window.draw(turns->getTextInstance());
  window.draw(cards->getTextInstance());
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
