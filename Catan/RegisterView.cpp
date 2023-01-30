#include "RegisterView.hpp"

Button btn4Players("4 Jugadores", { 200,60 }, 20, sf::Color::Green, sf::Color::Black);
Button btnPlay("Jugar", { 150,60 }, 20, sf::Color::Blue, sf::Color::Black);
Button btn3Players("3 Jugadores", { 200,60 }, 20, sf::Color::Green, sf::Color::Black);
TextBox name4 = TextBox(15, sf::Color::Black, false, { 345,420 }, { 180, 40 }, sf::Color::White);
TextBox name3 = TextBox(15, sf::Color::Black, false, { 345,360 }, { 180, 40 }, sf::Color::White);
TextBox name1 = TextBox(15, sf::Color::Black, false, { 345,240 }, { 180, 40 }, sf::Color::White);
TextBox name2 = TextBox(15, sf::Color::Black, false, { 345,300 }, { 180, 40 }, sf::Color::White);

bool RegisterView::goBack(sf::RenderWindow &window) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return true;
  return false;
}

void RegisterView::loadTextureButtons() {

    name1.serFont(font);
    name1.setPosition({ 365,250 });
    name2.serFont(font);
    name2.setPosition({ 365,310 });
    name3.serFont(font);
    name3.setPosition({ 365,370 });
    name4.serFont(font);
    name4.setPosition({ 365,430 });
    btnPlay.setPosition({ 1000,320 });
    btnPlay.setFont(font);
    btn3Players.setPosition2({ 100,280 });
    btn3Players.setFont(font);
    btn4Players.setPosition2({ 100,350 });
    btn4Players.setFont(font);

}

void RegisterView::drawRegisterView() {

    registerView.create(sf::VideoMode(1280, 720), "Register");
    registerView.setKeyRepeatEnabled(true);
    registerView.setFramerateLimit(120);
}

void RegisterView::goRegisterView() {
    loadTextureButtons();
    sf::Texture registerImage;
    registerImage.loadFromFile("Images/catan_1280x720.jpg");
    sf::Sprite registerSprite(registerImage);
    font.loadFromFile("mononoki.ttf");
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
    registerView.clear();
    registerView.draw(registerSprite);
    registerButton(registerView);
    loadRegisterButtons(registerView, btnPlay);
    loadRegisterButtons(registerView, btn3Players);
    loadRegisterButtons(registerView, btn4Players);

    if (Player3 == true) {
        loadTextFields(registerView, name1);
        loadTextFields(registerView, name2);
        loadTextFields(registerView, name3);
        if (Player4 == true) {
            loadTextFields(registerView, name4);
        }
    }
    registerView.display();

  }
}
void RegisterView::registerButton(sf::RenderWindow& window) {
    Label* title = new Label("Registro de Usuarios", sf::Color::Black, font, sf::Text::Bold, 30, 480.f, 50.f);
    Label* name = new Label("Nombre", sf::Color::Black, font, sf::Text::Bold, 20, 405.f, 200.f);
    Label* type = new Label("Tipo de jugador", sf::Color::Black, font, sf::Text::Bold, 20, 545.f, 200.f);
    Label* color = new Label("Color", sf::Color::Black, font, sf::Text::Bold, 20, 800.f, 200.f);

    window.draw(title->getTextInstance());
    window.draw(type->getTextInstance());
    window.draw(name->getTextInstance());
    window.draw(color->getTextInstance());
}

void RegisterView::loadRegisterButtons(sf::RenderWindow& registerView, Button& btn) {

    if (btn.isMouseOver(registerView)) {
        btn.setBackColor(sf::Color::White);
    }
    else {
        btn.setBackColor(sf::Color::Blue);
    }
    btn.drawTo(registerView);

}
void RegisterView::loadTextFields(sf::RenderWindow& registerView, TextBox& name1) {

    if (name1.isMouseOver(registerView)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            name1.setSelected(true);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::End)) {
            name1.setSelected(false);
        }
    }
    name1.drawTo(registerView);
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