#include <iostream>
#include "Drow.h"

using namespace std;

Drow::~Drow(){}
Drow::Drow(){
        maxHP = 150;
        HP = 150;
        Attack = 25;
        Defense = 15;
	race = 'd';
}


bool Drow::beStruckBy(Character &c){
	int damage = c.extraEffect(c.strike(*this, getDefense()), HP);
        if(damage == nonHostile) return false;
        else {
                bool result = defaultStruckBy(damage);
                ActionDisplay::setAttack(damage, string(1,c.getDisplay()));
                return result;
        }
}

