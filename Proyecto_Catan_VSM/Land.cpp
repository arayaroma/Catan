#include "Land.h"
using namespace std;
Land::Land(string typeLand, string urlLand) {
	type = typeLand;
	url = urlLand;
}

string Land::getType() { return type; }
string Land::getUrl() { return url; }

void Land::setType(string typeLand) { type = typeLand; }
void Land::setUrl(string urlLand) { url = urlLand; }

void Land::toString() {
	cout << type << "   " << url << " " << endl;
}