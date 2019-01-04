#include <iostream>
#include "RH.h"
using namespace std;

bool RH::known = false;

RH::RH(int xPos, int yPos):
xPos{xPos}, yPos{yPos} {}

RH::~RH() {}

void RH::pickUp(Character *&pc){
	known = true;
	srand(time(NULL));
	int newHP = pc->getHP() + rand() % 11;  
	pc->setHP(newHP);
}

string RH::getName() const{
	if (known){
		return name;
	} else{
		return "unknown potion";
	}
}
