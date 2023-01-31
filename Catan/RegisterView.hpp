#pragma once
#include "Button.hpp"
#include "Label.hpp"
#include "PlayView.hpp"
#include "TextBox.hpp"
#include "TitleView.hpp"
#include "View.hpp"
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include <list>
using std::list;
class RegisterView : public View {
public:
	RegisterView() { this->players = new list<Player*>(); }
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

  void loadPlayerList();
private:
  bool Player3 = false;
  bool Player4 = false;
};