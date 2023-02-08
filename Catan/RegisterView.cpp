#include "RegisterView.hpp"

RegisterView::RegisterView() {}

RegisterView::RegisterView(string fileName) { actualMatchName = fileName; }

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

  blue0 = Button("", {30, 30}, 20, sf::Color::Blue, sf::Color::Black);
  yellow0 = Button("", {30, 30}, 20, sf::Color::Yellow, sf::Color::Black);
  red0 = Button("", {30, 30}, 20, sf::Color::Red, sf::Color::Black);
  green0 = Button("", {30, 30}, 20, sf::Color::Green, sf::Color::Black);

  blue1 = blue0;
  green1 = green0;
  red1 = red0;
  yellow1 = yellow0;
  blue2 = blue0;
  green2 = green0;
  red2 = red0;
  yellow2 = yellow0;
  blue3 = blue0;
  green3 = green0;
  red3 = red0;
  yellow3 = yellow0;
}

void RegisterView::makeButtons() {
  makePlayerButtons();
  fourPlayersButton =
      Button("4 Jugadores", { 200, 60 }, 20, sf::Color::Green, sf::Color::Black);
  threePlayersButton =
      Button("3 Jugadores", { 200, 60 }, 20, sf::Color::Green, sf::Color::Black);
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
      log(actualMatchName);
      PlayView playView = PlayView(game.players, actualMatchName);
      playView.goView();
}



bool RegisterView:: textTextBoxCompleted(){
    if (isThreePlayers && firstTextbox.getText() != "" && secondTextbox.getText() != "" && thirdTextbox.getText() != "") {
        return true; 
    }
    else {
        return false; 
    }
}

void RegisterView::clearButtonPressed() {
  clearView();

  makePlayerButtons(); 
  //displayView();

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
            if (isPlayButtonPressed()) {
                 verify();
            }

          if (isClearButtonPressed())
            clearButtonPressed();

          isAnyColorPressed(event);

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
void RegisterView::verify() {

    if (textTextBoxCompleted()) {
        if (compareNames()) {
            if (!isAnyColorEmpty()) {
                if (compareColors()) {
                    playButtonPressed();
                }
                ErrorAlert alertSameColor = ErrorAlert(" ", "Debe seleccionar distintos colores");
                alertSameColor.goView();
            }
            else {
                ErrorAlert noneColor = ErrorAlert(" ", "Debe seleccionar algun color por cada jugador");
                noneColor.goView();
            }
        }
        else {
            ErrorAlert alertSameNames = ErrorAlert(" ", "Los juagdores deben tener distintos nombres");
            alertSameNames.goView();
        }
    }
    else {
        ErrorAlert alertNames = ErrorAlert(" ", "Debe llenar los espacios con nombres de jugadores");
        alertNames.goView();
    }
}

bool RegisterView::compareNames() {
    if (isThreePlayers) {
        if (firstTextbox.getText() != secondTextbox.getText() && firstTextbox.getText() != thirdTextbox.getText()) {
            if (secondTextbox.getText() != thirdTextbox.getText()) {
                return true;
            }
        }
        return false;
    }
    if (isFourPlayers) {
        if (firstTextbox.getText() != secondTextbox.getText() && firstTextbox.getText() != thirdTextbox.getText() ) {
            if (firstTextbox.getText() != fourthTextbox.getText()) {
                if (secondTextbox.getText() != thirdTextbox.getText() && secondTextbox.getText() != fourthTextbox.getText()) {
                    return true;
                }
            }
        }
        return false;
    }
}

bool RegisterView::isAnyColorEmpty() {
    if (isThreePlayers) {
        return (colorPlayerOne == "" || colorPlayerTwo == "" || colorPlayerThree == "");
    }
    if(isFourPlayers){
        return (colorPlayerOne == "" || colorPlayerTwo == "" || colorPlayerThree == "" || colorPlayerFour == "");
    }

}
bool RegisterView::compareColors() {
    if (isThreePlayers) {
        if (colorPlayerOne != colorPlayerTwo && colorPlayerOne != colorPlayerThree) {
            if (colorPlayerTwo != colorPlayerThree) {
                return true; 
            }
        }
        return false; 
    }
    if (isFourPlayers) {
        if (colorPlayerOne != colorPlayerTwo && colorPlayerOne != colorPlayerThree && colorPlayerOne != colorPlayerFour) {
            if (colorPlayerTwo != colorPlayerThree && colorPlayerTwo != colorPlayerFour) {
                return true; 
            }
        }
        return false; 
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
  
  title =  Label("Registro de Usuarios", sf::Color::Black, font,
                    sf::Text::Bold, 30, 480.f, 50.f);
  name =  Label("Nombre", sf::Color::Black, font, sf::Text::Bold, 20, 405.f,
                   200.f);

  color =  Label("Color", sf::Color::Black, font, sf::Text::Bold, 20, 600.f,
                    200.f);

  note =  Label("Nota: Acerca el cursor al campo de texto del jugador, "
                   "presiona ENTER para escribir y END para salir.",
                   sf::Color::Blue, font, sf::Text::Bold, 20, 10.f, 640.f);

  view.draw(title.getTextInstance());
  view.draw(name.getTextInstance());
  view.draw(color.getTextInstance());
  view.draw(note.getTextInstance());
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
   
        game.players->push_back(
            new Player(firstTextbox.getText(), 0, colorPlayerOne));
        game.players->push_back(
            new Player(secondTextbox.getText(), 0, colorPlayerTwo));
        game.players->push_back(
            new Player(thirdTextbox.getText(), 0, colorPlayerThree));
    
    
}

void RegisterView::loadFourPlayers() {
  game.players->push_back(
      new Player(firstTextbox.getText(), 0, colorPlayerOne));
  game.players->push_back(
      new Player(secondTextbox.getText(), 0, colorPlayerTwo));
  game.players->push_back(
      new Player(thirdTextbox.getText(), 0, colorPlayerThree));
  game.players->push_back(
      new Player(fourthTextbox.getText(), 0, colorPlayerFour));
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

  yellow3.setPosition({660, 425}, 3);
  yellow3.drawButton(view);
  blue3.setPosition({580, 425}, 3);
  blue3.drawButton(view);
  red3.setPosition({620, 425}, 3);
  red3.drawButton(view);
  loadColorButtons(red3, sf::Color(181, 26, 20));
  loadColorButtons(yellow3, sf::Color(199, 191, 42));
  loadColorButtons(blue3, sf::Color(19, 23, 126));
}

void RegisterView::loadRegisterButtons(Button &button, sf::Color color) {
  if (button.isMouseOver(view)) {
    button.setBackgroundColor(sf::Color::White);
  } else {
    button.setBackgroundColor(color);
  }
  button.drawButton(view);
}


void RegisterView::loadColorButtons(Button& button, sf::Color color) {
    if (button.isPressed(event)) {
        button.setBackgroundColor(color);
    }
    button.drawButton(view);
}

void RegisterView::loadColorsBlue() {

  blue0.setPosition({580, 245}, 3);
  blue0.drawButton(view);
  blue1.setPosition({580, 305}, 3);
  blue1.drawButton(view);
  blue2.setPosition({580, 365}, 3);
  blue2.drawButton(view);

  loadColorButtons(blue0, sf::Color (19,23,126));
  loadColorButtons(blue1, sf::Color(19, 23, 126));
  loadColorButtons(blue2, sf::Color(19, 23, 126));
}

void RegisterView::loadColorsRed() {

  red0.setPosition({620, 245}, 3);
  red0.drawButton(view);
  red1.setPosition({620, 305}, 3);
  red1.drawButton(view);
  red2.setPosition({620, 365}, 3);
  red2.drawButton(view);
  loadColorButtons(red0, sf::Color(181,26,20));
  loadColorButtons(red1, sf::Color(181, 26, 20));
  loadColorButtons(red2, sf::Color(181, 26, 20));
}

void RegisterView::loadColorsYellow() {
  yellow0.setPosition({660, 245}, 3);
  yellow0.drawButton(view);
  yellow1.setPosition({660, 305}, 3);
  yellow1.drawButton(view);
  yellow2.setPosition({660, 365}, 3);
  yellow2.drawButton(view);
  loadColorButtons(yellow0, sf::Color(199,191,42));
  loadColorButtons(yellow1, sf::Color(199,191,42));
  loadColorButtons(yellow2, sf::Color(199,191,42));
}

void RegisterView::loadColorsGreen() {

  green0.setPosition({700, 245}, 3);
  green0.drawButton(view);
  green1.setPosition({700, 305}, 3);
  green1.drawButton(view);
  green2.setPosition({700, 365}, 3);
  green2.drawButton(view);
  green3.setPosition({700, 425}, 3);
  green3.drawButton(view);
  loadColorButtons(green0, sf::Color(67,199,42));
  loadColorButtons(green1, sf::Color(67, 199, 42));
  loadColorButtons(green2, sf::Color(67, 199, 42));
  loadColorButtons(green3, sf::Color(67, 199, 42));
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
    if (isFourPlayers) {
      loadFourPlayers();
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}