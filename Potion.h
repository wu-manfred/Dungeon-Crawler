#ifndef __POTION_H__
#define __POTION_H__
#include <iostream>
#include "Character.h"
#include "Item.h"

class Potion: public Item{
protected:
	char display = 'P';
public:
	virtual ~Potion() = 0;
	char getDisplay() const override;
};

#endif
