#pragma once
#include "Label.hpp"
#include "TitleView.hpp"
#include <SFML/Graphics.hpp>

class AboutView {
public:
  void goAboutView();

private:
  void loadAboutView();
  void loadLabels();
  void drawAboutView();
  bool isMouseLeft(sf::Event) const;
  bool isEscapePressed() const;

private:
  sf::RenderWindow aboutView;
  sf::Texture aboutImage;
  sf::Sprite aboutSprite;
  sf::Font font;
  sf::Event event;
  Label *back;
};
