#ifndef __SHADE_H__
#define __SHADE_H__
#include <iostream>
#include <vector>
#include <utility>
#include "PC.h"
#include "Enemy.h"
class Shade : public PC{

public:
	Shade();
	~Shade() override;
	bool beStruckBy(Character &c) override;
};

#endif
