#include "Program.hpp"

Program::Program() {
  this->turn = 0;
  lands = LinkedList();
}

void Program::assemblyLand() {
  for (int i = 0; i < 4; i++) {
    lands.add(new Land("Grass", "Images/tiles/Grass.png"));
    lands.add(new Land("Forest", "Images/tiles/Forest.png"));
    if (i < 3) {
      lands.add(new Land("Brick", "Images/tiles/Brick.png"));
      lands.add(new Land("Mountain", "Images/tiles/Mountain.png"));
      lands.add(new Land("Field", "Images/tiles/Field.png"));
    }
  }
  lands.add(new Land("Dessert", "Images/tiles/Dessert.png"));
  lands.to_string();
}