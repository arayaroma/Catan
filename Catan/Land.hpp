#pragma once
#include "Component.hpp"
#include <iostream>
#include "LinkedList.hpp"
#define TAM 3;
class Land : public Component {
private:
  double posx;
  double posy;
  int idLand;
public:
  Land();
 
  LinkedList<Vertex> towns;
  Land(std::string, std::string, double x, double y, int id);

  LinkedList<Vertex> getTwons() {
      return this->towns;
  }
  void setPosx(double x);
  double getPosx();

  void setPosy(double y);
  double getPosy();

  void setIdLand(int id);
  int getIdLand();

  void toString() override { std::cout << posx << " " << posy << " " << idLand << std::endl; }

  void getClassName() override {
    std::cout << typeid(this).name() << std::endl;
  }
  void printImage() override {}



};
