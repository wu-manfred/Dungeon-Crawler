#ifndef __HUMAN_H__
#define __HUMAN_H__
#include <iostream>
#include <vector>
#include <utility>
#include "Enemy.h"

class Human : public Enemy{
public:
	Human();
	~Human() override;
	
	bool beStruckBy(Character &c) override;
	char getDisplay() const override;
};

#endif

