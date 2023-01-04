#include "Program.h"
#include "iostream"
Program::Program() {}
using namespace std;
void Program::assemblyLand() {
	Land* land = new Land("Bosque", "12345");
	LandNode *aux = new LandNode(land);
	lands->add(aux);
	lands->print();

	Card* card = new Card("Material","123","Wood");
	CardNode* aux2 = new CardNode(card);
	cards->push(aux2);
	cards->print();
}