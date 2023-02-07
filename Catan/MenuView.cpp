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
      sf::Event eventTest;
    while (view.pollEvent(eventTest)) {
      switch (eventTest.type) {
        case sf::Event::MouseButtonPressed:
         if (isNewGameButtonPressed(eventTest))
             newGameButtonPressed(newGameTextbox.getText());
         if (isLoadGameButtonPressed(eventTest))
             loadGameButtonPressed();
         break;

        case sf::Event::TextEntered:
         if (isOverTextbox(newGameTextbox))
              newGameTextbox.typeOn(eventTest);
            if (isOverTextbox(loadGameTextbox))
              loadGameTextbox.typeOn(eventTest);
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

bool MenuView::isOverTextbox(TextBox &textbox) {
  return (textbox.isMouseOver(view));
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
      "Texto vacio", "No se ingreso ningun nombre de archivo a guardar.");
  alert->goView();
}

void MenuView::newGame(string fileName) {
  FileHandler fileHandler;
  fileHandler.saveFile(getFullPathMatchName(fileName), game);
}

void MenuView::newGameButtonPressed(string fileName) {
  if (isNewGameTextboxEmpty())
    newGameTextboxEmpty();

  if (!isNewGameTextboxEmpty()) {
    actualMatchName = fileName;
    log(actualMatchName);
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
    log(loadGameTextbox.getText());
    loadGameView();
  }
}

void MenuView::loadFile(string fileName) {
  FileHandler fileHandler;
  fileHandler.loadFile(getFullPathMatchName(fileName), game);
}

void MenuView::loadGameView() {
  PlayView playView = PlayView(game);
  playView.goView();
}

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
  newGameTextbox = TextBox(32, sf::Color::Black, false, {480, 100}, {350, 80},
                           sf::Color::White);
  newGameTextbox.setFont(font);
  newGameTextbox.setPosition({485, 115});
}

void MenuView::createLoadGameTextbox() {
  loadGameTextbox = TextBox(32, sf::Color::Black, false, {480, 400}, {350, 80},
                            sf::Color::White);
  loadGameTextbox.setFont(font);
  loadGameTextbox.setPosition({485, 415});
}

void MenuView::drawNewGameTextbox() { loadTextbox(newGameTextbox); }
void MenuView::drawLoadGameTextbox() { loadTextbox(loadGameTextbox); }

void MenuView::loadTextbox(TextBox &textbox) {
  enterText(textbox);
  exitText(textbox);
  textbox.drawTextbox(view);
}

void MenuView::enterText(TextBox &textbox) {
  if (textbox.isMouseOver(view) && isReturnPressed())
    textbox.setSelected(true);
}

void MenuView::exitText(TextBox &textbox) {
  if (textbox.isMouseOver(view) && isEndPressed())
    textbox.setSelected(false);
}

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
  RegisterView registerView(actualMatchName);
  registerView.goView();
}