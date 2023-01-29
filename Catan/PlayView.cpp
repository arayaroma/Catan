#include "PlayView.hpp"

void PlayView::loadPlayView() {
  playView.create(sf::VideoMode(1280, 720), "Play");
  playView.setFramerateLimit(120);
  playImage.loadFromFile("Images/catan_1280x720.jpg");
  playSprite.setTexture(playImage);
}

void PlayView::loadGameButtons() {
  playerRectangle.setPosition(1020, 100);
  playerRectangle.setOutlineColor(sf::Color::White);
  playerRectangle.setSize({220, 400});
  playerRectangle.setFillColor(sf::Color(255, 255, 255, 128));
  playView.draw(playerRectangle);
  cardsRectangle = playerRectangle;
  cardsRectangle.setPosition(350, 600);
  cardsRectangle.setSize({600, 100});
  playView.draw(cardsRectangle);
}

void PlayView::goPlayView() {
  start = true;
  while (playView.isOpen()) {
    while (playView.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        playView.close();
      }
      playView.waitEvent(event);
      if (event.MouseButtonPressed &&
          event.mouseButton.button == sf::Mouse::Left) {
        // showCoordinates(playWindow);
        if (sf::Mouse::getPosition(playView).x > 1080 &&
            sf::Mouse::getPosition(playView).y > 0 &&
            sf::Mouse::getPosition(playView).x < 1175 &&
            sf::Mouse::getPosition(playView).y < 40) {
          playView.clear();
          playView.draw(playSprite);
        }
        if (sf::Mouse::getPosition(playView).x > 1200 &&
            sf::Mouse::getPosition(playView).y > 0 &&
            sf::Mouse::getPosition(playView).x < 1270 &&
            sf::Mouse::getPosition(playView).y < 40) {
          setTurn(4);
        }
      }
    }
    playView.clear();
    playView.draw(playSprite);
    loadGameButtons();
    printMaterialCard();
    printBoard();

    // loadStartButtons(playWindow);
    loadGameButtons();
    playView.display();
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
  playView.draw(materialCard->getTextInstance());
  playView.draw(pricingTable->getTextInstance());
  playView.draw(turns->getTextInstance());
  playView.draw(cards->getTextInstance());
}

void PlayView::printMaterialCard() {
  createLabels();
  printImages("Images/resourcesCards/clayCard.png", 0, 255);
  printImages("Images/resourcesCards/mineralCard.png", 70, 255);
  printImages("Images/resourcesCards/wheatCard.png", 140, 255);
  printImages("Images/resourcesCards/woodCard.png", 210, 255);
  printImages("Images/resourcesCards/woolCard.png", 280, 255);
  printImages("Images/extraCards/progressCardBackwards.png", 0, 385);
  printImages("Images/extraCards/pricingTable.jpeg", 0, 25);
  drawLabels();
}

// Ver que pex con Game -> Window
void PlayView::initializeLandsList() {
  window.game.loadLands();
  window.game.assignTownsToLand();
  window.game.makeGraph();
  window.landsList = window.game.getLandsList();
  window.it = window.landsList->begin();
}
void PlayView::printBoard() {
  int top_height = 30, bot_height = 30, cycle_cord_x = 0, i = 1;
  initializeLandsList();
  bot_height += 330;
  window.it2 = window.landsList->begin();
  std::advance(window.it2, 16);
  for (cycle_cord_x = 530; cycle_cord_x <= 680; cycle_cord_x += 75) {
    window.traverseFirstAndLastRow(cycle_cord_x, top_height, bot_height);
  }
  lastIteration = false;
  top_height += 80;
  bot_height = 270;
  lastIterationNumber = 755;
  window.it2 = window.landsList->begin();
  std::advance(window.it2, 12);
  for (cycle_cord_x = 505; cycle_cord_x <= 755; cycle_cord_x += 75) {
    window.traverseSecondAndNextToLastRow(cycle_cord_x, top_height, bot_height);
  }
  lastIteration = false;
  top_height += 80;
  lastIterationNumber = 760;
  window.it2 = window.landsList->begin();
  std::advance(window.it2, 7);
  for (cycle_cord_x = 460; cycle_cord_x <= 760; cycle_cord_x += 75) {
    window.traverseMiddleRow(cycle_cord_x, top_height, bot_height);
  }
}