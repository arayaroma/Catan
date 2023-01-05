#include "Figure.h"
using namespace std;

Figure::Figure(string typeCard, string urlCard) {
	type = typeCard;
	url = urlCard;
}
void Figure::to_string() {
	cout << type << "   " << url << " " << endl;
}
