#ifndef __PH_H__
#define __PH_H__
#include <iostream>
#include "Potion.h"
class PH: public Potion{
        static bool known;
        const std::string name = "PH";
        int xPos, yPos;
public:
        PH (int, int);
	~PH() override;
        void pickUp(Character *&pc) override;
        std::string getName() const override;
};

#endif
