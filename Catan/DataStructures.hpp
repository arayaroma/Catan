#pragma once
#include "Card.hpp"
#include "Land.hpp"
#include "LinkedList.hpp"
#include "Materials.hpp"
#include "ProgressCards.hpp"
#include "Stack.hpp"
#include <unordered_map>

class DataStructures {
public:
  std::unordered_map<const char *, const char *> um_Paths;
  LinkedList<Land> lands;

  Stack<Clay> *clayCards = new Stack<Clay>();
  Stack<Mineral> *mineralCards = new Stack<Mineral>();
  Stack<Wheat> *wheatCards = new Stack<Wheat>();
  Stack<Wood> *woodCards = new Stack<Wood>();
  Stack<Wool> *woolCards = new Stack<Wool>();
  Stack<Knight> *knightCards = new Stack<Knight>();
  Stack<Progress> *progressCards = new Stack<Progress>();
  Stack<VictoryPoints> *victoryPointCards = new Stack<VictoryPoints>();

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
