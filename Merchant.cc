#include <iostream>
#include "Merchant.h"
#include "ActionDisplay.h"

using namespace std;

bool Merchant::hostile = false;

Merchant::~Merchant(){}

Merchant::Merchant(){
        display = 'M';
        HP = 30;
        Attack = 70;
        Defense = 5;	
}

int Merchant::extraEffect(int damage, int defHP){
	if(!hostile) return nonHostile;
	else { 
		moved = true;
		return damage;
	}
	
}
//MAKE SURE THAT THE MERCHANT RESETS HOSTILE ON NEW GAME
bool Merchant::beStruckBy(Character &c){
	hostile = true;
	int damage = c.extraEffect(c.strike(*this, Defense), HP);
	bool result= defaultStruckBy(damage);
	cout << "Merchant took " << damage << " damage" << endl;
	ActionDisplay :: setAttack(damage, string(1,c.getDisplay()));
        return result;
}

void Merchant::resetHostile(){
	hostile = false;
}

char Merchant::getDisplay() const {return display;}

