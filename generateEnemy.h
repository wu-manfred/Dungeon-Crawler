#ifndef __GENERATE_ENEMY_H__
#define __GENERATE_ENEMY_H__
#include "Human.h"
#include "Dwarf.h"
#include "Elf.h"
#include "Merchant.h"
#include "Halfling.h"
#include "Orc.h"

const double humanSpawn = 0.22;
const double dwarfSpawn = 0.39;
const double halflingSpawn = 0.67;
const double elfSpawn = 0.78;
const double orcSpawn = 0.89;
const double merchantSpawn = 1.0;


class generateEnemy : public Enemy{
public:
        ~generateEnemy();
        static Enemy *generate();
};

#endif

