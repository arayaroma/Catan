#pragma once
#include "Button.hpp"
#include "Label.hpp"
#include "MenuView.hpp"
#include "PlayView.hpp"
#include "Player.hpp"
#include "TextBox.hpp"
#include "View.hpp"
#include <SFML/Graphics.hpp>
#include <list>

using std::list;
using std::string;
class RegisterView : public View {
public:
  void goView() override;

private:
  void loadView() override;
  void drawView() override;

public:
  RegisterView();
  RegisterView(string);

private:
  void registerButton();
  void showCoordinates(sf::Event);
  void loadTextFields(TextBox &);
  void loadButtons();
  void loadRegisterButtons(Button &, sf::Color color);
  void loadRegisterButtons(Button &);
  void loadColorButtons(Button&, sf::Color color);
  bool isThreePlayersButtonPressed(sf::Event);
  bool isFourPlayersButtonPressed(sf::Event);

  void loadAll();
  void loadThreeColors();
  void loadFourColors();

  void loadColorsBlue();
  void loadColorsRed();
  void loadColorsYellow();
  void loadColorsGreen();

 

  void getNamesThreePlayers();
  void getNamesFourPlayers();

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

  void goMenuView();
  bool isPlayButtonPressed();
  bool isClearButtonPressed();
  void playButtonPressed();
  void clearButtonPressed();
  void loadBeforeChangingScene();

  void playerOneColor();
  void playerTwoColor();
  void playerThreeColor();
  void playerFourColor();

  void isAnyColorPressed(sf::Event event);

private:
  TextBox firstTextbox, secondTextbox, thirdTextbox, fourthTextbox;
  Label *title, *name, *color, *note;
  Button threePlayersButton, fourPlayersButton, playButton, clear, blue0,
      yellow0, red0, green0, blue1, yellow1, red1, green1, blue2, yellow2, red2,
      green2, blue3, yellow3, red3, green3;

  bool isThreePlayers = false;
  bool isFourPlayers = false;

  string colorPlayerOne = "";
  string colorPlayerTwo = "";
  string colorPlayerThree = "";
  string colorPlayerFour = "";

  float y = 245;
  float x = 580;
};