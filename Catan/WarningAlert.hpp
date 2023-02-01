#pragma once
#include "Alert.hpp"
using std::string;

class WarningAlert : public Alert {
private:
  const string warningAlertPath = "Images/alerts/warning.png";
  Button cancelButton;

private:
  void makeOkButton() override;
  void makeCancelButton();
  void drawButton(Button &) override;

public:
  void goView() override;

private:
  void loadView() override;
  void drawView() override;
  void loadImageIcon() override;

public:
  WarningAlert();
  WarningAlert(string, string);

  const string getWarningAlertPath() const { return this->warningAlertPath; }
};
