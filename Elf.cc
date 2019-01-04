#include <iostream>
#include "Elf.h"

using namespace std;
Elf::~Elf(){}

Elf::Elf(){
        display = 'E';
        HP = 140;
        Attack = 30;
        Defense = 10;
}

int Elf::doubleStrike(int attack, int defense){
	//Total damage that is going to be dealt
	int totalDamage = 0;
	//Damage from a single attack
	int singleHit = ceil((100.0/(100 + defense)) * attack);
	//The chance of succesfully striking is a 1/2
	int hitChance;
	for (int i = 0; i < 2; ++ i){
		hitChance = rand() % 2;
		if (hitChance == 1){
			totalDamage += singleHit;
		}
	}	
	return totalDamage;
}
	

int Elf::strike(Vampire &v, int def){
        return doubleStrike(Attack, def);
}

int Elf::strike(Troll &t, int def){
        return doubleStrike(Attack, def);
}

int Elf::strike(Shade &s, int def){
        return doubleStrike(Attack, def);
}

int Elf::strike(Goblin &go, int def){
        return doubleStrike(Attack, def);
}



bool Elf::beStruckBy(Character &c){
	int damage = c.extraEffect(c.strike(*this, Defense), HP);
        bool result= defaultStruckBy(damage);
        ActionDisplay::setAttack(damage, string(1,c.getDisplay()));
        return result;
}

char Elf::getDisplay() const {return display;}

