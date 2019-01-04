#ifndef __DWARF_H__
#define __DWARF_H__
#include <iostream>
#include <vector>
#include <utility>
#include "Enemy.h"
#include "PC.h"
class Dwarf : public Enemy{
public:
        Dwarf();
        ~Dwarf() override;
        bool beStruckBy(Character &c) override;
        char getDisplay() const override;

};

#endif

