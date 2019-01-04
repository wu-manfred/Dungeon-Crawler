#include "Orc.h"

using namespace std;

Orc::~Orc(){}

Orc::Orc(){
	display = 'O';
        HP = 180;
        Attack = 30;
        Defense = 25;
}

int Orc::strike(Goblin &go, int def){
        return enemyStrike(Attack, def) * 1.5;
}

bool Orc::beStruckBy(Character &c){
	int damage = c.extraEffect(c.strike(*this, Defense), HP);
        bool result= defaultStruckBy(damage);
        ActionDisplay::setAttack(damage, string(1,c.getDisplay()));
        return result;
}

char Orc::getDisplay() const {return display;}
