#ifndef __ORC_H__
#define __ORC_H__
#include <iostream>
#include <vector>
#include <utility>
#include "Enemy.h"

class Orc : public Enemy{

public:
        Orc();
        ~Orc() override;
	int strike(class Goblin &go, int def) override;
        bool beStruckBy(Character &c) override;
	char getDisplay() const override;
};

#endif

