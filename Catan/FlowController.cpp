#include "FlowController.hpp"

extern CImg<unsigned char> image;

void FlowController::initializeFlow() {
  goView(image);
  constantFlow();
}

void FlowController::constantFlow() {
  Button buttonInstance;
  while (true) {
    // Play Label
    buttonInstance.changeState();
    if (Window::getInstance().isPlayClicked() && isMainDisplay == true)
      Window::getInstance().goPlayView();
    // About Label
    if (Window::getInstance().isAboutClicked() && isMainDisplay == true)
      Window::getInstance().goAboutView();
    // Back Label
    if (Window::getInstance().isBackClicked())
      Window::getInstance().goBackTitle();
  }
}

void FlowController::goView(CImg<unsigned char> &image) {
  this->currentImage = image;
  this->currentDisplay.show();
  this->currentDisplay.display(image);
}

void FlowController::close() { this->currentDisplay.close(); }