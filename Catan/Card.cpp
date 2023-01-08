#include "Card.hpp"
#include "iostream"
using namespace std;

Card::Card(string typeCard, string urlCard, string nameCard) {
  type = typeCard;
  url = urlCard;
  name = nameCard;
}

string Card::getName() { return name; }
void Card::setName(string nameCard) { name = nameCard; }
