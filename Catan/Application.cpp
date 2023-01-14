#include "Application.hpp"

Application &Application::run() {

  DataStructures program;
  program.loadLands();
  Window::getInstance().printTitleScreenLabels();
  Window::getInstance().showDisplay();
 // 
  return this->getInstance();
}
