#include "Program.h"
using namespace std;

Program::Program() {
	this->turn = 0;
	lands = LinkedList();	
}
void Program::assemblyLand() {
	for (int i = 0; i < 4; i++) {
		lands.add(new Land("Bosque", "images/bosque.png"));
		lands.add(new Land("Pastos", "images/pastos.png"));
		if (i < 3) {
			lands.add(new Land("Sembrados", "images/Sembrados.png"));
			lands.add(new Land("Cerros", "images/Cerros.png"));
			lands.add(new Land("Montañas", "images/Montañas.png"));}}
	lands.add(new Land("Desierto", "images/Desierto.png"));
	lands.to_string();
}