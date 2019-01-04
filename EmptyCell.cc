#include "EmptyCell.h"
using namespace std;

EmptyCell::EmptyCell(int xPos, int yPos):
Cell(xPos, yPos){
	walkable = false;
}

EmptyCell::~EmptyCell(){}

SubscriptionType EmptyCell::subType() const{return SubscriptionType::All;}

void EmptyCell::notify(Subject &whoNotified){
	/*if (charOnTile){
		charOnTile->strike(whoNotified.charOnTile); //set this enemy's move thing to false
	} else if(itemOnTile){
		if (itemOnTile->known){
			cout << "There is a BA potion near you" << endl;
		} else{
			cout << "There is an unknown potion near you" << endl;
		}
	}*/
} 

Info EmptyCell::getInfo() const {
	Info cellInfo = {xPos, yPos, display, addedToChamber};
	return cellInfo;
}

