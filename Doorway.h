#ifndef DOORWAY_H
#define DOORWAY_H
#include "Cell.h"
class Info;
class Character;

class Doorway : public Cell{
	bool addedToChamber = true;
	const char display = '+';
	public:
		Doorway(int xPos, int yPos);
		~Doorway() override;
		
		SubscriptionType subType() const override;
		void notify(Subject &whoNotified) override;
		Info getInfo() const override;
};
#endif
		
	
