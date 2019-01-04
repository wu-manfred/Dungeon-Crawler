#include <iostream>
#include "BD.h"
using namespace std;

bool BD::known = false;

BD::BD(Character *pc, int xPos, int yPos):
Decorator{pc, xPos, yPos}{}

BD::~BD() {}

int BD::getDefense(){
	int potionBoost = 5;
	return pc->getDefense() + potionBoost;
}

void BD::pickUp(Character *&pc){
	known = true;
	pc = new BD(pc, pc->getX(), pc->getY());
}

string BD::getName() const{
	if (known){
		return name;
	} else{
		return "unknown potion";
	}
}

void BD::newPos(int newX, int newY){
	pc->newPos(newX, newY);
	updatePC();
}

int BD::strike(Human &h, int def){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
	int output = pc->strike(h, def);
	pc->setDefense(originalDef);
	updatePC();
	return output;
}

int BD::strike(Dwarf &w, int def){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
        int output = pc->strike(w, def);
	pc->setDefense(originalDef);
        updatePC();
        return output;
}

int BD::strike(Elf &e, int def){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
        int output = pc->strike(e, def);
	pc->setDefense(originalDef);
        updatePC();
        return output;
}

int BD::strike(Orc &o, int def){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
        int output = pc->strike(o, def);
	pc->setDefense(originalDef);
        updatePC();
        return output;
}

int BD::strike(Merchant &m, int def){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
        int output = pc->strike(m, def);
	pc->setDefense(originalDef);
        updatePC();
        return output;
}

int BD::strike(Dragon &d, int def){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
        int output = pc->strike(d, def);
	pc->setDefense(originalDef);
        updatePC();
        return output;
}

int BD::strike(Halfling &l, int def){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
        int output = pc->strike(l, def);
	pc->setDefense(originalDef);
        updatePC();
        return output;
}

int BD::extraEffect(int damage, int defHP){
	int output = pc->extraEffect(damage, defHP);
	updatePC();
	return output;
}

bool BD::beStruckBy(Character &c){
	int originalDef = pc->getDefense();
	pc->setDefense(getDefense());
	int output = pc->beStruckBy(c);
	pc->setDefense(originalDef);
	updatePC();
	return output;
}
