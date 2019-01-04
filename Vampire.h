#ifndef __Vampire_H__
#define __Vampire_H__
#include <iostream>
#include <vector>
#include <utility>
#include "PC.h"
#include "Enemy.h"
#include <limits>

class Vampire : public PC{
private:
	const int lifeSteal = 5;
public:
	Vampire();
	~Vampire() override;
	
//	int strike(class Human &h, int def) override;
        int strike(class Dwarf &w, int def) override;
	/*
        int strike(class Elf &e, int def) override;
        int strike(class Orc &o, int def) override;
        int strike(class Merchant &m, int def) override;
        int strike(class Dragon &d, int def) override;
        int strike(class Halfling &l, int def) override;
	*/
        bool beStruckBy(Character &c) override;
	int extraEffect(int damage, int defHP) override;
};

#endif
