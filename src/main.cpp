#include <iostream>
#include "include/CImg.h"
#include <string>

using namespace std;
using namespace cimg_library;

// Global Scope

CImg<unsigned char> image("C:/Users/DanyG/Desktop/repos/Catan/src/Catan.jpg");
CImgDisplay title_display(1080, 720, "Title Screen", 3, false, false);

int main() {

  while(!title_display.is_closed()){
    title_display.display(image);
  }
  return 0;
}