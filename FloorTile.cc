#include "FloorTile.h"
using namespace std;
#include <iostream>
#include "DHoard.h"

FloorTile::FloorTile(int xPos, int yPos):
Cell(xPos, yPos){
	walkable = true;
}

FloorTile::~FloorTile(){
		delete charOnTile;
		delete itemOnTile;
}
	

void FloorTile:: setDisplay(char newDisplay){
	display = newDisplay;
}

SubscriptionType FloorTile::subType() const{return SubscriptionType::All;}

void FloorTile::notify(Subject &whoNotified){
	if (charOnTile && charOnTile->getDisplay() != 'D'){
		//calls the beStruckBy of the PC 
		whoNotified.getInfo().charOnTile->beStruckBy(*charOnTile);
	}
	else if(itemOnTile){
		string type = itemOnTile->getName();
		ActionDisplay::setPotion(type,false); 
		if (itemOnTile->getName() == "hoard"){
         		DHoard * theHoard = reinterpret_cast<DHoard *>(itemOnTile);
               		whoNotified.getInfo().charOnTile->beStruckBy(*theHoard->getDrag());
        	}
	}
}

Info FloorTile::getInfo() const {
	char the_display;
	if (charOnTile){
		the_display = charOnTile->getDisplay();
	}
	else if (itemOnTile){
		the_display = itemOnTile->getDisplay();
	}
	else{
		the_display = display;
	}
	Info cellInfo = {xPos, yPos, the_display, addedToChamber, charOnTile, itemOnTile};
	return cellInfo;
}


void FloorTile::flipAddedToChamber(){
	addedToChamber = true;
}
