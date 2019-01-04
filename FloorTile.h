#ifndef FLOORTILE_H
#define FLOORTILE_H
#include "Cell.h"
#include "Subscription.h"
class Character;

class FloorTile : public Cell{
	char display = '.';
	bool addedToChamber = false;
	public:
		FloorTile(int xPos, int yPos);
		~FloorTile() override;
		SubscriptionType subType() const override;
		void notify(Subject &whoNotified) override;
		void setDisplay(char newDisplay) override;
		Info getInfo() const override;
		void flipAddedToChamber() override;
};

#endif
		
	
