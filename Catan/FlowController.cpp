#include "FlowController.hpp"

extern CImg<unsigned char> image;

void FlowController::initializeFlow() {
  Window::getInstance().printTitleScreenLabels();

  goView(titleDisplay, image);
  constantFlow();
}

void FlowController::constantFlow() {
  while (true) {
    if (Window::getInstance().isPlayClicked())
      Window::getInstance().goPlayView();

    if (Window::getInstance().isAboutClicked())
      Window::getInstance().goAboutView();
  }
}

void FlowController::goView(CImgDisplay &display, CImg<unsigned char> &image) {
  this->currentDisplay = display;
  display.show();
  while (!display.is_closed()) {
    display.display(image);
    display.wait();
  }
}

void FlowController::close() { this->currentDisplay.close(); }