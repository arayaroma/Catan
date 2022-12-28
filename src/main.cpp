#include <iostream>
#include "include/CImg.h"
using namespace cimg_library;

// Global Scope
CImg<unsigned char> image("C:/Users/User/Documents/UNA/VERANO/Proyecto_Catan/Catan/src/Catan.jpg");
CImgDisplay title_display(1080, 720, "Title Screen", 3, false, false);

int main() {
CImg<unsigned char> c9("C:/Users/User/Documents/UNA/VERANO/Proyecto_Catan/Catan/src/nueve.png");
   CImg<unsigned char> cas("C:/Users/User/Documents/UNA/VERANO/Proyecto_Catan/Catan/src/as.png");

   // Declare output and intermediate variables
   CImg<unsigned char> row0,row1,grid;

   // Append horizontally into a row, you could append many - you are not restricted to 2
   row0 = c9.append(cas,'x');
   
   // Append vertically into a column
   CImg<unsigned char> row;
   row = c9.append(cas,'x');
   

  while(!title_display.is_closed()){
    title_display.display(image);
    row.display();
  }
   
  return 0;
}