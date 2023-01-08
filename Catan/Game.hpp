#pragma once
#include "Window.hpp"
#include <iostream>
/*
  Points:
  If a player has 10 points wins.

  If a player has more than 5 roads consecutive it gets:
  Biggest Path Card - II Points.
  However if someone have more than the highest roads player number
  then inmediatly it gets the card.


  Knight Cards
  If a player has at least 3 Knight cards, it gets:
  Biggest Army Card - II Points.

  Thief
  If a player gets 7 from the dice, nobody get materials.

  All player that has more than 7 cards of materials, must
  give those cards in the stacks. With even it rounds to down
  like (if a player has 9 cards, it must give 4 cards).

  Move the thief -> Method
  The player can move the Thief wherever it wants
  Then the player stoles a card of material to a player
  that has a Town or a City in that Tile, if there is more
  than one player, the thief chooses which.

  If the dice rolls the number where the thief stands, the players
  that has towns or cities in those numbers get no material, and the
  thief stands in the same place.
*/
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
