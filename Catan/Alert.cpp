#include "Alert.hpp"

// Terminar de arreglar este metodo
string Alert::separateText(string text) {
  int i, cont = 0;
  string modifiedText = "";
  for (i = 0; i < text.length() - 1; i++) {
    if (cont == 26) {
      text += '\n';
      cont = 0;
    }
    modifiedText += text;
    cont++;
  }
  return modifiedText;
}

sf::Text Alert::getTitleMessage() const {
  return this->titleLabel->getTextInstance();
}