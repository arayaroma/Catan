#include "DataStructures.hpp"
using namespace std;

DataStructures::DataStructures() { lands = LinkedList(); }

void DataStructures::loadMaps() {
  loadProgressPaths();
  loadTilesPaths();
}

void DataStructures::loadSpecialCards() {
  um_Paths.insert(pair<const char *, const char *>(
      "biggestPath", "Images/extraCards/biggestPathCard.png"));
  um_Paths.insert(pair<const char *, const char *>(
      "biggestArmyPath", "Images/extraCards/biggestArmyCard.png"));
}
void DataStructures::loadProgressPaths() {
  um_Paths.insert(pair<const char *, const char *>(
      "knightPath", "Images/knightCards/knightCard"));

  um_Paths.insert(pair<const char *, const char *>(
      "progressPath", "Images/progressCards/progressCard"));

  um_Paths.insert(pair<const char *, const char *>(
      "victoryPointsPath", "Images/victoryPointsCards/victoryPointCard"));
}

void DataStructures::loadTilesPaths() {
  um_Paths.insert(
      pair<const char *, const char *>("grassPath", "Images/tiles/Grass.png"));
  um_Paths.insert(
      pair<const char *, const char *>("brickPath", "Images/tiles/Brick.png"));
  um_Paths.insert(
      pair<const char *, const char *>("fieldPath", "Images/tiles/Field.png"));

  um_Paths.insert(pair<const char *, const char *>(
      "mountainPath", "Images/tiles/Mountain.png"));
  um_Paths.insert(pair<const char *, const char *>("forestPath",
                                                   "Images/tiles/Forest.png"));
  um_Paths.insert(pair<const char *, const char *>("dessertPath",
                                                   "Images/tiles/Dessert.png"));
}

void DataStructures::loadLands() {
  loadTilesPaths();
  int i;
  for (i = 0; i < 4; i++) {
    if (i < 1)
      lands.add(new Land("Dessert", um_Paths.at("dessertPath"), 0, 0));
    if (i < 3) {
      lands.add(new Land("Mountain", um_Paths.at("mountainPath"), 0, 0));
      lands.add(new Land("Field", um_Paths.at("fieldPath"), 0, 0));
    }
    lands.add(new Land("Grass", um_Paths.at("grassPath"), 0, 0));
    lands.add(new Land("Forest", um_Paths.at("forestPath"), 0, 0));
    lands.add(new Land("Brick", um_Paths.at("brickPath"), 0, 0));
  }
}

void DataStructures::loadStacks() {}

void DataStructures::makeConstructionCostsCard() {
  constructionCosts =
      new Card("ConstructionCosts", "Images/extraCards/pricingTable.png");
}

void DataStructures::makeSpecialCard() {
  specialCard[0] = new Card("SpecialCard", um_Paths.at("biggestPath"));
  specialCard[1] = new Card("SpecialCard", um_Paths.at("biggestArmyPath"));
}

void DataStructures::makeMaterialCard() {
  int i, numberOfCards = 19;
  for (i = 0; i < numberOfCards; i++) {
    woodCards->push(new Wood());
    woolCards->push(new Wool());
    wheatCards->push(new Wheat());
    clayCards->push(new Clay());
    mineralCards->push(new Mineral());
  }
}

void DataStructures::makeDevelopCard() {
  std::string knightPath, progressPath, victoryPointsPath;
  int i, num = 1, numberOfCards = 4;
  for (i = 0; i < numberOfCards; i++) {
    std::string stringNumber(std::to_string(num));

    knightPath = um_Paths.at("knightPath") + stringNumber;
    progressPath = um_Paths.at("progressPath") + stringNumber;
    victoryPointsPath = um_Paths.at("victoryPointsPath") + stringNumber;

    if (i < 2)
      progressCards->push(new Progress(progressPath));
    knightCards->push(new Knight(knightPath));
    victoryPointCards->push(new VictoryPoints(victoryPointsPath));

    num++;
  }
}
