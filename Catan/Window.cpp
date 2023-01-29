#include "Window.hpp"

int cont = 0;
bool var = false;

bool Window::goBack(sf::RenderWindow &window) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    return true;
  return false;
}

void Window::showCoordinates(sf::RenderWindow &window) {
  log("x: " << sf::Mouse::getPosition(window).x);
  log("y: " << sf::Mouse::getPosition(window).y);
}