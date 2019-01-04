#include <iostream>
#include "WD.h"
using namespace std;

bool WD::known = false;

WD::WD(Character *pc, int xPos, int yPos):
Decorator{pc, xPos, yPos}{}

WD::~WD() {}

int WD::getDefense(){
	int potionWeaken = 5;
	return max(pc->getDefense() - potionWeaken, 0);
}

void WD::pickUp(Character *&pc){
	known = true;
	pc = new WD(pc, pc->getX(), pc->getY());
}

string WD::getName() const{
	if (known){
		return name;
	} else{
		return "unknown potion";
	}
}

void WD::newPos(int newX, int newY){
	pc->newPos(newX, newY);
	updatePC();
}

int WD::strike(Human &h, int def){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
	int output = pc->strike(h, def);
	pc->setDefense(originalDef);
	updatePC();
	return output;
}

int WD::strike(Dwarf &w, int def){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
        int output = pc->strike(w, def);
	pc->setDefense(originalDef);
        updatePC();
        return output;
}

int WD::strike(Elf &e, int def){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
        int output = pc->strike(e, def);
	pc->setDefense(originalDef);
        updatePC();
        return output;
}

int WD::strike(Orc &o, int def){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
        int output = pc->strike(o, def);
	pc->setDefense(originalDef);
        updatePC();
        return output;
}

int WD::strike(Merchant &m, int def){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
        int output = pc->strike(m, def);
	pc->setDefense(originalDef);
        updatePC();
        return output;
}

int WD::strike(Dragon &d, int def){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
        int output = pc->strike(d, def);
	pc->setDefense(originalDef);
        updatePC();
        return output;
}

int WD::strike(Halfling &l, int def){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
        int output = pc->strike(l, def);
	pc->setDefense(originalDef);
        updatePC();
        return output;
}

int WD::extraEffect(int damage, int defHP){
	int output = pc->extraEffect(damage, defHP);
	updatePC();
	return output;
}

bool WD::beStruckBy(Character &c){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
	int output = pc->beStruckBy(c);
	pc->setDefense(originalDef);
	updatePC();
	return output;
}
