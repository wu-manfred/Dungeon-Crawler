#include "DHoard.h"
#include <iostream>
using namespace std;

DHoard::DHoard(int xPos, int yPos, Character *d):
Treasure(xPos, yPos, 6), dragon{d}{
	name = "hoard";
}

void DHoard::pickUp(Character *&pc){
	cout << "tried to pick up hoard" << endl;
	if (!dragon){
		cout << "no dragon" << endl;
		pc->setGold(pc->getGold() + value);
	}
}

DHoard::~DHoard() {
	delete dragon;
}

Character * DHoard::getDrag(){
	return dragon;
}	
