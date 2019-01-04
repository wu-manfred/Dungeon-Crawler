#ifndef __ENEMY_H__
#define __ENEMY_H__
#include <iostream>
#include <vector>
#include <utility>
#include "Character.h"

class Enemy : public Character{
protected:
	char display;
	bool moved = false;
public:
	Enemy();
	Character * removeDec() override;
	virtual ~Enemy() = 0;
	int extraEffect(int damage, int defHP) override;
	bool getMoved() override;
	void setMoved() override;
};

#endif
