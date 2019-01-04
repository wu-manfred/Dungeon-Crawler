#include <iostream>
#include "Halfling.h"

using namespace std;
Halfling::~Halfling(){}

Halfling::Halfling(){
        display = 'L';
        HP = 100;
        Attack = 15;
        Defense = 20;
}

bool Halfling::beStruckBy(Character &c){
	int hitChance = rand() % 2;
	int damage = c.extraEffect(c.strike(*this, Defense), HP);
	if (hitChance == missedAttack){
		damage =  missedAttack;
	}
        bool result = defaultStruckBy(damage);
        ActionDisplay::setAttack(damage, string(1,c.getDisplay()));
	return result;
}



char Halfling::getDisplay() const {return display;}

