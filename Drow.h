#ifndef __DROW_H__
#define __DROW_H__
#include <iostream>
#include <vector>
#include <utility>
#include "PC.h"
#include "Enemy.h"
class Drow : public PC{
	
public:
	Drow();
	~Drow() override;
	bool beStruckBy(Character &c) override;
};

#endif
