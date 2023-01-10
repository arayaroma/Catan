#include "DataStructures.hpp"
using namespace std;
std::string urlKnight = "images/knight_cards/knight_";
std::string urlEnd = "_card.png";
std::string urlProgress = "images/develop_cards/develop_";
std::string urlVictoryPoint = "Images/victory_points_cards/victory_point_";

DataStructures::DataStructures() {
  this->turn = 0;
  lands = LinkedList();
  townFigures = LinkedList();
  cityFigures = LinkedList();
  roadFigures = LinkedList();
}

void DataStructures::assemblyLand() {

  for (int i = 0; i < 4; i++) {
    lands.add(new Land("Grass", "Images/tiles/Grass.png", 0, 0));
    lands.add(new Land("Forest", "Images/tiles/Forest.png", 0, 0));
    lands.add(new Land("Brick", "Images/tiles/Brick.png", 0, 0));
    if (i < 3) {
      lands.add(new Land("Mountain", "Images/tiles/Mountain.png", 0, 0));
      lands.add(new Land("Field", "Images/tiles/Field.png", 0, 0));
    }
  }
  lands.add(new Land("Dessert", "Images/tiles/Dessert.png", 0, 0));
  lands.printImage();
  lands.toString();
}

void DataStructures::loadStacks() {}

void DataStructures::makeMaterialCard() {
        for (int i = 0; i < 19; i++) {
            woodCards->push(new Wood());
            woolCards->push(new Wool());
            wheatCards->push(new Wheat());
            clayCards->push(new Clay());
            mineralCards->push(new Mineral());
        }
        woodCards->print();
}

void DataStructures::makeDevelopCard() {
  int num = 1;
  for (int i = 0; i < 4; i++) {
          string num_str1(std::to_string(num));
          string fullUrlKnight = urlKnight + num_str1 + urlEnd;
          string fullUrlProgress = urlProgress + num_str1 + urlEnd;
          string fullUrlVictoryPoint = urlVictoryPoint + num_str1 + urlEnd;
          knightCards->push(new Knight( fullUrlKnight));
          victoryPointCards->push(new VictoryPoints( fullUrlVictoryPoint));
          if (i < 2) { 
              progressCards->push(new Progress( fullUrlProgress));
          }
          num++;
  }
}
void DataStructures::makeConstructionCostsCard() {
    for (int i = 0; i < 4;i++) {
        constructionCosts[i] =  Card("ConstructionCosts", "Images/extraCards/pricingTable.png");
    }
}
void DataStructures::makeSpecialCard() {
   specialCard[0] =  Card("SpecialCard", "Images/extraCards/biggestPathCard.png");
   specialCard[1] = Card("SpecialCard", "Images/extraCards/biggestArmyCard.png");
}

void DataStructures::makeFigures() {
    int i = 0;
    for (i = 0; i < 60; i++) {
        roadFigures.add(new Road("Road", "12",0,0));
        if (i < 20) {
            townFigures.add(new Town("Town", "Images/puebloX.png", 0, 0));
        }
        if (i < 16) {
            cityFigures.add(new City("City", "12", 0, 0));
        }
    }
    townFigures.printTown();
}
