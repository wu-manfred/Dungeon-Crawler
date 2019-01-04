#ifndef __RH_H__
#define __RH_H__
#include <iostream>
#include "Potion.h"
class RH: public Potion{
	static bool known;
	const std::string name = "RH";
	int xPos, yPos;
public:
	RH (int, int);
	~RH() override;
	void pickUp(Character *&pc) override;
	std::string getName() const override;
};

#endif	
