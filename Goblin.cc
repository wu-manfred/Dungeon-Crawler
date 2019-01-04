#include <iostream>
#include "Goblin.h"
#include "ActionDisplay.h"
using namespace std;

Goblin::~Goblin(){}
Goblin::Goblin(){
	maxHP = 110;
        HP = 110;
        Attack = 15;
        Defense = 20;
	race = 'g';
}
	
int Goblin::extraEffect(int damage, int defHP){
        if (damage >= defHP){
		gold += steal;
	}
        return damage;
}

bool Goblin::beStruckBy(Character &c){
	int damage = c.extraEffect(c.strike(*this, getDefense()), HP);
        //cout << "PC took " << damage << " damage" << endl;
	if(damage == nonHostile) return false;
        else {
                bool result = defaultStruckBy(damage);
                ActionDisplay::setAttack(damage, string(1,c.getDisplay()));
                return result;
        }
}
