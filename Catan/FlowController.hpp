#pragma once
#include "CImg.h"
#include "Window.hpp"
using namespace cimg_library;

extern CImgDisplay titleDisplay;

class FlowController {
public:
  FlowController(const FlowController &) = delete;

  static FlowController &getInstance() {
    static FlowController instance;
    return instance;
  }

  void initializeFlow();
  void constantFlow();

  void goView(CImgDisplay &, CImg<unsigned char> &);
  void close();

public:
  CImgDisplay &currentDisplay = titleDisplay;

private:
  FlowController() {}
};
