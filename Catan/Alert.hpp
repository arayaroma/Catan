#pragma once
#include "Button.hpp"
#include "Label.hpp"
#include "View.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>

#define NONE 0
#define INFORMATION 1 
#define CONFIRMATION 2
#define WARNING 3
#define ERROR 4

using std::string;

class Alert : public View {
private:
  Label *title, *message;
  string titleMessage;
  Button *okButton;
  int alertType;

public:
  void goView() override;

private:
  void loadView() override;
  void drawView() override;

private:
  void makeButton();
  void drawButton(Button &);
  string separateText(string);
  Alert createAlert(int);
  Alert noneAlert();
  Alert errorAlert();
  Alert warningAlert();
  Alert confirmationAlert();
  Alert informationAlert();

public:
  Alert();
  Alert(int, string, string);
  sf::Text getTitle() const;
};
