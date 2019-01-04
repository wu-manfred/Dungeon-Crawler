#include <iostream>
#include "Decorator.h"
using namespace std;

Decorator::Decorator(Character *pc, int xPos, int yPos):
pc{pc}, Character() {
	x = xPos;
	y = yPos;
	Attack = pc->getAttack();
	Defense = pc->getDefense();
	HP = pc->getHP();	
	race = pc->getRace();
	gold = pc->getGold();
}

Decorator::~Decorator(){
	delete pc;
}

void Decorator::updatePC(){
	x = pc->getX();
	y = pc->getY();
	HP = pc->getHP();
	Attack = pc->getAttack();
	Defense = pc->getDefense();
	race = pc->getRace();
}

Character * Decorator::removeDec(){
	return pc->removeDec();
}
