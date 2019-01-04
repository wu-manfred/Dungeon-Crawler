#include <iostream>
#include "WA.h"
using namespace std;

bool WA::known = false;

WA::WA(Character *pc, int xPos, int yPos):
Decorator{pc, xPos, yPos}{}

WA::~WA() {}

int WA::getAttack(){
	int potionWeaken = 5;
	return max(pc->getAttack() - potionWeaken, 0);
}

void WA::pickUp(Character *&pc){
	known = true;
	pc = new WA(pc, pc->getX(), pc->getY());
}

string WA::getName() const{
	if (known){
		return name;
	} else{
		return "unknown potion";
	}
}

void WA::newPos(int newX, int newY){
	pc->newPos(newX, newY);
	updatePC();
}

int WA::strike(Human &h, int def){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
	int output = pc->strike(h, def);
	pc->setAttack(originalAtt);
	updatePC();
	return output;
}

int WA::strike(Dwarf &w, int def){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
        int output = pc->strike(w, def);
	pc->setAttack(originalAtt);
        updatePC();
        return output;
}

int WA::strike(Elf &e, int def){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
        int output = pc->strike(e, def);
	pc->setAttack(originalAtt);
        updatePC();
        return output;
}

int WA::strike(Orc &o, int def){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
        int output = pc->strike(o, def);
	pc->setAttack(originalAtt);
        updatePC();
        return output;
}

int WA::strike(Merchant &m, int def){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
        int output = pc->strike(m, def);
	pc->setAttack(originalAtt);
        updatePC();
        return output;
}

int WA::strike(Dragon &d, int def){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
        int output = pc->strike(d, def);
	pc->setAttack(originalAtt);
        updatePC();
        return output;
}

int WA::strike(Halfling &l, int def){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
        int output = pc->strike(l, def);
	pc->setAttack(originalAtt);
        updatePC();
        return output;
}

int WA::extraEffect(int damage, int defHP){
	int output = pc->extraEffect(damage, defHP);
	updatePC();
	return output;
}

bool WA::beStruckBy(Character &c){
	int originalAtt = pc->getAttack();
	pc->setAttack(getAttack());
	int output = pc->beStruckBy(c);
	pc->setAttack(originalAtt);
	updatePC();
	return output;
}
