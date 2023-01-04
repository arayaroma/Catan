#include "Program.h"
Program::Program() {}
using namespace std;
void Program::assemblyLand() {
	Land land("Bosque", "12345");
	lands.add(land);
	lands.print();

	/*Card* card = new Card("Material","123","Wood");
	Node* aux2 = new Node(card);
	cards->push(aux2);
	cards->print();*/
}