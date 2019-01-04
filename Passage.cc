#include "Passage.h"
#include "Subscription.h"

Passage::Passage(int xPos, int yPos):
Cell(xPos, yPos){
	walkable = true;
}

Passage::~Passage(){
	if (charOnTile){delete charOnTile;}
} 

SubscriptionType Passage::subType() const {return SubscriptionType::All;}

void Passage::notify(Subject &whoNotified){}

Info Passage::getInfo() const {
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

