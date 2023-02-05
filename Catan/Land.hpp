#pragma once
#include "Component.hpp"
#include "StructureGraph.hpp"
#include <list>
#include <vector>

#define TAM 3;

using std::list;
using std::string;
class Land : public Component {
private:
  int landId, diceNumber;
  double posX, posY;
  string typeland;

public:
  list<Vertex *> *townsList;

public:
  Land();

  Land(string, string, double, double, int);

  list<Vertex *> *getTownsList() const { return this->townsList; }

  void setLandId(int);
  int getLandId() const;

  void setDiceNumber(int);
  int getDiceNumber() const;

  void setPosX(double);
  double getPosX() const;

  void setPosY(double);
  double getPosY() const;

  string getTypeLand() { return this->typeland; }
  string getType() const override { return LAND; }
  string getImagePath() override { return this->imagePath; }
  void toString() override {
    std::cout << "posX: " << posX << "\n"
              << "posY: " << posY << "\n " << landId << std::endl;
  }
};
