#pragma once
#include "Button.hpp"
#include "Label.hpp"
#include <SFML/Graphics.hpp>
#include <string>

#define INFORMATION "Information"
#define CONFIRMATION "Confirmation"
#define WARNING "Warning"
#define ERROR "Error"
#define NONE "None"

#define alertPosX 1280 / 2
#define alertPosY 720 / 2
#define alertOffsetX -200
#define alertOffsetY -50

using std::string;

class Alert {
private:
  sf::RectangleShape panel;
  sf::Font font;
  Label *title, *message;
  // Button *okButton;
  string alertType;

public:
  Alert();
  Alert(sf::RenderWindow &, string, string, string);
  void show();
  void setTitle(string);
  string getTitle() const;
};
