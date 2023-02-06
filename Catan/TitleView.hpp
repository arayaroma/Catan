#pragma once
#include "AboutView.hpp"
#include "ConfirmationAlert.hpp"
#include "ErrorAlert.hpp"
#include "InformationAlert.hpp"
#include "Label.hpp"
#include "MenuView.hpp"
#include "NoneAlert.hpp"
#include "RegisterView.hpp"
#include "View.hpp"
#include "WarningAlert.hpp"
#include <SFML/Graphics.hpp>

#define aboutView_X0 485
#define aboutView_X1 850
#define aboutView_Y0 460
#define aboutView_Y1 560

#define playView_X0 485
#define playView_X1 805
#define playView_Y0 265
#define playView_Y1 355

using std::string;
class TitleView : public View {

public:
  void goView() override;

private:
  void loadView() override;
  void drawView() override;

private:
  void loadLabels();
  bool isMouseLeft(sf::Event) const;
  bool isAboutView(sf::Event) const;
  bool isPlayView(sf::Event) const;
  void goMenuView();
  void goAboutView();

private:
  Label *title, *play, *about;
};
