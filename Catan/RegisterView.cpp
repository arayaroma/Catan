#include "RegisterView.hpp"

Button btnStart;
Button btnClose;

bool RegisterView::goBack(sf::RenderWindow &window) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return true;
  return false;
}

void RegisterView::drawRegisterView() {
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

void RegisterView::loadRegisterView() {
  registerView.create(sf::VideoMode(1280, 720), "Register");
  registerImage.loadFromFile("Images/catan_1280x720.jpg");
  registerSprite.setTexture(registerImage);
  font.loadFromFile("mononoki.ttf");
  registerView.setKeyRepeatEnabled(true);
  registerView.setFramerateLimit(120);
  loadTextBoxes();
  loadButtons();
}

void RegisterView::loadTextBoxes() {
  name1 = TextBox(15, sf::Color::Black, false, {345, 240}, {180, 40},
                  sf::Color::White);
  name1.serFont(font);
  name1.setPosition({365, 250});
  name2 = TextBox(15, sf::Color::Black, false, {345, 300}, {180, 40},
                  sf::Color::White);
  name2.serFont(font);
  name2.setPosition({365, 310});
  name3 = TextBox(15, sf::Color::Black, false, {345, 360}, {180, 40},
                  sf::Color::White);
  name3.serFont(font);
  name3.setPosition({365, 370});
  name4 = TextBox(15, sf::Color::Black, false, {345, 420}, {180, 40},
                  sf::Color::White);
  name4.serFont(font);
  name4.setPosition({365, 430});
}

void RegisterView::loadButtons() {
  btnPlay = Button("Jugar", {150, 60}, 20, sf::Color::Blue, sf::Color::Black);
  btnPlay.setPosition({1000, 320});
  btnPlay.setFont(font);
  btn3Players =
      Button("3 Jugadores", {200, 60}, 20, sf::Color::Green, sf::Color::Black);
  btn3Players.setPosition2({100, 280});
  btn3Players.setFont(font);
  btn4Players =
      Button("4 Jugadores", {200, 60}, 20, sf::Color::Green, sf::Color::Black);
  btn4Players.setPosition2({100, 350});
  btn4Players.setFont(font);
}

void RegisterView::goRegisterView() {
  loadRegisterView();
  drawRegisterView();
  while (registerView.isOpen()) {
    while (registerView.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        registerView.close();

      case sf::Event::TextEntered:
        if (name1.isMouseOver(registerView)) {
          name1.typeOn(event);
        } else if (name2.isMouseOver(registerView)) {

          name2.typeOn(event);
        } else if (name3.isMouseOver(registerView)) {

          name3.typeOn(event);
        } else if (name4.isMouseOver(registerView)) {
          name4.typeOn(event);
        }
        break;

      case sf::Event::KeyPressed:
        if (goBack(registerView)) {
          registerView.close();
          TitleView titleView;
          titleView.goTitleView();
        }
      case sf::Event::MouseButtonPressed:
        showCoordinates(registerView, event);
        if (event.mouseButton.button == sf::Mouse::Left) {
          if (btnPlay.isMouseOver(registerView)) {
            registerView.close();
            PlayView playView;
            playView.goPlayView();
          } else if (btn3Players.isMouseOver(registerView)) {

            Player3 = true;
          } else if (btn4Players.isMouseOver(registerView)) {

            Player4 = true;
          }
        }
        break;
      }
    }
  }
}

void RegisterView::loadStartButtons(sf::RenderWindow &playWindow) {

  Button p("p", {0, 0}, 20, sf::Color::Green, sf::Color::Black);
  p.setPosition3({0, 50});

  Button btnIni("Iniciar", {100, 40}, 20, sf::Color::Green, sf::Color::Black);
  btnIni.setPosition3({1040, 0});

  Button btnClose("Cerrar", {100, 40}, 20, sf::Color::Red, sf::Color::Black);
  btnClose.setPosition2({1145, 0});

  Button btnTurn("Turno", {100, 40}, 20, sf::Color::Red, sf::Color::Black);
  btnTurn.setPosition2({980, 600});

  Button btnTrade("Comerciar", {160, 40}, 20, sf::Color::Red, sf::Color::Black);
  btnTrade.setPosition2({30, 625});

  Button btnBuy("Comprar", {130, 40}, 20, sf::Color::Red, sf::Color::Black);
  btnBuy.setPosition2({200, 625});

  btnClose.setFont(font);
  p.setFont(font);
  btnIni.setFont(font);
  btnTurn.setFont(font);
  btnTrade.setFont(font);
  btnBuy.setFont(font);

  if (btnIni.isMouseOver(playWindow)) {

    btnIni.setBackColor(sf::Color::Blue);
  } else {
    btnIni.setBackColor(sf::Color::Green);
  }
  if (btnClose.isMouseOver(playWindow)) {

    btnClose.setBackColor(sf::Color::Blue);
  } else {
    btnClose.setBackColor(sf::Color::Red);
  }
  if (btnTurn.isMouseOver(playWindow)) {

    btnTurn.setBackColor(sf::Color::Blue);
  } else {
    btnTurn.setBackColor(sf::Color::Magenta);
  }
  if (btnTrade.isMouseOver(playWindow)) {

    btnTrade.setBackColor(sf::Color::Blue);
  } else {
    btnTrade.setBackColor(sf::Color::Magenta);
  }
  if (btnBuy.isMouseOver(playWindow)) {

    btnBuy.setBackColor(sf::Color::Blue);
  } else {
    btnBuy.setBackColor(sf::Color::Magenta);
  }

  p.drawTo(playWindow);
  btnIni.drawTo(playWindow);
  btnClose.drawTo(playWindow);
  btnTurn.drawTo(playWindow);
  btnTrade.drawTo(playWindow);
  btnBuy.drawTo(playWindow);
}

void RegisterView::loadTextFields(sf::RenderWindow &registerView,
                                  TextBox &name1, TextBox &name2,
                                  TextBox &name3, TextBox &name4) {
  if (Player3 == true) {
    if (name1.isMouseOver(registerView)) {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        name1.setSelected(true);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::End)) {
        name1.setSelected(false);
      }
    } else if (name2.isMouseOver(registerView)) {

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        name2.setSelected(true);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::End)) {
        name2.setSelected(false);
      }
    } else if (name3.isMouseOver(registerView)) {

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
        name3.setSelected(true);
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::End)) {
        name3.setSelected(false);
      }
    } else if (name4.isMouseOver(registerView)) {

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
  }
  if (Player4 == true) {
    name4.drawTo(registerView);
  }
}
void RegisterView::loadRegisterButtons(sf::RenderWindow &registerView,
                                       Button &btnPlay, Button &btn3Players,
                                       Button &btn4Players) {

  if (btnPlay.isMouseOver(registerView)) {
    btnPlay.setBackColor(sf::Color::White);
  } else {
    btnPlay.setBackColor(sf::Color::Blue);
  }
  if (btn3Players.isMouseOver(registerView)) {
    btn3Players.setBackColor(sf::Color::White);
  } else {
    btn3Players.setBackColor(sf::Color::Green);
  }
  if (btn4Players.isMouseOver(registerView)) {
    btn4Players.setBackColor(sf::Color::White);
  } else {
    btn4Players.setBackColor(sf::Color::Green);
  }
}

void RegisterView::registerButton(sf::RenderWindow &window) {
  Label *title = new Label("Registro de Usuarios", sf::Color::Black, font,
                           sf::Text::Bold, 30, 480.f, 50.f);
  Label *name = new Label("Nombre", sf::Color::Black, font, sf::Text::Bold, 20,
                          405.f, 200.f);
  Label *type = new Label("Tipo de jugador", sf::Color::Black, font,
                          sf::Text::Bold, 20, 545.f, 200.f);
  Label *color = new Label("Color", sf::Color::Black, font, sf::Text::Bold, 20,
                           800.f, 200.f);

  window.draw(title->getTextInstance());
  window.draw(type->getTextInstance());
  window.draw(name->getTextInstance());
  window.draw(color->getTextInstance());
}

void RegisterView::showCoordinates(sf::RenderWindow &window, sf::Event event) {
  if (event.type == sf::Event::MouseButtonPressed) {

    if (event.mouseButton.button == sf::Mouse::Right) {
      std::cout << "the right button was pressed" << std::endl;
      std::cout << "mouse x: " << event.mouseButton.x << std::endl;
      std::cout << "mouse y: " << event.mouseButton.y << std::endl;
    }
  }
  if (event.type == sf::Event::MouseButtonPressed) {
    if (event.mouseButton.button == sf::Mouse::Left) {
      std::cout << "the Left button was pressed" << std::endl;
      std::cout << "mouse x: " << event.mouseButton.x << std::endl;
      std::cout << "mouse y: " << event.mouseButton.y << std::endl;
    }
  }
}