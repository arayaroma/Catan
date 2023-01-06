#pragma once
#include "CImg.h"
#include "Label.hpp"
#include "Land.hpp"
#include "LinkedList.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>
using namespace cimg_library;

class Program {
private:
  int turn;
  LinkedList lands;
  Stack cards;

public:
  Program();
  void play();
  void build();
  void tradeMaterials();
  void assemblyLand();
  void playDevelopCard();

};
