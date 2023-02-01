#include "RegisterView.hpp"

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
}

void RegisterView::makeButtons() {
  makePlayerButtons();
  playButton =
      Button("Jugar", {150, 60}, 20, sf::Color::Blue, sf::Color::Black);
}

RegisterView::RegisterView() {}

void RegisterView::loadButtons() {
  makeButtons();
  playButton.setPosition({1000, 320});
  playButton.setFont(font);
  threePlayersButton.setPosition2({100, 280});
  threePlayersButton.setFont(font);
  fourPlayersButton.setPosition2({100, 350});
  fourPlayersButton.setFont(font);
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
  getNames();
}

void RegisterView::playButtonPressed() {
  loadBeforeChangingScene();
  view.close();
  PlayView playView = PlayView(game.players);
  playView.goView();
}

bool RegisterView::isPlayButtonPressed() {
  return (playButton.isMouseOver(view));
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

          if (threePlayersButton.isMouseOver(view))
            isThreePlayers = true;

          if (fourPlayersButton.isMouseOver(view))
            isFourPlayers = true;
        }
        break;

      case sf::Event::KeyPressed:
        if (isEscapePressed())
          goTitleView();
        break;

      case sf::Event::Closed:
        view.close();
        break;
      }
    }
    view.clear();
    view.draw(sprite);

    registerButton();
    drawButtons();
    drawTextboxes();
    loadColors();

    view.display();
  }
}

void RegisterView::drawButtons() {
  loadRegisterButtons(playButton);
  loadRegisterButtons(threePlayersButton);
  loadRegisterButtons(fourPlayersButton);
}

void RegisterView::drawTextboxes() {
  if (isThreePlayers) {
    isFourPlayers = false;
    loadTextFields(firstTextbox);
    loadTextFields(secondTextbox);
    loadTextFields(thirdTextbox);
    fourthTextbox.setVisible(false);
  }
  if (isFourPlayers) {
    isThreePlayers = false;
    fourthTextbox.setVisible(true);
    loadTextFields(firstTextbox);
    loadTextFields(secondTextbox);
    loadTextFields(thirdTextbox);
    loadTextFields(fourthTextbox);
  }
}

void RegisterView::goTitleView() {
  view.close();
  TitleView titleView;
  titleView.goView();
}

bool RegisterView::isEscapePressed() const {
  return (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
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
    button.setBackColor(sf::Color::White);
  } else {
    button.setBackColor(sf::Color::Blue);
  }
  button.drawTo(view);
}

void RegisterView::loadTextFields(TextBox &textbox) {
  if (textbox.isMouseOver(view)) {
    if (isReturnPressed())
      textbox.setSelected(true);

    if (isEndPressed())
      textbox.setSelected(false);
  }
  textbox.drawTo(view);
}

void RegisterView::loadColors() {
  int y = 245;
  for (int i = 0; i < 4; i++) {
    sf::Texture blue;
    blue.loadFromFile("Images/Colors/Blue.png");
    sf::Sprite blueSprite(blue);
    blueSprite.setPosition(580, y);
    y += 60;
    view.draw(blueSprite);
  }
  y = 245;
  for (int i = 0; i < 4; i++) {
    sf::Texture yellow;
    yellow.loadFromFile("Images/Colors/Yellow.png");
    sf::Sprite yellowSprite(yellow);
    yellowSprite.setPosition(620, y);
    y += 60;
    view.draw(yellowSprite);
  }
  y = 245;
  for (int i = 0; i < 4; i++) {
    sf::Texture red;
    red.loadFromFile("Images/Colors/Red.png");
    sf::Sprite redSprite(red);
    redSprite.setPosition(660, y);
    y += 60;
    view.draw(redSprite);
  }
  y = 245;
  for (int i = 0; i < 4; i++) {
    sf::Texture green;
    green.loadFromFile("Images/Colors/Green.png");
    sf::Sprite greenSprite(green);
    greenSprite.setPosition(700, y);
    y += 60;
    view.draw(greenSprite);
  }
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

void RegisterView::getNames() {
  log(firstTextbox.getText());
  log(secondTextbox.getText());
  log(thirdTextbox.getText());
  log(fourthTextbox.getText());
}

void RegisterView::loadThreePlayers() {
  game.players->push_back(new Player("jesus", 0, "COLOR"));
  game.players->push_back(new Player("dilan", 0, "COLOR"));
  game.players->push_back(new Player("daniel", 0, "COLOR"));
}

void RegisterView::loadFourPlayers() {
  game.players->push_back(new Player("jesus", 0, "COLOR"));
  game.players->push_back(new Player("jesus", 0, "COLOR"));
  game.players->push_back(new Player("jesus", 0, "COLOR"));
  game.players->push_back(new Player("jesus", 0, "COLOR"));
}

void RegisterView::loadPlayerList() {
  // Avisar que no ha escogido ni 3 ni 4 jugadores
  try {
    if (isThreePlayers)
      loadThreePlayers();
    if (isFourPlayers)
      loadFourPlayers();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}