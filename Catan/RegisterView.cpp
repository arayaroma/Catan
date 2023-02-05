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

  newGame = TextBox(15, sf::Color::Black, false, {10, 17.5}, {180, 40},
                    sf::Color::White);

  loadGame = TextBox(15, sf::Color::Black, false, {900, 17.5}, {180, 40},
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

  newGame.setFont(font);
  newGame.setPosition({20, 20});

  loadGame.setFont(font);
  loadGame.setPosition({1000, 20});
}

void RegisterView::makePlayerButtons() {
  fourPlayersButton =
      Button("4 Jugadores", {200, 60}, 20, sf::Color::Green, sf::Color::Black);
  threePlayersButton =
      Button("3 Jugadores", {200, 60}, 20, sf::Color::Green, sf::Color::Black);
  blue0 = Button("", {30, 30}, 20, sf::Color::Green, sf::Color::Black);
  yellow0 = Button("", {30, 30}, 20, sf::Color::Green, sf::Color::Black);
  red0 = Button("", {30, 30}, 20, sf::Color::Green, sf::Color::Black);
  green0 = Button("", {30, 30}, 20, sf::Color::Green, sf::Color::Black);
 
  blue1 = blue0; green1 = green0; red1 = red0; yellow1 = yellow0;
  blue2 = blue0; green2 = green0; red2 = red0; yellow2 = yellow0;
  blue3 = blue0; green3 = green0; red3 = red0; yellow3 = yellow0;
}

void RegisterView::makeButtons() {
  makePlayerButtons();
  playButton =
      Button("Jugar", {150, 60}, 20, sf::Color::Blue, sf::Color::Black);

  loadGames = Button("Load", {150, 60}, 20, sf::Color::Blue, sf::Color::Black);
  newGames = Button("Create", {150, 60}, 20, sf::Color::Blue, sf::Color::Black);
  clear = Button("Clear", {150, 60}, 20, sf::Color::Green, sf::Color::Black);

  loadGames = Button("Load", {150, 60}, 20, sf::Color::Blue, sf::Color::Black);
  newGames = Button("Create", {150, 60}, 20, sf::Color::Blue, sf::Color::Black);
}

void RegisterView::drawButtons() {
  loadRegisterButtons(playButton, sf::Color::Blue);
  loadRegisterButtons(threePlayersButton, sf::Color::Blue);
  loadRegisterButtons(fourPlayersButton, sf::Color::Blue);
  loadRegisterButtons(newGames, sf::Color::Blue);
  loadRegisterButtons(loadGames, sf::Color::Blue);
  loadRegisterButtons(clear, sf::Color::Blue);
}



void RegisterView::loadButtons() {
  makeButtons();
  playButton.setPosition({1000, 320}, 3);
  playButton.setFont(font);
  threePlayersButton.setPosition({100, 280}, 5);
  threePlayersButton.setFont(font);
  fourPlayersButton.setPosition({100, 350}, 5);
  fourPlayersButton.setFont(font);
  loadGames.setPosition({1100, 10}, 5);
  loadGames.setFont(font);
  newGames.setPosition({200, 10}, 5);
  newGames.setFont(font);
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
  if (newGame.isMouseOver(view))
    newGame.typeOn(event);

  if (loadGame.isMouseOver(view))
    loadGame.typeOn(event);
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

void RegisterView::clearButtonPressed() {
  view.clear();
  isThreePlayers = false;
  isFourPlayers = false;
  view.display();

  view.close();
  goView();
}

bool RegisterView::isPlayButtonPressed() {
  return (playButton.isMouseOver(view));
}
bool RegisterView::isClearButtonPressed() { return (clear.isMouseOver(view)); }

void RegisterView::loadAll() {
  view.clear();
  view.draw(sprite);
  registerButton();
  drawTextboxes();
  drawButtons();
  if (isThreePlayers) {
    loadThreeColors();
  }
  if (isFourPlayers) {
      loadFourColors(); 
  }
  view.display();
}

void RegisterView::countPlayers() {
  if (threePlayersButton.isMouseOver(view))
    isThreePlayers = true;

  if (fourPlayersButton.isMouseOver(view))
    isFourPlayers = true;
}

void RegisterView::goView() {
  loadView();
  drawView();

  while (view.isOpen()) {
    while (view.pollEvent(event)) {
      switch (event.type) {

      case sf::Event::Closed:
        view.close();

      case sf::Event::TextEntered:
        typeOverTextbox(event);
        break;

      case sf::Event::MouseButtonPressed:
        showCoordinates(event);
        if (isMouseLeftClicked(event)) {
            if (isPlayButtonPressed()) {
                playButtonPressed();
              
            }
          if (isClearButtonPressed())
            clearButtonPressed();
            countPlayers();
            isAnyColorPressed(event); 
        }
        break;
      case sf::Event::KeyPressed:
        if (isEscapePressed())
          goTitleView();
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
  loadTextFields(newGame);
  loadTextFields(loadGame);
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

void RegisterView::getNames() {
  log(firstTextbox.getText());
  log(secondTextbox.getText());
  log(thirdTextbox.getText());
  log(fourthTextbox.getText());
}

void RegisterView::loadThreePlayers() {
  game.players->push_back(new Player(firstTextbox.getText(), 0, colorPlayerOne));
  game.players->push_back(new Player(secondTextbox.getText(), 0, colorPlayerTwo));
  game.players->push_back(new Player(thirdTextbox.getText(), 0, colorPlayerThree));
}

void RegisterView::loadFourPlayers() {
  game.players->push_back(new Player(firstTextbox.getText(), 0, colorPlayerOne));
  game.players->push_back(new Player(secondTextbox.getText(), 0, colorPlayerTwo));
  game.players->push_back(new Player(thirdTextbox.getText(), 0, colorPlayerThree));
  game.players->push_back(new Player(fourthTextbox.getText(), 0, colorPlayerFour));
}



void RegisterView::loadThreeColors() {
    loadColorsBlue();
    loadColorsRed();
    loadColorsYellow(); 
}
void RegisterView::loadFourColors() {
    loadColorsBlue();
    loadColorsRed();
    loadColorsYellow();
    loadColorsGreen(); 

    yellow3.setPosition({ 660 , 425 }, 3);
    yellow3.drawButton(view);
    blue3.setPosition({ 580 , 425 }, 3);
    blue3.drawButton(view);
    red3.setPosition({ 620 , 425 }, 3);
    red3.drawButton(view);
    loadRegisterButtons(red3, sf::Color::Red);
    loadRegisterButtons(yellow3, sf::Color::Yellow);
    loadRegisterButtons(blue3, sf::Color::Blue);

}

void RegisterView::loadRegisterButtons(Button& button, sf::Color color) {
    if (button.isMouseOver(view)) {
        button.setBackgroundColor(sf::Color::White);
    }
    else {
        button.setBackgroundColor(color);
    }
    button.drawButton(view);
}

void RegisterView::loadColorsBlue() {

   blue0.setPosition({ 580, 245 }, 3);
   blue0.drawButton(view);
   blue1.setPosition({ 580 , 305 }, 3);
   blue1.drawButton(view);
   blue2.setPosition({ 580 , 365 }, 3);
   blue2.drawButton(view);

   loadRegisterButtons(blue0, sf::Color::Blue);
   loadRegisterButtons(blue1, sf::Color::Blue);
   loadRegisterButtons(blue2, sf::Color::Blue);   
}

void RegisterView::loadColorsRed() {

        red0.setPosition({ 620, 245 }, 3);
        red0.drawButton(view);
        red1.setPosition({ 620 , 305 }, 3);
        red1.drawButton(view);
        red2.setPosition({ 620 , 365 }, 3);
        red2.drawButton(view);
        loadRegisterButtons(red0, sf::Color::Red);
        loadRegisterButtons(red1, sf::Color::Red);
        loadRegisterButtons(red2, sf::Color::Red);
}

void RegisterView::loadColorsYellow() {
    yellow0.setPosition({ 660, 245 }, 3);
    yellow0.drawButton(view);
    yellow1.setPosition({ 660 , 305 }, 3);
    yellow1.drawButton(view);
    yellow2.setPosition({ 660 , 365 }, 3);
    yellow2.drawButton(view);
    loadRegisterButtons(yellow0, sf::Color::Yellow);
    loadRegisterButtons(yellow1, sf::Color::Yellow);
    loadRegisterButtons(yellow2, sf::Color::Yellow);
}

void RegisterView::loadColorsGreen(){

    green0.setPosition({ 700, 245 }, 3);
    green0.drawButton(view);
    green1.setPosition({ 700 , 305 }, 3);
    green1.drawButton(view);
    green2.setPosition({ 700 , 365 }, 3);
    green2.drawButton(view);
    green3.setPosition({ 700 , 425 }, 3);
    green3.drawButton(view);
    loadRegisterButtons(green0, sf::Color::Green);
    loadRegisterButtons(green1, sf::Color::Green);
    loadRegisterButtons(green2, sf::Color::Green);
    loadRegisterButtons(green3, sf::Color::Green);
}


void RegisterView::playerOneColor() {

   if (blue0.isMouseOver(view)) 
      colorPlayerOne = "BLUE";
    if (green0.isMouseOver(view)) 
      colorPlayerOne = "GREEN";
    if (red0.isMouseOver(view)) 
      colorPlayerOne = "RED";
    if (yellow0.isMouseOver(view)) 
      colorPlayerOne = "YELLOW";
   
       
}

void RegisterView::playerTwoColor() {
    if (blue1.isMouseOver(view)) 
       colorPlayerTwo = "BLUE";
    if (green1.isMouseOver(view)) 
       colorPlayerTwo = "GREEN";
    if (red1.isMouseOver(view)) 
       colorPlayerTwo = "RED";
    if (yellow1.isMouseOver(view)) 
       colorPlayerTwo = "YELLOW";
   
}

void RegisterView::playerThreeColor() {
     if (blue2.isMouseOver(view)) 
       colorPlayerThree = "BLUE";
     if (green2.isMouseOver(view)) 
       colorPlayerThree = "GREEN";
     if (red2.isMouseOver(view)) 
       colorPlayerThree = "RED";
     if (yellow2.isMouseOver(view)) 
       colorPlayerThree = "YELLOW";
    
}

void RegisterView::playerFourColor() {

     if (blue3.isMouseOver(view)) 
            colorPlayerFour = "BLUE";
     if (green3.isMouseOver(view)) 
            colorPlayerFour = "GREEN";
     if (red3.isMouseOver(view)) 
            colorPlayerFour = "RED";
     if (yellow3.isMouseOver(view)) 
            colorPlayerFour = "YELLOW";
    
}

void RegisterView::isAnyColorPressed(sf::Event event) {
   int x = event.mouseButton.x;
   int y = event.mouseButton.y;

    if (x > 580 && y > 245 && x < 730 && y < 275) {
        playerOneColor();
    }
    if (x > 580 && y > 305 && x < 730 && y < 335) {
        playerTwoColor();
    }
    if (x > 580 && y > 365 && x < 730 && y < 400) {
        playerThreeColor();
    }
    if (x > 580 && y > 425 && x < 730 && y < 455) {
        playerFourColor();
    }
}

void RegisterView::loadPlayerList() {
  try {
    if (isThreePlayers)
      loadThreePlayers();
    else if (isFourPlayers)
      loadFourPlayers();
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}