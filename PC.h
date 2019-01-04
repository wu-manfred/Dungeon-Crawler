#ifndef __PC_H__
#define __PC_H__
#include <iostream>
#include <vector>
#include <utility>
#include "Character.h"

class PC : public Character{
protected:
	const char display = '@'; 
public:
	PC();
	virtual ~PC() = 0;
	char getDisplay() const override;
	Character * removeDec() override;
};

#endif
