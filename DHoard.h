#ifndef __DHOARD_H__
#define __DHOARD_H__
#include <iostream>
#include "Treasure.h"
#include "Dragon.h"

class DHoard: public Treasure{
protected:
	Character * dragon;
public:
	DHoard(int xPos, int yPos, Character *dragon);
	~DHoard();	
	void pickUp(Character *&) override;
	Character * getDrag();
};

#endif
