#pragma once
#include <iostream>

using namespace std; 

class Human
{


public: 

	Human(); 
	
	void setName(string); 
	string getName(); 

	void setColor(string); 
	string getColor(); 

	void play();

private: 

	string name; 
	string color; 
	int numTurn; 

};

