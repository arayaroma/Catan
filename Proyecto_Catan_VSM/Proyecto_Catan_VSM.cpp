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

  // MOVER TODO EN UNA CLASE -> METODO
  // SE HACE ILEGIBLE EL MAIN

 /*
   int Qry1 = 325;
int Qry2 = 350;
int Qry3 = 375;

for (int i = 0; i < 3; i++) {
image.draw_line(575, Qry1, 545, Qry1, BLACK, 1);
image.draw_line(575, Qry3, 545, Qry3, BLACK, 1);
image.draw_line(545, Qry3, 530, Qry2, BLACK, 1);
image.draw_line(530, Qry2, 545, Qry1, BLACK, 1);
image.draw_line(575, Qry1, 590, Qry2, BLACK, 1);
image.draw_line(575, Qry3, 590, Qry2, BLACK, 1);

Qry1 = Qry1 + 50;
Qry2 = Qry2 + 50;
Qry3 = Qry3 + 50;
}
// Segunda fila de hexagonos
int rmy1 = 300;
int rmy2 = 325;
int rmy3 = 350;
for (int i = 0; i < 4; i++) {
image.draw_line(620, rmy1, 590, rmy1, BLACK, 1);
image.draw_line(620, rmy3, 590, rmy3, BLACK, 1);
image.draw_line(635, rmy2, 620, rmy3, BLACK, 1);
image.draw_line(590, rmy3, 575, rmy2, BLACK, 1);
image.draw_line(575, rmy2, 590, rmy1, BLACK, 1);
image.draw_line(620, rmy1, 635, rmy2, BLACK, 1);

rmy1 = rmy1 + 50;
rmy2 = rmy2 + 50;
rmy3 = rmy3 + 50;
}
int y1 = 275;
int y2 = 300;
int y3 = 325;

for (int i = 0; i < 5; i++) {
image.draw_line(635, y1, 665, y1, BLACK, 1); // techo lad 1
image.draw_line(665, y1, 680, y2, BLACK, 1); // lado der arr
image.draw_line(680, y2, 665, y3, BLACK, 1); // lado der abaj
image.draw_line(635, y3, 665, y3, BLACK, 1); // piso
image.draw_line(635, y3, 620, y2, BLACK, 1); // lado isq aba
image.draw_line(635, y1, 620, y2, BLACK, 1); // lado isq arri

y1 = y1 + 50;
y2 = y2 + 50;
y3 = y3 + 50;
}
int py1 = 300;
int py2 = 325;
int py3 = 350;
for (int i = 0; i < 4; i++) {
image.draw_line(680, py1, 665, py2, BLACK, 1); // lado isq arr
image.draw_line(665, py2, 680, py3, BLACK, 1); // lado isq abaj
image.draw_line(680, py1, 710, py1, BLACK, 1); // techo
image.draw_line(710, py1, 725, py2, BLACK, 1); // der arri
image.draw_line(725, py2, 710, py3, BLACK, 1); // der abajo
image.draw_line(710, py3, 680, py3, BLACK, 1); // piso

py1 = py1 + 50;
py2 = py2 + 50;
py3 = py3 + 50;
}
// tercera fila de hexagonos
int ysl1 = 325;
int ysl2 = 350;
int ysl3 = 375;
for (int i = 0; i < 3; i++) {
image.draw_line(725, ysl1, 710, ysl2, BLACK, 1); // der arriba
image.draw_line(710, ysl2, 725, ysl3, BLACK, 1); // der abajo
image.draw_line(725, ysl1, 755, ysl1, BLACK, 1); // techo
image.draw_line(755, ysl1, 770, ysl2, BLACK, 1); // isq arri
image.draw_line(770, ysl2, 755, ysl3, BLACK, 1); // isq abaj
image.draw_line(755, ysl3, 725, ysl3, BLACK, 1); // piso

ysl1 = ysl1 + 50;
ysl2 = ysl2 + 50;
ysl3 = ysl3 + 50;
}
  */

  return 0;
}