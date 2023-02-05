#include "MenuView.hpp"

MenuView::MenuView() {}

void MenuView::loadView() {
  view.create(sf::VideoMode(1280, 720), "Menu");
  image.loadFromFile("Images/inicio.jpg");
  sprite.setTexture(image);
  font.loadFromFile("mononoki.ttf");
  createButtons();
  createTextboxes();
}

void MenuView::drawView() {
  clearView();
  view.draw(sprite);
  drawButtons();
  drawTextboxes();
  displayView();
}

void MenuView::goView() {
  loadView();
  drawView();

  while (view.isOpen()) {
    while (view.pollEvent(event)) {
      switch (event.type) {

      case sf::Event::MouseButtonPressed:
        if (isNewGameButtonPressed(event))
          newGameButtonPressed("");
        break;

        if (isLoadGameButtonPressed(event))
          loadGameButtonPressed();
        break;

      case sf::Event::KeyPressed:
        if (isQKeyPressed())
          goTitleView();
        break;

      case sf::Event::Closed:
        closeView();
        break;
      }
    }
    drawView();
  }
}

void MenuView::createButtons() {
  createNewGameButton();
  createLoadGameButton();
}

void MenuView::createNewGameButton() {
  newGameButton =
      Button("Nueva Partida", {350, 80}, 42, sf::Color::Blue, sf::Color::White);
  newGameButton.setFont(font);
  newGameButton.setPosition({480, 200}, 5);
}

void MenuView::createLoadGameButton() {
  loadGameButton = Button("Cargar Partida", {350, 80}, 42, sf::Color::Blue,
                          sf::Color::White);
  loadGameButton.setFont(font);
  loadGameButton.setPosition({480, 500}, 5);
}

bool MenuView::isNewGameButtonPressed(sf::Event event) {
  return (newGameButton.isPressed(event));
}

bool MenuView::isNewGameTextboxEmpty() {
  return (newGameTextbox.getText() == "");
}

void MenuView::newGameTextboxEmpty() {
  ErrorAlert *alert = new ErrorAlert(
      "Texto vacio", "No se ingresó ningún nombre de archivo a guardar.");
  alert->goView();
}

void MenuView::newGame(string fileName) {
  FileHandler fileHandler;
  fileHandler.saveFile(fileName + extensionName, game);
}

void MenuView::newGameButtonPressed(string fileName) {
  if (isNewGameTextboxEmpty())
    goRegisterView();
    //newGameTextboxEmpty();

  if (!isNewGameTextboxEmpty()) {
    newGame(fileName);
    goRegisterView();
  }
}

bool MenuView::isLoadGameButtonPressed(sf::Event event) {
  return (loadGameButton.isPressed(event));
}

void MenuView::loadGameButtonPressed() {
  if (isLoadGameTextboxEmpty())
    loadGameTextboxEmpty();

  if (!isLoadGameTextboxEmpty()) {
    loadFile(loadGameTextbox.getText());
    loadGameView();
  }
}

void MenuView::loadFile(string fileName) {
  FileHandler fileHandler;
  fileHandler.loadFile(fileName + extensionName, loadGame);
}

void MenuView::loadGameView() { PlayView playView = PlayView(loadGame); }

void MenuView::loadGameTextboxEmpty() {
  ErrorAlert *alert = new ErrorAlert(
      "Texto vacio", "No se ingresó ningún nombre de archivo a cargar.");
  alert->goView();
}

bool MenuView::isLoadGameTextboxEmpty() {
  return (loadGameTextbox.getText() == "");
}

void MenuView::drawButtons() {
  newGameButton.drawButton(view);
  newGameButton.buttonInOutColors(sf::Color(255, 140, 0, 255),
                                  sf::Color(255, 160, 0, 255), view);

  loadGameButton.drawButton(view);
  loadGameButton.buttonInOutColors(sf::Color(255, 140, 0, 255),
                                   sf::Color(255, 160, 0, 255), view);
}

void MenuView::createTextboxes() {
  createNewGameTextbox();
  createLoadGameTextbox();
}

void MenuView::createNewGameTextbox() {
  newGameTextbox = TextBox(15, sf::Color::Black, false, {480, 100}, {350, 80},
                           sf::Color::White);
  newGameTextbox.setFont(font);
}

void MenuView::createLoadGameTextbox() {
  loadGameTextbox = TextBox(15, sf::Color::Black, false, {480, 400}, {350, 80},
                            sf::Color::White);
  loadGameTextbox.setFont(font);
}

void MenuView::drawNewGameTextbox() { newGameTextbox.drawTextbox(view); }
void MenuView::drawLoadGameTextbox() { loadGameTextbox.drawTextbox(view); }

void MenuView::drawTextboxes() {
  drawNewGameTextbox();
  drawLoadGameTextbox();
}

void MenuView::goTitleView() {
  closeView();
  TitleView titleView;
  titleView.goView();
}

void MenuView::goRegisterView() {
  closeView();
  RegisterView registerView;
  registerView.goView();
}