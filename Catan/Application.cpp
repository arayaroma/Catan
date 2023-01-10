#include "Application.hpp"

Application &Application::run() {

  DataStructures program;
  program.assemblyLand();
  program.makeFigures();

  Window::getInstance().printTitleScreenLabels();
  Window::getInstance().showDisplay();

  return this->getInstance();
}
