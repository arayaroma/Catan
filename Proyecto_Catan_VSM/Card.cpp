#include "Card.h"
#include "iostream" 
using namespace std;
Card::Card(string typeCard, string urlCard, string nameCard) {
	type = typeCard;
	url = urlCard;
	name = nameCard;
}
string Card::getType() { return type; }
string Card::getUrl() { return url; }
string Card::getName() { return name; }
void Card::setName(string nameCard) { name = nameCard; }
void Card::setType(string typeCard) { type = typeCard; }
void Card::setUrl(string urlCard) { url = urlCard; }
void Card::toString() {
	cout << type << "   " << url << " " << name<< endl;

}