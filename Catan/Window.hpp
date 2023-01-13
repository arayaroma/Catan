#pragma once
#include "Button.hpp"
#include "CImg.h"
#include "DataStructures.hpp"
#include "FlowController.hpp"
#include "Label.hpp"
#include "Land.hpp"
#include "LinkedList.hpp"
#include <iostream>

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
extern Label *princingTable;
extern Label *materialCard;
extern Label *developCard;
extern const char *const img;

class Window {

public:
  Window(const Window &) = delete;

  static Window &getInstance() {
    static Window instance;
    return instance;
  }

  bool isLeftClicked(CImgDisplay &);

  // Re hacer codigo -> se vuelve repetitivo
  bool isBackClicked();

  bool isPlayClicked();
  void goPlayView();
  void loadPlayDisplay();

  bool isAboutClicked();
  void goAboutView();
  void loadAboutDisplay();

  void goBackTitle();

  void printTowns();
  void printTown(std::string, int x, int y);
  void printHexagon(std::string, int x, int y);
  void printMaterialCard();
  void printBoard();

  void Image(std::string);
  void mouseFunction();

  bool clickAboutLabel(double, double, Label *);
  bool clickLabel(double, double);

private:
  Window() {}
};
