#include "Application.hpp"

Application &Application::run() {
  Window::getInstance().goTitleView();
  return this->getInstance();
}