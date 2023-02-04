#include "RegisterView.hpp"

RegisterView::RegisterView() {}

void RegisterView::makeTextboxes() {
  firstTextbox = TextBox(15, sf::Color::Black, false, {345, 240}, {180, 40},
                         sf::Color::White);

  secondTextbox = TextBox(15, sf::Color::Black, false, {345, 300}, {180, 40},
                          sf::Color::White);

  thirdTextbox = TextBox(15, sf::Color::Black, false, {345, 360}, {180, 40},
                         sf::Color::White);

  fourthTextbox = TextBox(15, sf::Color::Black, false, {345, 420}, {180, 40},
                          sf::Color::White);
}

void RegisterView::loadTextboxes() {
  makeTextboxes();
  firstTextbox.setFont(font);
  firstTextbox.setPosition({365, 250});

  secondTextbox.setFont(font);
  secondTextbox.setPosition({365, 310});

  thirdTextbox.setFont(font);
  thirdTextbox.setPosition({365, 370});

  fourthTextbox.setFont(font);
  fourthTextbox.setPosition({365, 430});
}

void RegisterView::makePlayerButtons() {
  fourPlayersButton =
      Button("4 Jugadores", {200, 60}, 20, sf::Color::Green, sf::Color::Black);
  threePlayersButton =
      Button("3 Jugadores", {200, 60}, 20, sf::Color::Green, sf::Color::Black);
  blue = Button("", {30, 30}, 20, sf::Color::Green, sf::Color::Black);
  yellow = Button("", {30, 30}, 20, sf::Color::Green, sf::Color::Black);
  red = Button("", {30, 30}, 20, sf::Color::Green, sf::Color::Black);
  green = Button("", {30, 30}, 20, sf::Color::Green, sf::Color::Black);
}

void RegisterView::makeButtons() {
  makePlayerButtons();
  playButton =
      Button("Jugar", {150, 60}, 20, sf::Color::Blue, sf::Color::Black);

  clear = Button("Clear", {150, 60}, 20, sf::Color::Green, sf::Color::Black);
}

void RegisterView::drawButtons() {
  loadRegisterButtons(playButton, sf::Color::Blue);
  loadRegisterButtons(threePlayersButton, sf::Color::Blue);
  loadRegisterButtons(fourPlayersButton, sf::Color::Blue);
  loadRegisterButtons(clear, sf::Color::Blue);
}

void RegisterView::loadFourColors() {

  y = 245;
  x = 580;
  for (int i = 0; i < 4; i++) {

    blue.setPosition({x, y}, 3);
    blue.drawButton(view);

    green.setPosition({x += 40, y}, 3);
    green.drawButton(view);

    yellow.setPosition({x += 40, y}, 3);
    yellow.drawButton(view);

    red.setPosition({x += 40, y}, 3);
    red.drawButton(view);
    x = 580;
    y += 60;
    loadRegisterButtons(blue, sf::Color::Blue);
    loadRegisterButtons(green, sf::Color::Green);
    loadRegisterButtons(yellow, sf::Color::Yellow);
    loadRegisterButtons(red, sf::Color::Red);
  }
}

void RegisterView::loadThreeColors() {

  y = 245;
  x = 580;
  for (int i = 0; i < 3; i++) {
    blue.setPosition({x, y}, 3);
    blue.drawButton(view);
    green.setPosition({x += 40, y}, 3);
    green.drawButton(view);
    red.setPosition({x += 40, y}, 3);
    red.drawButton(view);
    x = 580;
    y += 60;
    loadRegisterButtons(blue, sf::Color::Blue);
    loadRegisterButtons(green, sf::Color::Green);
    loadRegisterButtons(red, sf::Color::Red);
  }
}

void RegisterView::loadRegisterButtons(Button &button, sf::Color color) {
  if (button.isMouseOver(view)) {
    button.setBackgroundColor(sf::Color::White);
  } else {
    button.setBackgroundColor(color);
  }
  button.drawButton(view);
}

void RegisterView::loadButtons() {
  makeButtons();
  playButton.setPosition({1000, 320}, 3);
  playButton.setFont(font);
  threePlayersButton.setPosition({100, 280}, 5);
  threePlayersButton.setFont(font);
  fourPlayersButton.setPosition({100, 350}, 5);
  fourPlayersButton.setFont(font);
  clear.setPosition({1000, 450}, 3);
  clear.setFont(font);
}

void RegisterView::loadView() {
  view.create(sf::VideoMode(1280, 720), "Register");
  view.setKeyRepeatEnabled(true);
  view.setFramerateLimit(120);
  image.loadFromFile("Images/catan_1280x720.jpg");
  sprite.setTexture(image);
  font.loadFromFile("mononoki.ttf");
}

void RegisterView::drawView() {
  loadButtons();
  loadTextboxes();
}

void RegisterView::typeOverTextbox(sf::Event event) {
  if (isThreePlayers) {
    if (firstTextbox.isMouseOver(view))
      firstTextbox.typeOn(event);

    if (secondTextbox.isMouseOver(view))
      secondTextbox.typeOn(event);

    if (thirdTextbox.isMouseOver(view))
      thirdTextbox.typeOn(event);
    fourthTextbox.isTyping(false);
  }
  if (isFourPlayers) {
    if (firstTextbox.isMouseOver(view))
      firstTextbox.typeOn(event);

    if (secondTextbox.isMouseOver(view))
      secondTextbox.typeOn(event);

    if (thirdTextbox.isMouseOver(view))
      thirdTextbox.typeOn(event);

    if (fourthTextbox.isMouseOver(view))
      fourthTextbox.typeOn(event);
  }
}

void RegisterView::loadBeforeChangingScene() {
  loadPlayerList();
  game.makePlayer();
  if (isThreePlayers)
    getNamesThreePlayers();
  if (isFourPlayers)
    getNamesFourPlayers();
}

void RegisterView::playButtonPressed() {
  loadBeforeChangingScene();
  closeView();
  PlayView playView = PlayView(game.players);
  playView.goView();
}

void RegisterView::clearButtonPressed() {
  clearView();
  isThreePlayers = false;
  isFourPlayers = false;
  displayView();

  closeView();
  goView();
}

bool RegisterView::isPlayButtonPressed() {
  return (playButton.isMouseOver(view));
}
bool RegisterView::isClearButtonPressed() { return (clear.isMouseOver(view)); }

void RegisterView::loadAll() {
  clearView();
  view.draw(sprite);
  registerButton();
  drawTextboxes();
  drawButtons();
  if (isThreePlayers)
    loadThreeColors();

  if (isFourPlayers)
    loadFourColors();

  displayView();
}

bool RegisterView::isThreePlayersButtonPressed(sf::Event event) {
  return (threePlayersButton.isPressed(event));
}

bool RegisterView::isFourPlayersButtonPressed(sf::Event event) {
  return (fourPlayersButton.isPressed(event));
}

void RegisterView::goView() {
  loadView();
  drawView();

  while (view.isOpen()) {
    while (view.pollEvent(event)) {
      switch (event.type) {

      case sf::Event::TextEntered:
        typeOverTextbox(event);
        break;

      case sf::Event::MouseButtonPressed:
        showCoordinates(event);
        if (isMouseLeftClicked(event)) {
          if (isPlayButtonPressed())
            playButtonPressed();

          if (isClearButtonPressed())
            clearButtonPressed();

          if (isThreePlayersButtonPressed(event)) {
            isThreePlayers = true;
            isFourPlayers = false;
          }

          if (isFourPlayersButtonPressed(event)) {
            isFourPlayers = true;
            isThreePlayers = false;
          }
        }
        break;

      case sf::Event::KeyPressed:
        if (isQKeyPressed())
          goMenuView();
        break;

      case sf::Event::Closed:
        closeView();
        break;
      }
    }
    loadAll();
  }
}

void RegisterView::drawTextboxes() {
  if (isThreePlayers) {

    loadTextFields(firstTextbox);
    loadTextFields(secondTextbox);
    loadTextFields(thirdTextbox);
  }
  if (isFourPlayers) {

    loadTextFields(firstTextbox);
    loadTextFields(secondTextbox);
    loadTextFields(thirdTextbox);
    loadTextFields(fourthTextbox);
  }
}

void RegisterView::goMenuView() {
  closeView();
  MenuView menuView;
  menuView.goView();
}

void RegisterView::registerButton() {
  title = new Label("Registro de Usuarios", sf::Color::Black, font,
                    sf::Text::Bold, 30, 480.f, 50.f);
  name = new Label("Nombre", sf::Color::Black, font, sf::Text::Bold, 20, 405.f,
                   200.f);

  color = new Label("Color", sf::Color::Black, font, sf::Text::Bold, 20, 600.f,
                    200.f);

  note = new Label("Nota: Acerca el cursor al campo de texto del jugador, "
                   "presiona ENTER para escribir y END para salir.",
                   sf::Color::Blue, font, sf::Text::Bold, 20, 10.f, 640.f);

  view.draw(title->getTextInstance());
  view.draw(name->getTextInstance());
  view.draw(color->getTextInstance());
  view.draw(note->getTextInstance());
}

void RegisterView::loadRegisterButtons(Button &button) {
  if (button.isMouseOver(view)) {
    button.setBackgroundColor(sf::Color::White);
  } else {
    button.setBackgroundColor(sf::Color::Blue);
  }
  button.drawButton(view);
}

void RegisterView::loadTextFields(TextBox &textbox) {
  if (textbox.isMouseOver(view)) {
    if (isReturnPressed())
      textbox.setSelected(true);

    if (isEndPressed())
      textbox.setSelected(false);
  }
  textbox.drawTextbox(view);
}

void RegisterView::showCoordinates(sf::Event event) {
  if (isMousePressed(event)) {

    if (isMouseRightClicked(event)) {
      log("Right button was pressed");
      log("mouse x: " << event.mouseButton.x);
      log("mouse y: " << event.mouseButton.y);
    }
  }
  if (isMousePressed(event)) {
    if (isMouseLeftClicked(event)) {
      log("Left button was pressed");
      log("mouse x: " << event.mouseButton.x);
      log("mouse y: " << event.mouseButton.y);
    }
  }
}

void RegisterView::getNamesThreePlayers() {
  log(firstTextbox.getText());
  log(secondTextbox.getText());
  log(thirdTextbox.getText());
}

void RegisterView::getNamesFourPlayers() {
  log(firstTextbox.getText());
  log(secondTextbox.getText());
  log(thirdTextbox.getText());
  log(fourthTextbox.getText());
}

void RegisterView::loadThreePlayers() {
  game.players->push_back(new Player(firstTextbox.getText(), 0, "RED"));
  game.players->push_back(new Player(secondTextbox.getText(), 0, "BLUE"));
  game.players->push_back(new Player(thirdTextbox.getText(), 0, "GREEN"));
}

void RegisterView::loadFourPlayers() {
  game.players->push_back(new Player(firstTextbox.getText(), 0, "RED"));
  game.players->push_back(new Player(secondTextbox.getText(), 0, "BLUE"));
  game.players->push_back(new Player(thirdTextbox.getText(), 0, "GREEN"));
  game.players->push_back(new Player(fourthTextbox.getText(), 0, "YELLOW"));
}

void RegisterView::loadPlayerList() {
  // Avisar que no ha escogido ni 3 ni 4 jugadores
  try {
    if (isThreePlayers)
      loadThreePlayers();
    if (isFourPlayers) {
      loadFourPlayers();
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}