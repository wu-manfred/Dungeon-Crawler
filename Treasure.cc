#include <iostream>
#include "Treasure.h"
using namespace std;

Treasure::Treasure(int xPos, int yPos, int value):
xPos{xPos}, yPos{yPos}, value{value} {}

void Treasure::pickUp(Character *&pc){
	cout << "PC's gold before: " << pc->getGold() << endl;
	pc->setGold(pc->getGold() + value);
	cout << "PC's gold after: " << pc->getGold() << endl;
}

string Treasure::getName() const{
	return name;
}

char Treasure::getDisplay() const{
	return display;
}

Treasure::~Treasure() {}
