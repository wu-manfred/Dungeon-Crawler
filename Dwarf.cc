#include <iostream>
#include "Dwarf.h"

using namespace std;
Dwarf::~Dwarf(){}

Dwarf::Dwarf(){
        display = 'W';
        HP = 140;
        Attack = 20;
        Defense = 20;
}

bool Dwarf::beStruckBy(Character &c){
	int damage = c.extraEffect(c.strike(*this, Defense), HP);
        bool result= defaultStruckBy(damage);
        ActionDisplay::setAttack(damage, string(1,c.getDisplay()));
        return result;
}



char Dwarf::getDisplay() const {return display;}

