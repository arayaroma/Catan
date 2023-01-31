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
  void registerButton();
  void showCoordinates( sf::Event);
  bool goBack();
  void loadTextFields( TextBox &tex1);
  void loadTextureButtons();
  void loadRegisterButtons( Button &btn1);
  void loadColors(); 
  void getNames(); 
private:
  bool Player3 = false;
  bool Player4 = false;
};