#pragma once
#include "Card.hpp"
#include "Land.hpp"
#include "LinkedList.hpp"
#include "Materials.hpp"
#include "ProgressCards.hpp"
#include "Stack.hpp"
#include <unordered_map>


class DataStructures {
private:
  LinkedList lands;
  std::unordered_map<const char *, const char *> um_Paths;

  Stack *woodCards = new Stack(), *mineralCards = new Stack(),
        *clayCards = new Stack(), *wheatCards = new Stack(),
        *woolCards = new Stack();

  Stack *knightCards = new Stack(), *progressCards = new Stack(),
        *victoryPointCards = new Stack();

  Card *constructionCosts;
  Card *specialCard[2];

public:
  DataStructures();

  void loadMaps();

  void loadSpecialCards();
  void loadProgressPaths();
  void loadTilesPaths();

  void loadStacks();

  void play();
  void build();

  void tradeMaterials();
  void loadLands();

  void makeMaterialCard();
  void makeDevelopCard();
  void playDevelopCard();

  void makeConstructionCostsCard();
  void makeSpecialCard();
};
