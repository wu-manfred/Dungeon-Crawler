#ifndef __ELF_H__
#define __ELF_H__
#include <iostream>
#include <vector>
#include <utility>
#include "Enemy.h"

class Elf : public Enemy{
public:
        Elf();
        ~Elf() override;
        bool beStruckBy(Character &c) override;
	int strike(Vampire &v, int def) override;
	int strike(Troll &t, int def) override;
	int strike(Shade &s, int def) override;
	int strike(Goblin &go, int def) override;
	int doubleStrike(int attack, int defense);
	char getDisplay() const override;
};

#endif

