#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "math.h"
#include <stdlib.h>
#include "ActionDisplay.h"
const int missedAttack = 0;
const int nonHostile = -1;


class Character{
protected:
	int maxHP, HP, Attack, Defense, x, y;
	int gold = 0;
	bool moved = true;
	char race;
public:
	Character();
	virtual ~Character()=0;
	//check if pure virtual works 
	virtual int getAttack();
	virtual int getDefense();
	void setAttack(int newAtt);
	void setDefense(int newDef);
	virtual int getX();
	virtual int getY();
	virtual int getHP();
	void setHP(int newHP);
	char getRace() const;
	int getGold() const;
	void setGold(int newGold);
	virtual char getDisplay() const;
	virtual void newPos(int newX,int newY);	
	virtual Character * removeDec() = 0;	
	//Strike for Enemy
	virtual int strike(class Vampire &v, int def);
	virtual int strike(class Troll &t, int def);
	virtual int strike(class Shade &s, int def);
	virtual int strike(class Drow &dr, int def);
	virtual int strike(class Goblin &go, int def);

	//Strike for PC
	virtual int strike(class Human &h, int def);
	virtual int strike(class Dwarf &w, int def);
	virtual int strike(class Elf &e, int def);
	virtual int strike(class Orc &o, int def);
	virtual int strike(class Merchant &m, int def);
	virtual int strike(class Dragon &d, int def);
	virtual int strike(class Halfling &l, int def);
	//returns true if dead
	virtual int extraEffect(int damage, int defHP);
	virtual bool beStruckBy(Character &c);
	int enemyStrike(int attack, int defense);
	int PCStrike(int attack, int defense);
	bool defaultStruckBy(int damage);
	virtual bool getMoved();
	virtual void setMoved();

};

#endif
