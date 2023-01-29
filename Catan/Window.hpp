#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#define log(x) std::cout << x << std::endl;

class Window {
private:
  Window() {}

public:
  Window(const Window &) = delete;

  static Window &getInstance() {
    static Window instance;
    return instance;
  }

private:
  void showCoordinates(sf::RenderWindow &);
  bool goBack(sf::RenderWindow &);
};