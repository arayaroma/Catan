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
  void saveFile(const string fileName, Game &obj);
  void savePlayersList(std::ofstream& file,std::list<Player*>&);
  void savetownsList(std::ofstream& file, std::list<Town*>&);
  void saveCitiesList(std::ofstream& file, std::list<City*>&);
  void saveRoadsList(std::ofstream& file, std::list<Road*>&);
  void saveLandsList(std::ofstream& file, std::list<Land*>&);
  void saveKnightCards(std::ofstream& file, std::list<Knight*>&);
  void saveProgressCards(std::ofstream& file, std::list<Progress*>&);
  void saveVictoryPointsCards(std::ofstream& file, std::list<VictoryPoints*>&);
  void saveClayCards(std::ofstream& file, std::stack<Clay*>&);
  void saveMineralCards(std::ofstream& file, std::stack<Mineral*>&);
  void saveWheatCards(std::ofstream& file, std::stack<Wheat*>&);
  void saveWoodCards(std::ofstream& file, std::stack<Wood*>&);
  void saveWoolCards(std::ofstream& file, std::stack<Wool*>&);

  void loadFile(const string fileName, Game& obj);
  void loadPlayersList(std::ifstream& file, std::list<Player*>&);
  void loadtownsList(std::ifstream& file, std::list<Town*>&);
  void loadCitiesList(std::ifstream& file, std::list<City*>&);
  void loadRoadsList(std::ifstream& file, std::list<Road*>&);
  void loadLandsList(std::ifstream& file, std::list<Land*>&);
  void loadKnightCards(std::ifstream& file, std::list<Knight*>&);
  void loadProgressCards(std::ifstream& file, std::list<Progress*>&);
  void loadVictoryPointsCards(std::ifstream& file, std::list<VictoryPoints*>&);
  void loadClayCards(std::ifstream& file, std::stack<Clay*>&);
  void loadMineralCards(std::ifstream& file, std::stack<Mineral*>&);
  void loadWheatCards(std::ifstream& file, std::stack<Wheat*>&);
  void loadWoodCards(std::ifstream& file, std::stack<Wood*>&);
  void loadWoolCards(std::ifstream& file, std::stack<Wool*>&);
};
