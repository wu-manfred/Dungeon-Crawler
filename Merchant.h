#ifndef __MERCHANT_H__
#define __MERCHANT_H__
#include <iostream>
#include <vector>
#include <utility>
#include "Enemy.h"

class Merchant : public Enemy{
protected:
	static bool hostile;
public:
        Merchant();
        ~Merchant() override;
        bool beStruckBy(Character &c) override;
	void resetHostile();
	int extraEffect(int damage, int defHP);
	char getDisplay() const override;
};

#endif

