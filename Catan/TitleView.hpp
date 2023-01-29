#pragma once
#include "Label.hpp"
#include "AboutView.hpp"
#include "RegisterView.hpp"
#include <SFML/Graphics.hpp>

#define log(x) std::cout << x << std::endl;

#define aboutView_X0 485
#define aboutView_X1 850
#define aboutView_Y0 460
#define aboutView_Y1 560

#define playView_X0 485
#define playView_X1 805
#define playView_Y0 265
#define playView_Y1 355

class TitleView {
public:
  void goTitleView();

private:
  void loadTitleView();
  void loadLabels();
  void drawTitleView();
  bool isMouseLeft(sf::Event) const;
  bool isAboutView(sf::Event) const;
  bool isPlayView(sf::Event) const;

private:
  sf::RenderWindow titleWindow;
  sf::Texture titleImage;
  sf::Sprite titleSprite;
  sf::Font font;
  sf::Event event;
  Label *title, *play, *about;
};
