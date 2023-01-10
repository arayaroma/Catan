#include "DataStructures.hpp"
using namespace std;

DataStructures::DataStructures() { lands = LinkedList<Land>(); }

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
      lands.add(Land("Dessert", um_Paths.at("dessertPath"), 0, 0));
    if (i < 3) {
      lands.add(Land("Mountain", um_Paths.at("mountainPath"), 0, 0));
      lands.add(Land("Field", um_Paths.at("fieldPath"), 0, 0));
    }
    lands.add(Land("Grass", um_Paths.at("grassPath"), 0, 0));
    lands.add(Land("Forest", um_Paths.at("forestPath"), 0, 0));
    lands.add(Land("Brick", um_Paths.at("brickPath"), 0, 0));
  }
}

void DataStructures::loadStacks() {}

void DataStructures::makeSpecialCard() {
  specialCard[0] = new Progress("SpecialCard", um_Paths.at("biggestPath"));
  specialCard[1] = new Progress("SpecialCard", um_Paths.at("biggestArmyPath"));
}

void DataStructures::makeMaterialCard() {
  int i, numberOfCards = 19;
  for (i = 0; i < numberOfCards; i++) {
    woodCards->push(Wood());
    woolCards->push(Wool());
    wheatCards->push(Wheat());
    clayCards->push(Clay());
    mineralCards->push(Mineral());
  }
}

void DataStructures::makeDevelopCard() {
  std::string knightPath, progressPath, victoryPointsPath;
  int i, num = 1, numberOfCards = 4;
  for (i = 0; i < numberOfCards; i++) {
    std::string stringNumber(std::to_string(num));

    // Poner .png
    knightPath = um_Paths.at("knightPath") + stringNumber;
    progressPath = um_Paths.at("progressPath") + stringNumber;
    victoryPointsPath = um_Paths.at("victoryPointsPath") + stringNumber;

    if (i < 2)
      progressCards->push(Progress(progressPath));
    knightCards->push(Knight(knightPath));
    victoryPointCards->push(VictoryPoints(victoryPointsPath));

    num++;
  }
}
