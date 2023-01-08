#include "Button.hpp"

Button::Button() {}

void Button::setPressed(bool isPressed) { this->_isPressed = isPressed; }
bool Button::isPressed() const { return this->_isPressed; }