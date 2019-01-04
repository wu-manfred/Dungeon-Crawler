#include <iostream>
#include "BA.h"
using namespace std;

bool BA::known = false;

BA::BA(Character *pc, int xPos, int yPos):
Decorator{pc, xPos, yPos}{}

BA::~BA() {}

int BA::getAttack(){
	int potionBoost = 5;
	return pc->getAttack() + potionBoost;
}

void BA::pickUp(Character *&pc){
	known = true;
	pc = new BA(pc, pc->getX(), pc->getY());
}

string BA::getName() const{
	if (known){
		return name;
	} else{
		return "unknown potion";
	}
}

void BA::newPos(int newX, int newY){
	pc->newPos(newX, newY);
	updatePC();
}

int BA::strike(Human &h, int def){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
	int output = pc->strike(h, def);
	pc->setAttack(originalAtt);
	updatePC();
	return output;
}

int BA::strike(Dwarf &w, int def){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
        int output = pc->strike(w, def);
	pc->setAttack(originalAtt);
        updatePC();
        return output;
}

int BA::strike(Elf &e, int def){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
        int output = pc->strike(e, def);
	pc->setAttack(originalAtt);
        updatePC();
        return output;
}

int BA::strike(Orc &o, int def){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
        int output = pc->strike(o, def);
	pc->setAttack(originalAtt);
        updatePC();
        return output;
}

int BA::strike(Merchant &m, int def){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
        int output = pc->strike(m, def);
	pc->setAttack(originalAtt);
        updatePC();
        return output;
}

int BA::strike(Dragon &d, int def){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
        int output = pc->strike(d, def);
	pc->setAttack(originalAtt);
        updatePC();
        return output;
}

int BA::strike(Halfling &l, int def){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
        int output = pc->strike(l, def);
	pc->setAttack(originalAtt);
        updatePC();
        return output;
}

int BA::extraEffect(int damage, int defHP){
	int output = pc->extraEffect(damage, defHP);
	updatePC();
	return output;
}

bool BA::beStruckBy(Character &c){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
	int output = pc->beStruckBy(c);
	pc->setAttack(originalAtt);
	updatePC();
	return output;
}




