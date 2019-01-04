#include <iostream>
#include "Vampire.h"

using namespace std;

Vampire::~Vampire(){}
Vampire::Vampire(){
        maxHP = numeric_limits<int>::max();
	HP = 125;
        Attack = 25;
        Defense = 25;
	race = 'v';
}

int Vampire::strike(Dwarf &d, int def){
        HP -= 2 * lifeSteal;
        return PCStrike(getAttack(), def);
}

int Vampire::extraEffect(int damage, int defHP){
	if (damage == missedAttack) return damage;
	else { 
		HP += lifeSteal;
		return damage;
	}
}

bool Vampire::beStruckBy(Character &c){
	int damage = c.extraEffect(c.strike(*this, getDefense()), HP);
        if(damage == nonHostile) return false;
        else {
                bool result = defaultStruckBy(damage);
                ActionDisplay::setAttack(damage, string(1,c.getDisplay()));
                return result;
        }
}



