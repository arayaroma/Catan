#include "RegisterView.hpp"

Button btn4Players("4 Jugadores", {200, 60}, 20, sf::Color::Green,
                   sf::Color::Black);
Button btnPlay("Jugar", {150, 60}, 20, sf::Color::Blue, sf::Color::Black);
Button btn3Players("3 Jugadores", {200, 60}, 20, sf::Color::Green,
                   sf::Color::Black);
TextBox name4 = TextBox(15, sf::Color::Black, false, {345, 420}, {180, 40},
                        sf::Color::White);
TextBox name3 = TextBox(15, sf::Color::Black, false, {345, 360}, {180, 40},
                        sf::Color::White);
TextBox name1 = TextBox(15, sf::Color::Black, false, {345, 240}, {180, 40},
                        sf::Color::White);
TextBox name2 = TextBox(15, sf::Color::Black, false, {345, 300}, {180, 40},
                        sf::Color::White);

bool RegisterView::goBack() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return true;
  return false;
}

void RegisterView::loadTextureButtons() {

  name1.serFont(font);
  name1.setPosition({365, 250});
  name2.serFont(font);
  name2.setPosition({365, 310});
  name3.serFont(font);
  name3.setPosition({365, 370});
  name4.serFont(font);
  name4.setPosition({365, 430});
  btnPlay.setPosition({1000, 320});
  btnPlay.setFont(font);
  btn3Players.setPosition2({100, 280});
  btn3Players.setFont(font);
  btn4Players.setPosition2({100, 350});
  btn4Players.setFont(font);
}

void RegisterView::loadView() {}

void RegisterView::drawView() {
  view.create(sf::VideoMode(1280, 720), "Register");
  view.setKeyRepeatEnabled(true);
  view.setFramerateLimit(120);
}

void RegisterView::goView() {
  loadTextureButtons();
  sf::Texture registerImage;
  registerImage.loadFromFile("Images/catan_1280x720.jpg");
  sf::Sprite registerSprite(registerImage);
  font.loadFromFile("mononoki.ttf");
  drawView();
  

  while (view.isOpen()) {
    while (view.pollEvent(event)) {
      switch (event.type) {
      case sf::Event::Closed:
        view.close();

      case sf::Event::TextEntered:
        if (name1.isMouseOver(view)) {
          name1.typeOn(event);
        } else if (name2.isMouseOver(view)) {

          name2.typeOn(event);
        } else if (name3.isMouseOver(view)) {

          name3.typeOn(event);
        } else if (name4.isMouseOver(view)) {
          name4.typeOn(event);
        }
        break;

      case sf::Event::KeyPressed:
        if (goBack()) {
          view.close();
          TitleView titleView;
          titleView.goView();
        }
      case sf::Event::MouseButtonPressed:
        showCoordinates( event);
        if (event.mouseButton.button == sf::Mouse::Left) {
          if (btnPlay.isMouseOver(view)) {
            view.close();
            PlayView playView;
            //Acá se meten los nombres en un metodo a la lista
            getNames(); 
            playView.goView();
          } else if (btn3Players.isMouseOver(view)) {

            Player3 = true;
          } else if (btn4Players.isMouseOver(view)) {

            Player4 = true;
          }
        }
        break;
      }
    }
    view.clear();
    view.draw(registerSprite);
    registerButton();
   
    loadRegisterButtons(btnPlay);
    loadRegisterButtons( btn3Players);
    loadRegisterButtons(btn4Players);
 
    if (Player3 == true) {
      loadTextFields( name1);
      loadTextFields( name2);
      loadTextFields( name3);
      if (Player4 == true) {
        loadTextFields(name4);
      }
    }
    loadColors();
    view.display();
  }
}
void RegisterView::registerButton() {
  Label *title = new Label("Registro de Usuarios", sf::Color::Black, font,
                           sf::Text::Bold, 30, 480.f, 50.f);
  Label *name = new Label("Nombre", sf::Color::Black, font, sf::Text::Bold, 20,
                          405.f, 200.f);

  Label *color = new Label("Color", sf::Color::Black, font, sf::Text::Bold, 20,
                           600.f, 200.f);


  Label* note = new Label("Nota: Acerca el cursor al campo de texto del jugador, presiona ENTER para escribir y END para salir.", sf::Color::Blue, font, sf::Text::Bold, 20,
      10.f, 640.f);

  view.draw(title->getTextInstance());
  view.draw(name->getTextInstance());
  view.draw(color->getTextInstance());
  view.draw(note->getTextInstance());

}

void RegisterView::loadRegisterButtons(Button &btn) {
  if (btn.isMouseOver(view)) {
    btn.setBackColor(sf::Color::White);
  } else {
    btn.setBackColor(sf::Color::Blue);
  }
  btn.drawTo(view);
}

void RegisterView::loadTextFields( TextBox &name1) {

  if (name1.isMouseOver(view)) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
      name1.setSelected(true);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::End)) {
      name1.setSelected(false);
    }
  }
  name1.drawTo(view);
}

void RegisterView::loadColors() {
    int  y=245;
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

void RegisterView::showCoordinates( sf::Event event) {
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

void RegisterView::getNames() {

   std::cout<< name1.getText()<<std:: endl; 
   std::cout<< name2.getText()<<std:: endl; 
   std::cout<< name3.getText()<<std:: endl; 
   std::cout<< name4.getText()<<std:: endl;

}