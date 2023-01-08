#include "Application.hpp"

Application &Application::run() {

  Program program;
  program.assemblyLand();

  Window::getInstance().printTitleScreenLabels();
  Window::getInstance().showDisplay();

  return this->getInstance();
}
