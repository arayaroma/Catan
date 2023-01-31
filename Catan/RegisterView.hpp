#pragma once
#include "Button.hpp"
#include "Label.hpp"
#include "PlayView.hpp"
#include "TextBox.hpp"
#include "TitleView.hpp"
#include "View.hpp"
#include <SFML/Graphics.hpp>

class RegisterView : public View {
public:
  void goView() override;

private:
  void loadView() override;
  void drawView() override;

private:
  void registerButton(sf::RenderWindow &);
  void showCoordinates(sf::RenderWindow &, sf::Event);
  bool goBack(sf::RenderWindow &);
  void loadTextFields(sf::RenderWindow &registerwindow, TextBox &tex1);
  void loadTextureButtons();
  void loadRegisterButtons(sf::RenderWindow &registerwindow, Button &btn1);

private:
  bool Player3 = false;
  bool Player4 = false;
};