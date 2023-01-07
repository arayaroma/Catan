#include "CImg.h"
#include "Label.hpp"
#include "Program.hpp"
#include "Window.hpp"
#include <iostream>
#include <string>

using namespace cimg_library;
using namespace std;

int main() {
  Program program;
  program.assemblyLand();

  Window window;
  window.loadImages();
  window.printTitleScreenLabels();
  window.showDisplay();

  return 0;
}