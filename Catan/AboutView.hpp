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
  bool isMouseLeft(sf::Event) const;
  bool isEscapePressed() const;

private:
  Label *back;
};
