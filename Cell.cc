#include "Cell.h"
#include <utility>
#include "Subject.h"
#include "Observers.h"
using namespace std;
Cell::~Cell(){}

Cell::Cell(int xPos, int yPos):
xPos{xPos}, yPos{yPos}, charOnTile{nullptr}, itemOnTile{nullptr}{}

void Cell::deleteCell(){
	if (charOnTile){
		delete charOnTile;
		charOnTile = nullptr;
	} 
	if (itemOnTile){
		delete itemOnTile;
		itemOnTile = nullptr;
	}
}

void Cell::emptyCell(){
	if (charOnTile){
		charOnTile = nullptr;
	} else if (itemOnTile){
		itemOnTile = nullptr;
	}
}

void Cell::setDisplay(char newDisplay){}

bool Cell::moveTo(Character *pc){
	if(!walkable || charOnTile || (itemOnTile && (itemOnTile->getDisplay() == 'P'))){
		return false;
	} else if (itemOnTile && (itemOnTile->getName() == "gold")){
		useItem(pc);
		itemOnTile = nullptr;
	}
	charOnTile = pc;
	//cout << pc->getDisplay() << endl;
	pc->newPos(xPos,yPos);
	return true;

}

bool Cell::placeItem(Item *item){
	if (itemOnTile || charOnTile){
		return false;
	} 
	itemOnTile = item;
	return true;
}

bool Cell::useItem(Character *&pc){
	if (itemOnTile){
		itemOnTile->pickUp(pc);
		return true;
	} else {
		return false;
	}
}	

int Cell::cellContents() const{
	if (charOnTile){
		return 2;
	} else if (itemOnTile){
		return 1;
	} else {
		return 0;
	}
}

void Cell::flipAddedToChamber(){}
