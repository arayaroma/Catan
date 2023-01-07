#include "CImg.h"
#include "Label.hpp"
#include "Program.hpp"
#include "Window.hpp"
#include <iostream>
#include <string>

using namespace cimg_library;
using namespace std;

// hexaImage prueba
const char *const direcction = "images/tiles/Brick.png";
CImg<unsigned char> hexa(direcction);

int main() {
  Program program;
  program.assemblyLand();

  Window window;
  window.printTitleScreenLabels();
  window.showDisplay();





  return 0;
}