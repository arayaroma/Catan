#pragma once
#include "Button.hpp"
#include "Label.hpp"
#include "PlayView.hpp"
#include "Player.hpp"
#include "TextBox.hpp"
#include "TitleView.hpp"
#include "View.hpp"
#include <SFML/Graphics.hpp>
#include <list>

using std::list;
class RegisterView : public View {
public:
  void goView() override;

private:
  void loadView() override;
  void drawView() override;

public:
  RegisterView();

private:
  bool isEscapePressed() const;
  void registerButton();
  void showCoordinates(sf::Event);
  void loadTextFields(TextBox &);
  void loadButtons();
  void loadRegisterButtons(Button &);
  void loadColors();
  void getNames();

  void loadPlayerList();
  void loadThreePlayers();
  void loadFourPlayers();
  void loadTextboxes();
  void makeTextboxes();
  void makeButtons();
  void makePlayerButtons();
  void typeOverTextbox(sf::Event);

  void drawTextboxes();
  void drawButtons();

  void goTitleView();
  bool isPlayButtonPressed();
  void playButtonPressed();
  void loadBeforeChangingScene();

private:
  TextBox firstTextbox, secondTextbox, thirdTextbox, fourthTextbox,newGame,loadGame;
  Label *title, *name, *color, *note;
  Button threePlayersButton, fourPlayersButton, playButton,loadGames, newGames;
  bool isThreePlayers = false;
  bool isFourPlayers = false;
};