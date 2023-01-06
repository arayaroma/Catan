#pragma once
#include "CImg.h"
#include "Label.hpp"
#include "Land.hpp"
#include "LinkedList.hpp"
#include "Stack.hpp"
#include <iostream>
#include <string>
using namespace cimg_library;

extern const unsigned char WHITE[3];
extern const unsigned char BLACK[3];
extern const int transparent;
extern const float opacity;

extern const char *catan_window_title;
extern const char *const image_path;
extern unsigned int catan_title_display_width, catan_title_display_height;

extern Label *catan;
extern Label *playLabel;
extern Label *about;

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

  void printTitleScreenLabels();
  void showDisplay();
};
