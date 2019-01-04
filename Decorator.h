#ifndef __DECORATOR_H__
#define __DECORATOR_H__
#include <iostream>
#include "Character.h"

class Decorator: public Character{
protected:
	Character *pc;
public:
	Decorator(Character *, int, int);
	virtual ~Decorator();
	void updatePC();
	Character * removeDec() override;
};

#endif
