#pragma once
#include "Alert.hpp"
using std::string;

class ConfirmationAlert : public Alert {
private:
  const string confirmationAlertPath = "Images/alerts/confirmation.png";
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
  ConfirmationAlert();
  ConfirmationAlert(string, string);

  const string getConfirmationAlertPath() const {
    return this->confirmationAlertPath;
  }
};
