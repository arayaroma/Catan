#pragma once
#include "Button.hpp"
#include "Label.hpp"
#include "PlayView.hpp"
#include "TextBox.hpp"
#include "TitleView.hpp"
#include <SFML/Graphics.hpp>


class RegisterView {
public:
  void goRegisterView();

private:
  void loadRegisterView();
  void drawRegisterView();
  void loadTextFields(sf::RenderWindow &, TextBox &, TextBox &, TextBox &,
                      TextBox &);
  void loadRegisterButtons(sf::RenderWindow &, Button &, Button &, Button &);
  void loadStartButtons(sf::RenderWindow &);
  void registerButton(sf::RenderWindow &);
  void showCoordinates(sf::RenderWindow &, sf::Event);
  bool goBack(sf::RenderWindow &);
  void loadTextBoxes();
  void loadButtons();

private:
  sf::RenderWindow registerView;
  sf::Texture registerImage;
  sf::Sprite registerSprite;
  sf::Font font;
  sf::Event event;
  // sf::ConvexShape register;
  Button btnPlay, btn3Players, btn4Players;
  TextBox name1, name2, name3, name4;

private:
  bool Player3 = false;
  bool Player4 = false;
};