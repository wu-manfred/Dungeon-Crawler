#include <iostream>
#include "Troll.h"

using namespace std;

Troll::~Troll(){}
Troll::Troll(){
	maxHP = 120;
        HP = 120;
        Attack = 25;
        Defense = 15;
	race = 't';
}
//Regen on attack ???

void Troll::newPos(int newX, int newY){
	x = newX;
	y = newY;
	HP += regen;
	if (HP >= maxHP){HP = maxHP;}
}

bool Troll::beStruckBy(Character &c){
	int damage = c.extraEffect(c.strike(*this, getDefense()), HP);
        if(damage == nonHostile) return false;
        else {
                bool result = defaultStruckBy(damage);
                ActionDisplay::setAttack(damage, string(1,c.getDisplay()));
                return result;
        }
}


int Troll::extraEffect(int damage, int defHP){
	HP += regen;
	if (HP >= maxHP){HP = maxHP;}
	return damage;
}

