#ifndef __ITEM_H__
#define __ITEM_H__
#include <iostream>
#include <utility>
#include "Character.h"

class Item{
public:
	virtual ~Item() = 0;
	virtual void pickUp(Character *&) = 0;
	virtual char getDisplay() const = 0;
	virtual std::string getName() const = 0;
};
#endif
