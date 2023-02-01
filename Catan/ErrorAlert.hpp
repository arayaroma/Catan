#pragma once
#include "Alert.hpp"
using std::string;

class ErrorAlert : public Alert {
private:
  const string errorAlertPath = "Images/alerts/error.png";

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
  ErrorAlert();
  ErrorAlert(string, string);

  const string getErrorAlertPath() const { return this->errorAlertPath; }
};
