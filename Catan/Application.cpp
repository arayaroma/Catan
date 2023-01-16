#include "Application.hpp"

Application &Application::run() {
  FlowController::getInstance().initializeFlow();
  return this->getInstance();
}