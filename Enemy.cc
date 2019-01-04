#include "Enemy.h"

Character * Enemy::removeDec() {
	return this;
}

Enemy::~Enemy(){}

int Enemy::extraEffect(int damage, int defHP){
	moved = true;
	return damage;
}

bool Enemy:: getMoved(){return moved;}
void Enemy:: setMoved(){moved=!moved;}
Enemy::Enemy(){}

