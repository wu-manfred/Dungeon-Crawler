#include <iostream>
#include "PH.h"
using namespace std;

bool PH::known = false;

PH::PH(int xPos, int yPos):
xPos{xPos}, yPos{yPos} {}

PH::~PH() {}

void PH::pickUp(Character *&pc){
	known = true;
	int newHP = pc->getHP() - rand() % 11;  
	pc->setHP(newHP);
}

string PH::getName() const{
	if (known){
		return name;
	} else{
		return "unknown potion";
	}
}
