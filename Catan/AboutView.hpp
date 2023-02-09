#pragma once
#include "Label.hpp"
#include "TitleView.hpp"
#include "View.hpp"
#include <SFML/Graphics.hpp>

class AboutView : public View {
public:
  void goView() override;

private:
  void loadView() override;
  void drawView() override;

private:
  void loadLabels();
  void goTitleView();
  void loadDevelopersPhotos();

private:
  Label *back;
  sf::Texture danielImage, dilanImage, jesusImage;
  sf::Sprite danielSprite, dilanSprite, jesusSprite;
};
