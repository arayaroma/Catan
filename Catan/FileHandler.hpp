#pragma once
#include "Game.hpp"
#include <exception>
#include <fstream>
#include <string>

#define log(x) std::cout << x << std::endl;

using std::string;

class FileHandler {
public:
  FileHandler();
  void savePlayersList(std::list<Player*>&);
};
