#pragma once
#include "Alert.hpp"
using std::string;

class NoneAlert : public Alert {
private:
   string noneAlertPath = "Images/alerts/information.png";

private:
  void makeOkButton() override;
  void drawButton(Button &) override;

public:
  void goView() override;

private:
  void loadView() override;
  void drawView() override;
  void loadImageIcon() override;

public:
  NoneAlert();
  NoneAlert(string, string);
   string getNoneAlertPath() const { return this->noneAlertPath; }
};
