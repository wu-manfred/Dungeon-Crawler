#include "Character.h"
#include "ActionDisplay.h"
#include <iostream>
using namespace std;

Character::Character(): maxHP{0}, HP{0}, Attack{0}, Defense{0}, race{'e'}{}

char Character::getRace() const{
	return race;
}

void Character::newPos(int newX,int newY){
	x = newX;
	y = newY;
}
bool Character::getMoved(){return true;}

void Character::setMoved(){}

int Character::getAttack(){return Attack;}

int Character::getX(){return x;}

int Character::getY(){return y;}

int Character::getHP(){return HP;}

void Character::setHP(int newHP){
	HP = min(newHP, maxHP);
	HP = max(HP, 0);
} 

int Character::getDefense(){return Defense;}

int Character::getGold() const{return gold;}

void Character::setGold(int newGold){
	gold = newGold;
}

void Character::setAttack(int newAtt){Attack = newAtt;}

void Character::setDefense(int newDef){Defense = newDef;}

Character::~Character(){}

bool Character::defaultStruckBy(int damage){
	HP = HP - damage;
	if (HP < 0){return true;}
	else{return false;}
}


int Character::enemyStrike(int attack, int defense){
	int hitChance = rand() % 2;
	if (hitChance == 1){
		return ceil((100.0/(100 + defense)) * attack);
	} else {
		return missedAttack;
	}
}

int Character::PCStrike(int attack, int defense){
	return ceil((100.0/(100 + defense)) * attack); 
}

//Strike for Enemy
int Character::strike(Vampire &v, int def){
	if (HP <= 0) return nonHostile;
	return enemyStrike(Attack, def);
}

int Character::strike(Troll &t, int def){
	if (HP <= 0) return nonHostile;
	return enemyStrike(Attack, def);	
}

int Character::strike(Shade &s, int def){
	if (HP <= 0) return nonHostile;
	return enemyStrike(Attack, def);
}

int Character::strike(Drow &dr, int def){
	if (HP <= 0) return nonHostile;
	return enemyStrike(Attack, def);
}

int Character::strike(Goblin &go, int def){
	if (HP <= 0) return nonHostile;
	return enemyStrike(Attack, def);	
}

//Strike for PC
int Character::strike(Human &h, int def){
	return PCStrike(getAttack(), def);
}

int Character::strike(Dwarf &w, int def){
	return PCStrike(getAttack(), def);	
}

int Character::strike(Elf &e, int def){
	return PCStrike(getAttack(), def);
}

int Character::strike(Orc &o, int def){
	return PCStrike(getAttack(), def);
}

int Character::strike(Merchant &m, int def){
	return PCStrike(getAttack(), def);
}

int Character::strike(Dragon &d, int def){
	return PCStrike(getAttack(), def);
}

int Character::strike(Halfling &l, int def){
	return PCStrike(getAttack(), def);
}

char Character::getDisplay() const{ return '@';}

bool Character::beStruckBy(Character &c){ return true;}

int Character::extraEffect(int damage, int defHP){return damage;}
