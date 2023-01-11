#pragma once
#include "FlowController.hpp"

class Application {
public:
  Application(const Application &) = delete;

  static Application &getInstance() {
    static Application instance;
    return instance;
  }

  Application &run();

private:
  Application() {}
};
