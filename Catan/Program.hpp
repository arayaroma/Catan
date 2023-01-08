#pragma once
#include "CImg.h"
#include "LinkedList.hpp"
#include "Stack.hpp"
#include "Card.hpp"
#include "Component.hpp"
#include "Land.hpp"
#include "Clay.hpp"
#include "Mineral.hpp"
#include "Wheat.hpp"
#include "Wood.hpp"
#include "Wool.hpp"

using namespace cimg_library;

extern std::string urlKnight;
extern std::string urlEnd;
extern std::string urlProgress;
extern std::string urlVictoryPoint;

class Program {
private:
  int turn;
  LinkedList lands;

  Stack *woodCards = new Stack();
  Stack *mineralCards = new Stack();
  Stack *clayCards = new Stack();
  Stack *wheatCards = new Stack();
  Stack *woolCards = new Stack();

  Stack *knightCards = new Stack();
  Stack *progressCards = new Stack();
  Stack *victoryPointCards = new Stack();

public:
  Program();
  void play();
  void build();

  void tradeMaterials();
  void assemblyLand();

  void makeMaterialCard();
  void makeDevelopCard();
  void playDevelopCard();

  void loadStacks();
};
