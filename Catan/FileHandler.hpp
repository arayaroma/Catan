#pragma once
#include "Game.hpp"
#include <exception>
#include <fstream>
#include <string>

#define log(x) std::cout << x << std::endl;

using std::fstream;
using std::string;

class FileHandler {
public:
  void saveFile(const string &, Game &);
  void loadFile(const string &, Game &);
  FileHandler();
};
