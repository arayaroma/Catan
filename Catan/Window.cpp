#include "Window.hpp"
/*
Button btnStart;
Button btnClose;*/

int cont = 0;
bool var = false;

void Window::goTitleView() {
 
    sf::RenderWindow titleWindow(sf::VideoMode(1280, 720), "Main Menu");
    sf::Texture titleImage;
    titleImage.loadFromFile("Images/inicio.jpg");
    sf::Sprite titleSprite(titleImage);
    font.loadFromFile("mononoki.ttf");

    Label* title = new Label("Catan", sf::Color::Black, font, sf::Text::Bold, 100,
        500.f, 50.f);
    Label* play = new Label("Jugar", sf::Color::Black, font, sf::Text::Bold, 100,
        500.f, 250.f);
    Label* about = new Label("Acerca", sf::Color::Black, font, sf::Text::Bold,
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

void  Window::goRegisterView() {
  
    sf::RenderWindow registerView(sf::VideoMode(1280, 720), "About");
     registerView.setKeyRepeatEnabled(true);

    sf::ConvexShape register; 
    sf::Texture registerImage;
    registerImage.loadFromFile("Images/catan_1280x720.jpg");
    sf::Sprite registerSprite(registerImage);
    font.loadFromFile("mononoki.ttf");

    TextBox text1 = TextBox(15, sf::Color::Black, false, { 345,240 }, { 180, 40 }, sf::Color::White);
    text1.serFont(font);
    text1.setPosition({ 365,250 });

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            text1.setSelected(true);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            text1.setSelected(false);
        }

        while (registerView.pollEvent(event))
        {
            switch (event.type) {
            case sf::Event::Closed:

                registerView.close();

            case sf::Event::TextEntered:

                text1.typeOn(event);

                break;

            case sf::Event::KeyPressed:
                if (goBack(registerView)) {
                    registerView.close();
                    goTitleView();
                }

            case sf::Event::MouseMoved:

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
                break; 

            case sf::Event::MouseButtonPressed:

                if (event.mouseButton.button == sf::Mouse::Left && btnPlay.isMouseOver(registerView)) {
                   
                    registerView.close(); 
                    goPlayView();
                }
            }

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
        registerView.clear(); 
        registerView.draw(registerSprite); 
        registerButton(registerView);
        text1.drawTo(registerView);
        btnPlay.drawTo(registerView);
        btn3Players.drawTo(registerView);
        btn4Players.drawTo(registerView); 
        registerView.display();
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

void Window::goPlayView() {
  sf::RenderWindow playWindow(sf::VideoMode(1280, 720), "Play");
  sf::Texture playImage;
  playImage.loadFromFile("Images/catan_1280x720.jpg");
  sf::Sprite playSprite(playImage);
  playWindow.setFramerateLimit(120);

  while (playWindow.isOpen()) {
    playWindow.clear();
    sf::Event event;
    while (playWindow.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:

            playWindow.close();
        }
     }
    playWindow.clear();
    playWindow.draw(playSprite);
   
    printBoard(playWindow);
    printMaterialCard(playWindow);
    printTown(playWindow);
    loadStartButtons(playWindow);
    loadGameButtons(playWindow);
    playWindow.display();
  }
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
void Window::drawTurn(int turns, int posiI) {
    // turn.move(1020,posiI);
}
bool Window::goBack(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return true;
    return false;
}
void Window::showCoordinates(sf::RenderWindow& window) {
    std::cout << "x: " << sf::Mouse::getPosition(window).x << std::endl;
    std::cout << "y: " << sf::Mouse::getPosition(window).y << std::endl;
}
void Window::printResources(sf::RenderWindow& window, string imagePath,
int posX, int posY) {
    // string imagePath = imagePath;
    sf::Texture path;
    path.loadFromFile(imagePath);
    sf::Sprite sprite(path);
    sprite.setPosition(static_cast<float>(posX), static_cast<float>(posY));
    window.draw(sprite);
}

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
void Window::initializeLandsList() {
  game.loadLands();
  landsList = game.getLandsList();
  it = landsList->begin();
  // std::cout << (*it)->getType() << std::endl;
}

void Window::showLandsImagePath() {
  // initializeLandsList();
  // for (it; it != landsList->end(); it++)
  // std::cout << (*it)->getImagePath() << std::endl;
}

void Window::printBoard(sf::RenderWindow &window) {
  int top_height = 30, bot_height = 30, cycle_cord_x = 0, i = 1;
  string tempImagePath;
  initializeLandsList();
  // showLandsImagePath();

  bot_height += 295;
  for (cycle_cord_x = 530; cycle_cord_x <= 680; cycle_cord_x += 75) {
    if (landsList->begin() != landsList->end()) {
      tempImagePath = (*it)->getImagePath(); // problemas
      Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                           top_height);
      (*it)->setPosX(cycle_cord_x);
      (*it)->setPosY(top_height);
      calculateHexagonVertexes(it, cycle_cord_x, top_height);
      it++;
      tempImagePath = (*it)->getImagePath();
      Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                           bot_height);
      (*it)->setPosX(cycle_cord_x);
      (*it)->setPosY(bot_height);
      it++;
      calculateHexagonVertexes(it, cycle_cord_x, top_height);
    }
  }

  top_height += 75;
  bot_height = 250;
  for (cycle_cord_x = 505; cycle_cord_x <= 755; cycle_cord_x += 75) {
    tempImagePath = (*it)->getImagePath();
    Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                         top_height);
    (*it)->setPosX(cycle_cord_x);
    (*it)->setPosY(top_height);
    it++;
    tempImagePath = (*it)->getImagePath();

    Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                         bot_height);
    (*it)->setPosX(cycle_cord_x);
    (*it)->setPosY(top_height);
    it++;
  }

  top_height += 75;
  for (cycle_cord_x = 460; cycle_cord_x <= 760; cycle_cord_x += 75) {
    tempImagePath = (*it)->getImagePath();
    Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                         top_height);
    (*it)->setPosX(cycle_cord_x);
    (*it)->setPosY(top_height);
    it++;
  }
}

void Window::loadHexagonNodes(list<Vertex *>::iterator it, double posX,
                              double posY) {
  double relativePositionX =
      posX + (landsRadius * cos(getFormula((*it)->getVertexId())));
  double relativePositionY =
      posY + (landsRadius * sin(getFormula((*it)->getVertexId())));
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

void Window::calculateHexagonVertexes(list<Land *>::iterator it, int x, int y) {

  // del for para empezar a dibujar desde l
  /*aca se van a calcular todos los vertices de cada uno de los hexagonos*/
  /*utilizando la formula*/
  /*cuando se calcula el vertice, se manda posicion (x y) y el id del vertice al
   * metodo printTown*/
  /*para poder obtener el id del vertice de la lista del hexagono, se debe
   * recorrer la lista en orden*/
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

  printResources(window, "Images/resourcesCards/clayCard.png", 0, 255);
  printResources(window, "Images/resourcesCards/mineralCard.png", 70, 255);
  printResources(window, "Images/resourcesCards/wheatCard.png", 140, 255);
  printResources(window, "Images/resourcesCards/woodCard.png", 210, 255);
  printResources(window, "Images/resourcesCards/woolCard.png", 280, 255);
  printResources(window, "Images/extraCards/progressCardBackwards.png", 0, 385);
  printResources(window, "Images/extraCards/pricingTable.jpeg", 0, 25);
  window.draw(materialCard->getTextInstance());
  window.draw(pricingTable->getTextInstance());
  window.draw(turns->getTextInstance());
  window.draw(cards->getTextInstance());
}

void Window::printTown(sf::RenderWindow &window) {
  int top_height = 25, bot_height = 25, cycle_cord_x = 0, i = 1;
  game.makeGraph();
  Vertex *temp = game.graph.firstVertex;
  // Cambiar -> mapa de Rutas
  string tempImagePath = "Images/puebloX.png";
  bot_height += 295;
  for (cycle_cord_x = 560; cycle_cord_x <= 710; cycle_cord_x += 75) {
    if (cycle_cord_x == 710) {
      Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                           top_height);
      setPosXYtoVertex(temp, cycle_cord_x, top_height);
      printNeighborsTowns(window, temp, tempImagePath, cycle_cord_x,
                          top_height);
      printNeighborsFinalTowns(window, temp, tempImagePath, cycle_cord_x,
                               top_height);
    } else {
      Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                           top_height);
      setPosXYtoVertex(temp, cycle_cord_x, top_height);
      printNeighborsTowns(window, temp, tempImagePath, cycle_cord_x,
                          top_height);
      temp = temp->next;
    }
  }
  temp = game.graph.getVertex(40);
  for (cycle_cord_x = 560; cycle_cord_x <= 710; cycle_cord_x += 75) {
    if (cycle_cord_x == 710) {
      Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                           bot_height);
      setPosXYtoVertex(temp, cycle_cord_x, bot_height);
      printNeighborsTowns(window, temp, tempImagePath, cycle_cord_x,
                          bot_height);
      printNeighborsFinalTowns(window, temp, tempImagePath, cycle_cord_x,
                               bot_height);
    } else {
      Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                           bot_height);
      setPosXYtoVertex(temp, cycle_cord_x, bot_height);
      printNeighborsTowns(window, temp, tempImagePath, cycle_cord_x,
                          bot_height);
      temp = temp->next;
    }
  }
  temp = game.graph.getVertex(8);
  top_height += 75;
  bot_height = 250;
  for (cycle_cord_x = 535; cycle_cord_x <= 760; cycle_cord_x += 75) {
    if (cycle_cord_x == 760) {
      Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                           top_height);
      setPosXYtoVertex(temp, cycle_cord_x, top_height);
      printNeighborsTowns(window, temp, tempImagePath, cycle_cord_x,
                          top_height);
      printNeighborsFinalTowns(window, temp, tempImagePath, cycle_cord_x,
                               top_height);
    } else {
      Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                           top_height);
      setPosXYtoVertex(temp, cycle_cord_x, top_height);
      printNeighborsTowns(window, temp, tempImagePath, cycle_cord_x,
                          top_height);
      temp = temp->next;
    }
  }
  temp = game.graph.getVertex(29);
  for (cycle_cord_x = 535; cycle_cord_x <= 760; cycle_cord_x += 75) {
    if (cycle_cord_x == 760) {
      Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                           bot_height);
      setPosXYtoVertex(temp, cycle_cord_x, bot_height);
      printNeighborsTowns(window, temp, tempImagePath, cycle_cord_x,
                          bot_height);
      printNeighborsFinalTowns(window, temp, tempImagePath, cycle_cord_x,
                               bot_height);
    } else {
      Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                           bot_height);
      setPosXYtoVertex(temp, cycle_cord_x, bot_height);
      printNeighborsTowns(window, temp, tempImagePath, cycle_cord_x,
                          bot_height);
      temp = temp->next;
    }
  }
  temp = game.graph.getVertex(17);
  top_height += 75;
  for (cycle_cord_x = 490; cycle_cord_x <= 790; cycle_cord_x += 75) {
    if (cycle_cord_x == 790) {
      Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                           top_height);
      setPosXYtoVertex(temp, cycle_cord_x, top_height);
      printNeighborsTowns(window, temp, tempImagePath, cycle_cord_x,
                          top_height);
      printNeighborsFinalTowns(window, temp, tempImagePath, cycle_cord_x,
                               top_height);
    } else {
      Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                           top_height);
      setPosXYtoVertex(temp, cycle_cord_x, top_height);
      printNeighborsTowns(window, temp, tempImagePath, cycle_cord_x,
                          top_height);
      temp = temp->next;
    }
  }
  // game.printVertexXY();
}
void Window::printNeighborsTowns(sf::RenderWindow &window, Vertex *temp,
                                 std::string tempImagePath, int x, int y) {
  Window::getInstance().printResources(window, tempImagePath, x - 35, y + 25);
  // temp = game.graph.getVertex(game.graph.getIdVertex(temp) + 3);
  // assingXYtoTowns(temp, x - 35, y + 25);

  Window::getInstance().printResources(window, tempImagePath, x - 35, y + 50);
  // temp = game.graph.getVertex(game.graph.getIdVertex(temp) + 7);
  // assingXYtoTowns(temp, x - 35, y + 50);

  Window::getInstance().printResources(window, tempImagePath, x, y + 60);
  // temp = game.graph.getVertex(game.graph.getIdVertex(temp) + 12);
  // assingXYtoTowns(temp, x, y + 60);
}
void Window::printNeighborsFinalTowns(sf::RenderWindow &window, Vertex *temp,
                                      std::string tempImagePath, int x, int y) {
  Window::getInstance().printResources(window, tempImagePath, x + 30, y + 25);
  // temp = game.graph.getVertex(game.graph.getIdVertex(temp) + 4);
  // assingXYtoTowns(temp, x + 30, y + 25);

  Window::getInstance().printResources(window, tempImagePath, x + 30, y + 50);
  // temp = game.graph.getVertex(game.graph.getIdVertex(temp) + 8);
  // assingXYtoTowns(temp, x + 30, y + 50);
}
void Window::setPosXYtoVertex(Vertex *temp, int x, int y) {
  temp->town->setPosX(x);
  temp->town->setPosY(y);
}