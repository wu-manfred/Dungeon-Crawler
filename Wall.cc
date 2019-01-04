#include "Wall.h"
#include "Subscription.h"
class Character;

Wall::Wall(int xPos, int yPos,bool style):
Cell(xPos, yPos), style{style}{
	if(style){
		display = '|';
	}else{
		display = '-';
	}

	walkable = false;
}

Wall::~Wall(){} 

SubscriptionType Wall::subType() const{return SubscriptionType::All;}

void Wall::notify(Subject &whoNotified){}
//change get char for wall later
Info Wall::getInfo() const{
	Info cellInfo = {xPos, yPos, display, addedToChamber};
	return cellInfo;
}

