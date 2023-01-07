#include "Program.hpp"

std::string urlKnight = "images/knight_cards/knight_";
std::string urlEnd = "_card.png";
std::string urlProgress = "images/develop_cards/develop_";
std::string urlVictoryPoint = "Images/victory_points_cards/victory_point_";

Program::Program() {
  this->turn = 0;
  lands = LinkedList();
}

void Program::assemblyLand() {

  for (int i = 0; i < 4; i++) {
    lands.add(new Land("Grass", "Images/tiles/Grass.png", 0, 0));
    lands.add(new Land("Forest", "Images/tiles/Forest.png", 0, 0));
    if (i < 3) {
      lands.add(new Land("Brick", "Images/tiles/Brick.png", 0, 0));
      lands.add(new Land("Mountain", "Images/tiles/Mountain.png", 0, 0));
      lands.add(new Land("Field", "Images/tiles/Field.png", 0, 0));
    }
  }
  lands.add(new Land("Dessert", "Images/tiles/Dessert.png", 0, 0));
  lands.add(new Land("Brick", "Images/tiles/Brick.png", 0, 0));
  lands.to_string();
  lands.printImage();
}

void Program::loadStacks() {}

void Program::makeMaterialCard() {
  ////for (int i = 0; i < 19; i++) {
  // woodCard->push(new Card("Material", "Wood",
  // "images/resources_cards/wood_card.png")); woolCard->push(new
  // Card("Material", "Wool", "images/resources_cards/sheep_card.png"));
  // cerealCard->push(new Card("Material", "Cereal",
  // "images/resources_cards/wheat_card.png")); clayCard->push(new
  // Card("Material", "Clay", "images/resources_cards/brick_card.jpeg"));
  // mineralCard->push(new Card("Material", "Mineral",
  // "images/resources_cards/stone_card.png"));
  ////}
  // woodCard->print();
}

void Program::makeDevelopCard() {
  /*int num = 1;
  for (int i = 0; i < 4; i++) {
          string num_str1(std::to_string(num));
          string fullUrlKnight = urlKnight + num_str1 + urlEnd;
          string fullUrlProgress = urlProgress + num_str1 + urlEnd;
          string fullUrlVictoryPoint = urlVictoryPoint + num_str1 + urlEnd;
          knightCards->push(new Card("Develop", "Knight", fullUrlKnight));
          victoryPointCard->push(new Card("Develop", "VictoryPoint",fullUrlVictoryPoint)); 
          if (i < 2) { 
          progressCard->push(new Card("Develop","Progress", fullUrlProgress));
          }
          num++;
  }*/
  /*	for (int i = 0; i < 4; i++) {
                  lands.add(new Land("Grass", "Images/tiles/Grass.png"));
                  lands.add(new Land("Forest", "Images/tiles/Forest.png"));
                  if (i < 3) {
                          lands.add(new Land("Brick",
  "Images/tiles/Brick.png")); lands.add(new Land("Mountain",
  "Images/tiles/Mountain.png")); lands.add(new Land("Field",
  "Images/tiles/Field.png"));
                  }
          }
  lands.add(new Land("Dessert", "Images/tiles/Dessert.png"));
  lands.to_string();*/
}