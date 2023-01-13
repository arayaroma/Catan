#pragma once
#include "CImg.h"
#include "Window.hpp"
using namespace cimg_library;

extern CImgDisplay mainDisplay;

class FlowController {
public:
  FlowController(const FlowController &) = delete;

  static FlowController &getInstance() {
    static FlowController instance;
    return instance;
  }

  void initializeFlow();
  void constantFlow();

  void goView(CImg<unsigned char> &);
  void close();

public:
  CImgDisplay &currentDisplay = mainDisplay;
  CImg<unsigned char> currentImage;
  bool isMainDisplay = true;

private:
  FlowController() {}
};
