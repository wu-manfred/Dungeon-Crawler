#ifndef __GENERATE_ITEM_H__
#define __GENERATE_ITEM_H__
#include "WD.h"
#include "RH.h"
#include "PH.h"
#include "WA.h"
#include "BD.h"
#include "BA.h"
#include "DHoard.h"
#include "Dragon.h"
#include "Treasure.h"

const int numPotions = 6;
const int spawnRH = 0;
const int spawnPH = 1;
const int spawnWA = 2;
const int spawnWD = 3;
const int spawnBA = 4;
const int spawnBD = 5;

const int smallGold = 1;
const int normalGold = 2;
const int DHGold = 6;
const double spawnSmall = 0.25;
const double spawnNormal = 0.875;
const double spawnDHoard = 1;




class generateItem : public Item{
public:
        ~generateItem() override;
        static Item *generatePotion(Character *pc, int x, int y);
	static Item *generateGold(int x, int y);
};

#endif

