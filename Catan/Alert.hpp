#pragma once
#include "Button.hpp"
#include "Label.hpp"
#include "View.hpp"
#include <SFML/Graphics.hpp>
#include <string>

#define NONE 0
#define INFORMATION 1
#define CONFIRMATION 2
#define WARNING 3
#define ERROR 4

using std::string;

class Alert : public View {
protected:
  int alertType;
  Label *titleLabel, *messageLabel;
  string titleMessage, bodyMessage;
  Button okButton;
  sf::Texture imageIcon;
  sf::Sprite imageIconSprite;

public:
  virtual void goView() override = 0;

protected:
  virtual void loadView() override = 0;
  virtual void drawView() override = 0;
  virtual void drawButton(Button &) = 0;
  virtual void makeOkButton() = 0;
  virtual void loadImageIcon() = 0;

protected:
  virtual string separateText(string);
  virtual sf::Text getTitleMessage() const;
};
