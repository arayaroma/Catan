#include "Alert.hpp"

string Alert::separateText(string text) {
  characterLimit = initializeCharacterLimit();
  for (char letter : text) {
    addToModifiedText(letter);

    if (reachedLimit())
      makeAnEnterSpace();
  }
  return modifiedText;
}

sf::Text Alert::getTitleMessage() const {
  return this->titleLabel->getTextInstance();
}

bool Alert::isOkButtonPressed(sf::Event event) {
  log(okButton.isPressed(event));
  return (okButton.isPressed(event));
}
