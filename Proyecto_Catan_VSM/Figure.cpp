#include "Figure.h"
using namespace std;

Figure::Figure(string typeCard, string urlCard) {
	type = typeCard;
	url = urlCard;
}

string Figure::getType() { return type; }
string Figure::getUrl() { return url; }
void Figure::setType(string typeCard) { type = typeCard; }
void Figure::setUrl(string urlCard) { url = urlCard; }
