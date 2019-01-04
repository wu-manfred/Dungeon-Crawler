#ifndef __BA_H__
#define __BA_H__
#include <iostream>
#include "Decorator.h"
#include "Potion.h"
#include "Character.h"

class BA: public Potion, public Decorator{
	static bool known;
	const std::string name = "BA";
public:
	BA (Character *, int, int);
	~BA() override;
	int getAttack() override;
	void pickUp(Character *&) override;
	std::string getName() const override;
	bool beStruckBy(Character &) override;
	int extraEffect(int, int) override;
	void newPos(int newX, int newY) override;
	int strike(Human &h, int def) override;
	int strike(Dwarf &w, int def) override;
	int strike(Elf &e, int def) override;
	int strike(Orc &o, int def) override;
	int strike(Merchant &m, int def) override;
	int strike(Dragon &d, int def) override;
	int strike(Halfling &l, int def) override;
};

#endif
