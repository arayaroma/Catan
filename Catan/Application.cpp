#include "Application.hpp"

Application &Application::run() {

  DataStructures program;
  program.loadLands();
  program.makeGraph();

  Window::getInstance().printTitleScreenLabels();
  Window::getInstance().showDisplay();
 // 
  return this->getInstance();
}
