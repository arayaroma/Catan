#include "Program.h"
using namespace std;

Program::Program() {
	this->turn = 0;
	lands = LinkedList();	
}

void Program::assemblyLand() {
	Land forest = Land("Bosque", "12345");
	lands.add(forest);
	lands.to_string();

	//Land* forest = new Land("Bosque", "12345");
	//lands.add(forest);
	//lands.print();

	/*Card* card = new Card("Material","123","Wood");
	Node* aux2 = new Node(card);
	cards->push(aux2);
	cards->print();*/
}