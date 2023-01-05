#include "Land.h"
using namespace std;

Land::Land(string typeLand, string urlLand) {
	this->type = typeLand;
	this->url = urlLand;
}

void Land::to_string() {
	cout << type << "   " << url << " " << endl;
}