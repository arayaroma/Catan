#pragma once
#include "Game.hpp"
#include <fstream>
using std::fstream;

class FileHandler {
private:
  fstream file;
  Game match;

public:
  void saveFile();
  void loadFile();
  FileHandler();
};
