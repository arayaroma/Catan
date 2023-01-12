#include "FlowController.hpp"

extern CImg<unsigned char> image;

void FlowController::initializeFlow() {
  Window::getInstance().printTitleScreenLabels();

  goView(titleDisplay, image);
  constantFlow();
}

void FlowController::constantFlow() {
  while (true) {
    // Play Label
    if (Window::getInstance().isPlayClicked())
      Window::getInstance().goPlayView();
    // About Label
    if (Window::getInstance().isAboutClicked())
      Window::getInstance().goAboutView();
    // Back Label
    if (Window::getInstance().isBackClicked())
      Window::getInstance().goBackTitle();
  }
}

void FlowController::goView(CImgDisplay &display, CImg<unsigned char> &image) {
  this->currentDisplay = display;
  display.show();
  display.display(image);
}

void FlowController::close() { this->currentDisplay.close(); }