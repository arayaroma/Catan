#include "FileHandler.hpp"

FileHandler::FileHandler() {}

void FileHandler::saveFile(const string fileName, Game &obj) {
  try {
    std::ofstream file(fileName, std::ios::binary);
    if (file.is_open()) {
      savePlayersList(file, *obj.getPlayersList());
      savetownsList(file, *obj.getTownsList());
      saveCitiesList(file, *obj.getCitiesList());
      saveRoadsList(file, *obj.getRoadsList());
      saveLandsList(file, *obj.getLandsList());
      saveKnightCards(file, *obj.getKnightCards());
      saveProgressCards(file, *obj.getProgressCards());
      saveVictoryPointsCards(file, *obj.getVictoryPointsCards());
      saveClayCards(file, *obj.getClayCards());
      saveMineralCards(file, *obj.getMineralCards());
      saveWheatCards(file, *obj.getWheatCards());
      saveWoodCards(file, *obj.getWoodCards());
      saveWoolCards(file, *obj.getWoolCards());
      file.close();
    } else {
      throw std::runtime_error("Unable to open file: " + fileName);
    }

  } catch (const std::exception &e) {
    log("Error: " << e.what());
  }
}

void FileHandler::savePlayersList(std::ofstream &file,
                                  std::list<Player *> &players) {
  std::size_t size = players.size();
  file.write(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<Player *>::iterator itX = players.begin();
       itX != players.end(); itX++) {
    file.write(reinterpret_cast<char *>(&(*itX)), sizeof((*itX)));
  }
}

void FileHandler::savetownsList(std::ofstream &file, std::list<Town *> &towns) {
  std::size_t size = towns.size();
  file.write(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<Town *>::iterator itX = towns.begin(); itX != towns.end();
       itX++) {
    file.write(reinterpret_cast<char *>(&(*itX)), sizeof((*itX)));
  }
}

void FileHandler::saveCitiesList(std::ofstream &file,
                                 std::list<City *> &cities) {
  std::size_t size = cities.size();
  file.write(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<City *>::iterator itX = cities.begin(); itX != cities.end();
       itX++) {
    file.write(reinterpret_cast<char *>(&(*itX)), sizeof((*itX)));
  }
}

void FileHandler::saveRoadsList(std::ofstream &file, std::list<Road *> &roads) {
  std::size_t size = roads.size();
  file.write(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<Road *>::iterator itX = roads.begin(); itX != roads.end();
       itX++) {
    file.write(reinterpret_cast<char *>(&(*itX)), sizeof((*itX)));
  }
}

void FileHandler::saveLandsList(std::ofstream &file, std::list<Land *> &lands) {
  std::size_t size = lands.size();
  file.write(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<Land *>::iterator itX = lands.begin(); itX != lands.end();
       itX++) {
    file.write(reinterpret_cast<char *>(&(*itX)), sizeof((*itX)));
  }
}

void FileHandler::saveKnightCards(std::ofstream &file,
                                  std::list<Knight *> &knights) {
  std::size_t size = knights.size();
  file.write(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<Knight *>::iterator itX = knights.begin();
       itX != knights.end(); itX++) {
    file.write(reinterpret_cast<char *>(&(*itX)), sizeof((*itX)));
  }
}

void FileHandler::saveProgressCards(std::ofstream &file,
                                    std::list<Progress *> &progress) {
  std::size_t size = progress.size();
  file.write(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<Progress *>::iterator itX = progress.begin();
       itX != progress.end(); itX++) {
    file.write(reinterpret_cast<char *>(&(*itX)), sizeof((*itX)));
  }
}

void FileHandler::saveVictoryPointsCards(
    std::ofstream &file, std::list<VictoryPoints *> &victoryPoints) {
  std::size_t size = victoryPoints.size();
  file.write(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<VictoryPoints *>::iterator itX = victoryPoints.begin();
       itX != victoryPoints.end(); itX++) {
    file.write(reinterpret_cast<char *>(&(*itX)),
               sizeof((*itX))); // ver si es tamano de lista
                                // o iterador
  }
}

void FileHandler::saveClayCards(std::ofstream &file,
                                std::stack<Clay *> &clays) {
  std::size_t size = clays.size();
  file.write(reinterpret_cast<char *>(&size), sizeof(size));
  while (!clays.empty()) {
    file.write(reinterpret_cast<char *>(&(clays.top())),
               sizeof((clays.size())));
    clays.pop();
  }
}

void FileHandler::saveMineralCards(std::ofstream &file,
                                   std::stack<Mineral *> &minerals) {
  std::size_t size = minerals.size();
  file.write(reinterpret_cast<char *>(&size), sizeof(size));
  while (!minerals.empty()) {
    file.write(reinterpret_cast<char *>(&(minerals.top())),
               sizeof((minerals.size())));
    minerals.pop();
  }
}

void FileHandler::saveWheatCards(std::ofstream &file,
                                 std::stack<Wheat *> &wheats) {
  std::size_t size = wheats.size();
  file.write(reinterpret_cast<char *>(&size), sizeof(size));
  while (!wheats.empty()) {
    file.write(reinterpret_cast<char *>(&(wheats.top())),
               sizeof((wheats.size())));
    wheats.pop();
  }
}

void FileHandler::saveWoodCards(std::ofstream &file,
                                std::stack<Wood *> &woods) {
  std::size_t size = woods.size();
  file.write(reinterpret_cast<char *>(&size), sizeof(size));
  while (!woods.empty()) {
    file.write(reinterpret_cast<char *>(&(woods.top())),
               sizeof((woods.size())));
    woods.pop();
  }
}

void FileHandler::saveWoolCards(std::ofstream &file,
                                std::stack<Wool *> &wools) {
  std::size_t size = wools.size();
  file.write(reinterpret_cast<char *>(&size), sizeof(size));
  while (!wools.empty()) {
    file.write(reinterpret_cast<char *>(&(wools.top())),
               sizeof((wools.size())));
    wools.pop();
  }
}

void FileHandler::loadPlayersList(std::ifstream &file,
                                  std::list<Player *> &players) {
  std::size_t size = players.size();
  file.read(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<Player *>::iterator itX = players.begin();
       itX != players.end(); itX++) {
    file.read(reinterpret_cast<char *>(&(*itX)), sizeof((*itX)));
    players.push_back((*itX));
  }
}

void FileHandler::loadtownsList(std::ifstream &file, std::list<Town *> &towns) {
  std::size_t size = towns.size();
  file.read(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<Town *>::iterator itX = towns.begin(); itX != towns.end();
       itX++) {
    file.read(reinterpret_cast<char *>(&(*itX)), sizeof((*itX)));
    towns.push_back((*itX));
  }
}

void FileHandler::loadCitiesList(std::ifstream &file,
                                 std::list<City *> &cities) {
  std::size_t size = cities.size();
  file.read(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<City *>::iterator itX = cities.begin(); itX != cities.end();
       itX++) {
    file.read(reinterpret_cast<char *>(&(*itX)), sizeof((*itX)));
    cities.push_back((*itX));
  }
}

void FileHandler::loadRoadsList(std::ifstream &file, std::list<Road *> &roads) {
  std::size_t size = roads.size();
  file.read(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<Road *>::iterator itX = roads.begin(); itX != roads.end();
       itX++) {
    file.read(reinterpret_cast<char *>(&(*itX)), sizeof((*itX)));
    roads.push_back((*itX));
  }
}

void FileHandler::loadLandsList(std::ifstream &file, std::list<Land *> &lands) {
  std::size_t size = lands.size();
  file.read(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<Land *>::iterator itX = lands.begin(); itX != lands.end();
       itX++) {
    file.read(reinterpret_cast<char *>(&(*itX)), sizeof((*itX)));
    lands.push_back((*itX));
  }
}

void FileHandler::loadKnightCards(std::ifstream &file,
                                  std::list<Knight *> &knights) {
  std::size_t size = knights.size();
  file.read(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<Knight *>::iterator itX = knights.begin();
       itX != knights.end(); itX++) {
    file.read(reinterpret_cast<char *>(&(*itX)), sizeof((*itX)));
    knights.push_back((*itX));
  }
}

void FileHandler::loadProgressCards(std::ifstream &file,
                                    std::list<Progress *> &progress) {
  std::size_t size = progress.size();
  file.read(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<Progress *>::iterator itX = progress.begin();
       itX != progress.end(); itX++) {
    file.read(reinterpret_cast<char *>(&(*itX)), sizeof((*itX)));
    progress.push_back((*itX));
  }
}

void FileHandler::loadVictoryPointsCards(
    std::ifstream &file, std::list<VictoryPoints *> &victoryPoints) {
  std::size_t size = victoryPoints.size();
  file.read(reinterpret_cast<char *>(&size), sizeof(size));
  for (std::list<VictoryPoints *>::iterator itX = victoryPoints.begin();
       itX != victoryPoints.end(); itX++) {
    file.read(reinterpret_cast<char *>(&(*itX)),
              sizeof((*itX))); // ver si es tamano de lista //o iterador
    victoryPoints.push_back((*itX));
  }
}