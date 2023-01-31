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
  void drawRegisterView();

  void registerButton(sf::RenderWindow &);
  void showCoordinates(sf::RenderWindow &, sf::Event);
  bool goBack(sf::RenderWindow &);
  void loadTextFields(sf::RenderWindow &registerwindow, TextBox &tex1);
  void loadTextureButtons();

  void loadRegisterButtons(sf::RenderWindow &registerwindow, Button &btn1);

private:
  sf::RenderWindow registerView;
  sf::Texture registerImage;
  sf::Sprite registerSprite;
  sf::Font font;
  sf::Event event;

private:
  bool Player3 = false;
  bool Player4 = false;
};