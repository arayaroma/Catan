#pragma once
#include "Button.hpp"
#include "RegisterView.hpp"
#include "TextBox.hpp"
#include "TitleView.hpp"
#include "View.hpp"
#include <SFML/Graphics.hpp>

class MenuView : public View {
public:
  void goView() override;

private:
  void loadView() override;
  void drawView() override;

public:
  MenuView();

private:
  Button newGameButton, loadGameButton;
  TextBox newGameTextbox, loadGameTextbox;

private:
  void createButtons();
  void createNewGameButton();
  void createLoadGameButton();
  void drawButtons();
  bool isNewGameButtonPressed(sf::Event);
  void newGameButtonPressed();

  void createTextboxes();
  void createNewGameTextbox();
  void drawNewGameTextbox();
  void createLoadGameTextbox();
  void drawLoadGameTextbox();
  void drawTextboxes();
  void goTitleView();
};
