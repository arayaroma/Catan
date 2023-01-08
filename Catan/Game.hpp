#pragma once
#include "Window.hpp"
#include <iostream>
class Game {
public:
  Game(const Game &) = delete;

  static Game &getInstance() {
    static Game instance;
    return instance;
  }

protected:
  Game() {}
};
