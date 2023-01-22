#include "Window.hpp"

sf::RenderWindow playWindow(sf::VideoMode(1280, 720), "Play");

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

  sf::Texture playImage;
  playImage.loadFromFile("Images/catan_1280x720.jpg");
  sf::Sprite playSprite(playImage);

  playWindow.draw(playSprite);
  loadStartButtons();
  var = true;

  playWindow.display();
  while (playWindow.isOpen()) {
    sf::Event event;
    while (playWindow.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        playWindow.close();
        break;

      case sf::Event::KeyPressed:
        if (sf::Keyboard::Escape)
          playWindow.close();
        break;

      case sf::Event::MouseButtonPressed:

        if (event.mouseButton.button == sf::Mouse::Left) {
          showCoordinates(playWindow);
          if (sf::Mouse::getPosition(playWindow).x > 1080 &&
              sf::Mouse::getPosition(playWindow).y > 0 &&
              sf::Mouse::getPosition(playWindow).x < 1175 &&
              sf::Mouse::getPosition(playWindow).y < 40) {
            updateDisplay();
            playWindow.draw(playSprite);
            loadStartButtons();
            loadGameButtons();
            printBoard(playWindow);// se sale con codigo de error
            //printMaterialCard(playWindow);
            //printTown(playWindow); // se sale con codigo de error
          }
          if (sf::Mouse::getPosition(playWindow).x > 1200 &&
              sf::Mouse::getPosition(playWindow).y > 0 &&
              sf::Mouse::getPosition(playWindow).x < 1270 &&
              sf::Mouse::getPosition(playWindow).y < 40) {
            playWindow.close();
          }
        }
        break;
      }
    }
  }
}

void Window::updateDisplay() {
  playWindow.clear();
  playWindow.display();
}

bool Window::goBack(sf::RenderWindow &window) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return true;
  return false;
}

void Window::showCoordinates(sf::RenderWindow &window) {
  std::cout << "x: " << sf::Mouse::getPosition(window).x << std::endl;
  std::cout << "y: " << sf::Mouse::getPosition(window).y << std::endl;
}

void Window::printResources(sf::RenderWindow &window, string imagePath,
                            int posX, int posY) {
  // string imagePath = imagePath;
  sf::Texture path;
  path.loadFromFile(imagePath);
  sf::Sprite sprite(path);
  sprite.setPosition(static_cast<float>(posX), static_cast<float>(posY));
  window.draw(sprite);
}

void Window::loadStartButtons() {
  sf::RectangleShape start;
  sf::RectangleShape close;
  btnStart.createButton(playWindow, "Iniciar", start, {1080, 0},
                        sf::Color::Green, {95, 40}, {1085, 5});
  btnClose.createButton(playWindow, "Cerrar", close, {1185, 0}, sf::Color::Red,
                        {90, 40}, {1190, 5});
}

void Window::loadGameButtons() {
  Prueba.createButton(playWindow, "", prueba, {0, 0}, sf::Color::Blue, {0, 0},
                      {0, 0});

  sf::RectangleShape playerRectangle;
  sf::RectangleShape cardsRectangle;
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
void Window::initializeLandsList() {
  game.loadLands();
  landsList = game.getLandsList();
  it = landsList->begin();
  std::cout << (*it)->getType() << std::endl;
}

void Window::showLandsImagePath() {
  initializeLandsList();
  for (it; it != landsList->end(); it++)
    std::cout << (*it)->getImagePath() << std::endl;
}

void Window::printBoard(sf::RenderWindow &window) {
  int top_height = 30, bot_height = 30, cycle_cord_x = 0;
  string tempImagePath;


	int i = 1;
  // Traverse the list
  initializeLandsList();
  showLandsImagePath();

  bot_height += 295;
  for (cycle_cord_x = 530; cycle_cord_x <= 680; cycle_cord_x += 75) {
      if (landsList->begin() != landsList->end()) {
          tempImagePath = (*it)->getImagePath();//problemas
          Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
              top_height);
          it++;

          tempImagePath = (*it)->getImagePath();
          Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
              bot_height);
          it++;
      }
  }

  top_height += 75;
  bot_height = 250;
  for (cycle_cord_x = 505; cycle_cord_x <= 755; cycle_cord_x += 75) {
    tempImagePath = (*it)->getImagePath();
    Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                         top_height);
    it++;
    tempImagePath = (*it)->getImagePath();

    Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                         bot_height);
    it++;
  }

  top_height += 75;
  for (cycle_cord_x = 460; cycle_cord_x <= 760; cycle_cord_x += 75) {
    tempImagePath = (*it)->getImagePath();
	top_height += 75;
	}
Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                         top_height);
    it++;
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

    Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                         top_height);
    temp->town->setPosX(cycle_cord_x);
    temp->town->setPosY(top_height);
    temp = temp->next;

    Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                         bot_height);
    temp->town->setPosX(cycle_cord_x);
    temp->town->setPosY(top_height);
    temp = temp->next;
  }

  top_height += 75;
  bot_height = 255;
  for (cycle_cord_x = 525; cycle_cord_x <= 750; cycle_cord_x += 75) {

    Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                         top_height);
    temp->town->setPosX(cycle_cord_x);
    temp->town->setPosY(top_height);
    temp = temp->next;
    Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                         bot_height);
    temp->town->setPosX(cycle_cord_x);
    temp->town->setPosY(top_height);
    temp = temp->next;
  }

  top_height += 75;
  for (cycle_cord_x = 490; cycle_cord_x <= 750; cycle_cord_x += 75) {
    Window::getInstance().printResources(window, tempImagePath, cycle_cord_x,
                                         top_height);
    temp->town->setPosX(cycle_cord_x);
    temp->town->setPosY(top_height);
    temp = temp->next;
  }
}