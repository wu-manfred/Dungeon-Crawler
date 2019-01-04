#ifndef __TREASURE_H__
#define __TREASURE_H__
#include <iostream>
#include "Item.h"
#include "Character.h"

class Treasure: public Item{
protected:
	int xPos, yPos;
	char display = 'G';
	const int value;
	std::string name = "gold";
public:
	Treasure(int xPos, int yPos, int value);
	~Treasure() override;
	virtual void pickUp(Character *&) override;
	char getDisplay() const override;
	std::string getName() const override;
};

#endif
