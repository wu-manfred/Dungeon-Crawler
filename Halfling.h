#ifndef __HALFLING_H__
#define __HALFLING_H__
#include <iostream>
#include <vector>
#include <utility>
#include "Enemy.h"

class Halfling : public Enemy{
public:
        Halfling();
        ~Halfling() override;
        bool beStruckBy(Character &c) override;
        char getDisplay() const override;
	
};

#endif

