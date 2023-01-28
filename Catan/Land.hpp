#pragma once
#include "Component.hpp"
#include "StructureGraph.hpp"
#include <list>
#include <vector>

#define TAM 3;

using std::list;
using std::vector;
class Land : public Component {
private:
  int landId;
  double posX;
  double posY;
public:
  list<Vertex *>* townsList;

public:
  Land();
 
  Land( std::string, double x, double y, int id);

  list<Vertex *>* getTownsList() const { return this->townsList; }

  void setPosX(double);
  double getPosX() const;

  void setPosY(double);
  double getPosY() const;

  void setLandId(int);
  int getLandId() const;

  string getType() const override { return LAND; }
  string getImagePath() override { return this->imagePath; }
  void toString() override {
    std::cout << "posX: " << posX << "\n"
              << "posY: " << posY << "\n " << landId << std::endl;
  }

  
};
