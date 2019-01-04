#ifndef __DRAGON_H__
#define __DRAGON_H__
#include <iostream>
#include <vector>
#include <utility>
#include "Enemy.h"

class Dragon : public Enemy{
public:
        Dragon();
        ~Dragon() override;

        bool beStruckBy(Character &c) override;
        char getDisplay() const override;
};

#endif

