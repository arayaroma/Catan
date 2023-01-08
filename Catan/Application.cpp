#include "Application.hpp"

Application &Application::run() {

  DataStructures program;
  program.assemblyLand();

  Window::getInstance().printTitleScreenLabels();
  Window::getInstance().showDisplay();

  return this->getInstance();
}
