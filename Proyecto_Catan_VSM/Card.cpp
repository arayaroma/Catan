#include "Card.h"
#include "iostream" 
using namespace std;
Card::Card(string typeCard, string urlCard, string nameCard) {
	type = typeCard;
	url = urlCard;
	name = nameCard;
}
string Card::getName() { return name; }
void Card::setName(string nameCard) { name = nameCard; }
void Card::to_string() {
	cout << type << "   " << url << " " << name<< endl;

}