#include <iostream>
#include "Human.h"
#include "ActionDisplay.h"

using namespace std;
Human::~Human(){}

Human::Human(){
	display = 'H';
	HP = 140;
	Attack = 20;
	Defense = 20;
}

bool Human::beStruckBy(Character &c){
	int damage = c.extraEffect(c.strike(*this, Defense), HP);
	bool result= defaultStruckBy(damage);
	ActionDisplay::setAttack(damage, string(1,c.getDisplay()));
	return result;
}



char Human::getDisplay() const {return display;}

