#ifndef __GOBLIN_H__
#define __GOBLIN_H__
#include <iostream>
#include <vector>
#include <utility>
#include "PC.h"
#include "Enemy.h"
class Goblin : public PC{
	int steal = 5;
public:
	Goblin();
	~Goblin() override;
	bool beStruckBy(Character &c) override;
	int extraEffect(int damage, int defHP) override;
};

#endif
