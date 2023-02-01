#pragma once
#include "Alert.hpp"
using std::string;
class InformationAlert : public Alert {
private:
  const string informationAlertPath = "Images/alerts/information.png";

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
  InformationAlert();
  InformationAlert(string, string);

  const string getInformationAlertPath() const {
    return this->informationAlertPath;
  }
};
