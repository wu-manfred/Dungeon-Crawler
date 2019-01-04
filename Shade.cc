#include <iostream>
#include "Shade.h"

using namespace std;

Shade::~Shade(){}
Shade::Shade(){
	maxHP = 125;
	HP = 125;
	Attack = 25;
	Defense = 25;
	race = 's';
}


bool Shade::beStruckBy(Character &c){
	int damage = c.extraEffect(c.strike(*this, getDefense()), HP);
	if(damage == nonHostile) return false;
	else {
		bool result = defaultStruckBy(damage);
		ActionDisplay::setAttack(damage, string(1,c.getDisplay()));
		return result;
	}
}

