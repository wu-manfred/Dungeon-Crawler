#include "generateItem.h"


generateItem::~generateItem(){}

Item * generateItem::generatePotion(Character *pc, int x, int y){
	int spawn = rand() % numPotions;
	if (spawn == spawnRH){return new RH(x, y);}	
	else if (spawn == spawnPH){return new PH(x, y);}
	else if (spawn == spawnWA) {return new WA(pc, x, y);}
	else if (spawn == spawnWD) {return new WD(pc, x, y);}
	else if (spawn == spawnBA) {return new BA(pc, x, y);}
	return new BD(pc, x, y);
}

Item * generateItem::generateGold(int x, int y){
	double spawn = (double)rand() / RAND_MAX;
	if (spawn < spawnSmall){return new Treasure(x, y, smallGold);}
        else if (spawn < spawnNormal){return new Treasure(x, y, normalGold);}
        else{
		Character * drag = new Dragon();
		return new DHoard(x, y, drag);
	}
}


