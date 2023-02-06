#pragma once
#include "Button.hpp"
#include "ErrorAlert.hpp"
#include "FileHandler.hpp"
#include "PlayView.hpp"
#include "RegisterView.hpp"
#include "TextBox.hpp"
#include "TitleView.hpp"
#include "View.hpp"
#include <SFML/Graphics.hpp>

using std::string;

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
  void newGameButtonPressed(string);

  void createTextboxes();
  void createNewGameTextbox();
  void drawNewGameTextbox();
  void createLoadGameTextbox();
  void drawLoadGameTextbox();
  void drawTextboxes();

  bool isLoadGameButtonPressed(sf::Event);
  void loadGameButtonPressed();
  bool isLoadGameTextboxEmpty();
  void loadGameTextboxEmpty();
  void loadFile(string);
  void loadGameView();

  bool isNewGameTextboxEmpty();
  void newGameTextboxEmpty();
  void newGame(string);

  void loadTextbox(TextBox &);
  void enterText(TextBox &);
  void exitText(TextBox &);

  bool isOverTextbox(TextBox &);

  void goTitleView();
  void goRegisterView();
};