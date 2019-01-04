#ifndef __TROLL_H__
#define __TROLL_H__
#include <iostream>
#include <vector>
#include <utility>
#include "PC.h"
#include "Enemy.h"
class Troll : public PC{
private:
	int regen = 5;
public:
	Troll();
	~Troll() override;
	void newPos(int newX, int newY) override;
	int extraEffect(int damage, int defHP) override;
	bool beStruckBy(Character &c) override;
};

#endif
