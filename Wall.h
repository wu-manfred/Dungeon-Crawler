#ifndef WALL_H
#define WALL_H
#include "Cell.h"
#include "Subscription.h"
class Character;

class Wall : public Cell{
	char display = '-';
	bool style;
	bool addedToChamber = true;
	public:
		Wall(int xPos, int yPos,bool style);
		~Wall() override;
		SubscriptionType subType() const override;
		void notify(Subject &whoNotified)override;
		Info getInfo() const override;
};
#endif
		
	
