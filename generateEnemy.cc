#include "generateEnemy.h"
generateEnemy::~generateEnemy(){}

Enemy * generateEnemy::generate(){
	double spawn = (double)rand() / RAND_MAX;
	if (spawn < humanSpawn){return new Human();}
	else if (spawn < dwarfSpawn){return new Dwarf();}
	else if (spawn < halflingSpawn){return new Halfling();}
	else if (spawn < elfSpawn){return new Elf();}
	else if (spawn < orcSpawn){return new Orc();}
	else return new Merchant();
}


