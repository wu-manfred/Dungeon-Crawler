#include "Doorway.h"
#include "Subscription.h"

Doorway::Doorway(int xPos, int yPos):
Cell(xPos, yPos){
	walkable = true;
}

Doorway::~Doorway(){
	if (charOnTile){delete charOnTile;}	
}

SubscriptionType Doorway::subType() const {return SubscriptionType::All;}

void Doorway::notify(Subject &whoNotified){}

Info Doorway::getInfo() const {
	char the_display;
	if (charOnTile){
		the_display = charOnTile->getDisplay();
	}
	else{
		the_display = display;
	}
	Info cellInfo = {xPos, yPos, the_display, addedToChamber, charOnTile, itemOnTile};
	return cellInfo;
}

