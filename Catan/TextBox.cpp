#include "TextBox.hpp"

TextBox::TextBox() {
  /// cargar todo en nullptr
}

TextBox::TextBox(int size, sf::Color color, bool sel, sf::Vector2f position,
                 sf::Vector2f sizeBorder, sf::Color colorBorder) {
  textBox.setCharacterSize(size);
  textBox.setFillColor(color);
  border.setPosition(position);
  border.setSize(sizeBorder);
  border.setFillColor(colorBorder);
  isSelected = sel;
  if (sel) {
    textBox.setString("_");
  } else {
    textBox.setString("");
  }
}

bool TextBox::isTyping(int charType) const {
  return (charType != DELETE_KEY && charType != ENTER_KEY &&
          charType != ESCAPE_KEY);
}

void TextBox::inputLogic(int charType) {
  // este if se puede separar en un metodo que se llame isTyping
  if (isTyping(charType)) {
    text << static_cast<char>(charType);
  } // crear metodo bool para saber si es delete_key
  else if (charType == DELETE_KEY) {
    if (text.str().length() > 0) { // metodo para saber si hay texto
      deleteLastCharacter();
    }
  }
  textBox.setString(text.str() + "_");
}

void TextBox::deleteLastCharacter() {
  string t = text.str();
  string newT = "";
  for (int i = 0; i < t.length() - 1; i++) {
    newT += t[i];
  }
  text.str("");
  text << newT;
  textBox.setString(text.str());
}

void TextBox::serFont(sf::Font &font) { textBox.setFont(font); }

void TextBox::setPosition(sf::Vector2f pos) { textBox.setPosition(pos); }

void TextBox::setLimit(bool tOf) { hasLimit = tOf; }

void TextBox::setLimit(bool tOf, int lim) {
  hasLimit = tOf;
  limit = lim;
}
// no se entiende que es sel
void TextBox::setSelected(bool sel) {
  isSelected = sel;
  int i = 0;
  if (!sel) {
    string t = text.str();
    string newT = "";
    for (i = 0; i < t.length(); i++) {
      newT += t[i];
    }
    textBox.setString(newT);
  }
}

string TextBox::getText() { return text.str(); }
void TextBox::drawTo(sf::RenderWindow &window) {
  window.draw(border);
  window.draw(textBox);
}

void TextBox::typeOn(sf::Event input) {
  if (isSelected) {
    int charType = input.text.unicode;
    if (charType < 128) { // que es 128? cambiar a define o const
      if (hasLimit) {
        if (text.str().length() <= limit) {
          inputLogic(charType);
        } else if (text.str().length() > limit &&
                   charType == DELETE_KEY) { // ¿que significa?
          deleteLastCharacter();
        }
      } else {
        inputLogic(charType);
      }
    }
  }
}

bool TextBox::isMouseOver(sf::RenderWindow &window) {
  // si se usa una sola vez, se puede dejar aca, pero si no mejor global
  float mouseX = sf::Mouse::getPosition(window).x;
  float mouseY = sf::Mouse::getPosition(window).y;
  float btnPosX = border.getPosition().x;
  float btnPosY = border.getPosition().y;
  float btnxPosWidth = border.getPosition().x + border.getGlobalBounds().width;
  float btnyPosHeight =
      border.getPosition().y + border.getGlobalBounds().height;
  if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight &&
      mouseY > btnPosY) { // ¿que significa?
    return true;
  }
  return false;
}
