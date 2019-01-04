#include <iostream>
#include "Dragon.h"
#include "ActionDisplay.h"

using namespace std;
Dragon::~Dragon(){}

Dragon::Dragon(){
        display = 'D';
        HP = 150;
        Attack = 20;
        Defense = 20;
}

bool Dragon::beStruckBy(Character &c){
        int damage = c.extraEffect(c.strike(*this, Defense), HP);
        bool result= defaultStruckBy(damage);
        ActionDisplay::setAttack(damage, string(1,c.getDisplay()));
        return result;
}



char Dragon::getDisplay() const {return display;}

