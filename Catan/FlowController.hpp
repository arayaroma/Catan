#pragma once
#include "Window.hpp"

class FlowController {
public:
  FlowController(const FlowController &) = delete;

  static FlowController &getInstance() {
    static FlowController instance;
    return instance;
  }

  void initializeFlow();
  void goView(sf::RenderWindow);

  void close();

public:
    sf::RenderWindow actualWindow;

private:
  FlowController() {}
};
